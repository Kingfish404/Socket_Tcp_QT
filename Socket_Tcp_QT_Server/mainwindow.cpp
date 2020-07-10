#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowTitle("Server");
    this->centralWidget()->setStyleSheet("*{;"
                                         "font-family:'Microsoft YaHei','SF Pro Display',Roboto,Noto,Arial,'PingFang SC',sans-serif}");
    isConnect=false;
    tcpServer=nullptr;
    tcpServer=nullptr;


    // 监听套接字，指定父对象，让其自动回收空间
    tcpServer = new QTcpServer(this);

    tcpServer->listen(QHostAddress::Any, 8888);

    //监听tcp连接的建立
    connect(tcpServer, &QTcpServer::newConnection,
            [=]()
    {
        //取出建立好连接的套接字
        tcpSocket = tcpServer->nextPendingConnection();

        //获取对方的IP和端口
        QHostAddress hostAddr = tcpSocket->peerAddress();
        quint16 port = tcpSocket->peerPort();

        QString ip= hostAddr.toString();

        QString temp = QString("[%1:%2]:成功连接").arg(ip).arg(port);
        isConnect=true;
        showMsg(temp);
        connect(tcpSocket, &QTcpSocket::readyRead,
                [=](){
            //从通信套接字中取出内容
            QByteArray array = tcpSocket->readAll();
            showMsg("Client : "+array);
        });
    });

    // 初始化udp
    udpSocket = new QUdpSocket(this);
    udpSocket->bind(QHostAddress::AnyIPv4,8889);
}

void MainWindow::showMsg(QString msg)
{
    this->ui->textGet->insertPlainText(msg+"\n");
}


void MainWindow::on_pBtnSend_clicked()
{
    // tcp通信函数
    QString sendText=this->ui->textSend->toPlainText();
    if(isConnect)
    {
        this->ui->textSend->clear();
        tcpSocket->write(sendText.toUtf8().data());
        showMsg("To Client : "+sendText);
    }else
    {
        showMsg("None connected now!");
    }
}

void MainWindow::on_pBtnSendToAll_clicked()
{
    // udp通信函数
    QString sendText=this->ui->textSend->toPlainText();
    if(sendText!="")
    {
        this->ui->textSend->clear();
        udpSocket->writeDatagram(sendText.toUtf8(),QHostAddress::Broadcast,8889);
        showMsg("To All : "+sendText);
    }else
    {
        showMsg("Message is empty!");
    }
}

MainWindow::~MainWindow()
{
    udpSocket->leaveMulticastGroup(QHostAddress(udpIp));
    tcpSocket->disconnectFromHost();
    tcpSocket->close();
    if(tcpSocket!=nullptr)
    {
        delete tcpSocket;
    }
    if(tcpServer!=nullptr)
    {
        delete tcpServer;
    }
    if(udpSocket!=nullptr)
    {
        delete udpSocket;
    }
    delete ui;
}

#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowTitle("Client");
    this->centralWidget()->setStyleSheet("*{;"
                                         "font-family:'Microsoft YaHei','SF Pro Display',Roboto,Noto,Arial,'PingFang SC',sans-serif}");

    // 初始化数据
    isConnected=false;
    isChangeIp=true;
    hostip=this->ui->leTarget->text();
    port=8888;

    tcpSocket =nullptr;

    tcpSocket = new QTcpSocket(this);

    // tcp连接成功显示
    connect(tcpSocket,&QTcpSocket::connected,
            [=]()
    {
        showMsg("Connect to "+hostip+" successful!");
        isConnected=true;
        isChangeIp=false;
    });

    // tcp信息接收显示
    connect(tcpSocket,&QTcpSocket::readyRead,
            [=]()
    {
        // 获取对方发送的内容
        QByteArray array = tcpSocket->readAll();
        // 显示信息
        showMsg("Server : "+array);
    });

    // 初始化udp
    udpSocket = new QUdpSocket(this);

    udpSocket->bind(8889,QUdpSocket::ShareAddress);

    connect(udpSocket,&QUdpSocket::readyRead,this,&MainWindow::dealMsg);
}

void MainWindow::dealMsg()
{
    //读取对方发送的内容
    char buf[1024] = {0};
    showMsg("From Server:");
    QHostAddress cliAddr; //对方地址
    quint16 port;    //对方端口
    qint64 len = udpSocket->readDatagram(buf, sizeof(buf), &cliAddr, &port);
    if(len > 0)
    {
        //格式化 [192.68.2.2:8888]aaaa
        QString str = QString("[%1:%2]to all : %3")
                .arg(cliAddr.toString())
                .arg(port)
                .arg(buf);
        //给编辑区设置内容
        showMsg(str);
    }

}

inline void MainWindow::showMsg(QString msg)
{
    this->ui->textGet->insertPlainText(msg+"\n");
}

void MainWindow::on_pbtnSend_clicked()
{
    QString sendText=this->ui->textSend->toPlainText();
    if(isConnected)
    {
        this->ui->textSend->clear();

        if(sendText!="")
        {
            tcpSocket->write(sendText.toUtf8().data());
            showMsg("To Server : "+sendText);
        }
    }else
    {
        showMsg("None connected now!");
    }
}

void MainWindow::on_pbtnConnect_clicked()
{

    hostip=this->ui->leTarget->text();
    tcpSocket->disconnectFromHost();
    // 建立tcp连接
    tcpSocket->connectToHost(QHostAddress(hostip),port);

    if(tcpSocket->errorString()!="Unknown error")
    {
        showMsg(tcpSocket->errorString());
    }
}

MainWindow::~MainWindow()
{
    tcpSocket->disconnectFromHost();
    tcpSocket->close();
    if(tcpSocket!=nullptr)
    {
        delete tcpSocket;
    }
    delete ui;
}

void MainWindow::on_leTarget_editingFinished()
{
    isChangeIp=true;
}

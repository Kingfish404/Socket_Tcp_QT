#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTcpServer>       //监听套接字
#include <QTcpSocket>       //通信套接字
#include <QUdpSocket>       // Udp群发通信

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

protected:
    bool isConnect;        // 是否已经连接
    QTcpServer *tcpServer; //监听套接字
    QTcpSocket *tcpSocket; //通信套接字

    QUdpSocket *udpSocket;  //UDP套接字

    QString udpIp;

    // 在接受消息处显示信息
    void showMsg(QString msg);

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pBtnSend_clicked();

    void on_pBtnSendToAll_clicked();

private:


    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H

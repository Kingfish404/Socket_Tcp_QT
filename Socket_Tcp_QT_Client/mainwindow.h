#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTcpSocket>
#include <QHostAddress>
#include <QUdpSocket>
#include <QDebug>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT
private:
    int iResult;        // 错误代码
    bool isConnected;   // 是否已经连接
    bool isChangeIp;    // 是否改变ip
    QString hostip;   // 主机名
    qint16 port;


    // 通信套接字
    QTcpSocket *tcpSocket;

    QUdpSocket *udpSocket;  //UDP套接字

    QString udpIp;

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pbtnSend_clicked();

    void on_pbtnConnect_clicked();

    void on_leTarget_editingFinished();


protected:
    // 在接受消息处显示信息
    void showMsg(QString msg);

    // 处理群发消息
    void dealMsg();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H

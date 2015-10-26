#ifndef UDP_SENDER_H
#define UDP_SENDER_H

#include <QObject>
#include<string>

class QUdpSocket;
class QTimer;

class udp_sender : public QObject
{
    Q_OBJECT
public:
    explicit udp_sender(QObject *parent = 0);
    void init(int);
    void init();
    void test();

public slots:
    void broadcastDatagram();
    void broadcast_string(const std::string &);
private:
    QUdpSocket *udpSocket;
    QTimer *timer;
    QByteArray datagram;
    int messageNo;
    int port;
};

#endif // UDP_SENDER_H

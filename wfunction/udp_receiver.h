#ifndef UDP_RECEIVER_H
#define UDP_RECEIVER_H

#include<QObject>
#include<string>
class QUdpSocket;
class udp_receiver : public QObject
{
    Q_OBJECT
public:
    explicit udp_receiver(QObject *parent = 0);
    void init();
    void test();
signals:
    void broadcast_string(const std::string &);
public slots:
    void processPendingDatagrams();
private:
    QUdpSocket *udpSocket;
    QByteArray datagram;
};

#endif // UDP_RECEIVER_H

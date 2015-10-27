#include "udp_sender.h"

#include <QtNetwork>

#include<string>
#include<iostream>

using namespace std;


udp_sender::udp_sender(QObject *parent)
    :QObject(parent)
{

}
void udp_sender::init(int portnumber)
{
    udpSocket = new QUdpSocket(this);
    timer = new QTimer(this);
    messageNo=0;
    port=portnumber;

    connect(timer, SIGNAL(timeout()), this, SLOT(broadcastDatagram()));
}
void udp_sender::init()
{
    init(23425);
}
void udp_sender::test()
{
    timer->start(1000);
}
void udp_sender::broadcastDatagram()
{
    datagram = "Broadcast message " + QByteArray::number(messageNo);
    broadcast_string(datagram.data());
    if(messageNo%2)
    {
        broadcast_string("testing hahaha");
    }
    ++messageNo;
}
void udp_sender::broadcast_string(const std::string &msg)
{
 datagram = QByteArray(msg.c_str());
 udpSocket->writeDatagram(datagram.data(), datagram.size(),QHostAddress::Broadcast, port);
}

#include "udp_receiver.h"

#include <QtNetwork>

#include<string>
#include<iostream>

using namespace std;


udp_receiver::udp_receiver(QObject *parent) :
    QObject(parent)
{
}
void udp_receiver::init()
{
    udpSocket = new QUdpSocket(this);
    udpSocket->bind(45454, QUdpSocket::ShareAddress);
    connect(udpSocket, SIGNAL(readyRead()),this, SLOT(processPendingDatagrams()));
}
void udp_receiver::test()
{

}
void udp_receiver::processPendingDatagrams()
{
    while (udpSocket->hasPendingDatagrams())
    {
        datagram.resize(udpSocket->pendingDatagramSize());
        udpSocket->readDatagram(datagram.data(), datagram.size());
        emit broadcast_string(datagram.data());
        cout <<datagram.data()<<endl;
    }
}

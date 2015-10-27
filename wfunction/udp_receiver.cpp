#include "udp_receiver.h"

#include <QtNetwork>

#include<string>
#include<iostream>

using namespace std;


udp_receiver::udp_receiver(QObject *parent) :
    QObject(parent)
{
}
bool udp_receiver::init(int portnumber)
{
    udpSocket = new QUdpSocket(this);
    port=portnumber;
    if(udpSocket->bind(port, QUdpSocket::ShareAddress))
    {
        connect(udpSocket, SIGNAL(readyRead()),this, SLOT(processPendingDatagrams()));
        return true;
    }
    else
    {
        cerr <<"Listening Port: "<< port << " is in using"<<endl;
        return false;
    }
}
bool udp_receiver::init()
{
    return init(23425);
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
        cout <<datagram.data();
    }
}

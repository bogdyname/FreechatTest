/*
***Copyleft (C) 2019 Softwater, Inc
***Contact: bogdyname@gmail.com
*/

#ifndef CONNECTIONF2F_H
#define CONNECTIONF2F_H

#include "Network/peerout.h"
#include "Network/peerin.h"
#include "Bin/freechat.h"
#include <QNetworkInterface>
#include <QTcpSocket>
#include <QtNetwork>

class QTcpSocket;
class Freechat;
class Peerout;
class Peerin;

class ConnectionF2F : public QTcpSocket
{
    Q_OBJECT

private:
    QString ip;

public:
    static QString globalNetworkBuffer;

public:
    ConnectionF2F(QObject *parent = nullptr);
    ~ConnectionF2F();

    void NetworkInfo();
    void WriteIpAddressFromPeer();
    void OpenConnectingToPortPeer();
    void OpenDisconnectingFromPortPeer();
};
#endif

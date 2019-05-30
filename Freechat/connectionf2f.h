/*
***Copyleft (C) 2019 Softwater, Inc
***Contact: bogdyname@gmail.com
*/

#ifndef CONNECTIONF2F_H
#define CONNECTIONF2F_H

#include <QNetworkInterface>
#include <QAbstractSocket>
#include <QNetworkSession>
#include <QHostAddress>
#include <QHostAddress>
#include <QTimerEvent>
#include <QTcpSocket>
#include <QHostInfo>
#include <QtNetwork>

class ConnectionF2F : public QTcpSocket
{
    Q_OBJECT

    ConnectionF2F(QObject *parent = nullptr);

public:
    void DigitalSignature();
    void ConnectingToPeer();
    void WaitForConnected();
    void WaitForDisconnected();

public:
    void SockedErroe();
    void MakeSocket();

protected:
    quint16 GetPeerPort();
    QHostAddress GetPeerAddress();

private:
    QTimerEvent TimerForWaitingConnection();

};

#endif // CONNECTIONF2F_H

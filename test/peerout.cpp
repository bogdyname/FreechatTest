/*
***Copyleft (C) 2019 Softwater, Inc
***Contact: bogdyname@gmail.com
*/

#include "peerout.h"

Peerout::Peerout()
{
    connect(socket, SIGNAL(Connected()), this, SLOT(Connected()));
    connect(socket, SIGNAL(DoConnect()), this, SLOT(DoConnect()));
    connect(socket, SIGNAL(ReadyRead()), this, SLOT(ReadyRead()));
    connect(socket, SIGNAL(BytesWrittenOfData(qint64)), this, SLOT(BytesWrittenOfData(qint64)));
}

Peerout::~Peerout()
{
    if(socket != nullptr)
    {
        delete socket;
    }
    else
    {
        /*clear code*/
    }
}

void Peerout::DoConnect()
{
    socket = new QTcpSocket(this);

    #ifndef Q_DEBUG
    qDebug() << "A new socket created.";
    #endif

    socket->connectToHost("92.243.182.174", 80);

        if(socket->waitForConnected(3000))
        {
            #ifndef Q_DEBUG
            qDebug() << "Connected!";
            #endif

            socket->write("DATA OF TEXT");
            socket->waitForBytesWritten(1000);
            socket->waitForReadyRead(3000);
            #ifndef Q_DEBUG
            qDebug() << "Reading: " << socket->bytesAvailable();
            qDebug() << socket->readAll();
            #endif

            socket->close();
        }
        else
        {
            #ifndef Q_DEBUG
            qDebug() << "Not connected!";
            #endif
        }

        return;
}

void Peerout::BytesWrittenOfData(qint64 bytes)
{
    #ifndef Q_DEBUG
    qDebug() << bytes << " bytes written...";
    #endif

    return;
}

void Peerout::Connected()
{

    return;
}

void Peerout::Disconnected()
{

    return;
}

void Peerout::ReadyRead()
{
    #ifndef Q_DEBUG
    qDebug() << "reading...";
    qDebug() << socket->readAll();
    #endif

    return;
}

void Peerout::TaskResult(unsigned int &Number)
{
    Number = 0;

    return;
}

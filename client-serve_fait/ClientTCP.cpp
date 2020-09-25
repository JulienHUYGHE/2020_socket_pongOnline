#include "ClientTCP.h"
#include <iostream>
#include <string>

#include "mainwindow.h"


ClientTCP::ClientTCP(MainWindow * w)
{
    m_w = w;
    std::cout << "Application Client" << std::endl;
    m_tcpSocket = new QTcpSocket(this);

    // La méthode lireTexte sera appelée sur le signal readyRead

    connect( m_tcpSocket, SIGNAL(readyRead()), this,
    SLOT(RecevoirInfo()));

    // La méthode afficherErreur sera appelée sur le signal error

    connect( m_tcpSocket, SIGNAL(error(QAbstractSocket::SocketError)),
    this, SLOT(afficherErreur(QAbstractSocket::SocketError)));
    QNetworkConfigurationManager manager;
    QNetworkConfiguration config;

    std::cout << "Ouverture session" << std::endl;

    m_networkSession = new QNetworkSession(config, this);
    m_networkSession->open();
    m_blockSize = 0;
    m_tcpSocket->abort();

    // connexion au serveur (changer port et/ou adresse IP)

    m_tcpSocket->connectToHost(
    QHostAddress("10.16.2.107").toString(),53001 );
}



void ClientTCP::RecevoirInfo(){

    QDataStream in(m_tcpSocket);
    in.setVersion(QDataStream::Qt_4_0);
    if (m_blockSize == 0) {
    if (m_tcpSocket->bytesAvailable() < (int)sizeof(quint16))
    return;
    in >> m_blockSize;
    }
    if (m_tcpSocket->bytesAvailable() < m_blockSize)
    return;
    QString texte;
    int InfoRecu;
    in >> texte;
    InfoRecu = texte.toInt();
    m_blockSize = 0;

    m_w->positionnerBarreJoueurAdv(InfoRecu);

}




void ClientTCP:: afficherErreur(QAbstractSocket::SocketError socketError){

    switch (socketError) {
        case QAbstractSocket::RemoteHostClosedError:
        break;
        case QAbstractSocket::HostNotFoundError:
        std::cout << "Le serveur n'a pas ete trouve. Verifiez le parametrage du serveur et du port." << std::endl;
        break;
        case QAbstractSocket::ConnectionRefusedError:
        std::cout <<"La communication a ete refusee. Verifiez que serveur est pret, ainsi que le parametrage du serveur et du port." << std::endl;
        break;
        default:
        std::cout << "L'erreur suivante s'est produite : " << m_tcpSocket->errorString().toStdString() << std::endl;
    }
}

void ClientTCP::EnvoyerInfoBarre(int pos_Y)
{
    std::cout<<"coucou j'envoie la coo de ma barre : "<<endl;

        QByteArray block;
        QDataStream out(&block, QIODevice::WriteOnly);
        out.setVersion(QDataStream::Qt_4_0);
        out << (quint16)0;
        out << QString::number(pos_Y);
        out.device()->seek(0);
        out << (quint16)(block.size() - sizeof(quint16));
        m_tcpSocket->write(block);

}







//void ClientTCP::EnvoyerInfoBarre(int pos_Y)
//{
//        QByteArray block;
//        QDataStream out(&block, QIODevice::WriteOnly);
//        out.setVersion(QDataStream::Qt_4_0);
//        out << (quint16)0;
//        out << QString::number(pos_Y);
//        out.device()->seek(0);
//        out << (quint16)(block.size() - sizeof(quint16));
//        m_tcpSocket->write(block);

//}









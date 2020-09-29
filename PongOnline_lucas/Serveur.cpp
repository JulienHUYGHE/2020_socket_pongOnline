#include "Serveur.h"
#include <iostream>

#include "mainwindow.h"

Serveur::Serveur( MainWindow * w){

    m_w = w;
    m_blockSize = 0;
    QNetworkConfigurationManager manager;
    QNetworkConfiguration config = manager.defaultConfiguration();
    m_network_session = new QNetworkSession(config, this);

        // La méthode sessionOuverte sera appelée sur le signal opened

    connect( m_network_session, SIGNAL(opened()), this, SLOT(sessionOuverte()) );

        // Ouverture de la session

    m_network_session->open();

        // La méthode connexionClient sera appelée sur le signal newConnection

    connect( m_tcp_server, SIGNAL(newConnection()), this, SLOT(connexionClient()) );


}

void Serveur::sessionOuverte()
{
    // Méthode appelée lors de l'ouverture de session

    m_tcp_server = new QTcpServer(this); // instanciation

    // on écoute sur le port 53000

    if (!m_tcp_server->listen(QHostAddress::Any, 53001))
    {
        std::cout << "Le serveur n'a pas été correctement lance." << std::endl;
    }
    else
    {
        std::cout << "Le serveur est pret \n\nIP: " << m_tcp_server->serverAddress().toString().toStdString() << std::endl << "port: " << m_tcp_server->serverPort() << std::endl  <<  "Lancez l'application Client maintenant." << std::endl;
    }


}

void Serveur::connexionClient()
{
    // initialisation du socket client
    std::cout<<"connexion d'un client"<<std::endl;

    m_socket_client = m_tcp_server->nextPendingConnection();

    // La méthode RecevoirInfoBarreJ2 sera appelée sur le signal readyRead
    for(int i = 0; i < 1000; i++)
    connect( m_socket_client, SIGNAL(readyRead()), this, SLOT(RecevoirInfoBarreJ2()));



}

void Serveur::RecevoirInfoBarreJ2()
{
    QDataStream in(m_socket_client);
    in.setVersion(QDataStream::Qt_4_0);

        if (m_blockSize == 0)
        {
            if (m_socket_client->bytesAvailable() < (int)sizeof(quint16))
                return;
            in >> m_blockSize;
        }
        if (m_socket_client->bytesAvailable() < m_blockSize)
            return;
        QString texte;
        int InfoRecu;
        in  >> texte;
        InfoRecu = texte.toInt();
        m_blockSize = 0;

        m_w->PositionnerBarreJoueurAdv(InfoRecu);  
}

void Serveur::EnvoyerInfoBarreJ1(int pos_Y){

        QByteArray block;
        QDataStream out(&block, QIODevice::WriteOnly);
        out.setVersion(QDataStream::Qt_4_0);
        out << (quint16)0;
        out << QString::number(pos_Y);
        out.device()->seek(0);
        out << (quint16)(block.size() - sizeof(quint16));
        m_socket_client->write(block);
}

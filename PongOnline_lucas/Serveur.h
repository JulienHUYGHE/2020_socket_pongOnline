#ifndef SERVEUR_H
#define SERVEUR_H
#include <QtNetwork>
#include <QObject>



class MainWindow;

class Serveur : public QObject
{

Q_OBJECT

private slots:
    void sessionOuverte();
    void connexionClient();
    void RecevoirInfoBarreJ2();

private:

    QTcpServer *m_tcp_server;
    QTcpSocket *m_socket_client;
    QNetworkSession *m_network_session;
    quint16 m_blockSize;
    MainWindow *m_w;

public:
    int m_infoRecu;
    Serveur(MainWindow * w);
    void EnvoyerInfoBarreJ1(int pos_Y);

};

#endif



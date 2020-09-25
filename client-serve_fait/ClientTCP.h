#define CLIENTTCP_H
#define CLIENTTCP_H
#include <QtNetwork>
#include <QObject>

class MainWindow;

class ClientTCP : public QObject
{

Q_OBJECT

private slots:

    void RecevoirInfo();
    void afficherErreur( QAbstractSocket::SocketError socketError);

private :
    QTcpSocket *m_tcpSocket;
    quint16 m_blockSize;
    QNetworkSession *m_networkSession;
    MainWindow *m_w;

public:
    int m_info;
    ClientTCP(MainWindow * w);
    void ChangerInfo(int changement_pos_Y);
    void EnvoyerInfoBarre(int pos_Y);


};

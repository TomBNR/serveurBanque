#ifndef SERVEURBANQUE_H
#define SERVEURBANQUE_H

#include <QTcpServer>
#include <QList>
#include "compteclient.h"


class ServeurBanque : public QTcpServer
{
public:
    ServeurBanque(QObject *parent = nullptr);
    ~ServeurBanque();
    void  Start();
    void Stop();
    void EnvoyerMessage(QString msg, CompteClient* client);


private slots:
    void onServeurBanque_NewConnection();
    void onCompteCLient_disconnected();
    void onCompteClient_readyRead();
private :
    QList<CompteClient*> lesConnexionsClients;


};

#endif // SERVEURBANQUE_H

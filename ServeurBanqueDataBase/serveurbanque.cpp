#include "serveurbanque.h"
#include <QMessageBox>
#include <QBuffer>


ServeurBanque::ServeurBanque(QObject *parent):
     QTcpServer(parent)
{
    if (!QObject::connect(this,&ServeurBanque::newConnection,this,&ServeurBanque::onServeurBanque_NewConnection)){
           QMessageBox msgbox;
           msgbox.setText("erreur association signal/slot");
           msgbox.exec();
       }
}

ServeurBanque::~ServeurBanque()
{

}

void ServeurBanque::Start()
{
    if(!this->listen(QHostAddress::Any,8888)){
        QMessageBox msgbox;
        msgbox.setText("erreur listen "+this->errorString());
        msgbox.exec();
    }
}

void ServeurBanque::Stop()
{
    this->close();
}

void ServeurBanque::EnvoyerMessage(QString msg, CompteClient *client)
{
    quint16 taille=0;
    QBuffer tampon;
    tampon.open(QIODevice::WriteOnly);
    //association du tampon au flux de sortie
    QDataStream out(&tampon);
    //construction de la trame
    out<<taille<<msg;
    //calcul de la taille de la trame
    taille=(static_cast<quint16>(tampon.size()-sizeof(taille)));
    tampon.seek(0);
    out<<taille;
    client->write(tampon.buffer());
}
void ServeurBanque::onServeurBanque_NewConnection()
{

}

void ServeurBanque::onCompteCLient_disconnected()
{
    CompteClient *client=(CompteClient*)sender();
    if (!client)
    {
        QMessageBox msg;
        msg.setText("erreur deconnexion : "+client->errorString());
        msg.exec();
    }
    else
    {
        lesConnexionsClients.removeOne(client);
        client->deleteLater();
    }
}

void ServeurBanque::onCompteClient_readyRead()
{

}

#ifndef COMPTECLIENT_H
#define COMPTECLIENT_H
#include <QTcpSocket>
#include "interfaceaccesbdbanque.h"

class CompteClient : public QTcpSocket
{
public:
    CompteClient(QObject *parent=nullptr);
    bool Retirer(const float montant);
    float Deposer(const float montant);
    float ObtenirSolde();
    int DefinirNumCompte(int nc);
    int ObtenirNumCompte();

private:
    //InterfaceAccesBDBanque bd;
    int numCompte;
    float solde;
};

#endif // COMPTECLIENT_H

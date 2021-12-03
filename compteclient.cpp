#include "compteclient.h"


CompteClient::CompteClient(QObject *parent)
    :QTcpSocket(parent)
{

}

bool CompteClient::Retirer(const float montant)
{
    bool ret=false ;
    if(solde>=montant){
        solde=solde-montant;
       ret=true;
    }
    return ret;
}

float CompteClient::Deposer(const float montant)
{
    if(montant>0){
        solde=solde+montant;
    }

}

float CompteClient::ObtenirSolde()
{
    return solde;
}

int CompteClient::DefinirNumCompte( int nc)

{
    nc=numCompte;
    solde=200;
}

int CompteClient::ObtenirNumCompte()
{
    return numCompte;
}

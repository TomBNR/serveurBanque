#ifndef INTERFACEACCESBDBANQUE_H
#define INTERFACEACCESBDBANQUE_H

#include <QSqlDatabase>
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include <QString>
#include <QDebug>

class InterfaceAccesBDBanque : public QSqlDatabase
{
public:
    InterfaceAccesBDBanque(QString hote,QString bd,QString login,QString mdp);
    float ObtenirSolde(int numCompte);
    void MettreAJourLeSolde(int numCompte,float nouveauSolde);
    void CreerCompte(int numCompte);
    bool CompteExiste(int numCompte);

private :
     QSqlDatabase bdd;
};

#endif // INTERFACEACCESBDBANQUE_H

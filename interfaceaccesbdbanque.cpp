#include "interfaceaccesbdbanque.h"


InterfaceAccesBDBanque::InterfaceAccesBDBanque(QString hote, QString bd, QString login, QString mdp)
{
    bdd = QSqlDatabase::addDatabase("QMYSQL");
       bdd.setHostName(hote);
       bdd.setDatabaseName(bd);
       bdd.setUserName(login);
       bdd.setPassword(mdp);
       if(!bdd.open()){
           qDebug()<<"pb access " <<bdd.lastError();

       }
       else {
           qDebug()<<"acces bd";
       }
}

float InterfaceAccesBDBanque::ObtenirSolde(int numCompte)
{
    float solde =-1;
       QSqlQuery requete;

       requete.prepare("select solde from comptes where idCompte =:numCompte;");
       requete.bindValue(":numCompte",numCompte);
       qDebug()<<"numero de compte : "<<numCompte;
       if(!requete.exec()){

           qDebug()<<"pb requete ObtenirSolde"<<requete.lastError();
       }
       else {
           qDebug()<<"requete ObtenirSolde ok";
           while(requete.next()){

               solde=requete.value("solde").toFloat();

           }
       }

       return solde;
}

void InterfaceAccesBDBanque::MettreAJourLeSolde(int numCompte, float nouveauSolde)
{
    QSqlQuery requete;
       qDebug() << "numCompte : " << numCompte << "nouveauSolde : " << nouveauSolde;
       requete.prepare("UPDATE comptes SET solde = :nouveauSolde where idCompte = numCompte;");
       requete.bindValue(":nouveauSolde",nouveauSolde);
       requete.bindValue(":numCompte",numCompte);
       if(!requete.exec()){

           qDebug()<<"probleme requete "<<requete.lastError();

       }
       else {
           qDebug()<<"probleme requete";
       }
}

void InterfaceAccesBDBanque::CreerCompte(int numCompte)
{
    if (!(CompteExiste(numCompte))){
            QSqlQuery requete;
            requete.prepare("INSERT INTO comptes (idCompte) VALUES (:numCompte);");
            requete.bindValue(":numCompte",numCompte);
            qDebug()<<"COMPTE CREER";
            if(!requete.exec()){

                qDebug()<<"pb requete"<<requete.lastError();
            }
        }
        else {
            qDebug()<<"compte deja existant";
    }
}

bool InterfaceAccesBDBanque::CompteExiste(int numCompte)
{
    QSqlQuery requete;
        bool existe=false;
        requete.prepare("select solde from comptes where idCompte=:id;");
        requete.bindValue(":id",numCompte);

        if (!requete.exec()){
            qDebug()<<"pb requete compte existe "<<requete.lastError();
        }
        // si le compte existe on passe existe a vrai
        if (requete.size()!=0)
        {
            existe=true;
        }
        return existe;
}

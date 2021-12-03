#include "banquemainwindow.h"
#include "ui_banquemainwindow.h"

BanqueMainWindow::BanqueMainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::BanqueMainWindow)
{
    ui->setupUi(this);
    leServeur=new ServeurBanque();
    leServeur->Start();
}

BanqueMainWindow::~BanqueMainWindow()
{
    leServeur->Stop();
    delete ui;
}


void BanqueMainWindow::on_pushButton_clicked()
{
    // ajouter une ligne au tableau
      ui->tableWidgetInfos->insertRow(ui->tableWidgetInfos->rowCount());
      int ligne=0;    // numero de la ligne
      int col=0;      // numero de la colonne
      // ajouter un nom
      QTableWidgetItem *nomItem = new QTableWidgetItem("bidochon");
      ui->tableWidgetInfos->setItem(ligne,col,nomItem);
      col++;
      // ajouter un prenom
      QTableWidgetItem *prenomItem = new QTableWidgetItem("robert");
      ui->tableWidgetInfos->setItem(ligne,col,prenomItem);
      col++;
      // ajouter le numero de compte
      QTableWidgetItem *idCompteItem = new QTableWidgetItem(QString::number(1234));
      ui->tableWidgetInfos->setItem(ligne,col,idCompteItem);
      col++;
      // ajouter le solde
      QTableWidgetItem *soldeItem = new QTableWidgetItem(QString::number(518.68));
      ui->tableWidgetInfos->setItem(ligne,col,soldeItem);
}

void BanqueMainWindow::on_pushButtonConnexion_clicked()
{
    QSqlDatabase bd;
    bd = QSqlDatabase::addDatabase("QMYSQL");
       bd.setHostName(ui->lineEditIP->text());
       bd.setDatabaseName(ui->lineEditDB->text());
       bd.setUserName(ui->lineEditLogin->text());
       bd.setPassword(ui->lineEditLogin->text());
       if(!bd.open()){
           qDebug()<<"pb access " <<bd.lastError();

       }
       else {
           qDebug()<<"acces bd";
       }
}

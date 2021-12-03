#ifndef BANQUEMAINWINDOW_H
#define BANQUEMAINWINDOW_H

#include <QMainWindow>
#include <QList>
#include <serveurbanque.h>
#include <QTableWidget>
//test
QT_BEGIN_NAMESPACE
namespace Ui { class BanqueMainWindow; }
QT_END_NAMESPACE

class BanqueMainWindow : public QMainWindow
{
    Q_OBJECT

public:
    BanqueMainWindow(QWidget *parent = nullptr);
    ~BanqueMainWindow();

private slots:

    void on_pushButton_clicked();

    void on_pushButtonConnexion_clicked();

private:
    Ui::BanqueMainWindow *ui;
    ServeurBanque *leServeur;
};
#endif // BANQUEMAINWINDOW_H

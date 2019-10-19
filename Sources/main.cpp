#include "mainwindow.h"
#include <QApplication>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QDebug>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
/*
    QSqlDatabase db = QSqlDatabase::addDatabase("QODBC3");
    //db.setDatabaseName("DRIVER={SQL Server};Server=ITPL_PC1;Database=Test;Uid=sa;Port=1433;Pwd=*******;WSID=.");
    db.setDatabaseName("DRIVER={SQL Server Native Client 11.0};SERVER=localhost\\SQL2016DEV;DATABASE=SSRH_MONO;UID=user;PWD=userPwd;WSID=.;Trusted_connection=yes");
    db.open();
    QSqlQuery query;
    query.exec("SELECT * FROM UTILISAT");
    while (query.next())
    {
        QString trigramme = query.value(0).toString();
        QString name = query.value(1).toString();
        qDebug() << name << trigramme;
    }
    db.close();*/

    MainWindow w;
    w.show();

    return a.exec();
}

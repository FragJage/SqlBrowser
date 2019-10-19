#ifndef CONNECTIONTILE_H
#define CONNECTIONTILE_H

#include <QFrame>
#include <QLabel>
#include <QPushButton>
#include "connectionparameters.h"

class ConnectionTile : public QFrame
{
    Q_OBJECT

    public:
        ConnectionTile();
        ConnectionTile(ConnectionParameters* cnx);

    private slots:
        void openConnection();
        void modifyConnection();
        void newConnection();

    signals:
        void clickOpen(ConnectionParameters* cnx);
        void clickModify(ConnectionParameters* cnx);
        void clickNew();

    private:
        void commonProperties();
        QPushButton* createBottomButton(QString text);
        QLabel* m_Title;
        QLabel* m_LineOne;
        QLabel* m_LineTwo;
        ConnectionParameters* m_Cnx;
};

#endif // CONNECTIONTILE_H

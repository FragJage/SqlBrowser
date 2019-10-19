#ifndef CONNECTIONEDITOR_H
#define CONNECTIONEDITOR_H

#include "uibase/windowbase.h"
#include "uibase/qvlineedit.h"
#include "uibase/colorbutton.h"
#include "connectionparameters.h"
#include "connectiontile.h"

class ConnectionEditor : public WindowBase
{
    Q_OBJECT

    public:
        ConnectionEditor(QWidget* parent = nullptr);
        bool isNewConnection(ConnectionParameters* cnx);

    public slots:
        void addConnection();
        void modifyConnection(ConnectionParameters* cnx);

    private slots:
        void save();
        void remove();

    signals:
        void updateConnections(ConnectionParameters* cnx);
        void removeConnection(ConnectionParameters* cnx);

    private:
        ColorButton* m_BtnRemove;
        QVLineEdit* m_EditName;
        QVLineEdit* m_EditServer;
        QVLineEdit* m_EditUser;
        QVLineEdit* m_EditPass;
        ConnectionParameters* m_Cnx;
        ConnectionParameters m_NewCnx;
};

#endif // CONNECTIONEDITOR_H

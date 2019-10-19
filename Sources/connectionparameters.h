#ifndef CONNECTIONPARAMETERS_H
#define CONNECTIONPARAMETERS_H

#include <QObject>
#include <QString>
#include "simplecrypt.h"

class ConnectionParameters
{
    public:
        ConnectionParameters();
        ConnectionParameters(ConnectionParameters* cnx);
        ConnectionParameters(QString id, QString name, QString driver, QString server, QString database, QString user, QString encryptedPassword, QString customParameters);
        virtual ~ConnectionParameters();

        QString id() const;

        QString name() const;
        void setName(QString name);

        QString driver() const;
        void setDriver(QString driver);

        QString server() const;
        void setServer(QString server);

        QString database() const;
        void setDatabase(QString database);

        QString user() const;
        void setUser(QString user);

        QString encryptedPassword() const;
        void setEncryptedPassword(QString password);
        void setPassword(QString password);

        QString customParameters() const;
        void setCustomParameters(QString customParameters);

        void clear();
        QString getConnectionString();

    private:
        QString m_Id;
        QString m_Name;
        QString m_Driver;
        QString m_Server;
        QString m_Database;
        QString m_User;
        QString m_Password;
        QString m_CustomParameters;
        SimpleCrypt crypto;
};

#endif // CONNECTIONPARAMETERS_H

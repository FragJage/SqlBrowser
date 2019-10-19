#include "connectionparameters.h"

ConnectionParameters::ConnectionParameters()
{
    crypto.setKey(0x0d39c5b5bba8e132);
}

ConnectionParameters::~ConnectionParameters()
{
}

ConnectionParameters::ConnectionParameters(QString id, QString name, QString driver, QString server, QString database, QString user, QString encryptedPassword, QString customParameters) : ConnectionParameters()
{
    m_Id = id;
    m_Name = name;
    m_Driver = driver;
    m_Server = server;
    m_Database = database;
    m_User = user;
    m_Password = encryptedPassword;
    m_CustomParameters = customParameters;
}

ConnectionParameters::ConnectionParameters(ConnectionParameters* cnx) : ConnectionParameters()
{
    m_Name = cnx->name();
    m_Driver = cnx->driver();
    m_Server = cnx->server();
    m_Database = cnx->database();
    m_User = cnx->user();
    m_Password = cnx->encryptedPassword();
    m_CustomParameters = cnx->customParameters();
}

QString ConnectionParameters::id() const
{
    return m_Id;
}

QString ConnectionParameters::name() const
{
    return m_Name;
}

void ConnectionParameters::setName(QString name)
{
    m_Name = name;
}

QString ConnectionParameters::driver() const
{
    return m_Driver;
}

void ConnectionParameters::setDriver(QString driver)
{
    m_Driver = driver;
}

QString ConnectionParameters::server() const
{
    return m_Server;
}

void ConnectionParameters::setServer(QString server)
{
    m_Server = server;
}

QString ConnectionParameters::database() const
{
    return m_Database;
}

void ConnectionParameters::setDatabase(QString database)
{
    m_Database = database;
}

QString ConnectionParameters::user() const
{
    return m_User;
}

void ConnectionParameters::setUser(QString user)
{
    m_User = user;
}

QString ConnectionParameters::encryptedPassword() const
{
    return m_Password;
}

void ConnectionParameters::setEncryptedPassword(QString password)
{
    m_Password = password;
}

void ConnectionParameters::setPassword(QString password)
{
    m_Password = crypto.encryptToString(password);
}

QString ConnectionParameters::customParameters() const
{
    return m_CustomParameters;
}

void ConnectionParameters::setCustomParameters(QString customParameters)
{
    m_CustomParameters = customParameters;
}

void ConnectionParameters::clear()
{
    m_Id = "";
    m_Name = "";
    m_Driver = "";
    m_Server = "";
    m_Database = "";
    m_User = "";
    m_Password = "";
    m_CustomParameters = "";
}

QString ConnectionParameters::getConnectionString()
{
    QString cnx = QString("DRIVER={%1};SERVER=%2;DATABASE=%3;UID=%4;PWD=%5").arg(m_Driver, m_Server, m_Database, m_User, crypto.decryptToString(m_Password));
    if(m_CustomParameters!="") cnx += ";"+m_CustomParameters;
    return cnx;
}

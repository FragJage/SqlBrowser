#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>

using namespace std;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    m_Settings("FragJage", "SqlBrowser", parent)
{
    ui->setupUi(this);
    readSettings();

    m_ConnectionEditor = new ConnectionEditor();
    QObject::connect(m_ConnectionEditor, &ConnectionEditor::updateConnections, this, &MainWindow::updateConnections);
    QObject::connect(m_ConnectionEditor, &ConnectionEditor::removeConnection, this, &MainWindow::removeConnection);

    m_CnxLayout = new FlowLayout();
    displayConnectionTile();

    QWidget *window = new QWidget();
    window->setStyleSheet("background-color:white;");
    window->setLayout(m_CnxLayout);
    setCentralWidget(window);
    setWindowTitle(tr("SqlBrowser"));
    resize(800, 600);
}

void MainWindow::closeEvent(QCloseEvent *event)
{
    writeSettings();
    event->accept();
}

MainWindow::~MainWindow()
{
    list<ConnectionParameters*>::iterator it = m_ListCnx.begin();
    list<ConnectionParameters*>::iterator itEnd = m_ListCnx.end();
    while(it != itEnd)
    {
        delete *it;
        ++it;
    }
    m_ListCnx.clear();
    delete ui;
}

void MainWindow::displayConnectionTile()
{
    QLayoutItem *child;
    while ((child = m_CnxLayout->takeAt(0)) != nullptr)
    {
        //QObject::disconnect(child);
        m_CnxLayout->removeItem(child);
        delete child;
    }
    qDebug() << "Count Av : " << m_CnxLayout->count();

    list<ConnectionParameters*>::iterator it = m_ListCnx.begin();
    list<ConnectionParameters*>::iterator itEnd = m_ListCnx.end();
    while(it != itEnd)
    {
        qDebug() << "Add : " << (*it)->name();
        ConnectionTile* tmp = new ConnectionTile(*it);
        QObject::connect(tmp, &ConnectionTile::clickModify, m_ConnectionEditor, &ConnectionEditor::modifyConnection);
        m_CnxLayout->addWidget(tmp);
        ++it;
    }

    qDebug() << "Count Ap : " << m_CnxLayout->count();
    m_AddConnectionTile = new ConnectionTile();
    QObject::connect(m_AddConnectionTile, &ConnectionTile::clickNew, m_ConnectionEditor, &ConnectionEditor::addConnection);
    m_CnxLayout->addWidget(m_AddConnectionTile);
}

void MainWindow::updateConnections(ConnectionParameters* cnx)
{
    if(m_ConnectionEditor->isNewConnection(cnx))
    {
        ConnectionParameters* tmp = new ConnectionParameters(cnx);
        m_ListCnx.push_back(tmp);
    }
    displayConnectionTile();
}

void MainWindow::removeConnection(ConnectionParameters* cnx)
{
    m_ListCnx.remove(cnx);
    delete cnx;
    displayConnectionTile();
}

void MainWindow::readSettings()
{
    int size = m_Settings.beginReadArray("Connections");
    for (int i = 0; i < size; ++i)
    {
        m_Settings.setArrayIndex(i);
        m_ListCnx.push_back(new ConnectionParameters(
                                "#ID"+QString::number(i),
                                m_Settings.value("Name").toString(),
                                m_Settings.value("Driver").toString(),
                                m_Settings.value("Server").toString(),
                                m_Settings.value("Database").toString(),
                                m_Settings.value("User").toString(),
                                m_Settings.value("Password").toString(),
                                m_Settings.value("CustomParameters").toString()));
    }
    m_Settings.endArray();
}

void MainWindow::writeSettings()
{
    int i = 0;
    m_Settings.beginWriteArray("Connections");
    list<ConnectionParameters*>::iterator it = m_ListCnx.begin();
    list<ConnectionParameters*>::iterator itEnd = m_ListCnx.end();
    while(it != itEnd)
    {
        m_Settings.setArrayIndex(i);
        m_Settings.setValue("Name", (*it)->name());
        m_Settings.setValue("Driver", (*it)->driver());
        m_Settings.setValue("Server", (*it)->server());
        m_Settings.setValue("Database", (*it)->database());
        m_Settings.setValue("User", (*it)->user());
        m_Settings.setValue("Password", (*it)->encryptedPassword());
        m_Settings.setValue("CustomParameters", (*it)->customParameters());
        ++it;
        ++i;
    }
    m_Settings.endArray();
}

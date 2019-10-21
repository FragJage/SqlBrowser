#include <QVBoxLayout>
#include <QHBoxLayout>
#include "uibase/dropdownlist.h"
#include "connectioneditor.h"

ConnectionEditor::ConnectionEditor(QWidget *parent) : WindowBase("Server information", parent)
{
    m_EditName = new QVLineEdit("Name", "Display name");
    m_EditServer = new QVLineEdit("Server", "Host and instance");
    m_EditUser = new QVLineEdit("User", "User");
    m_EditPass = new QVLineEdit("Password", "Password");

    ColorButton* buttonCancel = new ColorButton("Cancel", "777", "#AAA", L"\xF05E");
    ColorButton* buttonSave = new ColorButton("Save", "#FFF", "#2B4", L"\xF0C7");
    ColorButton* buttonTest = new ColorButton("Test", "#FFF", "#8BD", L"\xF1E6");
    m_BtnRemove = new ColorButton("Remove", "#FFF", "#E33", L"\xF1F8");
    m_BtnDuplicate = new ColorButton("Duplicate", "#FFF", "#8BD", L"\xF0C5");

    DropdownList* comboType = new DropdownList(this);
    comboType->addItem("Sql Server");
    comboType->addItem("MySql");
    comboType->addItem("Sqlite");

    QHBoxLayout* hlayout1 = new QHBoxLayout;
    hlayout1->addWidget(m_EditUser);
    hlayout1->addWidget(m_EditPass);

    QVBoxLayout* layout = new QVBoxLayout;
    layout->addWidget(comboType);
    layout->addWidget(m_EditName);
    layout->addWidget(m_EditServer);
    layout->addLayout(hlayout1);

    setCentralLayout(layout);
    addBottomLeft(buttonTest);
    addBottomRight(m_BtnDuplicate);
    addBottomRight(m_BtnRemove);
    addBottomRight(buttonCancel);
    addBottomRight(buttonSave);

    QObject::connect(buttonCancel, &ColorButton::clicked, this, &ConnectionEditor::close);
    QObject::connect(buttonSave, &ColorButton::clicked, this, &ConnectionEditor::save);
    QObject::connect(m_BtnRemove, &ColorButton::clicked, this, &ConnectionEditor::remove);

    m_Cnx = nullptr;
}

bool ConnectionEditor::isNewConnection(ConnectionParameters* cnx)
{
    return (cnx==&m_NewCnx);
}

void ConnectionEditor::modifyConnection(ConnectionParameters* cnx)
{
    m_Cnx = cnx;
    m_EditName->setText(cnx->name());
    m_EditServer->setText(cnx->server());
    m_EditUser->setText(cnx->user());
    m_BtnRemove->show();
    m_BtnDuplicate->show();
    show();
}

void ConnectionEditor::addConnection()
{
    m_NewCnx.clear();
    m_Cnx = &m_NewCnx;
    m_EditName->setText("");
    m_EditServer->setText("");
    m_EditUser->setText("");
    m_BtnRemove->hide();
    m_BtnDuplicate->hide();
    show();
}

void ConnectionEditor::save()
{
    m_Cnx->setName(m_EditName->text());
    m_Cnx->setServer(m_EditServer->text());
    m_Cnx->setUser(m_EditUser->text());
    m_Cnx->setPassword(m_EditPass->text());
    emit updateConnections(m_Cnx);
    close();
}

void ConnectionEditor::remove()
{
    emit removeConnection(m_Cnx);
    close();
}

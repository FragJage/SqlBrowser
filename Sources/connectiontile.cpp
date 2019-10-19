#include "connectiontile.h"
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLabel>
#include <QDebug>
#include "uibase/fontawesome.h"

ConnectionTile::ConnectionTile() : QFrame()
{
    commonProperties();
    m_Cnx = nullptr;

    QPushButton* icoButton = new QPushButton(this);
    icoButton->setStyleSheet("QPushButton {border: none;}");
    icoButton->setFixedSize(226,96);
    icoButton->setIcon(QIcon(":/images/serveradd"));
    icoButton->setIconSize(QSize(65, 65));
    icoButton->setCursor(Qt::PointingHandCursor);

    QPushButton* txtButton = createBottomButton("New connection");
    QVBoxLayout *vLayout = new QVBoxLayout();
    vLayout->setMargin(0);
    vLayout->addWidget(icoButton);
    vLayout->addWidget(txtButton);
    setLayout(vLayout);

    QObject::connect(icoButton, SIGNAL(clicked()), this, SLOT(newConnection()));
    QObject::connect(txtButton, SIGNAL(clicked()), this, SLOT(newConnection()));
}

ConnectionTile::ConnectionTile(ConnectionParameters* cnx) : QFrame()
{
    commonProperties();
    m_Cnx = cnx;

    QPushButton* modifyButton = new QPushButton();
    modifyButton->setFont(FontAwesome::getFont(8));
    modifyButton->setText(QString::fromWCharArray(L"\xF304"));
    modifyButton->setFixedSize(30,30);
    modifyButton->setStyleSheet("QPushButton {border: 1px solid #DDD; border-radius: 15px; background-color: #DDD; color: #777;} QPushButton:hover {background-color: #AAA; border-color: #AAA} QPushButton:before { content: '»'; margin-right: 6px;}");
    modifyButton->setCursor(Qt::PointingHandCursor);

    QPushButton* connectButton = createBottomButton(QString::fromWCharArray(L"\xF1E6")+" Connect");

    QPixmap logo(":/images/sqlserverlogo");
    QLabel* image = new QLabel();
    image->setFixedSize(40,30);
    image->setPixmap(logo.scaledToWidth(40, Qt::SmoothTransformation));

    m_Title = new QLabel(cnx->name());
    m_Title->setStyleSheet("font-size: 18px; color: #111;");
    m_LineOne = new QLabel(cnx->server());
    m_LineOne->setStyleSheet("font-size: 14px; color: #888;");
    m_LineTwo = new QLabel(cnx->database());
    m_LineTwo->setStyleSheet("font-size: 14px; color: #888;");

    QVBoxLayout *descLayout = new QVBoxLayout();
    descLayout->setMargin(0);
    descLayout->setSpacing(0);
    descLayout->addSpacing(3);
    descLayout->addWidget(m_Title);
    descLayout->addSpacing(5);
    descLayout->addWidget(m_LineOne);
    descLayout->addWidget(m_LineTwo);

    QHBoxLayout *hLayout = new QHBoxLayout();
    hLayout->setAlignment(Qt::AlignTop);
    hLayout->addSpacing(8);
    hLayout->addWidget(image);
    hLayout->addLayout(descLayout);
    hLayout->addWidget(modifyButton);
    hLayout->addSpacing(8);

    QVBoxLayout *vLayout = new QVBoxLayout();
    vLayout->setMargin(0);
    vLayout->addLayout(hLayout);
    vLayout->addWidget(connectButton);
    setLayout(vLayout);

    QObject::connect(modifyButton, SIGNAL(clicked()), this, SLOT(modifyConnection()));
    QObject::connect(connectButton, SIGNAL(clicked()), this, SLOT(openConnection()));
}

void ConnectionTile::commonProperties()
{
    setFixedSize(230,130);
    setProperty("Tile", true);
    setStyleSheet("*[Tile='true'] {border: 1px solid #DDD; border-radius: 5px;}");
}

QPushButton* ConnectionTile::createBottomButton(QString text)
{
    QPushButton* button = new QPushButton();
    button->setFixedSize(230,40);
    button->setStyleSheet("QPushButton {border: 1px solid #DDD; border-bottom-left-radius: 5px; border-bottom-right-radius: 5px; background-color: #DDD; color: #777; font-size: 14px} QPushButton:hover {background-color: #AAA; border-color: #AAA}");
    button->setFont(FontAwesome::getFont(8));
    button->setText(text);
    button->setCursor(Qt::PointingHandCursor);
    return button;
}

void ConnectionTile::newConnection()
{
    emit clickNew();
}

void ConnectionTile::modifyConnection()
{
    emit clickModify(m_Cnx);
}

void ConnectionTile::openConnection()
{
    emit clickOpen(m_Cnx);
}

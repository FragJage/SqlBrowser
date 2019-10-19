#include <QFrame>
#include "windowbase.h"

WindowBase::WindowBase(QString title, QWidget *parent) : QWidget(parent)
{
    m_NbLeftWidget = 0;

    m_Title = new QLabel(title);
    m_Title->setStyleSheet("QLabel {background-color:#FCFCFC; padding:15px; font-size:22px;border-bottom: 1px solid #DDD;}");
    m_CentralLayout = new QWidget();
    m_BottomLayout = new QHBoxLayout();
    m_BottomLayout->setMargin(0);
    m_BottomLayout->addStretch();

    QFrame* frame = new QFrame();
    frame->setStyleSheet("QFrame {background-color:#F3F3F3; padding:10px; border-top: 1px solid #DDD;}");
    frame->setLayout(m_BottomLayout);

    m_MainLayout = new QVBoxLayout();
    m_MainLayout->setMargin(0);
    m_MainLayout->addWidget(m_Title);
    m_MainLayout->addWidget(m_CentralLayout);
    m_MainLayout->addStretch();
    m_MainLayout->addWidget(frame);

    //setWindowFlags(Qt::Window | Qt::FramelessWindowHint);
    setStyleSheet("background-color:#FFF");
    resize(600,400);
    setLayout(m_MainLayout);
}

void WindowBase::setCentralLayout(QLayout* layout)
{
    m_CentralLayout->setLayout(layout);
}

void WindowBase::addBottomLeft(QWidget *widget)
{
    m_BottomLayout->insertWidget(m_NbLeftWidget, widget);
    m_NbLeftWidget++;
}

void WindowBase::addBottomRight(QWidget *widget)
{
    m_BottomLayout->addWidget(widget);
}

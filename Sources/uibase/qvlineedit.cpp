#include "qvlineedit.h"
#include <QStyle>

QVLineEdit::QVLineEdit(QString title, QString placeholder, QWidget *parent) : QWidget(parent)
{
    m_Layout = new QVBoxLayout;
    m_Label = new QLabel(title);
    m_Label->setStyleSheet("font-size:12px; font-weight:bold; padding-top:5px;");
    m_LineEdit = new QLineEdit();
    m_LineEdit->setStyleSheet("QLineEdit{font-size:13px; padding:10px; border-radius:5px; border: 1px solid #DDD; color:#111} QLineEdit[text=\"\"]{ color:#AAA; } QLineEdit:focus { border-color:#8BD;}");
    m_LineEdit->setPlaceholderText(placeholder);
    connect(m_LineEdit, &QLineEdit::textChanged, [=]{ style()->polish(m_LineEdit); });

    m_Layout->setMargin(0);
    m_Layout->addWidget(m_Label);
    m_Layout->addWidget(m_LineEdit);
    setLayout(m_Layout);
}

void QVLineEdit::setText(QString text)
{
    m_LineEdit->setText(text);
}

QString QVLineEdit::text()
{
    return m_LineEdit->text();
}

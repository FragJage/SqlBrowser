#ifndef QVLINEEDIT_H
#define QVLINEEDIT_H

#include <QWidget>
#include <QString>
#include <QVBoxLayout>
#include <QLabel>
#include <QLineEdit>

class QVLineEdit : public QWidget
{
    Q_OBJECT

    public:
    explicit QVLineEdit(QString title, QString placeholder, QWidget *parent = nullptr);
    void setText(QString text);
    QString text();

    private:
    QVBoxLayout* m_Layout;
    QLabel* m_Label;
    QLineEdit* m_LineEdit;
};

#endif // QVLINEEDIT_H

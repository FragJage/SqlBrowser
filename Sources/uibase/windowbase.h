#ifndef WINDOWBASE_H
#define WINDOWBASE_H

#include <QWidget>
#include <QLabel>
#include <QVBoxLayout>
#include <QHBoxLayout>

class WindowBase : public QWidget
{
    Q_OBJECT

    public:
    WindowBase(QString title, QWidget *parent = nullptr);

    protected:
    void setCentralLayout(QLayout* layout);
    void addBottomLeft(QWidget *widget);
    void addBottomRight(QWidget *widget);

    private:
    int m_NbLeftWidget;
    QVBoxLayout* m_MainLayout;
    QLabel* m_Title;
    QWidget* m_CentralLayout;
    QHBoxLayout* m_BottomLayout;
};

#endif // WINDOWBASE_H

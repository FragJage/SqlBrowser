#ifndef COLORBUTTON_H
#define COLORBUTTON_H

#include <QWidget>
#include <QColor>
#include <QPushButton>

class ColorButton : public QPushButton
{
    public:
    ColorButton(QString text, QString textColor, QString backColor, const wchar_t* icone = nullptr, int width = 50, QWidget *parent = nullptr);
};

#endif // COLORBUTTON_H

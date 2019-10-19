#include "colorbutton.h"
#include "fontawesome.h"

ColorButton::ColorButton(QString text, QString textColor, QString backColor, const wchar_t* icone, int width, QWidget *parent) : QPushButton(text, parent)
{
    QColor color(backColor);
    setStyleSheet("QPushButton{padding:10px; color:"+textColor+"; background-color:"+backColor+"; border-radius:3px; min-width:"+QString::number(width)+"px} QPushButton:hover{background-color:"+color.darker(120).name()+";}");
    setFont(FontAwesome::getFont(10));
    if(icone!=nullptr) setText(QString::fromWCharArray(icone)+"  "+text);
    setCursor(Qt::PointingHandCursor);
}

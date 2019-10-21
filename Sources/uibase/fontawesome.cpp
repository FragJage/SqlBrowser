#include "fontawesome.h"

QString FontAwesome::m_FontName="";

QFont FontAwesome::getFont(int pointSize, int weight, bool italic)
{
    if(FontAwesome::m_FontName=="") FontAwesome::loadFont();
    QFont font(m_FontName, pointSize, weight, italic);
    return font;
}

void FontAwesome::loadFont()
{
    int id = QFontDatabase::addApplicationFont(":/fonts/fontawesome.ttf");
    m_FontName = (id == -1) ? "Arial" : QFontDatabase::applicationFontFamilies(id).at(0);
}

#ifndef FONTAWESOME_H
#define FONTAWESOME_H

#include <QFontDatabase>
#include <QFont>
#include <QString>

class FontAwesome
{
public:
    static QFont getFont(int pointSize = -1, int weight = -1, bool italic = false);
private:
    static void loadFont();
    static QString m_FontName;
};

#endif // FONTAWESOME_H

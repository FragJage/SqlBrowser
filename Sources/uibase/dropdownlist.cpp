#include "dropdownlist.h"

DropdownList::DropdownList(QWidget *parent) : QComboBox(parent)
{
    setStyleSheet("QComboBox{font-size:13px; padding:10px; border-radius:5px; border: 1px solid #DDD; color:#111} QComboBox:focus { border-color:#8BD;}");
    /*
    QComboBox::drop-down {
        subcontrol-origin: padding;
        subcontrol-position: top right;
        width: 15px;

        border-left-width: 1px;
        border-left-color: darkgray;
        border-left-style: solid; // just a single line
        border-top-right-radius: 3px; // same radius as the QComboBox
        border-bottom-right-radius: 3px;
    }

    QComboBox::down-arrow {
        image: url(/usr/share/icons/crystalsvg/16x16/actions/1downarrow.png);
    }

    QComboBox::down-arrow:on { // shift the arrow when popup is open
        top: 1px;
        left: 1px;
    }
    */
}

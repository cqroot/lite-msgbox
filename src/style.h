#ifndef LITE_MSGBOX_STYLE_H
#define LITE_MSGBOX_STYLE_H

#include <QString>

QString DefaultStyle()
{
    return "QDialog {"
           "  background-color: #282A36;"
           "  border: 3px solid #1E1F29;"
           "}"
           ""
           "QLabel#TitleLabel {"
           "  background-color: #1E1F29;"
           "  color: #F8F8F3;"
           "  font-size: 16px;"
           "  padding: 5px;"
           "}"
           ""
           "QLabel#MessageLabel {"
           "  color: #F8F8F3;"
           "  font-size: 20px;"
           "}"
           ""
           "QPushButton {"
           "  color: #F8F8F3;"
           "  background-color: #282A36;"
           "  border: 2px solid #1E1F29;"
           "  border-radius: 0;"
           "  margin: 10px;"
           "}"
           ""
           "QPushButton:hover {"
           "  border: 1px solid #F8F8F3;"
           "}"
           ""
           "QPushButton:pressed,"
           "QPushButton:checked {"
           "  background-color: #6272A4;"
           "}"
           ""
           "/*"
           " * vim:ft=css"
           " */";
}

#endif // LITE_MSGBOX_STYLE_H


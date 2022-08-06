#ifndef LITE_MSGBOX_STYLE_H
#define LITE_MSGBOX_STYLE_H

#include <QString>

QString DefaultStyle()
{
    return "QDialog {"
           "  background-color: #282a36;"
           "  border: 2px solid #1e1f29;"
           "}"
           ""
           "QLabel#MessageLabel {"
           "  color: #f8f8f3;"
           "  font-size: 20px;"
           "}"
           ""
           "QPushButton {"
           "  color: #f8f8f3;"
           "  background-color: #282a36;"
           "  border: 1px solid #1e1f29;"
           "  padding: 10px;"
           "  border-radius: 0;"
           ""
           "  width: 80px;"
           "}"
           ""
           "QPushButton:hover {"
           "  border: 1px solid #f8f8f3;"
           "}"
           ""
           "QPushButton:pressed,"
           "QPushButton:checked {"
           "  background-color: #6272a4;"
           "}"
           ""
           "/*"
           " * vim:ft=css"
           " */";
}

#endif // LITE_MSGBOX_STYLE_H

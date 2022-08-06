#include "src/maindialog.h"

#include <QApplication>
#include <QFile>
#include <QString>
#include <string>

#include "third-party/cmdline/cmdline.h"

#include <src/style.h>

QString CleanString(QString str)
{
    if (str.at(0) == '\'' || str.at(0) == '"')
        str.remove(0, 1);

    int strLen = str.length();
    if (str.at(strLen - 1) == '\'' || str.at(strLen - 1) == '"')
        str.remove(strLen - 1, 1);

    return str;
}

void InitFlags(cmdline::parser& cp)
{
    cp.add<std::string>("message", 'm', "message", true, "");
    cp.add<int>("width", 'w', "width", false, 300);
    cp.add<int>("height", 'h', "height", false, 150);
    cp.add<std::string>("qss", 's', "qt style sheets file", false, "");
    cp.add<int>("timeout", 't', "timeout(s)", false, 60);
    cp.add<std::string>("buttons",
                        'b',
                        "a json string describing the button group",
                        false,
                        "cancel:0");
}

int main(int argc, char* argv[])
{
    cmdline::parser cp;
    InitFlags(cp);
    cp.parse_check(argc, argv);

    QApplication app(argc, argv);

    app.setStyleSheet(DefaultStyle());
    if (cp.exist("qss")) {
        QFile qssFile(QString::fromStdString(cp.get<std::string>("qss")));
        qssFile.open(QFile::ReadOnly);
        QString styleSheet = QLatin1String(qssFile.readAll());

        app.setStyleSheet(styleSheet);
    };

    MainDialog d(
      CleanString(QString::fromStdString(cp.get<std::string>("message"))),
      cp.get<int>("width"),
      cp.get<int>("height"));

    QString buttonStr =
      CleanString(QString::fromStdString(cp.get<std::string>("buttons")));

    QStringList buttonList = buttonStr.split(';');
    for (QString buttonInfo : buttonList) {
        if (!buttonInfo.contains(':')) {
            continue;
        }
        QStringList buttonInfoList = buttonInfo.split(':');
        if (buttonInfoList.length() == 2) {
            d.addButton(buttonInfoList[0], buttonInfoList[1].toInt());
        }
    }

    if (cp.exist("timeout")) {
        d.setTimeout(cp.get<int>("timeout"));
    }

    int res = d.exec();

    return res;
}

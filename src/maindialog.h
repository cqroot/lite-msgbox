#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QDialog>
#include <QHBoxLayout>
#include <QLabel>

class MainDialog : public QDialog
{
    Q_OBJECT

public:
    MainDialog(QString message,
               int width,
               int height,
               QWidget* parent = nullptr);

    ~MainDialog();

    void setTimeout(int timeout);
    void setTitle(QString title);
    void addButton(QString text, int code);

protected:
    void mouseMoveEvent(QMouseEvent* event);
    void mousePressEvent(QMouseEvent* event);
    void mouseReleaseEvent(QMouseEvent* event);

private:
    // ui components
    QLabel* titleLabel;
    QLabel* messageLabel;
    QHBoxLayout* buttonLayout;

    QString _message;
    int _width;
    int _height;

    bool mMoving = false;
    QPoint mLastMousePosition;

    void setupComponents();
};

#endif // MAINWINDOW_H

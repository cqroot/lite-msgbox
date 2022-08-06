#include "maindialog.h"

#include <QDialog>
#include <QMouseEvent>
#include <QPushButton>
#include <QSize>
#include <QTimer>

MainDialog::MainDialog(QString message, int width, int height, QWidget* parent)
  : QDialog(parent)
  , _message(message)
  , _width(width)
  , _height(height)
{
    setupUi();
}

MainDialog::~MainDialog() {}

void MainDialog::setupUi()
{
    messageLabel = new QLabel(_message);
    messageLabel->setObjectName("MessageLabel");
    messageLabel->setAlignment(Qt::AlignCenter);

    buttonLayout = new QHBoxLayout();
    buttonLayout->addSpacerItem(
      new QSpacerItem(1, 1, QSizePolicy::Expanding, QSizePolicy::Fixed));

    QVBoxLayout* mainLayout = new QVBoxLayout();
    mainLayout->addWidget(messageLabel);
    mainLayout->addLayout(buttonLayout);

    setLayout(mainLayout);

    setFixedSize(_width, _height);
    setWindowFlags(windowFlags() | Qt::FramelessWindowHint);
}

void MainDialog::setTimeout(int timeout)
{
    QTimer::singleShot(timeout * 1000, this, [this] { done(0); });
}

void MainDialog::addButton(QString text, int code)
{
    QPushButton* button = new QPushButton(text);
    QObject::connect(
      button, &QPushButton::clicked, this, [this, code] { done(code); });
    buttonLayout->addWidget(button);
}

void MainDialog::mousePressEvent(QMouseEvent* event)
{
    if (event->button() == Qt::LeftButton) {
        mMoving = true;
        mLastMousePosition = event->pos();
    }
}

void MainDialog::mouseMoveEvent(QMouseEvent* event)
{
    if (event->buttons().testFlag(Qt::LeftButton) && mMoving) {
        this->move(this->pos() + (event->pos() - mLastMousePosition));
    }
}

void MainDialog::mouseReleaseEvent(QMouseEvent* event)
{
    if (event->button() == Qt::LeftButton) {
        mMoving = false;
    }
}

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
    setupComponents();

    setFixedSize(_width, _height);
    setWindowFlags(windowFlags() | Qt::FramelessWindowHint |
                   Qt::WindowStaysOnTopHint | Qt::X11BypassWindowManagerHint);
}

MainDialog::~MainDialog() {}

void MainDialog::setTimeout(int timeout)
{
    QTimer::singleShot(timeout * 1000, this, [this] { done(0); });
}

void MainDialog::setTitle(QString title)
{
    titleLabel->setVisible(true);
    titleLabel->setText(title);
}

void MainDialog::addButton(QString text, int code)
{
    QPushButton* button = new QPushButton(text);
    QObject::connect(
      button, &QPushButton::clicked, this, [this, code] { done(code); });
    button->setFixedSize(QSize(80, 60));
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
void MainDialog::setupComponents()
{
    // title
    titleLabel = new QLabel();
    titleLabel->setObjectName("TitleLabel");
    titleLabel->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
    titleLabel->setVisible(false);

    // message
    messageLabel = new QLabel(_message);
    messageLabel->setObjectName("MessageLabel");
    messageLabel->setAlignment(Qt::AlignCenter);

    // button
    buttonLayout = new QHBoxLayout();
    buttonLayout->addSpacerItem(
      new QSpacerItem(1, 1, QSizePolicy::Expanding, QSizePolicy::Fixed));

    // main
    QVBoxLayout* mainLayout = new QVBoxLayout();
    mainLayout->setContentsMargins(0, 0, 0, 0);

    mainLayout->addWidget(titleLabel);
    mainLayout->addWidget(messageLabel);
    mainLayout->addLayout(buttonLayout);

    setLayout(mainLayout);
}

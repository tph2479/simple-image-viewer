#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QKeyEvent>
#include <QTimer>
#include <qtimer.h>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
  QTimer::singleShot(1000, this, &MainWindow::uptime);
  ui->setupUi(this);
  shall_quit = false;
}

MainWindow::~MainWindow() { delete ui; }

void MainWindow::keyPressEvent(QKeyEvent *event) {
  switch (event->key()) {
  case Qt::Key_Q:
    ui->label->setText("Press Q again to quit\nAny other key to cancel");
    if (shall_quit) {
      close();
    }
    shall_quit = true;
    QTimer::singleShot(3000, this, &MainWindow::resetAppState);
    break;
  default:
    resetAppState();
    QMainWindow::keyPressEvent(event);
  }
}

void MainWindow::resetAppState() {
  shall_quit = false;
  ui->label->setText("Hello");
}

void MainWindow::uptime() {
  static int seconds = 1;
  ui->status_bar->showMessage(QString("_%1_").arg(seconds));
  seconds++;
  QTimer::singleShot(1000, this, &MainWindow::uptime);
}
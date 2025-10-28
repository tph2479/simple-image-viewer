#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QMouseEvent>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    shall_quit = false;
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::keyPressEvent(QKeyEvent *event)
{
    if (event->key() == Qt::Key_Q) {
        ui->label->setText("You pressed Q, time to quit?\n(Q to confirm or any other key to cancel)");
        if (shall_quit) {
            close();
        }
        shall_quit = true;
    } else {
        ui->label->setText("Hello");
        shall_quit = false;
        QMainWindow::keyPressEvent(event);
    }
}
#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->alertButton->connect(ui->alertButton, &QPushButton::clicked, this, &MainWindow::CreateAlert);
}

void MainWindow::CreateAlert() {
    QMessageBox::information(this, "Message", "Hello!");
}

MainWindow::~MainWindow()
{
    delete ui;
}

#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "codeinput.h"
#include <QLayout>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    CodeInput *codeInput = new CodeInput(this);
    codeInput->show();

    connect(ui->closeButton, &QPushButton::released, this, &MainWindow::closeWindow);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::closeWindow() {
    // (*count)++;

    // ui->label->setText("You pressed for " + QString::number(*count));

    this->close();
    // this->~MainWindow();
}
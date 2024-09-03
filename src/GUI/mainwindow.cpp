#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>
#include <QTextStream>
#include <QDebug>

#include "codeinput.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    CodeInput *codeInput = new CodeInput(this);
    codeInput->show();

    connect(ui->closeButton, &QPushButton::released, this, &MainWindow::closeWindow);
    //connect(ui->openButton, &QPushButton::clicked, this, &MainWindow::on_openButton_clicked);
    //connect(ui->saveButton, &QPushButton::clicked, this, &MainWindow::on_saveButton_clicked);
}

MainWindow::~MainWindow()
{
    delete ui;
    delete codeInput;
}

void MainWindow::closeWindow() {
    // (*count)++;

    // ui->label->setText("You pressed for " + QString::number(*count));

    this->close();
    // this->~MainWindow();
}

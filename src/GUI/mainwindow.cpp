#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>
#include <QTextStream>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    codeInput = new CodeInput(this);
    codeInput->show();

    connect(ui->closeButton, &QPushButton::released, this, &MainWindow::closeWindow);
    connect(ui->openButton, &QPushButton::clicked, this, &MainWindow::on_openButton_clicked);
    connect(ui->saveButton, &QPushButton::clicked, this, &MainWindow::on_saveButton_clicked);
}

MainWindow::~MainWindow()
{
    delete ui;
    delete codeInput;
}

void MainWindow::on_openButton_clicked()
{
    QString fileName = QFileDialog::getOpenFileName(this, "Открыть файл");
    if (!fileName.isEmpty()) {
        QFile file(fileName);
        if (file.open(QIODevice::ReadOnly | QIODevice::Text)) {
            QTextStream in(&file);
            QString text = in.readAll();
            if (codeInput != nullptr) {
                codeInput->setPlainText(text); // Используем setPlainText для замены содержимого
            } else {
                qDebug() << "codeInput is null!";
            }
            file.close();
        } else {
            qDebug() << "Failed to open file";
        }
    } else {
        qDebug() << "No file selected";
    }
}

void MainWindow::on_saveButton_clicked()
{
    qDebug() << "Saving file...";
    QString fileName = QFileDialog::getSaveFileName(this, "Сохранить файл");
    if (!fileName.isEmpty()) {
        qDebug() << "File selected:" << fileName;
        QFile file(fileName);
        if (file.open(QIODevice::WriteOnly | QIODevice::Text)) {
            qDebug() << "File opened successfully";
            QTextStream out(&file);
            out << codeInput->toPlainText();
            file.close();
            qDebug() << "File written and closed";
        } else {
            qDebug() << "Failed to open file";
        }
    } else {
        qDebug() << "No file selected";
    }
}

void MainWindow::closeWindow() {
    this->close();
}

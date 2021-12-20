#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setCentralWidget(ui->textEdit);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionNowy_triggered()
{
    QMainWindow *wdg = new MainWindow;
    wdg->show();
}

void MainWindow::on_actionOtworz_triggered()
{
    MainWindow *wdg = new MainWindow;
    QString fileName = QFileDialog::getOpenFileName(this, "Open file");
    QFile file(fileName);
    currentFile = fileName;
    if(!file.open(QIODevice::ReadOnly | QFile::Text)){
        QMessageBox::warning(this, "Warning", "Cannot open this file: " + file.errorString());
    }
    setWindowTitle(fileName);
    QTextStream in(&file);
    QString text = in.readAll();
    wdg->ui->textEdit->setText(text);
    wdg->show();
    file.close();
}

void MainWindow::on_actionZapisz_jako_triggered()
{
    QString fileName = QFileDialog::getSaveFileName(this, "Save as...");
    QFile file(fileName);
    if(!file.open(QFile::WriteOnly | QFile::Text)){
        QMessageBox::warning(this, "Warning", "Cannot save this file: " + file.errorString());
        return;
    }
    currentFile = fileName;
    setWindowTitle(fileName);
    QTextStream out(&file);
    QString text = ui->textEdit->toPlainText();
    out << text;
    file.close();
}

void MainWindow::on_actionWyjdz_triggered()
{
    QApplication::quit();
}

void MainWindow::on_actionKopiuj_triggered()
{
    ui->textEdit->copy();
}

void MainWindow::on_actionWklej_triggered()
{
    ui->textEdit->paste();
}

void MainWindow::on_actionWytnij_triggered()
{
    ui->textEdit->cut();
}

void MainWindow::on_actionCofnij_triggered()
{
    ui->textEdit->undo();
}

void MainWindow::on_actionPrzywroc_triggered()
{
    ui->textEdit->redo();
}

void MainWindow::on_actionPolicz_znaki_triggered()
{
    //int count = 0;
    QString text = ui->textEdit->toPlainText();
    int num = text.length();
    QString znaki = QString::number(num);
    statusBar()->showMessage("Number of characters: " + znaki);
}

void MainWindow::on_actionPolicz_wyrazy_triggered()
{
    QString text = ui->textEdit->toPlainText();
    int num = text.length();
    int words = 0;
    for(int i=0; i!=num; i++)
    {
        if(text[i]==' ')
        {
            words ++;
        }
    }
    QString slowa = QString::number(words+1);
    statusBar()->showMessage("Number of words: " + slowa);
}

void MainWindow::on_actionWyswietl_raport_triggered()
{
    QString text = ui->textEdit->toPlainText();
    int num = text.length();
    int words = 0;
    for(int i=0; i!=num; i++)
    {
        if(text[i]==' ')
        {
            words ++;
        }
    }
    QString znaki = QString::number(num);
    QString slowa = QString::number(words+1);
    QMessageBox msgBox;
    msgBox.setText("Current text include:");
    msgBox.setInformativeText("Number of characters: " + znaki + "\nNumber of words: " + slowa);
    msgBox.exec();
}

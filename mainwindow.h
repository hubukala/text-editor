#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include <QFile>
#include <QFileDialog>
#include <QTextStream>
#include <QMessagebox>
#include <QPrinter>
#include <QPrintDialog>
#include <QTabWidget>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_actionNowy_triggered();

    void on_actionOtworz_triggered();

    void on_actionZapisz_jako_triggered();

    void on_actionWyjdz_triggered();

    void on_actionCofnij_triggered();

    void on_actionWklej_triggered();

    void on_actionWytnij_triggered();

    void on_actionKopiuj_triggered();

    void on_actionPrzywroc_triggered();

    void on_actionPolicz_znaki_triggered();

    void on_actionPolicz_wyrazy_triggered();

    void on_actionWyswietl_raport_triggered();

private:
    Ui::MainWindow *ui;
    QString currentFile = "";
};

#endif // MAINWINDOW_H

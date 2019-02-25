#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDebug>
#include <QVector>
#include <QFileDialog>
#include <QMessageBox>
#include "salvar_arq.h"
#include "empregado.h"
#include "empresa.h"

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
private:
    Empresa tipo_de_empresa;

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
void atualizarAnaliseDeDados();

private slots:
    void salvar();
    void carregar();

 void on_btn_salvar_clicked();

 void on_btn_ordenar_clicked();


 void on_btn_ord_maior_clicked();

 void on_btn_remove_clicked();

private:
    Ui::MainWindow *ui;
    void inserirEmpregadoNaTabela(Empregado empregado, int row);
};

#endif // MAINWINDOW_H



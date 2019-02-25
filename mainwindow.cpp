#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->actionSalvar_em,SIGNAL(triggered()), this, SLOT(salvar()));
    connect(ui->actionAbrir_arquivo,SIGNAL(triggered()), this, SLOT(carregar()));
}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::atualizarAnaliseDeDados()
{
    ui->label_3->setText(QString::number(tipo_de_empresa.mediaDaEmpresa(),'f',2));
    ui->label_4->setText(QString(tipo_de_empresa.getEmpregado_do_mes()));
}

void MainWindow::inserirEmpregadoNaTabela(Empregado empregado, int row)
{
    ui->tableWidget->setItem(row,0,new QTableWidgetItem(empregado.getNome()));
    ui->tableWidget->setItem(row,1,new QTableWidgetItem(QString::number(empregado.getMeta())));
    ui->tableWidget->setItem(row,2,new QTableWidgetItem(QString::number(empregado.getPorcentagem())));
}


void MainWindow::on_btn_salvar_clicked()
{
    if(ui->lineEdit_2->text().size() != 0 && ui->lineEdit->text().size() != 0){
        Empregado empregado;
        empregado.setNome(ui->lineEdit_2->text());
        empregado.setMeta(ui->lineEdit->text().toFloat());

        int qnt_row = ui->tableWidget->rowCount();

        ui->tableWidget->insertRow(qnt_row);
        inserirEmpregadoNaTabela(empregado, qnt_row);

        ui->lineEdit_2->clear();
        ui->lineEdit->clear();

        tipo_de_empresa.inserirEmpregado(empregado);
        atualizarAnaliseDeDados();
    }
}

void MainWindow::on_btn_ordenar_clicked()
{
    ui->tableWidget->clearContents();
    tipo_de_empresa.ordenarPorMenorMeta();
    for(int i = 0; i<tipo_de_empresa.size();i++){
        inserirEmpregadoNaTabela(tipo_de_empresa[i],i);
    }
}


void MainWindow::on_btn_ord_maior_clicked()
{
    ui->tableWidget->clearContents();
    tipo_de_empresa.ordenarPorMaiorMeta();
    for(int i = 0; i<tipo_de_empresa.size();i++){
        inserirEmpregadoNaTabela(tipo_de_empresa[i],i);
    }
}

void MainWindow::salvar()
{

    QString nomeArquivo = QFileDialog::getSaveFileName(this,"Relacao de Empregados","","Texto Puro(*.txt);;Arquivos Separado por Vírgulas(*.csv)");
    if(salvar_arq::salvarEmpresa(nomeArquivo,tipo_de_empresa) ){
        QMessageBox::information(this, "Salvar Dados","Dados Salvos com Sucesso");
    }else{
        QMessageBox::information(this, "Salvar Dados","Não foi possível salvar os dados");
    }

}

void MainWindow::carregar()
{
    QString nomeArquivo = QFileDialog::getOpenFileName(this,"Relacao de Empregados","","Texto Puro(*.txt);;Arquivos Separado por Vírgulas(*.csv)");
    tipo_de_empresa.clear();

    if(salvar_arq::carregarEmpresa(nomeArquivo,tipo_de_empresa)){

        ui->tableWidget->clearContents();
        for(int i=0;i<tipo_de_empresa.size();i++){

            if(i >= ui->tableWidget->rowCount())
                ui->tableWidget->insertRow(i);

            inserirEmpregadoNaTabela(tipo_de_empresa[i],i);
        }

    }else{
        QMessageBox::information(this, "Abrir arquivo","Não foi possível carregar os dados");
    }

}

void MainWindow::on_btn_remove_clicked()
{
    int qnt_row = ui->tableWidget->rowCount();
    for(int i=0;i<qnt_row;i++){
    ui->tableWidget->removeRow(i);
    }
    atualizarAnaliseDeDados();
}

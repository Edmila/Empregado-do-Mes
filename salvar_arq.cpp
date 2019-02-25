#include "salvar_arq.h"

salvar_arq::salvar_arq()
{

}

bool salvar_arq::salvarEmpresa(QString &arquivo, Empresa &empresa)
{
    QFile file(arquivo);

    if(!file.open(QIODevice::WriteOnly)){
        return false;
    }

    QTextStream out(&file);

    for(int i=0;i<empresa.size();i++){
        out <<empresa[i].getNome()<<","<<empresa[i].getMeta()<<"\n";
    }

    file.close();
    return true;
}
bool salvar_arq::carregarEmpresa(QString &arquivo, Empresa &empresa)
{
    QFile file(arquivo);

    if(!file.open(QIODevice::ReadOnly)){
        return false;
    }

    QTextStream in(&file);

    QString linha;

    while(!in.atEnd()){
        linha = in.readLine();

        QStringList dados = linha.split(",");

        Empregado a(dados[0],dados[1].toFloat());
        empresa.inserirEmpregado(a);

    }
    return true;
}

#ifndef SALVAR_ARQ_H
#define SALVAR_ARQ_H
#include <QObject>
#include <QFile>
#include <QTextStream>
#include <fstream>
#include <QDebug>
#include "empregado.h"
#include "empresa.h"

class salvar_arq
{
public:
    salvar_arq();
    static bool salvarEmpresa(QString &arquivo, Empresa &empresa);
    static bool carregarEmpresa(QString &arquivo, Empresa &empresa);
};

#endif // SALVAR_ARQ_H

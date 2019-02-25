#ifndef EMPRESA_H
#define EMPRESA_H
#include <QObject>
#include <QVector>
#include <numeric>
#include <algorithm>
#include "empregado.h"


class Empresa : public QObject
{
    Q_OBJECT
private:
    QVector<Empregado>empresa;

public:
    //empresa();
    explicit Empresa(QObject *parent = nullptr);
    void inserirEmpregado(const Empregado a);
    float mediaDaEmpresa();
    float maiorMeta();
    float menorMeta();
    void ordenarPorMenorMeta();
    void ordenarPorMaiorMeta();
    QString getEmpregado_do_mes();

    int size();
    void clear();

    Empregado operator[](int i);


signals:

public slots:
};

#endif // EMPRESA_H

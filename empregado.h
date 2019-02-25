#ifndef EMPREGADO_H
#define EMPREGADO_H

#include <QObject>

#define META 50

class Empregado
{
private:
    QString nome;
    float meta;
    float porcentagem;

public:
    explicit Empregado();
    Empregado(QString n, float m);

    QString getNome() const;
    void setNome(const QString &value);

    float getMeta() const;
    void setMeta(float value);

    float getPorcentagem() const;

    QString getEmpregado_do_mes();

signals:

public slots:
};

#endif // EMPREGADO_H

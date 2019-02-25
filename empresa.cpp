#include "empresa.h"


Empresa::Empresa(QObject *parent) : QObject(parent)
{

}

void Empresa::inserirEmpregado(const Empregado a)
{
    empresa.push_back(a);
}

float Empresa::mediaDaEmpresa()
{
    return std::accumulate(empresa.begin(),empresa.end(),0.0, [](float acc, Empregado a){return acc+=a.getMeta();})/empresa.size();
}

float Empresa::maiorMeta()
{
    Empregado *maior = std::max_element(empresa.begin(),empresa.end(),[](Empregado a, Empregado b){ return a.getMeta() < b.getMeta();});
    return maior->getMeta();
}

float Empresa::menorMeta()
{
    Empregado *menor = std::min_element(empresa.begin(),empresa.end(),[](Empregado a, Empregado b){return a.getMeta() < b.getMeta();});
    return menor->getMeta();
}

void Empresa::ordenarPorMenorMeta()
{
    std::sort(empresa.begin(), empresa.end(), [](Empregado a, Empregado b){return a.getNome()<b.getNome();});
    std::stable_sort(empresa.begin(),empresa.end(),[](Empregado a, Empregado b){return a.getMeta()<b.getMeta();});
}

void Empresa::ordenarPorMaiorMeta()
{
    std::sort(empresa.begin(), empresa.end(), [](Empregado a, Empregado b){return a.getNome()>b.getNome();});
    std::stable_sort(empresa.begin(),empresa.end(),[](Empregado a, Empregado b){return a.getMeta()>b.getMeta();});
}
    bool compar(Empregado a, Empregado b){
    return a.getMeta()<b.getMeta();
}
QString Empresa::getEmpregado_do_mes()
{       Empregado *maior = std::max_element(empresa.begin(),empresa.end(),compar);
        return maior->getNome();
}

int Empresa::size()
{
    return empresa.size();
}

void Empresa::clear()
{
    empresa.clear();
}
Empregado Empresa::operator[](int i)
{
    return empresa[i];
}


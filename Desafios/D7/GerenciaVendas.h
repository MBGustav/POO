#ifndef GERENCIA_H
#define GERENCIA_H

#include "Venda.h"
#include <fstream>

#include <string>

using namespace std;

class GerenciaVendas {
    private:
    string fileName;
    public:
    GerenciaVendas(string fileName);
    double totalVendas(int id);
    double mediaVendas(int id);
    Venda maiorVenda();
};

#endif /* GERENCIA_H */
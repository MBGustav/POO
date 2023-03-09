#ifndef __DATAHORARIO_H__
#define __DATAHORARIO_H__

#include <iostream>
#include <string>
#include <iomanip>
using std::setfill, std::setw;

class DataHorario
{
private:
    int dia, mes, ano;
    int hora, min, seg;

    const std::string Month[12] = {"Janeiro", "Fevereiro", "Março", "Abril",
                    "Maio", "Junho","Julho", "Agosto", 
                    "Setembro", "Outubro", "Novembro", "Dezembro"};
    const int day_month[12] ={31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
//=======================

public:
    DataHorario(int dia, int mes, int ano, int hora, int min, int seg);
    ~DataHorario();

    //Getters 
    int getDia() const;
    int getMes() const;
    int getAno() const;
    int getHora() const;
    int getMinuto() const;
    int getSegundo() const;



    //Metodos
    int comparaData(DataHorario &D);
    int comparaHora(DataHorario &D);
    int compara(DataHorario&);

    bool is_bissexto(int i);
    //Metodos -- impressao
    void imprime(bool a = false) const;
    void imprimePorExtenso() const;

};




#endif //__DATAHORARIO_H__
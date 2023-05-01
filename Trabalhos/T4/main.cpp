#include <cstdlib>

#include "CD.h"
#include "DVD.h"
#include "Catalogo.h"
#include "Jogo.h"

#define CATALOG_SET 1


using namespace std;
using namespace catalogo;

void GeraCatalogo(Catalogo *G){
    CD *cd1, *cd2;
    DVD *dvd1, *dvd2;
    Jogo *jogo1, *jogo2;
    Catalogo *catalogo;
    
    cd1 = new CD("X & Y", 2005, "Cold Play");
    cd2 = new CD("Bachianas Brasileiras No.2", 2004,"Orquestra de Câmara da Universidade de São Paulo");
    
    dvd1 = new DVD("O Senhor dos Anéis - A Sociedade dos Anel", 2001,"Peter Jacson");
    dvd2 = new DVD("Matrix", 1999, "Andy & Larry Wachoski");

    jogo1 = new Jogo("Need For Speed - Underground II", 2005, "Corrida");
    jogo2 = new Jogo("Fifa 2008", 2008, "Esporte");
    
    cd1->adicionaFaixa("Square One", 287); // 4:47
    cd1->adicionaFaixa("What If", 297); // 4:57
    cd1->adicionaFaixa("White Shadows", 328); // 5:28
    cd1->adicionaFaixa("Fix You", 294); // 4:54
    cd1->adicionaFaixa("Talk", 311); // 5:11
    cd1->adicionaFaixa("X&Y", 274); // 4:34

    cd2->adicionaFaixa("(Prelúdio) O Canto do Capadócio", 512); // 4:32
    cd2->adicionaFaixa("(Ária) O Canto da Nossa Terra", 389); // 6:29
    cd2->adicionaFaixa("(Dança) Lembranca do Sertão", 324); // 5:24
    cd2->adicionaFaixa("(Tocata) O Trenzinho do Caipira", 284); // 4:44
    
    // adiciona 6 midias
    G->adicionaMidia(*cd1);
    G->adicionaMidia(*dvd1);
    G->adicionaMidia(*jogo1);
    G->adicionaMidia(*cd2);
    G->adicionaMidia(*dvd2);
    G->adicionaMidia(*jogo2);
}

void realizaTestes() {
}

int main() {
    Catalogo *catalogo = new Catalogo("data/dataset.dat");
    char op;
    string Titulo;
    int Ano;
    int tipo;
    int opc_qtd;
    do {

        op = Catalogo::opcao();
        switch (op) {
            case 'B': {
                catalogo->Clear_All();
                GeraCatalogo(catalogo);
                std::cout << "Catalogo com um total de:";
                std::cout << catalogo->quantidadeDeMidias();
                std::cout << " Midias\n";
                std::cout << "---------------------\n";
                break;
            }
            case 'I': { 
                catalogo->imprimeColecao(false);
                break;
            }
            case 'O': { 
                catalogo->imprimeColecao(true);
                break;
            }
            case 'T': {
                cout << "Selecione o tipo:\n";
                cout <<"\t[1]-CD\n";
                cout <<"\t[2]-DVD\n";
                cout <<"\t[3]-Jogo\n";
                cout << "> ";
                
                cin >> opc_qtd;
                catalogo->imprimeColecaoPorTipo(opc_qtd);
                break;
            }
            case 'C': {
                catalogo->adicionaMidia(type_CD);
                break;
            }
            case 'D': {
                catalogo->adicionaMidia(type_DVD);
                break;
            }
            case 'J': {
                catalogo->adicionaMidia(type_JOGO);
                break;
            }
            case 'M': {
                cout << "Titulo: ";
                cin.ignore();
                // cin.getline(Titulo, 50);
                getline(cin, Titulo);

                cout << "Ano: ";
                cin >> Ano;
                
                cout << "Atualização " << (catalogo->ModificaAno(Titulo,Ano)? "ok" : "não ok") << endl;
    
                break;
            }

            case 'R': {
                cin.ignore();
                cout << "Titulo: "; 
                // cin.getline(Titulo, 50);
                getline(cin, Titulo);
                cout << "Remoção " << (catalogo->removeMidia(Titulo) ? "ok" : "não ok") << endl;
                // bool ok = cadastro.remove(Titulo);
                
                break;
            }
            case 'Q': {

                cout << "Selecione o tipo:\n";
                cout <<"\t[0]-Total\n";
                cout <<"\t[1]-CD\n";
                cout <<"\t[2]-DVD\n";
                cout <<"\t[3]-Jogo\n";
                cout << "> ";
                
                cin >> opc_qtd;
                switch(opc_qtd){
                    case 0 : std::cout << "Total: " << catalogo->quantidadeDeMidias()<<endl; break;
                    case 1 : std::cout << "Total: " << catalogo->quantidadeDeCDs()<<endl; break;
                    case 2 : std::cout << "Total: " << catalogo->quantidadeDeDVDs()<<endl; break;
                    case 3 : std::cout << "Total: " << catalogo->quantidadeDeJogos()<<endl; break;
                    default: std::cout << "Nao reconhecido\n"; break;
                }
            }
        }
        cin.ignore();
        cout << endl;
    } while (op != 'F');
}


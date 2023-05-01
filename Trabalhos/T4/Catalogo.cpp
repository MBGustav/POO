#include "Catalogo.h"
#include <algorithm> 
#include <fstream> 
using std::ifstream, std::ofstream;//, std::ifstream::gcount;
using std::ios;
#include <string>
using std::string;
#include "Jogo.h"
#include "CD.h"
#include "DVD.h"
#include "Artista.h"

namespace catalogo
{
    Catalogo::Catalogo(string filename):filename(filename){
        vMidia.clear();
        recupera();
    }
    Catalogo::~Catalogo(){}

    bool Catalogo::adicionaMidia(Midia &M){

        //caso seja encontrado em algum local => falso
        if(this->obtemMidia(M.getTitulo())!=NULL)
            return false;
        
        //Insere no vetor
        vMidia.push_back(&M);

        //Ordenamos o vetor que temos armazenado
        sort(vMidia.begin(), vMidia.end(), CatalogoOrder);
        grava();
        return true;
    }
    
    bool Catalogo::removeMidia(string titulo){
        vector<Midia*>::iterator it=vMidia.begin();
        bool remove = false;
        while(it != vMidia.end() && !remove){
            if((*it)->getTitulo() == titulo){
                //remove na posicao em que o 
                //iterator se encontra
                vMidia.erase(it);
                remove = true;
            }
            else it++;

        }
        grava();
        return remove;
    }

    Midia* Catalogo::obtemMidia(string titulo){
        
        bool found = false;
        int i = static_cast<int>(vMidia.size());

        while(!found && i>0)
            if(vMidia[--i]->getTitulo() == titulo)
                found = true; 
            
        //em caso de ser encontrado
        if(found) return vMidia[i];

        //em caso de nao ser encontrao
        return NULL;

    }

    int Catalogo::quantidadeDeMidias() const{return static_cast<int>(vMidia.size());}
        
    int Catalogo::quantidadeDeCDs() const{
        int total_CD = 0; 
        for(int i=0; i < quantidadeDeMidias(); i++){
            if(vMidia[i]->getTipo() == type_CD) total_CD++;
        }
        return total_CD;
    }

    int Catalogo::quantidadeDeDVDs() const{
        int total_DVD = 0; 
        for(int i=0; i < quantidadeDeMidias(); i++){
            if(vMidia[i]->getTipo() == type_DVD) total_DVD++;
        }
        return total_DVD;
    }

    int Catalogo::quantidadeDeJogos() const{
        int total_JOGO = 0; 
        for(int i=0; i < quantidadeDeMidias(); i++){
            if(vMidia[i]->getTipo() == type_JOGO) total_JOGO++;
        }
        return total_JOGO;
    }

    void Catalogo::imprimeColecao(bool ord=false){
        //outra opção : inserção ja ordenada ? sim
        if(ord) sort(vMidia.begin(), vMidia.end(), CatalogoOrder);
        std::cout << "Impressao de catalogo\n";
        for(auto it=vMidia.begin(); it != vMidia.end();it++)
            (*it)->imprimeFicha();
    }

    void Catalogo::imprimeColecao(string Titulo){
        //outra opção : inserção ja ordenada ? sim
        Midia *M = this->obtemMidia(Titulo);
        
        if(M == NULL) return;
        M->imprimeFicha();
    }

    void Catalogo::imprimeColecaoPorTipo(int type) const{
        for(auto it=vMidia.begin(); it != vMidia.end();it++)
            if((*it)->getTipo()== type) (*it)->imprimeFicha();
    }

    bool Catalogo::CatalogoOrder(const Midia *M1, const Midia *M2){return *M1<*M2;}

    char Catalogo::opcao() {
    char c;
    cout << "[B] Importa BD padrao" << endl;
    cout << "[I] Impressao Comum" << endl;
    cout << "[O] Imprime ordenado (Nome)" << endl;
    cout << "[T] Imprime Midia (Por Tipo)" << endl;
    cout << "[C] Adiciona CD" << endl;
    cout << "[D] Adiciona DVD" << endl;
    cout << "[J] Adiciona JOGO" << endl;
    cout << "[M] Modifica Ano (por Titulo)" << endl;
    cout << "[R] Remove (por Titulo)" << endl;
    cout << "[Q] Quantidade de Midia" << endl;
    cout << "[F] Fim" << endl;
    cout << "> ";
    std::cin >> c;
    return (toupper(c));
    }

    bool Catalogo::continuar(int tipo = 0){
        char include_more;
        switch(tipo){
            case type_CD: cout << "Deseja Incluir Musicas?(Y/N): ";
            case type_DVD: cout << "Deseja Incluir Artistas?(Y/N): ";
            default:cout << "Deseja Continuar?(Y/N): ";
        }
        cin >> include_more;
        return 'Y' ==  toupper(include_more);
    }

    void Catalogo::grava()
    {
        //Variaveis auxiliares na gravação
        int tam; // usada para strings -- size
        int Ano; 
        int tipo;
        string Titulo; //midia
        string Genero, Diretor, Artista;  //CD,DVD,JOGO
        
        CD* cd;
        Faixa *F;
        string NomeF;
        int Duracao;
        long int totalF;

        DVD* dvd; 
        Jogo* jogo; 
        //Gravamos os dados de Midia, inicialmente
        //1. Abrimos o arquivo -- escrita
        ofstream saida(filename, ios::binary);
        for(int i = 0; i < vMidia.size(); i++){
            
            //2. Escrita de info. Midia
            tipo = vMidia[i]->getTipo();
            saida.write(reinterpret_cast<char*>(&tipo), sizeof(tipo));

            Titulo = vMidia[i]->getTitulo();
            tam = Titulo.size();

            saida.write(reinterpret_cast<char*>(&tam), sizeof(tam));
            saida.write(reinterpret_cast<char*>(&Titulo[0]), tam);

            Ano = vMidia[i]->getanoCriacao(); 
            saida.write(reinterpret_cast<char*>(&Ano), sizeof(Ano));

            switch (tipo)
            {
            case type_CD:
                {
                //3. Escrita de CD
                    cd = dynamic_cast<CD*>(vMidia[i]);
                    Artista = cd->getArtista();
                    tam = Artista.size();

                    saida.write(reinterpret_cast<char*>(&tam), sizeof(tam));
                    saida.write(reinterpret_cast<char*>(&Artista[0]), tam);

                    //Escrita das Faixas do CD:
                    totalF = cd->getTotalFaixas();
                    saida.write(reinterpret_cast<char*>(&totalF), sizeof(totalF));
                    for(auto i = 0; i <cd->getTotalFaixas();i++){
                        F = cd->GetFaixa(i);
                        NomeF = F->getNome();
                        tam = NomeF.size(); 

                        //Escreve Nome                       
                        saida.write(reinterpret_cast<char*>(&tam), sizeof(tam));
                        saida.write(reinterpret_cast<char*>(&NomeF[0]), tam);
                        //Escreve Duracao
                        Duracao = F->getDuracao();
                        saida.write(reinterpret_cast<char*>(&Duracao), sizeof(Duracao));
                    }
                break;
                }
            case type_DVD:
                {
                    //3. Escrita de DVD
                    dvd = dynamic_cast<DVD*>(vMidia[i]);
                    Diretor = dvd->getDiretor();
                    tam = Diretor.size();

                    saida.write(reinterpret_cast<char*>(&tam), sizeof(tam));
                    saida.write(reinterpret_cast<char*>(&Diretor[0]), tam);
                
                break;
                }

            case type_JOGO:
                {
                    //3. Escrita de JOGO
                    jogo = dynamic_cast<Jogo*>(vMidia[i]);
                    Genero = jogo->getGenero();
                    tam = Genero.size();

                    saida.write(reinterpret_cast<char*>(&tam), sizeof(tam));
                    saida.write(reinterpret_cast<char*>(&Genero[0]), tam);
                
                break;
                }

            }//switch
        }//for loop
    
        saida.close();
    }

    void Catalogo::recupera()
    {
        //Variaveis auxiliares na gravação
        int tam; // usada para strings -- size
        int Ano; 
        int tipo;
        string Titulo; //midia
        string Genero, Diretor, Artista;  //CD,DVD,JOGO
        CD* cd;
        // Faixa *F;
        long int totalF;
        string NomeF;
        int DuracaoF;
        // DVD* dvd; 
        // Jogo* jogo; 
        //Gravamos os dados de Midia, inicialmente
        int gcount_check;
        bool end_of_file = false;

        //1. Abrimos o arquivo -- escrita
        ifstream entrada(filename, ios::binary);
        if(!entrada.is_open()){
            std::cout << "Erro de Abertura de Arquivo !\n";
            exit(-1);
        }
        //limpa vetor  - caso haja dados anteriores
        vMidia.clear();
        
        //2. Leitura dos dados de Midia
        entrada.read(reinterpret_cast<char*>(&tipo), sizeof(tipo));
        while (entrada.good() && !end_of_file)
        {
            entrada.read(reinterpret_cast<char*>(&tam), sizeof(tam));
            Titulo.resize(tam);
            entrada.read(reinterpret_cast<char*>(&Titulo[0]), tam);

            entrada.read(reinterpret_cast<char*>(&Ano),sizeof(Ano));
            switch (tipo)
            {
            case type_CD:{
                    //3. Escrita de CD
                    entrada.read(reinterpret_cast<char*>(&tam), sizeof(tam));
                    Artista.resize(tam);//necessario sempre realocar tamanho de str
                    entrada.read(reinterpret_cast<char*>(&Artista[0]), tam);
                    // Adicao do novo CD ao vector de Midia
                    cd = new CD(Titulo, Ano, Artista);
                    
                    
                    entrada.read(reinterpret_cast<char*>(&totalF), sizeof(totalF));

                    for(int i = 0; i < totalF; i++){

                        //Leitura nome faixa: tamanho + nome
                        entrada.read(reinterpret_cast<char*>(&tam), sizeof(tam));
                        NomeF.resize(tam);
                        entrada.read(reinterpret_cast<char*>(&NomeF[0]), tam);
                        //Leitura duracao
                        entrada.read(reinterpret_cast<char*>(&DuracaoF), sizeof(DuracaoF));
                            
                        cd->adicionaFaixa(NomeF, DuracaoF);
                    }

                    vMidia.push_back(cd);
                
                break;
                }
            case type_DVD:{
                    //3. Escrita de DVD
                    entrada.read(reinterpret_cast<char*>(&tam), sizeof(tam));
                    Diretor.resize(tam);//necessario sempre realocar tamanho de str
                    entrada.read(reinterpret_cast<char*>(&Diretor[0]), tam);

                    // Adicao do novo DVD ao vector de Midia
                    vMidia.push_back(new DVD(Titulo, Ano, Diretor));
                
                break;
                }
            case type_JOGO:{
                    //3. Escrita de JOGO
                    entrada.read(reinterpret_cast<char*>(&tam), sizeof(tam));
                    Genero.resize(tam);//necessario sempre realocar tamanho de str
                     entrada.read(reinterpret_cast<char*>(&Genero[0]), tam);

                    // Adicao do novo DVD ao vector de Midia
                    vMidia.push_back(new Jogo(Titulo, Ano, Genero));

                break;
                }
            }//end switch
            
            //Leitura ao final do while -- checagem de eof
            entrada.read(reinterpret_cast<char*>(&tipo), sizeof(tipo));
        }//end while
        entrada.close();
    }

    bool Catalogo::adicionaMidia(int tipo){

        bool added = false;

        //Dados de Midia
        string Titulo; 
        int Ano;
        Midia *ptr_M= NULL;
        cin.ignore();
        std::cout << "Titulo: ";
        getline(cin, Titulo);

        std::cout << "Ano: ";
        std::cin >> Ano;

        switch (tipo){
        case type_CD:{
                cin.ignore();
                string artista;
                std::cout << "Artista: ";
                getline(cin, artista);

                //instancia objeto
                ptr_M = new CD(Titulo, Ano, artista);

                string nomeF;
                int duracaoF;
                CD *cd = dynamic_cast<CD*>(ptr_M);
                while(continuar(tipo)){
                    cout << "Nome da Faixa: "; 
                    cin.ignore();getline(cin, nomeF);
                    cout << "Duracao: ";
                    cin >> duracaoF;
                    cd->adicionaFaixa(nomeF, duracaoF);
                }
                added = true;
                break;
            }
        case type_DVD:{
                string Diretor;
                cin.ignore();
                std::cout << "Diretor: ";
                getline(cin, Diretor);
                
                //instancia objeto
                ptr_M = new DVD(Titulo, Ano, Diretor);
                added = true;
                break;
            }
        case type_JOGO:{
                cin.ignore();
                string Genero;
                std::cout << "Genero: ";
                getline(cin, Genero);
                

                //instancia objeto
                ptr_M = new Jogo(Titulo, Ano, Genero);
                added = true;
                break;
            }
        default:
            added = false;
            break;
        }
        if(ptr_M != NULL) vMidia.push_back(ptr_M);
        grava();
        return added;
    }
    // int Catalogo::indice(string nome_midia) const{       
    // }
    int Catalogo::indice(string Titulo)const{
        size_t pos= 0;
        size_t tam = vMidia.size();
        while (pos < tam && vMidia[pos]->getTitulo() != Titulo) {
            pos++;
        }

        if(pos<tam) return pos; 
        //else ... 
        return -1;
    }

    bool Catalogo::ModificaAno(string Titulo, int Ano){
        bool mod= false;
        int pos = indice(Titulo);
        if(pos !=-1){
            vMidia[pos]->setanoCriacao(Ano);
            mod=true;
        }
        grava();
        return mod; 

    }

    void Catalogo::Clear_All(){
        for(int i =0; i<vMidia.size(); i++){
            delete vMidia[i];
        }
        vMidia.clear();
    }
}
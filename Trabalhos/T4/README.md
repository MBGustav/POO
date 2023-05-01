# Documentação - T4

Neste arquivo, temos como objetivo a declaração do funcionamento e hierarquia de classes. Com isso, abaixo, temos as principais explicações sobre a mesma.

# Descrição de classes

```cpp
        Catalogo(Concreta)
| > char opcao()                        |
| > bool adiciona()                     |
| > bool adicionaMidia(Midia)           |
| > bool removeMidia(string)            |
| > Midia *obtemMidia(string)           |
| > int quantidadeDeMidias()            |
| > int quantidadeDeCDs()               |
| > int quantidadeDeDVDs()              |
| > int quantidadeDeJogos()             |
| > void imprimeColecao(bool ordenado)  |
| > void imprimePorTipo(int tipo)       |
+---------------------------------------+

    Midia(Abstrato)
| > Midia(string, int)  |
| > (*) int GetTipo()   |
| > void ImprimeDados() |
| > void imprimeFicha() |
+-----------------------+
CD
| > void AdicionaFaixa(string, int) |
| > int GetTipo()                   |
| > void ImprimeDados()             |
+-----------------------------------+

DVD
| > void adicionaArtista(string, string) |
| > int getTipo()                        |                      
| > void imprimeDados()                  |                            
-----------------------------------------+

Jogo 
|> Jogo(string, int, string) |              
|> int getTipo()             |  
|> void imprimeDados()       |        
+----------------------------+
```
## Associação de Classes - grafico: 

``` 
    +--| Catalogo |       +--| Jogo |
    |                     |
    +--> | Midia | <------+--|  DVD | <-Artistas
                          |
                          +--|  CD  |<-Faixas

```

Nesta etapa, temos a associação de Classes. Vale salientar que a classe "midia" é abstrata - impedindo a sua instanciação. Com isso, temos em sua hierarquia as seguintes classes, que herdam seus metodos e atributos: Jogo, CD, DVD. Na representação anterior pode ser evidenciado quais metodos que são necessarios para eventual inclusao de nova classe para herdeiros de Midia


## Execução:

Para facilitar a exeução e testes do programa, foi incluido um exemplo inicial. Pressionando a opção B, teremos a inclusao de 6 midias, duas quais têm 2CD's, 2DVD's e 2 Jogos.

- B: Importa BD padrao"
- I: Impressao Comum"
- O: Imprime ordenado (Nome)"
- T: Imprime Midia (Por Tipo)"
- C: Adiciona CD"
- D: Adiciona DVD"
- J: Adiciona JOGO"
- M: Modifica Ano (por Titulo)"
- R: Remove (por Titulo)"
- Q: Quantidade de Midia"
- F: Fim"


Alem disso, foi incluido um sistema de inclusao de musicas dentro do modelo "CD", marcado na opção C.



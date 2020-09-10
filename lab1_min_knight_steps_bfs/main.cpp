#include <iostream>
#include <queue>
#include<stdio.h>
using namespace std;
#define limite_inicio  0
#define limite_fim  7
 
struct Celula
{
    int x, y, nivel;
    Celula(int x, int y, int nivel = 0):
        x(x),
        y(y),
        nivel(nivel){}
};
 
bool valida_expansao(int valor)
{
    if(valor >= limite_inicio && valor <= limite_fim)
        return true;
    else
        return false;
}
 
//retorna nivel do no encontrado
int busca_profunda_expansiva(Celula origem, Celula destino)
{
    int dx = destino.x;
    int dy = destino.y;
    int cx,cy,cnivel;
    int N_expansoes_possiveis = 8;
    int expande_x[] = { 2, 2, -2, -2, 1, 1, -1, -1 };
    int expande_y[] = { -1, 1, 1, -1, 2, -2, 2, -2 };
    int board[8][8] = {0,0,0,0,0,0,0,0,
                       0,0,0,0,0,0,0,0,
                       0,0,0,0,0,0,0,0,
                       0,0,0,0,0,0,0,0,
                       0,0,0,0,0,0,0,0,
                       0,0,0,0,0,0,0,0,
                       0,0,0,0,0,0,0,0,
                       0,0,0,0,0,0,0,0};
 
    queue<Celula> candidatos;
 
    candidatos.push(origem); //insere no final
 
    while (!candidatos.empty()) {
        Celula candidato = candidatos.front(); //pega o primeiro elemento
        candidatos.pop(); //remove o primeiro elemento
 
        cx = candidato.x;
        cy = candidato.y;
        cnivel = candidato.nivel;
 
        //no encontrado no nível (cada nivel um passo)
        if (cx == dx && cy == dy)
            return cnivel;
 
        //expansao em largura para movimentos possiveis
        //fazendo corte no grafo de busca e evitando expansao em candidatos ja visitados
        if (board[cx][cy] == 0) {
 
            //marcando visita
            board[cx][cy]++;
 
            //expandindo lista com candidatos possiveis
            int x,y,nivel;
            for (int i = 0; i < N_expansoes_possiveis; ++i){
                x = cx + expande_x[i];
                y = cy + expande_y[i];
                nivel = cnivel + 1;
                if(valida_expansao(x) && valida_expansao(y)){
 
                    //adicionando candidato na lista de candidatos validados
                    candidatos.push(Celula(x,y,nivel));
                }
            }
        }
    }
    //ninguem encontrado (impossivel de ocorrer neste problema para um tabuleiro 8*8 com 2 posições validas pois o cavalo pode percorrer todo o tabuleiro atraves de um ciclo hamiltoniano)
    return -1;
}
 
int main()
{
    char origem_input[3];
    char destino_input[3];
    scanf("%s %s", origem_input, destino_input);
    int x1,y1,x2,y2;
    x1 = origem_input[0] - 'a';
    y1 = origem_input[1] - '1';
    x2 = destino_input[0] - 'a';
    y2 = destino_input[1] - '1';
    Celula origem(x1,y1);
    Celula destino(x2,y2);
    printf("%d", busca_profunda_expansiva(origem, destino));
    return 1;
}
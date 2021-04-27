#include <iostream>
#include "ptime.h"
#include <stack>
#include <queue>
#define vetor_size 10000 //Tamanho inicial pilha/fila
using namespace std;

int main()
{
    ptime <milliseconds> time_pilha; //Instacia de Cronometro

    cout << endl;
    cout << "Pilha" << endl;
    cout << endl;

    time_pilha.start(); //Inicia a contagem do conometro

    for(int n = 1; n < 6 ; n++) //Mutiplica o tamanho do vetor
    {
        //PILHA -> O PRIMEIRO A ENTRAR É O ÚLTIMO A SAIR

        stack <int> pilha; //Instanciando uma pilha

        for(int b = 0; b < 1000; b++) //Instancia de teste
        {
            for(int j = 0; j < vetor_size*n; j++)
            {
                pilha.push(j); //Adiciona o elemento 'i' no topo da pilha
            }
            for(int p = 0; p < vetor_size*n; p++)
            {
                pilha.pop(); //Exclui o elemento mais superior da pilha
            }
        }
       cout << "n = " << vetor_size*n << " -> " << time_pilha.elapsed(time_pilha.point()) << " ms" << endl; //Tempo do teste a cada tamanho da pilha
    }

    cout << endl;
    cout << "Media pilha: " << time_pilha.total()/5 << " ms" << endl; //Média do tempo de teste

    ptime <milliseconds> time_fila; //Instancia o conometro

    cout << endl;
    cout << "Fila" << endl;
    cout << endl;

    time_fila.start(); //Inicia contagem do conometro

    for(int n = 1; n < 6; n++) //Mutiplica o tamanho do vetor
    {
       //FILA -> FIFO(FIRST IN - FIRST OUT)

        queue <int> fila; //Instancia uma fila

        for(int f = 0; f < 1000; f++) //Instancia de testes
        {
            for(int i = 0; i < vetor_size*n; i++)
            {
                fila.push(i); //Adiciona o elemento 'i' no topo da pilha
            } 
            for (int p = 0; p < vetor_size*n; p++)
            {
                fila.pop(); //Exclui o elemento mais superior da pilha
            }
        }

        cout << "n = " << vetor_size*n << " -> " << time_fila.elapsed(time_fila.point()) << " ms" << endl; //Tempo do teste a cada tamanho da fila

    }

    cout << endl;
    cout << "Media fila: " << time_fila.total()/5 << " ms" << endl; //Média do tempo de teste
    cout << endl;

    return EXIT_SUCCESS;

}


/*
A complexidades dos dois algoritmos são O(1), pois não precisam fazer iterações sobre os elementos (uso de laço),
uma vez que inserem apenas no final da fila ou aparecem na frente dela

*/



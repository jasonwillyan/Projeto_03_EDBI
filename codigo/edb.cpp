#include <iostream>
#include "ptime.h"
#include "pilha.h"
#include "fila.h"
#define vetor_size 10000 //Quantidade inicial de testes
using namespace std;

int main()
{

    //*******************************************************
    //PILHA -> O PRIMEIRO A ENTRAR É O ÚLTIMO A SAIR
    //*******************************************************


    int tam = 1000;                                                  //  Váriavel que guarda o tamanho da pilha/fila
    ptime <milliseconds> time_pilha;                                //  Instacia de Cronometro

    cout << endl;
    cout << "Pilha" << endl;
    cout << endl;

    Pilha <int> pilha;                                              //Instanciando uma pilha
    time_pilha.start();                                             //Inicia a contagem do conometro
    
    for(int n = 1; n < 6 ; n++)                                     //Mutiplica o tamanho do vetor
    {
        for(int b = 0; b < vetor_size*n; b++)                       //Instancia de teste
        {
            for(int j = 0; j < tam; j++)
            {
                pilha.push(j);                                      //Adiciona o elemento 'i' no topo da pilha
                pilha.size();
                pilha.top();
                pilha.pop();                                        //Exclui o elemento mais superior da pilha
            }
        }
        cout << "n = " << vetor_size*n << " -> " << time_pilha.elapsed(time_pilha.point()) << " ms" << endl; //Tempo do teste a cada tamanho da pilha
    }

    cout << endl;
    cout << "Media pilha: " << time_pilha.total()/5 << " ms" << endl; //Média do tempo de teste

    ptime <milliseconds> time_fila;                                   //Instancia o conometro

    cout << endl;
    cout << "Fila" << endl;
    cout << endl;


    //***************************************
    //FILA -> FIFO(FIRST IN - FIRST OUT)
    //***************************************


    Fila <int> fila;                                                    //Instancia uma fila

    time_fila.start();                                                  //Inicia contagem do conometro
    for(int n = 1; n < 6; n++)                                          //Mutiplica o tamanho do vetor
    {
        for(int f = 0; f < vetor_size*n; f++)                           //Instancia de testes
        {
            for(int i = 0; i < tam; i++)
            {
                fila.push(i);                                           //Adiciona o elemento 'i' no topo da pilha
                fila.size();
                fila.back();
                fila.pop();                                             //Exclui o elemento mais superior da pilha
            }
        }
        cout << "n = " << vetor_size*n << " -> " << time_fila.elapsed(time_fila.point()) << " ms" << endl; //Tempo do teste a cada tamanho da fila
    }

    cout << endl;
    cout << "Media fila: " << time_fila.total()/5 << " ms" << endl;      //Média do tempo de teste
    cout << endl;

    return EXIT_SUCCESS;

}
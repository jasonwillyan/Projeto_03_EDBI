#include <iostream>
#include "ptime.h"
#include "pilha.h"
#include "fila.h"
#define vetor_size 100 //Quantidade inicial de testes
using namespace std;

int main()
{

    //*******************************************************
    //PILHA -> O PRIMEIRO A ENTRAR É O ÚLTIMO A SAIR
    //*******************************************************


    int tam = 1000;                                                  //  Váriavel que guarda o tamanho da pilha/fila
    ptime <nanoseconds> time_pilha; 
    Pilha <int> pilha;                                              //Instanciando uma pilha

    cout << endl;
    cout << "Pilha" << endl;
    cout << endl;

     
    double media_pilha = 0;
    size_t count_pilha = 0;                                           //Inicia a contagem do conometro
    double media_total_pilha = 0;

    for(int n = 1; n < 6 ; n++)                                     //Mutiplica o tamanho do vetor
    {
        count_pilha = 0;
        media_pilha = 0;
        for(int b = 0; b < vetor_size*n; b++)                       //Instancia de teste
        {
            for(int j = 0; j < tam; j++)
            {
                time_pilha.start();                                    //inicio
                pilha.push(j);                                      //Adiciona o elemento 'i' no topo da pilha
                pilha.size();
                pilha.top();
                pilha.pop();                                        //Exclui o elemento mais superior da pilha
                media_pilha+= time_pilha.elapsed(time_pilha.point()); 
                count_pilha++;    
            }
        }
        media_total_pilha += media_pilha/count_pilha;
        cout << "n = " << vetor_size*n << " -> " << media_pilha/count_pilha << " ns" << endl; //Tempo do teste a cada tamanho da pilha
    }

    cout << endl;
    cout << "Media pilha: " << media_total_pilha/5 << " ms" << endl; //Média do tempo de teste


    //***************************************
    //FILA -> FIFO(FIRST IN - FIRST OUT)
    //***************************************


    ptime <nanoseconds> time_fila;                                      //Instancia o conometro
    Fila <int> fila;                                                    //Instancia uma fila

    cout << endl;
    cout << "Fila" << endl;
    cout << endl;

    
    double media_fila = 0;
    size_t count_fila = 0;
    double media_total_fila = 0;  
                                        
    for(int n = 1; n < 6; n++)                                          //Mutiplica o tamanho do vetor
    {
        count_fila = 0;
        media_fila = 0;
        for(int f = 0; f < vetor_size*n; f++)                           //Instancia de testes
        {
            for(int i = 0; i < tam; i++)
            {
                time_fila.start(); 
                fila.push(i);                                           //Adiciona o elemento 'i' no topo da pilha
                fila.size();
                fila.back();
                fila.pop();                                             //Exclui o elemento mais superior da pilha
                media_fila+= time_fila.elapsed(time_fila.point()); 
                count_fila++;  
            }
        }
        media_total_fila += media_fila/count_fila;
        cout << "n = " << vetor_size*n << " -> " << media_fila/count_fila << " ns" << endl; //Tempo do teste a cada tamanho da fila
    }

    cout << endl;
    cout << "Media fila: " << media_total_fila/5 << " ms" << endl;      //Média do tempo de teste
    cout << endl;

    return EXIT_SUCCESS;

}
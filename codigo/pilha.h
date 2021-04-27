#ifndef PILHA_H
#define PILHA_H

#include  <iostream>
#include <exception>
using namespace std;


template<typename type>

class Pilha
{
    public:
        void push(const type& value)noexcept
        {
			tam++;
			if (head != nullptr)
            {
                node* other = new node();
                other->dado = value;
                other->prev = tail;
                tail->next = other;
                tail = other;
            }
            else
            {
                head = new node();
                head->dado = value;
                tail = head;
            }
		}
        void pop()noexcept
        {
            if(tail == nullptr)  //Verifica se a lista está vazia
            {
                return;
            }
			tam--;
			node *temp = tail;
            tail = tail->prev;

            if(tail != nullptr)
            {
                tail->next = nullptr;
            }
            else
            {
                head = nullptr;
            }
            delete temp;
		}
        size_t size()noexcept
        {
			return tam;
		}
        type& top()
        {
            if(tam == 0)
            {
                throw inexistent_element();
            }
            return tail->dado;
        }
        Pilha()
        {
            //Construtor padrão
        }
        
        ~Pilha()
        {
            if (tam == 0)
            {
                return;
            }
            node* current = head;
            while (current != nullptr)
            {
                node* tmp = current->next;
                delete current;
                current = tmp;
            }
            tam = 0;
            head = nullptr;
            tail = nullptr;
        }
    private:
        size_t tam = 0;    //Tamanho da lista
        struct node    //Declarando struct que define um nó
		{
			type dado;  //Variável do tipo declarado
			node *next = nullptr;  //Ponteiro para o próximo nó
            node *prev = nullptr;  //Ponteiro para o nó anterior
		};
        node *head = nullptr;  //Cabeça da lista
        node *tail = nullptr;  //Cauda da lista
		
        struct inexistent_element : std::exception
        {
            const char* what() const noexcept
            {
                return "O elemento em questao nao existe";
            }
        };
};

#endif
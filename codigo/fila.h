#ifndef FILA_H
#define FILA_H

#include  <iostream>
#include <exception>
using namespace std;


template<typename type>

class Fila
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
			node *temp = head;
            head = head->next;
            delete temp;
		}
        size_t size()noexcept
        {
			return tam;
		}
        type& front()
        {
            if(tam == 0)
            {
                throw inexistent_element();
            }
            return head->dado;
        }
        type& back()
        {
            if(tam == 0)
            {
                throw inexistent_element();
            }
            return tail->dado;
        }
        Fila()
        {
            //Construtor padrão
        }
        
        ~Fila()
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
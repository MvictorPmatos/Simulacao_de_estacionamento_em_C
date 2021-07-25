#include <iostream>
#include <string.h>
#include "lines.h"

using namespace std;

class cValet{
    
    int top; // Guarda a posição do topo da pilha da area de manobra
    int size; // Guarda o tamanho da pilha
    string* stack; // Array que contém os dados da pilha

    public:
        cValet(cLines parking); // Inicializa a area de manobra
        bool isEmpty(); // Retorna se a area de manobra está vazia
        bool isFull(cLines parking); // Retorna se está cheia
        string pop(); // Retira o elemento do topo da area de manobra
        void push(cLines parking, int line); // Insere um novo elemento na area de manobra a partir o topo de uma linha
        string valTop(); // Retorna o topo da area de manobra
        void printVal(cLines parking); // Printa a area de manobra
        void pushEx(string car, cLines parking); // Insere um novo elemento na area de manobra
};
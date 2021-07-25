#include <iostream>
#include <string>
#include <bits/stdc++.h>

using namespace std;

class cLines{
    string *arr; // Array que guarda as pilhas
    int *top; // Array que guarda o topo de cada pilha
    int *next; // Array que guarda o próximo item do arr
    int *numEl; // Guarda o número de elementos de cada pilha
    int k, n; // Guarda o número de pilhas e o tamanho total da array
    int free; // Guarda uma posição livre da array que guarda as pilhas

    public:
        cLines(int k, int n); // Inicializa as linhas

        bool isFull(){return (free == -1);} // Retorna se está cheia

        void push(string car, int line); // Faz a inserção de elementos

        string pop (int line); // Retira o primeiro elemento da pilha

        bool isEmpty(int line){return (top[line] == -1);}// Retorna se a pilha está vazia

        string topLine(int line); // Retorna o topo de uma dada linha

        int range(); // Retorna o tamanho da array que guarda as pilhas

        void print(int line); // Printa uma linha

        int size(int line); // Retorna o nº de elementos de uma linha
};
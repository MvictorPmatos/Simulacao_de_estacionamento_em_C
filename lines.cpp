#include <iostream>
#include <string.h>
#include <bits/stdc++.h>
#include "lines.h"

using namespace std;

//  Inicializa as arrays, o free e o número de elementos
cLines::cLines(int nLines, int size){
    k = nLines;
    n = size;

    arr = new string[n];
    top = new int[k];
    next = new int[n];
    numEl = new int[k];

    for (int i = 0; i < k; i++)
        top[i] = -1;

    for (int i = 0; i < k; i++)
        numEl[i] = 0;
  
    
    free = 0;
    
    for (int i=0; i<n-1; i++)
        next[i] = i+1;
    next[n-1] = -1;  
}

//  Insere elementos em uma dada linha
void cLines::push(string car, int line){
    if (isFull()){
        cout << "\nLINHA CHEIA DE CARROS\n";
        return;
    }
  
    int i = free;  
 
    free = next[i];
  
    next[i] = top[line];
    top[line] = i;
  
    arr[i] = car;
    numEl[line]++;
}

// Retira o elemento do topo de uma linha
string cLines::pop(int line){
    if (isEmpty(line))
        return "Não tem carros nessa linha";
    
  
    int i = top[line];
  
    top[line] = next[i]; 
  
    next[i] = free;
    free = i;
    
    --numEl[line];

    return arr[i];
}

// Retorna o topo de uma dada linha
string cLines::topLine(int line){
    if (isEmpty(line))
        return "Não tem carros nessa linha";

    int i = top[line];

    return arr[i];
}

// Retorna o tamanho total da array que guarda as linhas
int cLines::range(){
    return n;
}

// Printa uma dada linha
void cLines::print(int line){
    if (isEmpty(line))
        return;
 
    string x = topLine(line);

    pop(line);
  
    print(line);
  
    cout << " [" << x << "] ";
 
    push(x,line);
}

//  Retorna a quantidade de elementos em uma linha
int cLines::size(int line){
    return numEl[line];
}
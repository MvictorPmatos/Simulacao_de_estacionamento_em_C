#include <iostream>
#include <string.h>
#include "valet.h"

using namespace std;

//  Inicializa a area de manobra
cValet::cValet(cLines parking){
    stack = new string[parking.range()];
    top = -1;
    size = parking.range();
}

// Retorna se a area de manobra está vazia
bool cValet::isEmpty(){
    if (top == -1)
        return true;
    return false;
}

//  Retorna se a area de manobra está cheia
bool cValet::isFull(cLines parking){
   if (top == parking.range())
        return true;
    return false;
}

//  Insere um novo elemento na area de manobra a partir do topo de uma dada linha
void cValet::push(cLines parking, int line){
    if (isFull(parking)){
        cout << "\nStack Overflow\n";
        return;
    }

    stack[++top] = parking.topLine(line);
    return;
}

// Insere um novo elemento na area de manobra
void cValet::pushEx(string car, cLines parking){
    if(isFull(parking)){
        cout << "\nStack Overflow\n";
        return;
    }
        
    stack [++top] = car;
    return;
}

//  Retira um elemento do topo da area de manobra
string cValet::pop(){
   if (isEmpty()){
        return "Stack Underflow";
    }

    return stack[top--];
}

// Retorna o topo da area de manobra
string cValet::valTop(){
    if (isEmpty())
        return "STACK UNDERFLOW";
    

    return stack[top];
}

//  Printa a area de manobra
void cValet::printVal(cLines parking){
    if (isEmpty())
        return;
 
    string x = valTop();
 
    // Pop the top element of the stack
    pop();
 
    // Recursively call the function PrintStack
    printVal(parking);
 
    // Print the stack element starting
    // from the bottom
    cout << " [" << x << "] ";
 
    // Push the same element onto the stack
    // to preserve the order
    pushEx(x, parking);
}
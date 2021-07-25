#include <iostream>
#include <string>
#include <stdlib.h>
#include <time.h>
#include "plate.h"
using std::string;
using namespace std;

//Retorna uma string com 3 letras e 4 números como uma placa de carro de forma aleatória
string plateGenerator(){
    char simbols, numbers;
    string plate, letters, numeric;

    for(int i = 0; i < 3; i++){
        int r1 = rand()%26;
        simbols = 'A' + r1;
        letters = letters + simbols;
    }
    for(int w = 0; w < 4; w++){
        int r2 = rand()%9;
        numbers = '0'+ r2;
        numeric = numeric + numbers;
    }

    plate = letters + numeric;

    return plate;
}
#include <iostream>
#include "plate.h"
#include "valet.h"


using namespace std;

int main(){

    srand(time(NULL));
        int size = 10 + rand()%10; // Gera aleatoriamento o tamanho total da array que guarda as linhas de 10 a 20
        int nLines = 2 + rand()%3; // Gerar aleatoriamento o tamanho das linhas de 2 a 5
        cLines parking(nLines, size); // Inicializa o objeto que guarda as linhas e seus métodos
        cValet valet(parking); // Inicializa o objeto que guarda a area de manobra e seus métodos
        int contador = 0;
        int vagas = size/nLines;
        int i, j, k, veic, ciev, line, inParking;
        string exit;
        char opt;
        
        // Faz a inserção de acordo com a quantidade de linhas e de "vagas"
        for(i = 0; i < nLines; i++){
            for(j = 0; j < vagas; j++){
                parking.push(plateGenerator(), i);
                contador++;
            }
        }

        // Verifica se alguma vaga ficou sem ser preenchida, caso sim, insere nas vagas faltantes
        if(contador < size){
            for(k = 0; k < (size - (nLines*vagas)); k++){
                parking.push(plateGenerator(), k);
            }
        }

        //  Programa funcional
        do{
            cout << endl;
            cout << "ESTACIONAMENTO AUTONOMO" << endl;
            cout << endl;


            cout << "=======================================";
            for(i = 0; i < nLines; i++){
                cout << endl;
                cout << "Linha " << i << ": ";
                parking.print(i);
                cout << endl;
            }
            cout << "======================================="<< endl;
            
            cout << endl;
            cout << "Deseja estacionar(1) ou retirar(2) [1/2]? ";
            cin >> inParking;
            cout << endl;

            if(inParking == 1){
                cout << "Em qual linha deseja estacionar um novo carro? ";
                cin >> line;
                cout << endl;
                parking.push(plateGenerator(), line);
               
            } else{
                cout << "De qual linha deseja retirar? ";
                cin >> line;
                cout << endl;
                cout << "Qual veiculo retirar? (Digite sua posicao, 1, 2, 3...) ";
                cin >> ciev;
                cout << endl;
                veic = (parking.size(line) - ciev)+1;

                for(i = 0; i < veic; i++){
                    valet.push(parking, line);
                    parking.pop(line);
                }

                cout << "=======================================";
                for(i = 0; i < nLines; i++){
                    cout << endl;
                    cout << "Linha " << i << ": ";
                    parking.print(i);
                    cout << endl;
                }
                cout << "======================================="<< endl;

                cout << endl;
                cout << "[AREA DE MANOBRA]: ";
                valet.printVal(parking);
                cout << endl;

                exit = valet.valTop();
                valet.pop();

                for(i = 0; i < veic - 1; i++){
                    parking.push(valet.valTop(), line);
                    valet.pop();
                }
                
                cout << endl;
                cout << "O veiculo [" << exit << "] saiu!" << endl;
                cout << endl;

            }

            cout << endl;
            cout << "ESTACIONAMENTO ATUAL" << endl;;
            cout << "=======================================";
            for(i = 0; i < nLines; i++){
                cout << endl;
                cout << "Linha " << i << ": ";
                parking.print(i);
                cout << endl;
            }
            cout << "=======================================" << endl;

            cout << endl;
            cout << "Deseja continuar estacionando ou retirando carros? [S/N]";
            cin >> opt;
            cout << endl;

        } while((opt == 'S') || (opt == 's'));

    return 0;
}
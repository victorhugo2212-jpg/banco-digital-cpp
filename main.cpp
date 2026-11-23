#include <iostream>
#include <string>
using namespace std;

int main() {
    int saldo = 50;
    int deposito;
    int saque;
    string nome;
    int option;

    while (true) {
        cout << "Seja bem vindo ao banco digital" << endl;
        cout << "[1] - Ver saldo" << endl;
        cout << "[2] - Depositar dinheiro" << endl;
        cout << "[3] - Sacar dinheiro" << endl;
        cout << "[4] - Sair" << endl;
        cin >> option;
        if (option == 1) {
            cout << "Seu saldo é de: " << saldo << endl;
        }
        else if (option == 2) {
            cout << "Digite o dinheiro que deseja depositar: " << endl;
            cin >> deposito;
            saldo += deposito;
            cout << "Seu saldo atual é de: " << saldo << endl;
        }
        else if (option == 3) {
            cout << "Quando voce deseja sacar do seu saldo: " << endl;
            cin >> saque;
            if (saldo < saque) {
                cout << "Dinheiro insuficiente" << endl;
            }
            else if (saldo > saque) {
                saldo -= saque;
                cout << "Saque realizado com sucesso" << endl;
            }

        }
        else if (option == 4) {
            cout << "Saindo do banco..." << endl;
            break;
        }

    }


    return 0;


}

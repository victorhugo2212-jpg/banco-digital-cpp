#include <iostream>
#include <string>
#include <fstream>

using namespace std;

//declarando variaveis
int saque;
int saldo = 500;

//voids
void sacarDinheiro() {
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

int main() {
    int option = 0;
    int senha;
    int opcoes_login;
    string usuarioDigitado;
    string senhaDigitada;
    string senhaSalva;
    string usuarioSalva;
    bool logado = false;


    //sistema de login
    cout << "==BEM VINDO AO BANCO DIGITAL==\n"
        << "  [1] - Entrar na conta\n"
        << "  [2] - Criar conta\n"
        << "  Escolha: " << endl;
    cin >> opcoes_login;
    //entrar na conta
    if (opcoes_login == 1) {
        cout << "Usuario: " << endl;
        cin >> usuarioDigitado;
        cout << "Senha: " << endl;
        cin >> senhaDigitada;

        //ifstream
        ifstream arquivoEntrada("conta.text");

        if (!arquivoEntrada.is_open()) {
            cout << "Arquivo não encontrado...";
        }
        arquivoEntrada >> usuarioSalva;
        arquivoEntrada >> senhaSalva;
        arquivoEntrada.close();

        if (usuarioDigitado == usuarioSalva && senhaDigitada == senhaSalva) {
            cout << "Logado com Sucesso!\n";
            logado = true;
        }
        else {
            cout << "Usuario ou Senha errada" << endl;
        }


    }
    //criando a conta
    else if (opcoes_login == 2) {
        cout << "Digite um nome de Usuario: " << endl;
        cin >> usuarioDigitado;
        cout << "Digite uma senha: " << endl;
        cin >> senhaDigitada;

        //ofstream
        ofstream arquivoSaida("conta.text");
        arquivoSaida << usuarioDigitado << endl;
        arquivoSaida << senhaDigitada << endl;
        arquivoSaida.close();

        cout << "Conta Criada! Feche e abra o banco para entrar" << endl;

    }

    if (logado == true) {

        while (option != 3) {
            cout << "   --BANK DIGITAL--\n"
                << " [1] - Ver Saldo\n"
                << " [2] - Sacar Dinheiro\n"
                << " [3] - Sair" << endl;
            cin >> option;

            switch (option) {
            case 1:
                cout << "Seu saldo e de: " << saldo << endl;
                break;
            case 2:
                sacarDinheiro();
                break;
            case 3:
                cout << "Fechando o Banco..." << endl;
                break;
            default:
                cout << "Opcao Invalida..." << endl;
                break;
            }
        }
    }


        return 0;

}

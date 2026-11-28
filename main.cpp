#include <iostream>
#include <string>
#include <vector> 
#include "Operacoes.h"


void Sistema(std::vector<Conta>& contas, int indiceLogado) {
    int option = 0;

    if (contas[indiceLogado].chavePix.empty()) {
        chavePixGerar(contas[indiceLogado]);
    }

    while (option != 4) {
        std::cout << "   --BANK DIGITAL--\n"
            << " [1] - Ver Saldo\n"
            << " [2] - Sacar Dinheiro\n"
            << " [3] - Transferencia\n"
            << " [4] - Sair" << std::endl;
        std::cin >> option;

        switch (option) {
        case 1:
            std::cout << "Seu saldo e de: " << contas[indiceLogado].saldo << std::endl;
            break;
        case 2:
            sacarDinheiro(contas[indiceLogado]);
            break;
        case 3: {
            pixTransferencia(contas, indiceLogado);
            break;
        }
        case 4: {
            salvarContas(contas);
            std::cout << "Saindo e salvando dados..." << std::endl;
            break;
        }
        default:
            std::cout << "Opcao Invalida..." << std::endl;
            break;
        }
    }
}

int main() {
    int opcoes_login;
    std::string usuarioDigitado;
    std::string senhaDigitada;
    int indiceLogado = -1;

    std::vector<Conta> contas = carregarContas();

    //sistema de login
    std::cout << "--BEM VINDO AO BANCO DIGITAL--\n"
        << " [1] - Entrar na conta\n"
        << " [2] - Criar conta\n"
        << " Escolha: " << std::endl;
    std::cin >> opcoes_login;
    //entrar na conta
    if (opcoes_login == 1) {
        std::cout << "Usuario: " << std::endl;
        std::cin >> usuarioDigitado;
        std::cout << "Senha: " << std::endl;
        std::cin >> senhaDigitada;

        for (int i = 0; i < contas.size(); i++) {
            if (contas[i].usuarioSalva == usuarioDigitado && contas[i].senhaSalva == senhaDigitada) {
                indiceLogado = i;
                break;
            }
        }
        if (indiceLogado != -1) {
            std::cout << "Logado com Sucesso!\n";
            Sistema(contas, indiceLogado);
        }
        else {
            std::cout << "Usuario ou Senha errada!" << std::endl;
        }
    }

    
else if (opcoes_login == 2) {
    Conta novaConta;

    std::cout << "Digite um nome de Usuario: " << std::endl;
    std::cin >> novaConta.usuarioSalva;
    std::cout << "Digite uma senha: " << std::endl;
    std::cin >> novaConta.senhaSalva;

    // Gera a chave Pix antes de salvar para nao deixar campo vazio no arquivo
    chavePixGerar(novaConta);

    // Adiciona a nova conta no vector e salva o arquivo atualizado
    contas.push_back(novaConta);
    salvarContas(contas);

    std::cout << "Conta Criada! Chave Pix gerada: " << novaConta.chavePix << std::endl;
    std::cout << "Feche e abra o banco para entrar!" << std::endl;
    }
else {
        std::cout << "Opcao invalida!" << std::endl;
        }

        return 0;


}

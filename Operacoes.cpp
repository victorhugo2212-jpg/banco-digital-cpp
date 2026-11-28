#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "Operacoes.h"
#include <random>
#include <ctime>


void chavePixGerar(Conta& contaAtual) {
    srand(static_cast<unsigned int>(time(0)));

    std::string caixa = "ABCDE12345";

    contaAtual.chavePix = "";

    for (int i = 0; i < 9; i++) {
        contaAtual.chavePix += caixa[rand() % 10];
    }
}

//vector
std::vector<Conta> carregarContas() {
    std::vector<Conta> lista;
    std::ifstream arquivo("banco_dados.text");
    Conta temp;

    while (arquivo >> temp.usuarioSalva >> temp.senhaSalva >> temp.chavePix >> temp.saldo) {
        lista.push_back(temp);
    }
    arquivo.close();
    return lista;
}

//reescrevendo vector
void salvarContas(const std::vector<Conta>& lista) {
    std::ofstream arquivo("banco_dados.text");
    for (const auto& c : lista) {
        arquivo << c.usuarioSalva << " " << c.senhaSalva << " " << c.chavePix << " " << c.saldo << "\n";
    }
    arquivo.close();
}

bool transferirPix(std::vector<Conta>& lista, int indiceOrigem, const std::string& chaveDestino, int valor) {
    if (valor <= 0 || lista[indiceOrigem].saldo < valor) {
        return false;
    }

    for (int i = 0; i < lista.size(); i++) {
        if (lista[i].chavePix == chaveDestino && i != indiceOrigem) {
            lista[indiceOrigem].saldo -= valor;
            lista[i].saldo += valor;
            return true;
        }
    }
    return false;
}

void sacarDinheiro(Conta& contaAtual) {
    int saque;
    std::cout << "Quando voce deseja sacar do seu saldo: " << std::endl;
    std::cin >> saque;
    if (saque <= 0) {
        std::cout << "Valor Invalido!" << std::endl;
    }
    else if (contaAtual.saldo < saque) {
        std::cout << "Dinheiro insuficiente!" << std::endl;
    }
    else if (contaAtual.saldo >= saque) {
        contaAtual.saldo -= saque;
        std::cout << "Saque realizado com sucesso!" << std::endl;
    }

}

void pixTransferencia(std::vector<Conta>& lista, int indiceOrigem) {
    int opcoes_transferencia;
    int saldo_transferencia;
    std::string chavePix_transferencia;

    while (true) {
        std::cout << " --TRANSFERENCIA--\n"
            << " [1] - Enviar Pix\n"
            << " [2] - Ver Chave Pix\n"
            << " [3] - Voltar" << std::endl;
        std::cin >> opcoes_transferencia;
        if (opcoes_transferencia == 1) {
            std::cout << "Digite a Chave Pix: " << std::endl;
            std::cin >> chavePix_transferencia;
            std::cout << "Digite o Valor: " << std::endl;
            std::cin >> saldo_transferencia;

            if (chavePix_transferencia == lista[indiceOrigem].chavePix) {
                std::cout << "Nao pode enviar para sua chave pix!" << std::endl;
            }
            else if (saldo_transferencia <= 0) {
                std::cout << "Valor invalido!" << std::endl;
            }
            else if (lista[indiceOrigem].saldo < saldo_transferencia) {
                std::cout << "Saldo Insuficiente!" << std::endl;
            }
            else {
                if (transferirPix(lista, indiceOrigem, chavePix_transferencia, saldo_transferencia)) {
                    salvarContas(lista);
                    std::cout << "Transferido! Valor: " << saldo_transferencia << std::endl;
                }
                else {
                    std::cout << "Chave Pix nao encontrada!" << std::endl;
                }
            }
        }
        else if (opcoes_transferencia == 2) {
            std::cout << "Chave Pix: " << lista[indiceOrigem].chavePix << std::endl;
        }
        else if (opcoes_transferencia == 3) {
            break;
        }
    }   
}

void emprestimo(Conta& contaAtual) {
    int emprestimo;
    int valor;
    while (true) {
        std::cout << "--EMPRESTIMO--\n"
            << "[1] - Emprestimo\n"
            << "[2] - Pagar divida\n"
            << "[3] - Voltar" << std::endl;
        std::cin >> emprestimo;
        switch (emprestimo) {
        case 1:
            std::cout << "Digite quanto de valor deseja ($1000 MAX): " << std::endl;
            std::cin >> valor;
            contaAtual.saldo += valor;
            valor = std::min(valor, 1000);
            std::cout << "Novo saldo: " << contaAtual.saldo << std::endl;
            std::cout << "Em 2 Messes a divida sera cobrada" << std::endl;
        case 2:
            ;
        case 3:
            ;
        case 4:
            ;
        }

    }

}

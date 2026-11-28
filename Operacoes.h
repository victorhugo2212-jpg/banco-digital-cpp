#pragma once
#include <string>
#include <vector>

struct Conta {
    std::string chavePix;
    int saldo = 500;
    std::string usuarioSalva;
    std::string senhaSalva;
};

void sacarDinheiro(Conta& contaAtual);
void chavePixGerar(Conta& contaAtual);
void pixTransferencia(std::vector<Conta>& lista, int indiceOrigem);

std::vector<Conta> carregarContas();
void salvarContas(const std::vector<Conta>& lista);
bool transferirPix(std::vector<Conta>& lista, int indiceOrigem, const std::string& chaveDestino, int valor);


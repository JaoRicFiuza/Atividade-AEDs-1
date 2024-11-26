#include <vector>
#include <string>

class Tripulante {
public:
    std::string nome;
    std::string funcao;

    Tripulante(std::string nome, std::string funcao) : nome(nome), funcao(funcao) {}
};

class Voo {
private:
    std::string data;
    std::string hora;
    std::string origem;
    std::string destino;
    double tarifa;
    std::vector<Tripulante> tripulacao;
    std::string aviao;
    bool ativo;

public:
    Voo(std::string data, std::string hora, std::string origem, std::string destino, double tarifa, std::vector<Tripulante> tripulacao, std::string aviao)
        : data(data), hora(hora), origem(origem), destino(destino), tarifa(tarifa), tripulacao(tripulacao), aviao(aviao), ativo(false) {}

    bool verificarTripulacao() {
        bool temPiloto = false;
        bool temCopiloto = false;

        for (const auto& membro : tripulacao) {
            if (membro.funcao == "piloto") {
                temPiloto = true;
            } else if (membro.funcao == "copiloto") {
                temCopiloto = true;
            }
        }

        return temPiloto && temCopiloto;
    }

    void marcarComoAtivo() {
        if (verificarTripulacao()) {
            ativo = true;
        }
    }

    void exibirInformacoes() {
        std::cout << "Data: " << data << "\nHora: " << hora << "\nOrigem: " << origem << "\nDestino: " << destino
                  << "\nTarifa: " << tarifa << "\nAviao: " << aviao << "\nAtivo: " << (ativo ? "Sim" : "Nao") << std::endl;
    }

    void adicionarTripulante(const Tripulante& novoTripulante) {
        tripulacao.push_back(novoTripulante);
    }
};

int main() {
    std::vector<Tripulante> tripulacao = {Tripulante("Joao", "piloto"), Tripulante("Maria", "copiloto")};
    Voo voo("2023-10-01", "14:00", "São Paulo", "Rio de Janeiro", 300.0, tripulacao, "Boeing 737");

    voo.marcarComoAtivo();
    voo.exibirInformacoes();

    voo.adicionarTripulante(Tripulante("Carlos", "comissario"));
    voo.exibirInformacoes();

    return 0;
}
#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Assento {
public:
    int numero;
    std::string codigoVoo;
    std::string status;

    Assento(int num, std::string codigo, std::string stat) : numero(num), codigoVoo(codigo), status(stat) {}
};

class Voo {
public:
    std::string codigoVoo;
    std::vector<Assento> assentos;

    Voo(std::string codigo) : codigoVoo(codigo) {}

    void cadastrarAssento(int numero, std::string status) {
        assentos.push_back(Assento(numero, codigoVoo, status));
    }

    void cadastrarAssentosRecursivo(int numeroInicial, int numeroFinal, std::string status) {
        if (numeroInicial > numeroFinal) {
            return;
        }
        cadastrarAssento(numeroInicial, status);
        cadastrarAssentosRecursivo(numeroInicial + 1, numeroFinal, status);
    }

    void mostrarAssentos() {
        for (const auto& assento : assentos) {
            std::cout << "Assento: " << assento.numero << ", Voo: " << assento.codigoVoo << ", Status: " << assento.status << std::endl;
        }
    }

    bool escolherAssentoLivre(int numero) {
        for (auto& assento : assentos) {
            if (assento.numero == numero && assento.status == "livre") {
                assento.status = "ocupado";
                return true;
            }
        }
        return false;
    }
};

int main() {
    Voo voo("AB0901");
    voo.cadastrarAssentosRecursivo(1, 5, "livre");
    voo.mostrarAssentos();

    int numeroAssento;
    std::cout << "Digite o numero do assento que deseja escolher: ";
    std::cin >> numeroAssento;

    if (voo.escolherAssentoLivre(numeroAssento)) {
        std::cout << "Assento " << numeroAssento << " escolhido com sucesso!" << std::endl;
    } else {
        std::cout << "Assento " << numeroAssento << " não está disponível." << std::endl;
    }

    voo.mostrarAssentos();

    return 0;
}

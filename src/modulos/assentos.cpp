#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Assento {
public:
    int numero;
    string codigoVoo;
    string status;

    Assento(int num, string codigo, string stat) : numero(num), codigoVoo(codigo), status(stat) {}
};

class Voo {
public:
    string codigoVoo;
    vector<Assento> assentos;

    Voo(string codigo) : codigoVoo(codigo) {}

    void cadastrarAssento(int numero, string status) {
        assentos.push_back(Assento(numero, codigoVoo, status));
    }

    void cadastrarAssentos(int numeroInicial, int numeroFinal, string status) {
        for (int i = numeroInicial; i <= numeroFinal; ++i) {
            cadastrarAssento(i, status);
        }
    }

    void mostrarAssentos() {
        for (const auto& assento : assentos) {
            cout << "Assento: " << assento.numero << ", Voo: " << assento.codigoVoo << ", Status: " << assento.status << endl;
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
    voo.cadastrarAssentos(1, 5, "livre");
    voo.mostrarAssentos();

    int numeroAssento;
    cout << "Digite o numero do assento que deseja escolher: ";
    cin >> numeroAssento;

    if (voo.escolherAssentoLivre(numeroAssento)) {
        cout << "Assento " << numeroAssento << " escolhido com sucesso!" << endl;
    } else {
        cout << "Assento " << numeroAssento << " não está disponível." << endl;
    }

    voo.mostrarAssentos();

    return 0;
}

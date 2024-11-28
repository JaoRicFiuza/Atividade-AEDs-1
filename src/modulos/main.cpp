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


class Reserva : public Assento {
public:
    string codigoPassageiro;

    Reserva(int num, string codigoVoo, string stat, string codigoPassageiro)
        : Assento(num, codigoVoo, stat), codigoPassageiro(codigoPassageiro) {}

    //  Verificar se um assento está disponível para reserva
    static bool verificarDisponibilidade(vector<Reserva>& reservas, string codigoVoo, int numero) {
        for (const auto& reserva : reservas) {
            if (reserva.codigoVoo == codigoVoo && reserva.numero == numero) {
                return false;  // Assento já reservado
            }
        }
        return true;  // Assento disponível
    }

    // Estático para fazer uma reserva
    static void fazerReserva(vector<Reserva>& reservas, string codigoVoo, int numero, string codigoPassageiro) {
        if (verificarDisponibilidade(reservas, codigoVoo, numero)) {
            reservas.push_back(Reserva(numero, codigoVoo, "ocupado", codigoPassageiro));
            cout << "Reserva feita com sucesso!\n";
        } else {
            cout << "Erro: O assento ja esta reservado.\n";
        }
    }
};

class Voo {
public:
    string codigoVoo;
    vector<Assento> assentos;  // Lista de assentos do voo

    Voo(string codigo) : codigoVoo(codigo) {}

    // Cadastrar um assento no voo
    void cadastrarAssento(int numero, string status) {
        assentos.push_back(Assento(numero, codigoVoo, status));
    }

    // Cadastrar múltiplos assentos no voo
    void cadastrarAssentos(int numeroInicial, int numeroFinal, string status) {
        for (int i = numeroInicial; i <= numeroFinal; ++i) {
            string stat = (i % 2 == 0) ? "ocupado" : "livre";  // Alterna entre ocupado e livre
            cadastrarAssento(i, stat);
        }
    }

    // Mostrar todos os assentos do voo
    void mostrarAssentos() {
        for (const auto& assento : assentos) {
            cout << "Assento: " << assento.numero << ", Voo: " << assento.codigoVoo << ", Status: " << assento.status << endl;
        }
    }

    // Escolher um assento livre
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
    // Cria um voo com o código "AB1234"
    Voo voo("AB1234");

    voo.cadastrarAssentos(1, 10, "livre");

    voo.mostrarAssentos();

    vector<Reserva> reservas;  // Lista de reservas

    int numeroAssento;
    string codigoPassageiro;
    bool reservaFeita = false;

    while (!reservaFeita) {
        cout << "Digite o numero do assento que deseja escolher: ";
        cin >> numeroAssento;
        cout << "Digite o codigo do passageiro: ";
        cin >> codigoPassageiro;

        // Tenta escolher um assento livre
        if (voo.escolherAssentoLivre(numeroAssento)) {
            // Faz a reserva se o assento estiver livre
            Reserva::fazerReserva(reservas, voo.codigoVoo, numeroAssento, codigoPassageiro);
            reservaFeita = true;
        } else {
            cout << "Assento " << numeroAssento << " nao esta disponivel. Tente novamente." << endl;
        }
    }

    // Mostra os assentos após a reserva
    voo.mostrarAssentos();

    return 0;
}

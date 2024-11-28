#include <iostream>
#include <string.h>
#include <locale.h>

using namespace std;

class Pessoa {
protected:
    int codigo;
    string nome;
    string endereco;
    int tel;
public:
    int getCodigo() {
        return codigo;
    }

    void setCodigo(int cod) {
        codigo = cod;
    }

    string getNome() {
        return nome;
    }

    void setNome(string n) {
        nome = n;
    }

    string getEndereco() {
        return endereco;
    }

    void setEndereco(string e) {
        endereco = e;
    }

    int getTel() {
        return tel;
    }

    void setTel(int t) {
        tel = t;
    }
};

class Passageiro : public Pessoa {
protected:
    int codPassageiro;
    bool fidelidade;
public:
    int getCodPassageiro() {
        return codPassageiro;
    }

    void setCodPassageiro(int codPass) {
        codPassageiro = codPass;
    }

    bool getFidelidade() {
        return fidelidade;
    }

    void setFidelidade(bool f) {
        fidelidade = f;
    }
};

class Tripulacao : public Pessoa {
protected:
    int cargo;
public:
    int getCargo() {
        return cargo;
    }

    void setCargo(int c) {
        cargo = c;
    }
};

class Voo {
protected:
    int codAviao;
    int codComisario;
    int codPiloto;
    int codCopiloto;
    int codVoo;
    int data;
    int hora;
    string destino;
    bool status;
    float tarifa;
public:
    int getCodAviao() {
        return codAviao;
    }

    void setCodAviao(int cod) {
        codAviao = cod;
    }

    int getCodComisario() {
        return codComisario;
    }

    void setCodComisario(int cod) {
        codComisario = cod;
    }

    int getCodPiloto() {
        return codPiloto;
    }

    void setCodPiloto(int cod) {
        codPiloto = cod;
    }

    int getCodCopiloto() {
        return codCopiloto;
    }

    void setCodCopiloto(int cod) {
        codCopiloto = cod;
    }

    int getCodVoo() {
        return codVoo;
    }

    void setCodVoo(int cod) {
        codVoo = cod;
    }

    int getData() {
        return data;
    }

    void setData(int d) {
        data = d;
    }

    int getHora() {
        return hora;
    }

    void setHora(int h) {
        hora = h;
    }

    string getDestino() {
        return destino;
    }

    void setDestino(string dest) {
        destino = dest;
    }

    bool getStatus() {
        return status;
    }

    void setStatus(bool s) {
        status = s;
    }

    float getTarifa() {
        return tarifa;
    }

    void setTarifa(float t) {
        tarifa = t;
    }
};

class Assento {
protected:
    int numAssento;
    bool status;
public:
    int getNumAssento() {
        return numAssento;
    }

    void setNumAssento(int num) {
        numAssento = num;
    }

    bool getStatus() {
        return status;
    }

    void setStatus(bool s) {
        status = s;
    }
};

class Reserva : public Passageiro, public Voo, public Assento {
protected:
public:
};

int cadastroPassageiro() {
    Passageiro p;
    string nome, endereco;
    int telefone;
    bool fidelidade;

    cout << "SEU NOME: ";
    cin >> nome;
    p.setNome(nome);

    cout << "SEU ENDERECO: ";
    cin >> endereco;
    p.setEndereco(endereco);

    cout << "SEU TELEFONE: ";
    cin >> telefone;
    p.setTel(telefone);

    cout << "GOSTARIA DE TER FIDELIDADE? (1 para sim, 0 para nao): ";
    cin >> fidelidade;
    p.setFidelidade(fidelidade);

}

int main() {
    setlocale(LC_ALL, "Portuguese");
    cadastroPassageiro();
    return 0;
}

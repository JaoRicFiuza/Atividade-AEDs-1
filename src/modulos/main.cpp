#include <iostream>
#include <string.h>
#include <random>
#include <cstdlib>
#include <ctime> 

using namespace std;
// CLASSES 
class Pessoa {
protected:
    int codigo;
    string nome;
    string endereco;
    int tel;
public: // GETTERS e SETTERS
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
public: // GETTERS e SETTERS
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
public: // GETTERS e SETTERS
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
public: // GETTERS e SETTERS
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
public: // GETTERS e SETTERS
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

// FUNÇOES PRINCIPAIS 

void cadastroPassageiro() {
    Passageiro p;
    string nome, endereco;
    int telefone;
    bool fidelidade;

    cout << "SEU NOME: ";
    getline(cin, nome);  
    p.setNome(nome);

    cout << "SEU ENDERECO: ";
    getline(cin, endereco);  
    p.setEndereco(endereco);

    cout << "SEU TELEFONE(sem espacos): ";
    cin >> telefone;
    p.setTel(telefone);

    cout << "GOSTARIA DE TER FIDELIDADE? (1 para sim, 0 para nao): ";
    cin >> fidelidade;
    p.setFidelidade(fidelidade);
 
}

void cadastroTripulacao(){
  cout <<"ENTROU";
}

void cadastroVoo(){
    cout <<"ENTROU";
}

void cadastroAssento(){
    cout <<"ENTROU";
}

void reserva(){
    cout <<"ENTROU";

}

void baixaReserva(){
    cout <<"ENTROU";
}

void pesquisa(){
    cout <<"ENTROU";

}

void programaFid(){
    cout <<"ENTROU";
}

void menu() {
    cout << "        __|__" << endl;
    cout << "--@--@--(_)--@--@--" << endl;
    cout << "\n==== MENU ====" << endl;
    cout << "1. Cadastrar Passageiro" << endl;
    cout << "2. Cadastrar Tripulacao" << endl;
    cout << "3. Cadastrar Voo" << endl;
    cout << "4. Cadastrar Assento" << endl;
    cout << "5. Realizar Reserva" << endl;
    cout << "6. Baixa em Reservas" << endl;
    cout << "7. Pesquisa" << endl;
    cout << "8. Consultar Programa de Fidelidade" << endl;
    cout << "9. Sair" << endl;
    cout << "=====================" << endl;
}



int main() {
   int op;
    while (op != 9)
    {
        menu();  
        cout << "Escolha uma opcao (1-9): ";
        cin >> op;  

        switch (op) {
            case 1:
                cadastroPassageiro();
                break;
            case 2:
                cadastroTripulacao();
                break;
            case 3:
                cadastroVoo();
                break;
            case 4:
                cadastroAssento();
                break;
            case 5:
                reserva();
                break;
            case 6:
                baixaReserva();
                break;
            case 7:
                pesquisa();
                break;
            case 8:
                programaFid();
                break;
            case 9:
                cout << "Saindo do sistema" << endl;
                return 0;  
            default:
                cout << "Opção inválida! Por favor, escolha um número entre 1 e 9." << endl;
        }
    }

    return 0;  
}
 
     
        

       




    
    


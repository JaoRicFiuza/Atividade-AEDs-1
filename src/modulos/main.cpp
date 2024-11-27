#include <iostream>
#include <string.h>
#include <fstream> //Biblioteca para manipulação de arquivos

using namespace std;

class Pessoa {
protected:
    int codigo;
    string nome;
    string endereco;
    int tel;

public:
    Pessoa() : codigo(0), tel (0) {}

    void SetDadosPessoa (int cod, string n, string end, int t) {
        codigo = cod;
        nome = n;
        endereco = end;
        tel = t;
    }

    string GetDadosPessoa() {
        return "Codigo: " + to_string(codigo) + "\nNome: " + nome + "\nEndereco: " + endereco + "\nTelefone: " + to_string(tel);
    }
};

class Passageiro : public Pessoa {
private:
    int codPassageiro;
    bool fidelidade;

public:
    Passageiro() : codPassageiro(0), fidelidade(false) {}

    void CadastrarPassageiro (int cod, string n, string end, int t, int codPass, bool fid) {
        SetDadosPessoa(cod, n, end, t);
        codPassageiro = codPass;
        fidelidade = fid;
    }

    string GetDadosPassageiro() {
        return GetDadosPessoa() + "\nCodigo Passageiro: " + to_string(codPassageiro) + "\nFidelidade: " + (fidelidade ? "Sim" : "Nao" + "\n");
    }
};

class Tripulacao : public Pessoa{
    int cargo // Piloto= 1 Copiloto= 2 Comissario= 3

    Pessoa.codigo;
    Pessoa.endereco;
    Pessoa.nome;
    Pessoa.tel;
};

class Reserva : public Passageiro , public Voo, public Assento{
    Passageiro.codPassageiro;
    Passageiro.fidelidade;
    Voo.codVoo;
    Assento.numAssento;
};

class Assento : public Reserva, public Voo{
    int numAssento;
    bool status;
    Voo.codVoo;
};

class Voo{
    int codAviao;
    int codComisario;
    int codPiloto;
    int codCopiloto;
    int codVoo;

    int data;
    int hora;
    string destino;
    float tarifa;
    
    bool status;
};

//Funções

void salvarPassageiroNoArquivo(Passageiro passageiro) {
    ofstream arquivo("passageiros.txt", ios::app); // Modo append
    if (arquivo.is_open()) {
        arquivo << passageiro.getDadosPassageiro() << "------------------\n";
        arquivo.close();
        cout << "Passageiro salvo com sucesso!" << endl;
    } else {
        cout << "Erro ao salvar passageiro!" << endl;
    }
}

int cadastroPassageiro(){
// Criar funcao para gerar Cod/ Return Codigo do passageiro
cout << "Digite o nome do passageiro:";
cin >> Passageiro.nome;
cout << "Digiteo o endereco do passageiro:";
cin >> Passageiro.endereco;
cout << "Digite o telefone do passageiro:";
cin >> Passageiro.tel;
cout << "O passageiro gostaria de participar da fidelidade de Voo: (s/n)";
cin >> Passageiro.fidelidade;
// chamar função para setar os dados da pessoa?
salvarPassageiroNoArquivo(Passageiro);
}



int main()
{
    
}


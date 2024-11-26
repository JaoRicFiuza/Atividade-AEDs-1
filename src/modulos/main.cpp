#include <iostream>
#include <string.h>

using namespace std;

class Pessoa {
    int codigo;
    string nome;
    string endereco;
    int tel;
public:
    void teste(){
        cout << "SE LEU MAMOU";
    }
};

class Passageiro : public Pessoa {
    Pessoa.codigo;
    Pessoa.endereco;
    Pessoa.nome;
    Pessoa.tel;
    int codPassageiro;
    bool fidelidade;
public:
     cadastroPassageiro()

};

class Tripulacao : public Pessoa{
    int cargo // Piloto =1 Copiloto =2 Comissario =3
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

    bool status;
    float tarifa;

};

//FUNCOES
int cadastroPassageiro(){
// Criar funcao para gerar Cod/ Return Codigo do passageiro
cout << "SEU NOME:";
cin << Passageiro.nome;

cout << "SEU ENDERECO:";
cin << Passageiro.endereco;

cout << "SEU TELEFONE:";
cin << Passageiro.tel;

cout << "GOSTARIA DE TER FIDELIDADE?:";
cin << Passageiro.fidelidade;

}



int main()
{

}

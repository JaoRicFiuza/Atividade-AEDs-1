#include <iostream>
#include <string.h>
#include <random>
#include <cstdlib>
#include <ctime>
#include <fstream>

using namespace std;
// CLASSES
class Pessoa {
protected:
    int codigo;
    string nome;
    string endereco;
    string tel;
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

    string getTel() {
        return tel;
    }

    string setTel(string t) {
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

    Assento(int num, string codigo, string stat) : numAssento(num), status(stat == "livre") {}

    static void cadastrarAssento(vector<Assento>& assentos, int numero, string status) {
        assentos.push_back(Assento(numero, "", status));
    }

    static void cadastrarAssentos(vector<Assento>& assentos, int numeroInicial, int numeroFinal, string status) {
        for (int i = numeroInicial; i <= numeroFinal; ++i) {
            cadastrarAssento(assentos, i, status);
        }
    }

    static void mostrarAssentos(const vector<Assento>& assentos) {
        for (const auto& assento : assentos) {
            cout << "Assento: " << assento.numAssento << ", Status: " << (assento.status ? "livre" : "ocupado") << endl;
        }
    }

    static bool escolherAssentoLivre(vector<Assento>& assentos, int numero) {
        for (auto& assento : assentos) {
            if (assento.numAssento == numero && assento.status) {
                assento.status = false;
                return true;
            }
        }
        return false;
    }
};

class Reserva : public Passageiro, public Voo, public Assento {
protected:
public:
};

// FUNÇOES PRINCIPAIS

// Função para criar códigos sequenciais de passageiros
int gerarCodigo() {
    ifstream arquivoEntrada("codigos_passageiros.txt");
    ofstream arquivoSaida;
    int ultimoCodigo = 0;

    // Lê o último código do arquivo, se existir
    if (arquivoEntrada.is_open()) {
        arquivoEntrada >> ultimoCodigo;
        arquivoEntrada.close();
    }

    // Incrementa o código
    int novoCodigo = ultimoCodigo + 1;

    // Salva o novo código no arquivo
    arquivoSaida.open("codigos_passageiros.txt", ios::trunc); // Sobrescreve o arquivo
    if (arquivoSaida.is_open()) {
        arquivoSaida << novoCodigo;
        arquivoSaida.close();
    }

    return novoCodigo;
}

// Função para salvar as informações do passageiro no arquivo
void salvarPassageiroNoArquivo(Passageiro& p) {
    ofstream arquivo("passageiros.txt", ios::app); // Modo append
    if (arquivo.is_open()) {
        arquivo << "Codigo do Passageiro: " << p.getCodPassageiro() << endl;
        arquivo << "Nome: " << p.getNome() << endl;
        arquivo << "Endereco: " << p.getEndereco() << endl;
        arquivo << "Telefone: " << p.getTel() << endl;
        arquivo << "Fidelidade: " << (p.getFidelidade() ? "Sim" : "Nao") << endl;
        arquivo << "-------------------------" << endl;
        arquivo.close();
        cout << "Passageiro salvo com sucesso!" << endl;
    } else {
        cout << "Erro ao abrir o arquivo para salvar!" << endl;
    }
}

void cadastroPassageiro() {
    Passageiro p; // Criando um objeto Passageiro

    string nome, endereco;
    string telefone;
    char fidelidadeChar; // Para capturar entrada do usuário
    bool fidelidade;     // Valor booleano derivado da entrada

    // Entrada de dados
    cout << "Digite o nome do passageiro: ";
    cin.ignore(); // Ignorar o buffer
    getline(cin, nome);

    cout << "Digite o endereco do passageiro: ";
    getline(cin, endereco);

    cout << "Digite o telefone do passageiro: ";
    cin >> telefone;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    cout << "O passageiro deseja participar do programa de fidelidade? (s/n): ";
    cin >> fidelidadeChar;

    // Converte 's' ou 'n' em valor booleano
    fidelidade = (fidelidadeChar == 's' || fidelidadeChar == 'S');

    // Geração do código único para o passageiro
    int CodPassageiro;

    // Configurando os atributos do passageiro
    p.setCodPassageiro(CodPassageiro);
    p.setNome(nome);
    p.setEndereco(endereco);
    p.setTel(telefone);
    p.setFidelidade(fidelidade);

    // Exibindo os dados cadastrados
    cout << "\nPassageiro cadastrado com sucesso!\n";
    cout << "Codigo do Passageiro: " << p.getCodPassageiro() << endl;
    cout << "Nome: " << p.getNome() << endl;
    cout << "Endereco: " << p.getEndereco() << endl;
    cout << "Telefone: " << p.getTel() << endl;
    cout << "Fidelidade: " << (p.getFidelidade() ? "Sim" : "Nao") << endl << endl;
}
void cadastroTripulacao(){
  Tripulacao t;
    string nome, endereco, telefone;
    int cargo;

    cout << "SEU NOME: ";
    getline(cin, nome);
    t.setNome(nome);cin.ignore(numeric_limits<streamsize>::max(), '\n');

    cout << "SEU ENDERECO: ";
    getline(cin, endereco);
    t.setEndereco(endereco);cin.ignore(numeric_limits<streamsize>::max(), '\n');

    cout << "SEU TELEFONE(sem espacos): ";
    cin >> telefone;
    t.setTel(telefone);cin.ignore(numeric_limits<streamsize>::max(), '\n');

    cout << "SEU CARGO 1- PILOTO 2-COPILOTO 3-COMISSARIO:";
    cin >>cargo;
    t.setCargo(cargo);
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
    cout << "        |" << endl;
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

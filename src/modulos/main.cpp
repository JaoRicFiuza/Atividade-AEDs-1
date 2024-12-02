#include <iostream>
#include <string.h>
#include <random>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <vector>


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

    void setTel(string t) {
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
    string data;
    string hora;
    string destino, origem;
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

    string getData() {
        return data;
    }

    void setData(string d) {
        data = d;
    }

    string getHora() {
        return hora;
    }

    void setHora(string h) {
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

    string getOrigem(){
        return origem;
    }

    void setOrigem(string o){
        origem = o;
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

// Função para criar códigos sequenciais de passageiros
int gerarCodigoPassageiro() {
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
// Finção para cadastrar passageiro
void cadastroPassageiro() {
    vector<Passageiro> p; // Criando um vetor do objeto passageiro

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
    getline(cin, telefone);


    cout << "O passageiro deseja participar do programa de fidelidade? (s/n): ";
    cin >> fidelidadeChar;

    // Converte 's' ou 'n' em valor booleano
    fidelidade = (fidelidadeChar == 's' || fidelidadeChar == 'S');

    // Geração do código único para o passageiro
    int CodPassageiro = gerarCodigoPassageiro();

    // Configurando os atributos do passageiro

    Passageiro novoPassageiro; // Instanciando um novo objeto
    novoPassageiro.setCodPassageiro(CodPassageiro);
    novoPassageiro.setNome(nome);
    novoPassageiro.setEndereco(endereco);
    novoPassageiro.setTel(telefone);
    novoPassageiro.setFidelidade(fidelidade);

    p.push_back(novoPassageiro); // Adiciona um novo objeto no vetor

    // Exibindo os dados cadastrados
    cout << "\nPassageiro cadastrado com sucesso!\n";
    cout << "Codigo do Passageiro: " << novoPassageiro.getCodPassageiro() << endl;
    cout << "Nome: " << novoPassageiro.getNome() << endl;
    cout << "Endereco: " << novoPassageiro.getEndereco() << endl;
    cout << "Telefone: " << novoPassageiro.getTel() << endl;
    cout << "Fidelidade: " << (novoPassageiro.getFidelidade() ? "Sim" : "Nao") << endl << endl;

    salvarPassageiroNoArquivo(novoPassageiro);
}
// Função para salvar as informações do passageiro no arquivo
void salvarTripulacaoNoArquivo(Tripulacao& t){
    ofstream arquivo("tripulacao.txt", ios::app); // Modo append
    if (arquivo.is_open()) {
        arquivo << "Codigo do Tripulante: " << t.getCodigo() << endl;
        arquivo << "Nome: " << t.getNome() << endl;
        arquivo << "Endereco: " << t.getEndereco() << endl;
        arquivo << "Telefone: " << t.getTel() << endl;
        arquivo << "Cargo: " << t.getCargo() << endl;
        arquivo << "-------------------------" << endl;
        arquivo.close();
        cout << "Tripulante salvo com sucesso!" << endl;
    } else {
        cout << "Erro ao abrir o arquivo para salvar!" << endl;
    }

}
// Função para criar códigos sequenciais de passageiros
int gerarCodigoTripulante(){
    ifstream arquivoEntrada("codigos_tripulante.txt");
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
    arquivoSaida.open("codigos_tripulante.txt", ios::trunc); // Sobrescreve o arquivo
    if (arquivoSaida.is_open()) {
        arquivoSaida << novoCodigo;
        arquivoSaida.close();
    }

    return novoCodigo;

}
 vector<Tripulacao> t;
void cadastroTripulacao(){

  string nome, endereco, telefone;
  int cargo, cod;
    // Entrada de dados
    cout << "Digite o nome do tripulante: ";
    cin.ignore(); // Ignorar o buffer
    getline(cin, nome);

    cout << "Digite o endereco do tripulante: ";
    getline(cin, endereco);

    cout << "Digite o telefone do tripulante: ";
    getline(cin, telefone);

    do {
        cout << "Digite seu cargo (1-Piloto(a) 2-Copiloto(a) 3-Comissario(a)): ";
        cin >> cargo;
        if (cargo < 1 || cargo > 3) {
            cout << "Cargo inválido. Tente novamente.\n";
            }
        }while (cargo < 1 || cargo > 3);

    cod = gerarCodigoTripulante();

    Tripulacao novoTripulante;
    novoTripulante.setNome(nome);
    novoTripulante.setEndereco(endereco);
    novoTripulante.setTel(telefone);
    novoTripulante.setCargo(cargo);
    novoTripulante.setCodigo(cod);

    t.push_back(novoTripulante);

    salvarTripulacaoNoArquivo(novoTripulante);
    cout << "\Tripulante cadastrado com sucesso!\n";
    cout << "Codigo do Tripulante: " << novoTripulante.getCodigo() << endl;
    cout << "Nome: " << novoTripulante.getNome() << endl;
    cout << "Endereco: " << novoTripulante.getEndereco() << endl;
    cout << "Telefone: " << novoTripulante.getTel() << endl;
}

// Funçao para verificar os codigos dos comissarios
bool verificarCodigoTripulacao(int cod){
    for(int i=0; i<t.size();i++){
        if (t[i].getCodigo() == cod){
            return true;
        }
    }
return false;
}
vector <Voo> v;
void cadastroVoo(){

    int codAviao,codComisario,codPiloto,codCopiloto,codVoo;
    string data,hora,destino,origem;
    bool status;
    float tarifa;

    cout << "Digite a origem do Voo: ";
    cin.ignore(); // Ignorar o buffer
    getline(cin, origem);

    cout << "Digite o destino do Voo: ";
    cin.ignore(); // Ignorar o buffer
    getline(cin, destino);

    cout << "Digite a data do Voo: ";
    cin.ignore(); // Ignorar o buffer
    getline(cin, data);

    cout << "Digite a hora do Voo: ";
    cin.ignore(); // Ignorar o buffer
    getline(cin, hora);

    cout << "Digite a tarifa do Voo: ";
    cin >>tarifa;



    do{
        cout << "Digite o Codigo do Piloto(a): ";
        cin >>codPiloto;
        if(!verificarCodigoTripulacao(codPiloto)){
        cout<<"Piloto Nao Encontrado, tente novamente: "<<endl;
    }}while(!verificarCodigoTripulacao(codPiloto));
    cout <<"Piloto adicionada com sucesso a Tripulacao!"<<endl;

    do{
        cout << "Digite o Codigo do Copiloto(a): ";
        cin >>codCopiloto;
    if(!verificarCodigoTripulacao(codCopiloto)){
        cout<<"Copiloto Nao Encontrado, tente novamente: "<<endl;
    }}while(!verificarCodigoTripulacao(codCopiloto));
        cout <<"Copiloto adicionada com sucesso a Tripulacao!"<<endl;

    do{
        cout << "Digite o Codigo do Comissario(a): ";
        cin >>codComisario;
    if(!verificarCodigoTripulacao(codComisario)){
        cout<<"Comissario Nao Encontrado, tente novamente: "<<endl;
        }
    }while(!verificarCodigoTripulacao(codComisario));
        cout <<"Comisasario adicionado com sucesso a Tripulacao!"<<endl;

    cout <<"Voo registrado com sucesso: "<<endl;

    Voo novosVos;
    novosVos.setOrigem(origem);
    novosVos.setDestino(destino);
    novosVos.setData(data);
    novosVos.setHora(hora);
    novosVos.setTarifa(tarifa);
    novosVos.setCodVoo(codAviao);
    novosVos.setCodPiloto(codPiloto);
    novosVos.setCodCopiloto(codCopiloto);
    novosVos.setCodComisario(codComisario);

    v.push_back(novosVos);

}

bool verificarCodigoVoo(int cod){
    for(int i=0; i<v.size();i++){
        if (v[i].getCodVoo() == cod){
            return true;
        }
    }
return false;
}
void criarAssento () {
    // Criando os assentos
        for (int i = 0; i < assentos; i++) {
            Assento novoAssento;
            novoAssento.setNumAssento(i + 1);  // Atribuindo um número sequencial para cada assento
            novoAssento.setStatus(false);  // Supondo que todos os assentos começam como não ocupados

            listaAssentos.push_back(novoAssento);  // Adicionando o assento à lista
        }
}


// Função para cadastrar assentos
void cadastroAssento() {
    int cod;
    int assentos;

    cout << "Digite o codigo do voo: ";
    cin >> cod;
    if (verificarCodigoVoo(cod)) {
        vector<Assento> listaAssentos; // Vetor de assentos para o voo

        cout << "Escreva a quantidade de assentos que deseja cadastrar: " << endl;
        cin >> assentos;
    }
    criarAssento()
}


void reserva(){

    /*cout << "Digite o codigo do voo que deseja reservar um assento: " << endl;

    int numerodeassentos;

    // printar na tela quantos assentos estão disponiveis:
    cout <<"Quantos assentos deseja selecionar: ";
    cin >> numerodeassentos;

    for (int i = 0; i < numerodeassentos) {
        cout << "Digite o numero do assento:";
        // (if) verificar se assento esta ocupado ou não
        //se estiver livre printar
    }*/
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
    cout << "         |" << endl;
    cout << "--@--@--(_)--@--@--" << endl;
    cout << "\n==== MENU ==========" << endl;
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

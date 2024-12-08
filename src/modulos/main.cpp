#include <iostream>
#include <string.h>
#include <random>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <vector>
#include <unordered_set>

using namespace std;
// CLASSES
class Pessoa
{
protected:
    int codigo;
    string nome;
    string endereco;
    string tel;

public: // GETTERS e SETTERS
    int getCodigo()
    {
        return codigo;
    }

    void setCodigo(int cod)
    {
        codigo = cod;
    }

    string getNome()
    {
        return nome;
    }

    void setNome(string n)
    {
        nome = n;
    }

    string getEndereco()
    {
        return endereco;
    }

    void setEndereco(string e)
    {
        endereco = e;
    }

    string getTel()
    {
        return tel;
    }

    void setTel(string t)
    {
        tel = t;
    }
};

class Passageiro : public Pessoa
{
protected:
    int codPassageiro;
    bool fidelidade;

public: // GETTERS e SETTERS
    int getCodPassageiro()
    {
        return codPassageiro;
    }

    void setCodPassageiro(int codPass)
    {
        codPassageiro = codPass;
    }

    bool getFidelidade()
    {
        return fidelidade;
    }

    void setFidelidade(bool f)
    {
        fidelidade = f;
    }
};

class Tripulacao : public Pessoa
{
protected:
    int cargo;

public: // GETTERS e SETTERS
    int getCargo()
    {
        return cargo;
    }

    void setCargo(int c)
    {
        cargo = c;
    }
};

class Voo
{
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
    int getCodAviao()
    {
        return codAviao;
    }

    void setCodAviao(int cod)
    {
        codAviao = cod;
    }

    int getCodComisario()
    {
        return codComisario;
    }

    void setCodComisario(int cod)
    {
        codComisario = cod;
    }

    int getCodPiloto()
    {
        return codPiloto;
    }

    void setCodPiloto(int cod)
    {
        codPiloto = cod;
    }

    int getCodCopiloto()
    {
        return codCopiloto;
    }

    void setCodCopiloto(int cod)
    {
        codCopiloto = cod;
    }

    int getCodVoo()
    {
        return codVoo;
    }

    void setCodVoo(int cod)
    {
        codVoo = cod;
    }

    string getData()
    {
        return data;
    }

    void setData(string d)
    {
        data = d;
    }

    string getHora()
    {
        return hora;
    }

    void setHora(string h)
    {
        hora = h;
    }

    string getDestino()
    {
        return destino;
    }

    void setDestino(string dest)
    {
        destino = dest;
    }

    bool getStatus()
    {
        return status;
    }

    void setStatus(bool s)
    {
        status = s;
    }

    float getTarifa()
    {
        return tarifa;
    }

    void setTarifa(float t)
    {
        tarifa = t;
    }

    string getOrigem()
    {
        return origem;
    }

    void setOrigem(string o)
    {
        origem = o;
    }
};

class Assento
{
protected:
    int numAssento;
    bool status;

public: // GETTERS e SETTERS
    int getNumAssento()
    {
        return numAssento;
    }

    void setNumAssento(int num)
    {
        numAssento = num;
    }

    bool getStatus()
    {
        return status;
    }

    void setStatus(bool s)
    {
        status = s;
    }
};

class Reserva : public Passageiro, public Voo, public Assento
{
protected:
    int codReserva;

public:
    int getCodReserva()
    {
        return codReserva;
    }

    void setCodReserva(int cod)
    {
        codReserva = cod;
    }
};
// Funções Basicas
void erroArquivo()
{
    cout << "Erro ao abrir o arquivo para salvar!" << endl;
}
void registradoArquivo()
{
    cout << "Salvo com sucesso!" << endl;
}
bool buscaArquivo(string nomeArquivo, string codBusca)
{
    ifstream arquivo(nomeArquivo + ".txt"); // Abre o arquivo
    string linha;
    string busca = codBusca; // O que você quer buscar
    bool encontrado = false;

    if (arquivo.is_open())
    {
        while (std::getline(arquivo, linha))
        { // Lê o arquivo linha por linha
            if (linha.find(busca) != string::npos)
            { // Busca pela palavra
                cout << "Encontrado: " << linha << endl;
                encontrado = true;
                break; // Opcional: para após encontrar
            }
        }
        arquivo.close(); // Fecha o arquivo
    }
    else
    {
        erroArquivo();
    }

    if (!encontrado)
    {
        cout << "Dado não encontrado." << endl;
    }
    return encontrado;
}
// FUNÇOES PRINCIPAIS
// Funçoes para Salvar no arquivo.txt

void salvarPassageiroNoArquivo(Passageiro &p)
{
    ofstream arquivo("passageiros.txt", ios::app); // Modo append
    if (arquivo.is_open())
    {
        arquivo << "Codigo do Passageiro: " << p.getCodPassageiro() << endl;
        arquivo << "Nome: " << p.getNome() << endl;
        arquivo << "Endereco: " << p.getEndereco() << endl;
        arquivo << "Telefone: " << p.getTel() << endl;
        arquivo << "Fidelidade: " << (p.getFidelidade() ? "Sim" : "Nao") << endl;
        arquivo << "-------------------------" << endl;
        arquivo.close();
        registradoArquivo();
    }
    else
    {
        erroArquivo();
    }
}
void salvarTripulacaoNoArquivo(Tripulacao &t)
{
    ofstream arquivo("tripulacao.txt", ios::app); // Modo append
    if (arquivo.is_open())
    {
        arquivo << "Codigo do Tripulante: " << t.getCodigo() << endl;
        arquivo << "Nome: " << t.getNome() << endl;
        arquivo << "Endereco: " << t.getEndereco() << endl;
        arquivo << "Telefone: " << t.getTel() << endl;
        arquivo << "Cargo: " << (t.getCargo() == 1 ? "Piloto(a)" : (t.getCargo() == 2 ? "Copiloto(a)" : "Comissario(a)")) << endl;
        arquivo << "-------------------------" << endl;
        arquivo.close();
        registradoArquivo();
    }
    else
    {
        // Adicionando mensagens de erro
        erroArquivo();
        if (arquivo.fail())
        {
            cout << "Erro específico ao tentar abrir o arquivo!" << endl;
        }
    }
}
void salvarVooNoArquivo(Voo &v)
{
    ofstream arquivo("voo.txt", ios::app); // Modo append
    if (arquivo.is_open())
    {
        arquivo << "Codigo do Voo: " << v.getCodVoo() << endl;
        arquivo << "Data do Voo: " << v.getData() << endl;
        arquivo << "Hora do Voo: " << v.getHora() << endl;
        arquivo << "Origem do Voo: " << v.getOrigem() << endl;
        arquivo << "Destino do Voo: " << v.getDestino() << endl;
        arquivo << "Codigo do Avião: " << v.getCodAviao() << endl;
        arquivo << "Codigo do Piloto: " << v.getCodPiloto() << endl;
        arquivo << "Codigo do Copiloto: " << v.getCodCopiloto() << endl;
        arquivo << "Codigo do Comissario(a): " << v.getCodComisario() << endl;
        arquivo << "Status do Voo: " << (v.getStatus() == true ? "Ativo" : (v.getStatus() == false ? "Inativo" : "Erro")) << endl;
        arquivo << "Tarifa do Voo: " << v.getTarifa() << endl;
        arquivo << "-------------------------" << endl;
        arquivo.close();
        registradoArquivo();
    }
    else
    {
        erroArquivo();
    }
}

void salvarReservaNoArquivo(Reserva &r)
{
    ofstream arquivo("reservas.txt", ios::app); // Modo append
    if (arquivo.is_open())
    {
        arquivo << "Codigo da Reserva: " << r.getCodReserva() << endl;
        arquivo << "Codigo do Passageiro: " << r.getCodPassageiro() << endl;
        arquivo << "Codigo do Voo: " << r.getCodVoo() << endl;
        arquivo << "Numero do Assento: " << r.getNumAssento() << endl;
        arquivo << "-------------------------" << endl;
        arquivo.close();
        registradoArquivo();
    }
    else
    {
        erroArquivo();
    }
}

// Funçoes para gerar codigos
int gerarCodigoPassageiro()
{
    ifstream arquivoEntrada("codigos_passageiros.txt");
    ofstream arquivoSaida;
    int ultimoCodigo = 0;

    // Lê o último código do arquivo, se existir
    if (arquivoEntrada.is_open())
    {
        arquivoEntrada >> ultimoCodigo;
        arquivoEntrada.close();
    }

    // Incrementa o código
    int novoCodigo = ultimoCodigo + 1;

    // Salva o novo código no arquivo
    arquivoSaida.open("codigos_passageiros.txt", ios::trunc); // Sobrescreve o arquivo
    if (arquivoSaida.is_open())
    {
        arquivoSaida << novoCodigo;
        arquivoSaida.close();
    }

    return novoCodigo;
}
int gerarCodigoTripulante()
{
    ifstream arquivoEntrada("codigos_tripulante.txt");
    ofstream arquivoSaida;
    int ultimoCodigo = 0;
    unordered_set<int> codigosExistentes;

    // Tenta ler os códigos do arquivo e verificar se o novo código é único
    if (arquivoEntrada.is_open())
    {
        // Lê todos os códigos no arquivo e armazena no conjunto para verificação de duplicatas
        int codigo;
        while (arquivoEntrada >> codigo)
        {
            codigosExistentes.insert(codigo); // Armazena todos os códigos no conjunto
        }
        arquivoEntrada.close();
    }

    // Incrementa o código até que ele seja único
    int novoCodigo = ultimoCodigo + 1;
    while (codigosExistentes.find(novoCodigo) != codigosExistentes.end())
    {
        novoCodigo++; // Incrementa o código até encontrar um único
    }

    // Salva o novo código no arquivo
    arquivoSaida.open("codigos_tripulante.txt", ios::out | ios::app); // Abre para sobrescrever ou adicionar
    if (arquivoSaida.is_open())
    {
        arquivoSaida << novoCodigo << endl; // Adiciona o novo código ao final do arquivo
        arquivoSaida.close();
        cout << "Novo código de tripulante gerado: " << novoCodigo << endl;
    }
    else
    {
        cout << "Erro ao abrir o arquivo para salvar o código!" << endl;
    }

    return novoCodigo;
}
int gerarCodigoVoo()
{
    ifstream arquivoEntrada("codigos_Voo.txt");
    ofstream arquivoSaida;
    int ultimoCodigo = 0;

    // Lê o último código do arquivo, se existir
    if (arquivoEntrada.is_open())
    {
        arquivoEntrada >> ultimoCodigo;
        arquivoEntrada.close();
    }

    // Incrementa o código
    int novoCodigo = ultimoCodigo + 1;

    // Salva o novo código no arquivo
    arquivoSaida.open("codigos_Voo.txt", ios::app);
    if (arquivoSaida.is_open())
    {
        arquivoSaida << novoCodigo;
        arquivoSaida.close();
    }

    return novoCodigo;
}

int gerarCodigoReserva()
{
    ifstream arquivoEntrada("codigos_reservas.txt");
    ofstream arquivoSaida;
    int ultimoCodigo = 0;

    // Lê o último código do arquivo, se existir
    if (arquivoEntrada.is_open())
    {
        arquivoEntrada >> ultimoCodigo;
        arquivoEntrada.close();
    }

    // Incrementa o código
    int novoCodigo = ultimoCodigo + 1;

    // Salva o novo código no arquivo
    arquivoSaida.open("codigos_reservas.txt", ios::trunc); // Sobrescreve o arquivo
    if (arquivoSaida.is_open())
    {
        arquivoSaida << novoCodigo;
        arquivoSaida.close();
    }

    return novoCodigo;
}

// Funçoes para a verificaçao de Codigo
bool verificarCodigoTripulacao(const string &arquivoNome, int codTripulacao)
{
    ifstream arquivo(arquivoNome); // Abre o arquivo com os códigos de tripulantes
    int codigo;

    // Verifica se o arquivo foi aberto corretamente
    if (!arquivo.is_open())
    {
        erroArquivo();
        return false;
    }

    // Lê os códigos de tripulantes do arquivo e compara com o código fornecido
    while (arquivo >> codigo)
    {
        if (codigo == codTripulacao)
        {
            arquivo.close(); // Fecha o arquivo após encontrar o código
            return true;     // Código encontrado
        }
    }

    arquivo.close(); // Fecha o arquivo se não encontrar o código
    return false;    // Retorna falso se não encontrar o código
}
bool verificarCodigosVoo(const string &arquivoNome, int codVoo)
{
    ifstream arquivo(arquivoNome); // Abre o arquivo com os códigos de tripulantes
    int codigo;

    // Verifica se o arquivo foi aberto corretamente
    if (!arquivo.is_open())
    {
        erroArquivo();
        return false;
    }

    // Lê os códigos de tripulantes do arquivo e compara com o código fornecido
    while (arquivo >> codigo)
    {
        if (codigo == codVoo)
        {
            arquivo.close(); // Fecha o arquivo após encontrar o código
            return true;     // Código encontrado
        }
    }

    arquivo.close(); // Fecha o arquivo se não encontrar o código
    return false;    // Retorna falso se não encontrar o código
}

// Funções de cadastros
vector<Passageiro> p;
void cadastroPassageiro()
{
    // Criando um vetor do objeto passageiro

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
    cout << "Fidelidade: " << (novoPassageiro.getFidelidade() ? "Sim" : "Nao") << endl
         << endl;

    salvarPassageiroNoArquivo(novoPassageiro);
}

vector<Tripulacao> t;
void cadastroTripulacao()
{

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

    do
    {
        cout << "Digite seu cargo (1-Piloto(a) 2-Copiloto(a) 3-Comissario(a)): ";
        cin >> cargo;
        if (cargo < 1 || cargo > 3)
        {
            cout << "Cargo inválido. Tente novamente.\n";
        }
    } while (cargo < 1 || cargo > 3);

    cod = gerarCodigoTripulante();

    Tripulacao novoTripulante;
    novoTripulante.setNome(nome);
    novoTripulante.setEndereco(endereco);
    novoTripulante.setTel(telefone);
    novoTripulante.setCargo(cargo);
    novoTripulante.setCodigo(cod);

    t.push_back(novoTripulante);

    salvarTripulacaoNoArquivo(novoTripulante);
    cout << "Tripulante cadastrado com sucesso!\n";
    cout << "Codigo do Tripulante: " << novoTripulante.getCodigo() << endl;
    cout << "Nome: " << novoTripulante.getNome() << endl;
    cout << "Endereco: " << novoTripulante.getEndereco() << endl;
    cout << "Telefone: " << novoTripulante.getTel() << endl;
}

vector<Voo> v;
void cadastroVoo()
{

    int codAviao, codComisario, codPiloto, codCopiloto, codVoo;
    string data, hora, destino, origem;
    bool status;
    float tarifa;

    cout << "Digite a origem do Voo: ";
    cin.ignore(); // Ignorar o buffer
    getline(cin, origem);

    cout << "Digite o destino do Voo: ";
    getline(cin, destino);

    cout << "Digite a data do Voo: ";
    getline(cin, data);

    cout << "Digite a hora do Voo: ";
    getline(cin, hora);

    cout << "Digite a tarifa do Voo: ";
    cin >> tarifa;

    do
    {
        cout << "Digite o Codigo do Piloto(a): ";
        cin >> codPiloto;
        if (verificarCodigoTripulacao("codigos_tripulante.txt", codPiloto) != true)
        {
            cout << "Piloto Nao Encontrado, tente novamente: " << endl;
        }
    } while (verificarCodigoTripulacao("codigos_tripulante.txt", codPiloto) == false);
    cout << "Piloto adicionada com sucesso a Tripulacao!" << endl;

    do
    {
        cout << "Digite o Codigo do Copiloto(a): ";
        cin >> codCopiloto;
        if (verificarCodigoTripulacao("codigos_tripulante.txt", codCopiloto) != true)
        {
            cout << "Copiloto Nao Encontrado, tente novamente: " << endl;
        }
    } while (verificarCodigoTripulacao("codigos_tripulante.txt", codCopiloto) == false);
    cout << "Copiloto adicionada com sucesso a Tripulacao!" << endl;

    do
    {
        cout << "Digite o Codigo do Comissario(a): ";
        cin >> codComisario;
        if (verificarCodigoTripulacao("codigos_tripulante.txt", codComisario) != true)
        {
            cout << "Comissario Nao Encontrado, tente novamente: " << endl;
        }
    } while (verificarCodigoTripulacao("codigos_tripulante.txt", codComisario) == false);
    cout << "Comissario adicionado com sucesso a Tripulacao!" << endl;

    cout << "Voo registrado com sucesso: " << endl;

    codVoo = gerarCodigoVoo();

    Voo novosVos;
    novosVos.setOrigem(origem);
    novosVos.setDestino(destino);
    novosVos.setData(data);
    novosVos.setHora(hora);
    novosVos.setTarifa(tarifa);
    novosVos.setCodVoo(codVoo);
    novosVos.setCodPiloto(codPiloto);
    novosVos.setCodCopiloto(codCopiloto);
    novosVos.setCodComisario(codComisario);

    v.push_back(novosVos);
    salvarVooNoArquivo(novosVos);

    cout << "Numero do seu Voo e: " << novosVos.getCodVoo();
}

void criarAssento(int assentos, vector<Assento> &listaAssentos)
{
    // Criando os assentos
    for (int i = 0; i < assentos; i++)
    {
        Assento novoAssento;
        novoAssento.setNumAssento(i + 1); // Atribuindo um número sequencial para cada assento
        novoAssento.setStatus(false);     // Supondo que todos os assentos começam como não ocupados

        listaAssentos.push_back(novoAssento); // Adicionando o assento à lista
    }
}

bool verificarCodigo(const string &arquivoNome, int codigo)
{
    ifstream arquivo(arquivoNome);
    int codigoLido;

    if (!arquivo.is_open())
    {
        erroArquivo();
        return false;
    }

    while (arquivo >> codigoLido)
    {
        if (codigoLido == codigo)
        {
            return true;
        }
    }

    return false;
}

// Função para cadastrar assentos
void cadastroAssento()
{
    int codVoo, assentos;
    vector<Assento> listaAssentos;

    cout << "Digite o código do voo: ";
    cin >> codVoo;

    if (!verificarCodigo("codigos_Voo.txt", codVoo))
    {
        cout << "Voo não registrado. Tente novamente." << endl;
        return;
    }

    cout << "Digite a quantidade de assentos: ";
    cin >> assentos;

    criarAssento(assentos, listaAssentos);

    // Aqui você deveria salvar os assentos em arquivo ou associá-los ao voo
    cout << "Assentos cadastrados com sucesso!" << endl;
}

void reserva()
{
    int codPassageiro, codVoo, numAssento;
    bool passageiroEncontrado = false, vooEncontrado = false, assentoDisponivel = false;

    cout << "\n--- CADASTRO DE RESERVA ---\n";

    // Solicitar o código do passageiro
    cout << "Digite o código do passageiro: ";
    cin >> codPassageiro;

    if (!verificarCodigo("codigos_passageiros.txt", codPassageiro))
    {
        cout << "Passageiro não encontrado! Tente novamente.\n";
        return;
    }

    // Solicitar o código do voo
    cout << "Digite o código do voo: ";
    cin >> codVoo;

    if (!verificarCodigo("codigos_Voo.txt", codVoo))
    {
        cout << "Voo não encontrado! Tente novamente.\n";
        return;
    }

    // Solicitar o número do assento
    cout << "Digite o número do assento: ";
    cin >> numAssento;

    // Aqui você deveria verificar se o assento está disponível
    // Para simplificação, vamos assumir que o assento está disponível

    // Geração do código único para a reserva
    int codReserva = gerarCodigoReserva();

    // Configurando os atributos da reserva
    Reserva novaReserva;
    novaReserva.setCodReserva(codReserva);
    novaReserva.setCodPassageiro(codPassageiro);
    novaReserva.setCodVoo(codVoo);
    novaReserva.setNumAssento(numAssento);

    // Salvar a reserva no arquivo
    salvarReservaNoArquivo(novaReserva);

    cout << "\nReserva cadastrada com sucesso!\n";
    cout << "Codigo da Reserva: " << novaReserva.getCodReserva() << endl;
    cout << "Codigo do Passageiro: " << novaReserva.getCodPassageiro() << endl;
    cout << "Codigo do Voo: " << novaReserva.getCodVoo() << endl;
    cout << "Numero do Assento: " << novaReserva.getNumAssento() << endl;
}

void baixaReserva()
{
    int codReserva;
    cout << "Digite o código da reserva para dar baixa: ";
    cin >> codReserva;

    ifstream arquivoEntrada("reservas.txt");
    ofstream arquivoSaida("reservas_temp.txt");
    string linha;
    bool reservaEncontrada = false;

    if (arquivoEntrada.is_open() && arquivoSaida.is_open())
    {
        while (getline(arquivoEntrada, linha))
        {
            if (linha.find("Codigo da Reserva: " + to_string(codReserva)) != string::npos)
            {
                reservaEncontrada = true;
                // Pular as próximas 4 linhas (dados da reserva)
                for (int i = 0; i < 4; ++i)
                {
                    getline(arquivoEntrada, linha);
                }
            }
            else
            {
                arquivoSaida << linha << endl;
            }
        }
        arquivoEntrada.close();
        arquivoSaida.close();

        remove("reservas.txt");
        rename("reservas_temp.txt", "reservas.txt");

        if (reservaEncontrada)
        {
            cout << "Reserva de código " << codReserva << " baixada com sucesso!" << endl;
        }
        else
        {
            cout << "Reserva não encontrada." << endl;
        }
    }
    else
    {
        erroArquivo();
    }
}

void pesquisa()
{
    int op;
    cout << "Escolha o que deseja pesquisar:" << endl;
    cout << "1. Pesquisar Passageiro" << endl;
    cout << "2. Pesquisar Tripulante" << endl;
    cout << "Digite sua opção: ";
    cin >> op;

    if (op == 1)
    {
        string codBusca;
        cout << "Digite o código do passageiro: ";
        cin >> codBusca;
        buscaArquivo("passageiros", codBusca);
    }
    else if (op == 2)
    {
        string codBusca;
        cout << "Digite o código do tripulante: ";
        cin >> codBusca;
        buscaArquivo("tripulacao", codBusca);
    }
    else
    {
        cout << "Opção inválida!" << endl;
    }
}

void programaFid()
{
    ifstream arquivo("passageiros.txt");
    string linha;
    bool fidelidadeEncontrada = false;

    if (arquivo.is_open())
    {
        while (getline(arquivo, linha))
        {
            if (linha.find("Fidelidade: Sim") != string::npos)
            {
                fidelidadeEncontrada = true;
                cout << "-------------------------" << endl;
                cout << linha << endl;
                // Exibir as próximas 4 linhas (dados do passageiro)
                for (int i = 0; i < 4; ++i)
                {
                    getline(arquivo, linha);
                    cout << linha << endl;
                }
            }
        }
        arquivo.close();

        if (!fidelidadeEncontrada)
        {
            cout << "Nenhum passageiro encontrado no programa de fidelidade." << endl;
        }
    }
    else
    {
        erroArquivo();
    }
}

void menu()
{
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
int main()
{
    int op = 0;
    while (op != 9)
    {
        menu();
        cout << "Escolha uma opcao (1-9): ";
        cin >> op;

        switch (op)
        {
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
}
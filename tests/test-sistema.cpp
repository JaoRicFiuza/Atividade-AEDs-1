#include <iostream>
#include <string.h>
#include <random>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <vector>
#include <unordered_set>
#include <string>  // Necessário para o uso de stoi()
#include <sstream> // Usado para stream de strings
#include <munit.h> // Biblioteca munit

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
    int getCodPassageiro() const
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

    int getCodVoo() const
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

    int getNumAssento() const
    {
        return numAssento;
    }

    void setNumAssento(int num)
    {
        numAssento = num;
    }

    bool getStatus() const
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
    int getCodReserva() const
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
        arquivo << "Pontos de Fidelidade: 0" << endl; // Inicializa com 0 pontos de fidelidade
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
        arquivo << "------------------------" << endl;
        arquivo.close();
        registradoArquivo();
    }
    else
    {
        erroArquivo();
    }
}

void salvarAssentosNoArquivo(int codVoo, const vector<Assento>& listaAssentos)
{
    // Abrindo o arquivo para salvar os assentos
    ofstream arquivo("assentos_voo.txt", ios::app);
    if (!arquivo.is_open())
    {
        cerr << "Erro ao abrir o arquivo de assentos!" << endl;
        return;
    }

    // Salvando as informações do voo
    arquivo << "Voo: " << codVoo << endl;
    arquivo << "Assentos:" << endl;

    // Salvando cada assento com o seu status
    for (const auto& assento : listaAssentos)
    {
        arquivo << assento.getNumAssento() << ": "
                << (assento.getStatus() ? "Ocupado" : "Disponível") << endl;
    }

    // Separando blocos de voo com uma linha
    arquivo << "------------------------" << endl;

    arquivo.close();

    // Confirmação de sucesso
    cout << "Assentos salvos com sucesso no arquivo!" << endl;
}

void salvarReservaNoArquivo(const Reserva &reserva)
{
    ofstream arquivo("reservas.txt", ios::app);
    if (!arquivo.is_open())
    {
        cerr << "Erro ao abrir o arquivo de reservas!" << endl;
        return;
    }

    arquivo << "Codigo Reserva: " << reserva.getCodReserva() << endl;
    arquivo << "Codigo Passageiro: " << reserva.getCodPassageiro() << endl;
    arquivo << "Codigo Voo: " << reserva.getCodVoo() << endl;
    arquivo << "Numero Assento: " << reserva.getNumAssento() << endl;
    arquivo << "------------------------" << endl;

    arquivo.close();
}

void salvarPontosFidNoArquivo(int codPassageiro, int pontos)
{
    ifstream arquivoEntrada("passageiros.txt"); // Abre o arquivo para leitura
    ofstream arquivoSaida("passageiros_temp.txt"); // Arquivo temporário para salvar as mudanças
    string linha;
    bool encontrado = false;

    // Verifica se os arquivos foram abertos corretamente
    if (!arquivoEntrada.is_open() || !arquivoSaida.is_open())
    {
        cout << "Erro ao abrir os arquivos!" << endl;
        return;
    }

    // Processa o arquivo linha por linha
    while (getline(arquivoEntrada, linha))
    {
        // Verifica se a linha contém o código do passageiro
        if (linha.find("Codigo do Passageiro: " + to_string(codPassageiro)) != string::npos)
        {
            // Aqui você pode localizar e atualizar a linha dos pontos de fidelidade
            // Exemplo de manipulação simples: Adiciona os pontos de fidelidade
            linha += "\nPontos de Fidelidade: " + to_string(pontos);  // Atualiza os pontos

            encontrado = true;
        }
        // Escreve a linha no arquivo temporário
        arquivoSaida << linha << endl;
    }

    arquivoEntrada.close();
    arquivoSaida.close();

    // Se o passageiro foi encontrado, substitui o arquivo original
    if (encontrado)
    {
        remove("passageiros.txt"); // Remove o arquivo original
        rename("passageiros_temp.txt", "passageiros.txt"); // Renomeia o arquivo temporário para o original
        cout << "Pontos de fidelidade do passageiro " << codPassageiro << " atualizados com sucesso!" << endl;
    }
    else
    {
        // Caso o passageiro não seja encontrado
        cout << "Passageiro com código " << codPassageiro << " não encontrado!" << endl;
    }
}

// Atualizar Informaçoes no arquivo.txt
void atualizarStatusAssento(int codVoo, int numAssento, bool status)
{
    // Abra o arquivo de assentos
    ifstream arquivoEntrada("assentos_voo.txt");
    ofstream arquivoSaida("assentos_voo_temp.txt");
    string linha;

    if (arquivoEntrada.is_open() && arquivoSaida.is_open())
    {
        bool assentoAtualizado = false;
        while (getline(arquivoEntrada, linha))
        {
            // Verifique se a linha contém o código do voo
            if (linha.find("Voo: " + to_string(codVoo)) != string::npos)
            {
                // Processar os assentos
                while (getline(arquivoEntrada, linha) && linha != "------------------------")
                {
                    int num = 0;
                    try {
                        num = stoi(linha.substr(0, linha.find(":")));
                    } catch (const invalid_argument& e) {
                        continue;
                    }
                    if (num == numAssento)
                    {
                        assentoAtualizado = true;
                        arquivoSaida << num << ": " << (status ? "Ocupado" : "Disponível") << endl;
                    }
                    else
                    {
                        arquivoSaida << linha << endl;
                    }
                }
            }
            else
            {
                arquivoSaida << linha << endl;
            }
        }

        arquivoEntrada.close();
        arquivoSaida.close();

        // Substituir o arquivo de assentos pelo temporário
        remove("assentos_voo.txt");
        rename("assentos_voo_temp.txt", "assentos_voo.txt");

        if (assentoAtualizado)
        {
            cout << "Assento atualizado com sucesso!" << endl;
        }
        else
        {
            cout << "Assento não encontrado!" << endl;
        }
    }
    else
    {
        erroArquivo();
    }
}

void atualizarPontosFidelidade(int codPassageiro, int pontos)
{
    ifstream arquivoEntrada("passageiros.txt");
    ofstream arquivoSaida("passageiros_temp.txt");
    string linha;
    bool encontrado = false;

    // Verifica se o arquivo foi aberto corretamente
    if (!arquivoEntrada.is_open() || !arquivoSaida.is_open())
    {
        cout << "Erro ao abrir o arquivo de passageiros!" << endl;
        return;
    }

    // Processa cada linha no arquivo de passageiros
    while (getline(arquivoEntrada, linha))
    {
        // Verifica se a linha contém o código do passageiro
        if (linha.find("Codigo do Passageiro: " + to_string(codPassageiro)) != string::npos)
        {
            // Aqui você pode atualizar os pontos de fidelidade no arquivo
            // Exemplo de manipulação simples (dependendo do formato do seu arquivo):
            // Atualize a linha com os novos pontos de fidelidade
            linha += "\nPontos de Fidelidade: " + to_string(pontos);  // Adiciona os pontos

            encontrado = true;
        }
        // Escreve as linhas no arquivo temporário
        arquivoSaida << linha << endl;
    }

    arquivoEntrada.close();
    arquivoSaida.close();

    // Substitui o arquivo original pelo temporário
    remove("passageiros.txt");
    rename("passageiros_temp.txt", "passageiros.txt");

    if (encontrado)
    {
        cout << "Pontos de fidelidade atualizados com sucesso!" << endl;
    }
    else
    {
        cout << "Passageiro não encontrado!" << endl;
    }
}

// Função para calcular ponto de fidelidade
int calcularPontosFidelidade(int codVoo)
{


    int pontos = 50;  // Definindo pontos fixos para todos os voos

    return pontos;
}

// Funçoes para gerar codigos
int gerarCodigoPassageiro()
{
    ifstream arquivoEntrada("codigos_passageiros.txt");
    ofstream arquivoSaida;
    int ultimoCodigo = 0;

    // Verificar se o arquivo existe e contém códigos
    if (arquivoEntrada.is_open())
    {
        string linha;
        // Ler todas as linhas do arquivo e pegar o maior código
        while (getline(arquivoEntrada, linha))
        {
            int codigoAtual = 0;
            try {
                codigoAtual = stoi(linha);  // Tenta converter a linha para um número
            }
            catch (const invalid_argument& e) {
                continue;  // Caso o conteúdo não seja um número válido, ignorar
            }
            if (codigoAtual > ultimoCodigo)
            {
                ultimoCodigo = codigoAtual;
            }
        }
        arquivoEntrada.close();
    }

    // Incrementa o código
    int novoCodigo = ultimoCodigo + 1;

    // Salva o novo código no arquivo, sobrescrevendo
    arquivoSaida.open("codigos_passageiros.txt", ios::out);
    if (arquivoSaida.is_open())
    {
        arquivoSaida << novoCodigo << endl;
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
            if (codigo > ultimoCodigo)
            {
                ultimoCodigo = codigo; // Atualiza o último código encontrado
            }
        }
        arquivoEntrada.close();
    }

    // Incrementa o código até que ele seja único
    int novoCodigo = ultimoCodigo + 1;  // Inicia com o próximo código após o último código
    while (codigosExistentes.find(novoCodigo) != codigosExistentes.end())
    {
        novoCodigo++; // Incrementa o código até encontrar um único
    }

    // Salva o novo código no arquivo
    arquivoSaida.open("codigos_tripulante.txt", ios::out | ios::app); // Abre para adicionar ao final do arquivo
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
    unordered_set<int> codigosExistentes;

    // Tenta ler os códigos do arquivo e verificar se o novo código é único
    if (arquivoEntrada.is_open())
    {
        // Lê todos os códigos no arquivo e armazena no conjunto para verificação de duplicatas
        int codigo;
        while (arquivoEntrada >> codigo)
        {
            codigosExistentes.insert(codigo); // Armazena todos os códigos no conjunto
            if (codigo > ultimoCodigo)
            {
                ultimoCodigo = codigo; // Atualiza o último código encontrado
            }
        }
        arquivoEntrada.close();
    }
    else
    {
        cout << "Erro ao abrir o arquivo de códigos de voo!" << endl;
        return -1; // Retorna -1 caso não consiga abrir o arquivo
    }

    // Incrementa o código até que ele seja único
    int novoCodigo = ultimoCodigo + 1;  // Inicia com o próximo código após o último código
    while (codigosExistentes.find(novoCodigo) != codigosExistentes.end())
    {
        novoCodigo++; // Incrementa o código até encontrar um único
    }

    // Salva o novo código no arquivo
    arquivoSaida.open("codigos_Voo.txt", ios::out | ios::app); // Abre para adicionar ao final do arquivo
    if (arquivoSaida.is_open())
    {
        arquivoSaida << novoCodigo << endl; // Adiciona o novo código ao final do arquivo
        arquivoSaida.close();
        cout << "Novo código de voo gerado: " << novoCodigo << endl;
    }
    else
    {
        cout << "Erro ao abrir o arquivo para salvar o código de voo!" << endl;
    }

    return novoCodigo;
}

int gerarCodigoReserva()
{
    ifstream arquivoEntrada("codigos_reservas.txt");
    ofstream arquivoSaida;
    int ultimoCodigo = 0;

    // Verifica se o arquivo existe e está aberto
    if (arquivoEntrada.is_open())
    {
        string linha;
        // Lê todas as linhas do arquivo e pega o último código
        while (getline(arquivoEntrada, linha))
        {
            // Tenta converter a linha para inteiro
            try
            {
                ultimoCodigo = stoi(linha); // Atualiza o último código com o valor lido
            }
            catch (const invalid_argument& e)
            {
                cout << "Erro ao ler o código do arquivo: " << e.what() << endl;
            }
        }
        arquivoEntrada.close();
    }
    else
    {
        cout << "Erro ao abrir o arquivo codigos_reservas.txt!" << endl;
    }

    // Incrementa o código
    int novoCodigo = ultimoCodigo + 1;

    // Abre o arquivo para adicionar o novo código
    arquivoSaida.open("codigos_reservas.txt", ios::out | ios::app);
    if (arquivoSaida.is_open())
    {
        arquivoSaida << novoCodigo << endl; // Adiciona o novo código ao final
        arquivoSaida.close();
        cout << "Novo código de reserva gerado: " << novoCodigo << endl;
    }
    else
    {
        cout << "Erro ao abrir o arquivo para salvar o código de reserva!" << endl;
        return -1; // Caso ocorra erro ao abrir o arquivo
    }

    return novoCodigo;
}

void gerarPontosFid(int codPassageiro, int pontos)
{
    ifstream arquivoEntrada("passageiros.txt");
    ofstream arquivoSaida("passageiros_temp.txt");
    string linha;
    bool passageiroEncontrado = false;

    if (arquivoEntrada.is_open() && arquivoSaida.is_open())
    {
        while (getline(arquivoEntrada, linha))
        {
            arquivoSaida << linha << endl;
            if (linha.find("Codigo do Passageiro: " + to_string(codPassageiro)) != string::npos)
            {
                passageiroEncontrado = true;
                while (getline(arquivoEntrada, linha) && linha != "-------------------------")
                {
                    if (linha.find("Pontos de Fidelidade: ") != string::npos)
                    {
                        int pontosAtuais = 0;
                        try {
                            pontosAtuais = stoi(linha.substr(linha.find(": ") + 2));
                        } catch (const invalid_argument& e) {
                            continue;
                        }
                        pontosAtuais += pontos;
                        arquivoSaida << "Pontos de Fidelidade: " << pontosAtuais << endl;
                    }
                    else
                    {
                        arquivoSaida << linha << endl;
                    }
                }
                arquivoSaida << "-------------------------" << endl;
            }
        }
        arquivoEntrada.close();
        arquivoSaida.close();

        remove("passageiros.txt");
        rename("passageiros_temp.txt", "passageiros.txt");

        if (passageiroEncontrado)
        {
            cout << "Pontos de fidelidade adicionados com sucesso!" << endl;
        }
        else
        {
            cout << "Passageiro não encontrado." << endl;
        }
    }
    else
    {
        erroArquivo();
    }
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

bool verificarCodigo(const string& arquivo, int codBusca)
{
    ifstream arquivoEntrada(arquivo);
    if (!arquivoEntrada.is_open())
    {
        cout << "Erro ao abrir o arquivo: " << arquivo << endl;
        return false;
    }

    string linha;
    bool encontrado = false;

    // Percorre o arquivo linha por linha
    while (getline(arquivoEntrada, linha))
    {
        // Verifica se a linha contém o código do passageiro
        if (linha.find("Codigo do Passageiro: " + to_string(codBusca)) != string::npos)
        {
            encontrado = true;
            break; // Código encontrado, pode parar a busca
        }
    }

    arquivoEntrada.close();
    return encontrado;
}

bool verificarStatusAssento(int codVoo, int numAssento)
{
    ifstream arquivo("assentos_voo.txt");
    if (!arquivo.is_open())
    {
        cerr << "Erro ao abrir o arquivo de assentos!" << endl;
        return false;
    }

    string linha;
    bool vooEncontrado = false;

    while (getline(arquivo, linha))
    {
        if (linha.find("Voo: " + to_string(codVoo)) != string::npos)
        {
            vooEncontrado = true;
        }

        if (vooEncontrado && linha.find(to_string(numAssento) + ":") != string::npos)
        {
            // Verificar o status do assento
            if (linha.find("Disponível") != string::npos)
            {
                arquivo.close();
                return true; // Assento disponível
            }
            else
            {
                arquivo.close();
                return false; // Assento ocupado
            }
        }

        // Reset vooEncontrado if we reach the end of the current flight's section
        if (vooEncontrado && linha == "------------------------")
        {
            vooEncontrado = false;
        }
    }

    arquivo.close();
    return false; // Assento ou voo não encontrado
}

bool verificarCodigoVoo(const string &arquivoNome, int codVoo)
{
    ifstream arquivo(arquivoNome);
    int codigo;

    if (!arquivo.is_open())
    {
        erroArquivo();
        return false;
    }

    while (arquivo >> codigo)
    {
        if (codigo == codVoo)
        {
            arquivo.close();
            return true;
        }
    }

    arquivo.close();
    return false;
}

// Funçoes para Pesquisa
void pesquisaArquivo(const string& tipo, const string& codBusca)
{
    ifstream arquivo(tipo + ".txt");
    if (!arquivo.is_open())
    {
        cout << "Erro ao abrir o arquivo de " << tipo << "!" << endl;
        return;
    }

    string linha;
    bool encontrado = false;
    int linhasExibidas = 0;

    // Buscar no arquivo linha por linha
    while (getline(arquivo, linha))
    {
        if (linha.find(codBusca) != string::npos)  // Encontrou o código na linha
        {
            cout << "Informações encontradas: " << endl;
            cout << linha << endl;
            encontrado = true;
            linhasExibidas = 1;  // Já exibiu a linha com o código
            break;
        }
    }

    // Se o código foi encontrado, exibe as próximas 5 linhas
    if (encontrado)
    {
        while (linhasExibidas < 5 && getline(arquivo, linha))  // Mostrar as próximas 5 linhas
        {
            cout << linha << endl;
            linhasExibidas++;
        }
    }

    if (!encontrado)
    {
        cout << "Código " << codBusca << " não encontrado no arquivo de " << tipo << "." << endl;
    }

    arquivo.close();
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
    int codAviao, codComisario, codPiloto, codCopiloto, codVoo, qtdAssentos;
    string data, hora, destino, origem;
    float tarifa;

    // Capturar informações do voo
    cout << "Digite a origem do Voo: ";
    cin.ignore(); // Ignorar o buffer
    getline(cin, origem);

    cout << "Digite o destino do Voo: ";
    getline(cin, destino);

    cout << "Digite a data do Voo (DD/MM/AAAA): ";
    getline(cin, data);

    cout << "Digite a hora do Voo (HH:MM): ";
    getline(cin, hora);

    cout << "Digite a tarifa do Voo: ";
    cin >> tarifa;

    cout << "Digite quantos assentos o avião possui: ";
    cin >> qtdAssentos;

    // Verificação do código do piloto
    do
    {
        cout << "Digite o Codigo do Piloto(a): ";
        cin >> codPiloto;
        if (!verificarCodigoTripulacao("codigos_tripulante.txt", codPiloto))
        {
            cout << "Piloto Nao Encontrado, tente novamente." << endl;
        }
    } while (!verificarCodigoTripulacao("codigos_tripulante.txt", codPiloto));
    cout << "Piloto adicionado com sucesso à Tripulacao!" << endl;

    // Verificação do código do copiloto
    do
    {
        cout << "Digite o Codigo do Copiloto(a): ";
        cin >> codCopiloto;
        if (!verificarCodigoTripulacao("codigos_tripulante.txt", codCopiloto))
        {
            cout << "Copiloto Nao Encontrado, tente novamente." << endl;
        }
    } while (!verificarCodigoTripulacao("codigos_tripulante.txt", codCopiloto));
    cout << "Copiloto adicionado com sucesso à Tripulacao!" << endl;

    // Verificação do código do comissário
    do
    {
        cout << "Digite o Codigo do Comissario(a): ";
        cin >> codComisario;
        if (!verificarCodigoTripulacao("codigos_tripulante.txt", codComisario))
        {
            cout << "Comissario Nao Encontrado, tente novamente." << endl;
        }
    } while (!verificarCodigoTripulacao("codigos_tripulante.txt", codComisario));
    cout << "Comissario adicionado com sucesso à Tripulacao!" << endl;

    // Gerar código do voo
    codVoo = gerarCodigoVoo();

    // Criar o voo
    Voo novoVoo;
    novoVoo.setOrigem(origem);
    novoVoo.setDestino(destino);
    novoVoo.setData(data);
    novoVoo.setHora(hora);
    novoVoo.setTarifa(tarifa);
    novoVoo.setCodVoo(codVoo);
    novoVoo.setCodPiloto(codPiloto);
    novoVoo.setCodCopiloto(codCopiloto);
    novoVoo.setCodComisario(codComisario);

    // Criar os assentos
    vector<Assento> listaAssentos;
    for (int i = 0; i < qtdAssentos; i++)
    {
        Assento novoAssento;
        novoAssento.setNumAssento(i + 1); // Assentos numerados sequencialmente
        novoAssento.setStatus(false);    // Todos começam como disponíveis
        listaAssentos.push_back(novoAssento);
    }

    // Salvar o voo e os assentos no arquivo
    salvarVooNoArquivo(novoVoo);
    salvarAssentosNoArquivo(novoVoo.getCodVoo(), listaAssentos);

    cout << "Voo registrado com sucesso!" << endl;
    cout << "Número do seu Voo é: " << novoVoo.getCodVoo() << endl;

    // Adicionar o voo à lista de voos na memória
    v.push_back(novoVoo);
}

void reserva()
{
    int codPassageiro, codVoo, numAssento;
    bool assentoDisponivel = false;

    cout << "\n--- CADASTRO DE RESERVA ---\n";

    // Solicitar o código do passageiro
    cout << "Digite o código do passageiro: ";
    cin >> codPassageiro;

    // Verificar se o passageiro existe
    if (!verificarCodigo("passageiros.txt", codPassageiro))
    {
        cout << "Passageiro não encontrado! Tente novamente.\n";
        return;
    }

    // Solicitar o código do voo
    cout << "Digite o código do voo: ";
    cin >> codVoo;

    // Verificar se o voo existe (não fazemos mais verificação de voo internacional)
    if (!verificarCodigo("voos.txt", codVoo))
    {
        cout << "Voo não encontrado! Tente novamente.\n";
        return;
    }

    // Solicitar o número do assento
    cout << "Digite o número do assento: ";
    cin >> numAssento;

    // Verificar se o assento está disponível
    assentoDisponivel = verificarStatusAssento(codVoo, numAssento);

    if (!assentoDisponivel)
    {
        cout << "Assento não está disponível! Tente outro número.\n";
        return;
    }

    // Geração do código único para a reserva
    int codReserva = gerarCodigoReserva();

    // Criar a nova reserva
    Reserva novaReserva;
    novaReserva.setCodReserva(codReserva);
    novaReserva.setCodPassageiro(codPassageiro);
    novaReserva.setCodVoo(codVoo);
    novaReserva.setNumAssento(numAssento);

    // Calcular e atualizar pontos de fidelidade
    int pontosFidelidade = calcularPontosFidelidade(codVoo);
    atualizarPontosFidelidade(codPassageiro, pontosFidelidade);

    // Atualizar o status do assento no arquivo
    atualizarStatusAssento(codVoo, numAssento, true);

    // Salvar a reserva no arquivo
    salvarReservaNoArquivo(novaReserva);

    // Exibir os dados da reserva
    cout << "\nReserva cadastrada com sucesso!\n";
    cout << "Código da Reserva: " << novaReserva.getCodReserva() << endl;
    cout << "Código do Passageiro: " << novaReserva.getCodPassageiro() << endl;
    cout << "Código do Voo: " << novaReserva.getCodVoo() << endl;
    cout << "Número do Assento: " << novaReserva.getNumAssento() << endl;
    cout << "Pontos de Fidelidade: " << pontosFidelidade << endl;
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
    int codVoo = 0, numAssento = 0, codPassageiro = 0;

    if (arquivoEntrada.is_open() && arquivoSaida.is_open())
    {
        while (getline(arquivoEntrada, linha))
        {
            if (linha.find("Codigo da Reserva: " + to_string(codReserva)) != string::npos)
            {
                reservaEncontrada = true;
                for (int i = 0; i < 4; ++i)
                {
                    getline(arquivoEntrada, linha);
                    if (linha.find("Codigo do Voo: ") != string::npos)
                    {
                        codVoo = stoi(linha.substr(linha.find(": ") + 2));
                    }
                    else if (linha.find("Numero do Assento: ") != string::npos)
                    {
                        numAssento = stoi(linha.substr(linha.find(": ") + 2));
                    }
                    else if (linha.find("Codigo do Passageiro: ") != string::npos)
                    {
                        codPassageiro = stoi(linha.substr(linha.find(": ") + 2));
                    }
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
            atualizarStatusAssento(codVoo, numAssento, false);

            cout << "Reserva de código " << codReserva << " baixada com sucesso!" << endl;

            // Adicionar pontos de fidelidade
            gerarPontosFid(codPassageiro, 10);
            salvarPontosFidNoArquivo(codPassageiro, 10);
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

        // Verificação se o código fornecido é numérico
        if (codBusca.empty() || codBusca.find_first_not_of("0123456789") != string::npos)
        {
            cout << "Código inválido! Apenas números são permitidos." << endl;
            return;
        }

        pesquisaArquivo("passageiros", codBusca);
    }
    else if (op == 2)
    {
        string codBusca;
        cout << "Digite o código do tripulante: ";
        cin >> codBusca;

        // Verificação se o código fornecido é numérico
        if (codBusca.empty() || codBusca.find_first_not_of("0123456789") != string::npos)
        {
            cout << "Código inválido! Apenas números são permitidos." << endl;
            return;
        }

        pesquisaArquivo("tripulacao", codBusca);
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
                while (getline(arquivo, linha) && linha != "-------------------------")
                {
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
    cout << "4. Realizar Reserva" << endl;
    cout << "5. Baixa em Reservas" << endl;
    cout << "6. Pesquisa" << endl;
    cout << "7. Consultar Programa de Fidelidade" << endl;
    cout << "8. Sair" << endl;
    cout << "=====================" << endl;
}

int main(int argc, char* argv[MUNIT_ARRAY_PARAM(argc + 1)])
{
    int op = 0;
    while (op != 8)
    {
        menu();
        cout << "Escolha uma opcao (1-8): ";
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
            reserva();
            break;
        case 5:
            baixaReserva();
            break;
        case 6:
            pesquisa();
            break;
        case 7:
            programaFid();
            break;
        case 8:
            cout << "Saindo do sistema" << endl;
            return 0;
        default:
            cout << "Opção inválida! Por favor, escolha um número entre 1 e 8." << endl;
        }
    }
    return 1;
}

// Funções de teste
static MunitResult test_gerarCodigoPassageiro(const MunitParameter params[], void* data) {
    int codigo = gerarCodigoPassageiro();
    munit_assert_int(codigo, >, 0);
    return MUNIT_OK;
}

static MunitResult test_gerarCodigoTripulante(const MunitParameter params[], void* data) {
    int codigo = gerarCodigoTripulante();
    munit_assert_int(codigo, >, 0);
    return MUNIT_OK;
}

static MunitResult test_gerarCodigoVoo(const MunitParameter params[], void* data) {
    int codigo = gerarCodigoVoo();
    munit_assert_int(codigo, >, 0);
    return MUNIT_OK;
}

static MunitResult test_gerarCodigoReserva(const MunitParameter params[], void* data) {
    int codigo = gerarCodigoReserva();
    munit_assert_int(codigo, >, 0);
    return MUNIT_OK;
}

static MunitResult test_calcularPontosFidelidade(const MunitParameter params[], void* data) {
    int pontos = calcularPontosFidelidade(123); // Exemplo de código de voo
    munit_assert_int(pontos, ==, 50); // Verifica se os pontos são 50
    return MUNIT_OK;
}

// Teste para verificar erro ao abrir arquivo de passageiros
static MunitResult test_erroAbrirArquivoPassageiros(const MunitParameter params[], void* data) {
    ifstream arquivoEntrada("passageiros_inexistente.txt");
    munit_assert_false(arquivoEntrada.is_open());
    return MUNIT_OK;
}

// Teste para verificar erro ao abrir arquivo de tripulantes
static MunitResult test_erroAbrirArquivoTripulantes(const MunitParameter params[], void* data) {
    ifstream arquivoEntrada("tripulacao_inexistente.txt");
    munit_assert_false(arquivoEntrada.is_open());
    return MUNIT_OK;
}

// Teste para verificar erro ao abrir arquivo de voos
static MunitResult test_erroAbrirArquivoVoos(const MunitParameter params[], void* data) {
    ifstream arquivoEntrada("voo_inexistente.txt");
    munit_assert_false(arquivoEntrada.is_open());
    return MUNIT_OK;
}

// Teste para verificar erro ao abrir arquivo de reservas
static MunitResult test_erroAbrirArquivoReservas(const MunitParameter params[], void* data) {
    ifstream arquivoEntrada("reservas_inexistente.txt");
    munit_assert_false(arquivoEntrada.is_open());
    return MUNIT_OK;
}

// Teste para verificar erro ao abrir arquivo de assentos
static MunitResult test_erroAbrirArquivoAssentos(const MunitParameter params[], void* data) {
    ifstream arquivoEntrada("assentos_voo_inexistente.txt");
    munit_assert_false(arquivoEntrada.is_open());
    return MUNIT_OK;
}

// Definição dos testes
static MunitTest tests[] = {
    { (char*) "/test_gerarCodigoPassageiro", test_gerarCodigoPassageiro, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
    { (char*) "/test_gerarCodigoTripulante", test_gerarCodigoTripulante, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
    { (char*) "/test_gerarCodigoVoo", test_gerarCodigoVoo, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
    { (char*) "/test_gerarCodigoReserva", test_gerarCodigoReserva, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
    { (char*) "/test_calcularPontosFidelidade", test_calcularPontosFidelidade, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
    { (char*) "/test_erroAbrirArquivoPassageiros", test_erroAbrirArquivoPassageiros, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
    { (char*) "/test_erroAbrirArquivoTripulantes", test_erroAbrirArquivoTripulantes, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
    { (char*) "/test_erroAbrirArquivoVoos", test_erroAbrirArquivoVoos, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
    { (char*) "/test_erroAbrirArquivoReservas", test_erroAbrirArquivoReservas, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
    { (char*) "/test_erroAbrirArquivoAssentos", test_erroAbrirArquivoAssentos, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
    // ...adicionar mais testes conforme necessário...
    { NULL, NULL, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL }
};

// Configuração da suíte de testes
static const MunitSuite suite = {
    (char*) "", tests, NULL, 1, MUNIT_SUITE_OPTION_NONE
};

// Função principal para executar os testes
int main(int argc, char* argv[MUNIT_ARRAY_PARAM(argc + 1)]) {
    return munit_suite_main(&suite, NULL, argc, argv);
}

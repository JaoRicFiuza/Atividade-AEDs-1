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
    // Definindo o nome do arquivo dependendo do cargo
    string nomeArquivo;
    if (t.getCargo() == 1)
        nomeArquivo = "pilotos.txt";      // Piloto
    else if (t.getCargo() == 2)
        nomeArquivo = "copilotos.txt";    // Copiloto
    else
        nomeArquivo = "comissarios.txt"; // Comissário

    // Abrindo o arquivo correspondente
    ofstream arquivo(nomeArquivo, ios::app); // Modo append
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
    ifstream arquivoEntrada("assentos_voo.txt");
    ofstream arquivoSaida("assentos_voo_temp.txt");
    string linha;
    bool assentoAtualizado = false;

    if (arquivoEntrada.is_open() && arquivoSaida.is_open())
    {
        while (getline(arquivoEntrada, linha))
        {
            // Verifique se a linha contém o código do voo
            if (linha.find("Voo: " + to_string(codVoo)) != string::npos)
            {
                // Agora processa os assentos do voo até encontrar a linha "------------------------"
                arquivoSaida << linha << endl; // Escreve a linha do código do voo no arquivo temporário
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
                        // Atualiza o status do assento
                        arquivoSaida << num << ": " << (status ? "Ocupado" : "Disponível") << endl;
                    }
                    else
                    {
                        // Caso não seja o assento a ser atualizado, escreve a linha original
                        arquivoSaida << linha << endl;
                    }
                }
                // Após a atualização, escreve a linha de separação
                arquivoSaida << "------------------------" << endl;
            }
            else
            {
                // Se não for o voo desejado, escreve a linha original
                arquivoSaida << linha << endl;
            }
        }

        arquivoEntrada.close();
        arquivoSaida.close();

        // Substitui o arquivo de assentos pelo temporário
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
    bool pontosAtualizados = false;

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
            encontrado = true;
            bool dentroDoBloco = true;

            // Escreve a linha de código do passageiro
            arquivoSaida << linha << endl;

            // Processa as linhas seguintes até encontrar o bloco de informações do passageiro
            while (getline(arquivoEntrada, linha) && dentroDoBloco)
            {
                // Verifica a linha de pontos de fidelidade
                if (linha.find("Pontos de Fidelidade: ") != string::npos)
                {
                    int pontosAtuais = 0;
                    try {
                        pontosAtuais = stoi(linha.substr(linha.find(": ") + 2)); // Pega os pontos atuais
                    } catch (const invalid_argument& e) {
                        cout << "Erro ao ler os pontos de fidelidade." << endl;
                        pontosAtuais = 0;
                    }

                    // Acumula os pontos ao valor atual
                    pontosAtuais += pontos;

                    // Atualiza a linha com os novos pontos
                    linha = "Pontos de Fidelidade: " + to_string(pontosAtuais);
                    pontosAtualizados = true;
                }

                // Se encontrar a linha de separação do bloco de dados do passageiro, termina o bloco
                if (linha == "-------------------------")
                {
                    dentroDoBloco = false;
                }

                // Escreve a linha atualizada ou original no arquivo de saída
                arquivoSaida << linha << endl;
            }

            // Se não encontrou a linha de pontos de fidelidade, adiciona os pontos
            if (!pontosAtualizados)
            {
                arquivoSaida << "Pontos de Fidelidade: " << pontos << endl;
            }

            // Adiciona a linha de separação do bloco
            arquivoSaida << "-------------------------" << endl;
        }
        else
        {
            // Escreve as outras linhas no arquivo temporário
            arquivoSaida << linha << endl;
        }
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

    // Verifica se o arquivo existe, se não, cria o arquivo vazio
    if (!arquivoEntrada.is_open())
    {
        // O arquivo não existe, então cria um arquivo vazio
        arquivoSaida.open("codigos_Voo.txt", ios::out);
        if (arquivoSaida.is_open())
        {
            arquivoSaida.close();  // Apenas cria o arquivo vazio e fecha
            cout << "Arquivo codigos_Voo.txt não encontrado. Criando um novo arquivo..." << endl;
        }
        else
        {
            cout << "Erro ao criar o arquivo codigos_Voo.txt!" << endl;
            return -1; // Retorna -1 caso não consiga criar o arquivo
        }
    }
    else
    {
        // O arquivo existe, agora lê os códigos no arquivo e armazena os códigos existentes
        int codigo;
        while (arquivoEntrada >> codigo)
        {
            codigosExistentes.insert(codigo); // Armazena os códigos no conjunto
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
    arquivoSaida.open("codigos_Voo.txt", ios::app); // Abre para adicionar ao final do arquivo
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
    bool pontosAtualizados = false;

    if (arquivoEntrada.is_open() && arquivoSaida.is_open())
    {
        while (getline(arquivoEntrada, linha))
        {
            // Escreve a linha atual no arquivo temporário
            arquivoSaida << linha << endl;

            // Verifica se encontrou o passageiro
            if (linha.find("Codigo do Passageiro: " + to_string(codPassageiro)) != string::npos)
            {
                passageiroEncontrado = true;
                // Processa as linhas subsequentes
                while (getline(arquivoEntrada, linha) && linha != "-------------------------")
                {
                    if (linha.find("Pontos de Fidelidade: ") != string::npos)
                    {
                        int pontosAtuais = 0;
                        try {
                            pontosAtuais = stoi(linha.substr(linha.find(": ") + 2)); // Pega os pontos atuais
                        } catch (const invalid_argument& e) {
                            cout << "Erro ao ler os pontos de fidelidade." << endl;
                            pontosAtuais = 0;
                        }

                        pontosAtuais += pontos;  // Atualiza os pontos

                        // Escreve os novos pontos de fidelidade no arquivo temporário
                        arquivoSaida << "Pontos de Fidelidade: " << pontosAtuais << endl;
                        pontosAtualizados = true;
                    }
                    else
                    {
                        arquivoSaida << linha << endl;  // Copia as linhas não modificadas
                    }
                }

                if (!pontosAtualizados) {
                    // Se não encontrou a linha de pontos de fidelidade, adiciona a linha com os pontos
                    arquivoSaida << "Pontos de Fidelidade: " << pontos << endl;
                }

                arquivoSaida << "-------------------------" << endl; // Adiciona a linha separadora
            }
        }

        arquivoEntrada.close();
        arquivoSaida.close();

        // Substitui o arquivo original pelo temporário
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
        cout << "Erro ao abrir os arquivos!" << endl;
    }
}

// Funçoes para a verificaçao de Codigo
bool verificarCodigoTripulacao(const string &nomeArquivo, int codTripulacao, int cargo)
{
    ifstream arquivo(nomeArquivo); // Abre o arquivo correspondente ao cargo de tripulante
    string linha;
    string cargoEsperado = (cargo == 1) ? "Piloto(a)" : (cargo == 2) ? "Copiloto(a)" : "Comissario(a)";

    // Verifica se o arquivo foi aberto corretamente
    if (!arquivo.is_open())
    {
        erroArquivo(); // Trata o erro de abertura do arquivo
        return false;
    }

    // Lê o arquivo linha por linha
    while (getline(arquivo, linha))
    {
        // Procurar pela linha "Codigo do Tripulante" e extrair o código
        if (linha.find("Codigo do Tripulante: " + to_string(codTripulacao)) != string::npos)
        {
            // Ler o próximo bloco para comparar o cargo
            getline(arquivo, linha); // Ignora a linha "Nome"
            getline(arquivo, linha); // Ignora a linha "Endereco"
            getline(arquivo, linha); // Ignora a linha "Telefone"
            getline(arquivo, linha); // Lê a linha do cargo
            
            // Verifica se o cargo corresponde ao esperado
            if (linha.find("Cargo: " + cargoEsperado) != string::npos)
            {
                arquivo.close(); // Fecha o arquivo após encontrar o código e o cargo
                return true;     // Código e cargo válidos
            }
        }
    }

    arquivo.close(); // Fecha o arquivo se não encontrar o código ou o cargo
    return false;    // Retorna falso se não encontrar o código ou o cargo
}

bool verificarCodigosVoo(const string &arquivoNome, int codVoo)
{
    ifstream arquivo(arquivoNome); // Abre o arquivo com os códigos de voos
    string linha;

    // Verifica se o arquivo foi aberto corretamente
    if (!arquivo.is_open())
    {
        cout << "Erro ao abrir o arquivo: " << arquivoNome << endl;
        return false;
    }

    // Lê o arquivo linha por linha
    while (getline(arquivo, linha))
    {
        // Verifica se a linha contém "Codigo do Voo: X"
        if (linha.find("Codigo do Voo: " + to_string(codVoo)) != string::npos)
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
            if (!encontrado)  // Se for a primeira ocorrência, exibe uma mensagem
            {
                cout << "Informações encontradas: " << endl;
                encontrado = true;
            }

            cout << linha << endl;  // Exibe a linha com o código encontrado
            linhasExibidas++;

            // Se o código for encontrado, tenta mostrar as próximas 5 linhas
            while (linhasExibidas < 5 && getline(arquivo, linha)) 
            {
                cout << linha << endl;
                linhasExibidas++;
            }

            // Podemos parar após exibir a primeira ocorrência e as 5 linhas seguintes
            break;
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
        if (!verificarCodigoTripulacao("pilotos.txt", codPiloto, 1)) // 1 para Piloto
        {
            cout << "Piloto Nao Encontrado ou Cargo Invalido, tente novamente." << endl;
        }
    } while (!verificarCodigoTripulacao("pilotos.txt", codPiloto, 1)); // 1 para Piloto
    cout << "Piloto adicionado com sucesso à Tripulacao!" << endl;

    // Verificação do código do copiloto
    do
    {
        cout << "Digite o Codigo do Copiloto(a): ";
        cin >> codCopiloto;
        if (!verificarCodigoTripulacao("copilotos.txt", codCopiloto, 2)) // 2 para Copiloto
        {
            cout << "Copiloto Nao Encontrado ou Cargo Invalido, tente novamente." << endl;
        }
    } while (!verificarCodigoTripulacao("copilotos.txt", codCopiloto, 2)); // 2 para Copiloto
    cout << "Copiloto adicionado com sucesso à Tripulacao!" << endl;

    // Verificação do código do comissário
    do
    {
        cout << "Digite o Codigo do Comissario(a): ";
        cin >> codComisario;
        if (!verificarCodigoTripulacao("comissarios.txt", codComisario, 3)) // 3 para Comissário
        {
            cout << "Comissario Nao Encontrado ou Cargo Invalido, tente novamente." << endl;
        }
    } while (!verificarCodigoTripulacao("comissarios.txt", codComisario, 3)); // 3 para Comissário
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

    // Verificar se o voo existe
    if (!verificarCodigosVoo("voo.txt", codVoo))  // Arquivo corrigido para "output/voo.txt"
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
            // Verifica se encontrou o código da reserva
            if (linha.find("Codigo da Reserva: " + to_string(codReserva)) != string::npos)
            {
                reservaEncontrada = true;
                // Pula as 4 linhas seguintes para capturar os dados
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
                // Depois de ler as informações, não escreve nada no arquivo de saída para a reserva que está sendo baixada
            }
            else
            {
                arquivoSaida << linha << endl; // Escreve as outras linhas normalmente
            }
        }

        arquivoEntrada.close();
        arquivoSaida.close();

        // Substitui o arquivo original com o temporário
        remove("reservas.txt");
        rename("reservas_temp.txt", "reservas.txt");

        if (reservaEncontrada)
        {
            cout << "Reserva de código " << codReserva << " baixada com sucesso!" << endl;

            // Adiciona pontos de fidelidade ao passageiro
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

        string cargo;
        cout << "Digite o cargo do tripulante (piloto/copiloto/comissario): ";
        cin >> cargo;

        // Verificar se o cargo é válido e escolher o arquivo correspondente
        if (cargo == "piloto")
        {
            pesquisaArquivo("pilotos", codBusca);
        }
        else if (cargo == "copiloto")
        {
            pesquisaArquivo("copilotos", codBusca);
        }
        else if (cargo == "comissario")
        {
            pesquisaArquivo("comissarios", codBusca);
        }
        else
        {
            cout << "Cargo inválido!" << endl;
        }
    }
    else
    {
        cout << "Opção inválida!" << endl;
    }
}

void programaFid()
{
    int codBusca;
    cout << "Digite o código do passageiro para verificar os pontos de fidelidade: ";
    cin >> codBusca;

    ifstream arquivo("passageiros.txt");
    string linha;
    bool passageiroEncontrado = false;

    if (arquivo.is_open())
    {
        while (getline(arquivo, linha))
        {
            // Verifica se encontrou o código do passageiro
            if (linha.find("Codigo do Passageiro: " + to_string(codBusca)) != string::npos)
            {
                passageiroEncontrado = true;
                cout << "-------------------------" << endl;
                cout << linha << endl;  // Exibe o código do passageiro

                // Procurar os pontos de fidelidade para esse passageiro
                while (getline(arquivo, linha) && linha != "-------------------------")
                {
                    if (linha.find("Pontos de Fidelidade: ") != string::npos)
                    {
                        cout << linha << endl;  // Exibe os pontos de fidelidade
                    }
                }
                break;  // Encerra a busca após encontrar o passageiro
            }
        }
        arquivo.close();

        if (!passageiroEncontrado)
        {
            cout << "Passageiro não encontrado no programa de fidelidade." << endl;
        }
    }
    else
    {
        erroArquivo();  // Se não conseguiu abrir o arquivo
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

int main()
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

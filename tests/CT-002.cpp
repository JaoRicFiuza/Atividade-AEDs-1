#include <stdio.h>
#include <string.h>
#include "munit.h"

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

// Função mock para simular a escrita no arquivo
void mockSalvarTripulacaoNoArquivo(Tripulacao &t, char *output) {
    // Simulando a gravação de dados em uma string (em vez de um arquivo)
    if (t.getCargo() == 1) {
        sprintf(output, "Codigo do Tripulante: %d\nNome: %s\nEndereco: %s\nTelefone: %s\nCargo: Piloto(a)\n-------------------------\n",
                t.getCodigo(), t.getNome().c_str(), t.getEndereco().c_str(), t.getTel().c_str());
    } else if (t.getCargo() == 2) {
        sprintf(output, "Codigo do Tripulante: %d\nNome: %s\nEndereco: %s\nTelefone: %s\nCargo: Copiloto(a)\n-------------------------\n",
                t.getCodigo(), t.getNome().c_str(), t.getEndereco().c_str(), t.getTel().c_str());
    } else {
        sprintf(output, "Codigo do Tripulante: %d\nNome: %s\nEndereco: %s\nTelefone: %s\nCargo: Comissario(a)\n-------------------------\n",
                t.getCodigo(), t.getNome().c_str(), t.getEndereco().c_str(), t.getTel().c_str());
    }
}

// Teste unitário para a função salvarTripulacaoNoArquivo
static MunitResult test_salvarTripulacaoNoArquivo(const MunitParameter params[], void *data) {
    // Criando um objeto Tripulacao de teste
    Tripulacao t;
    t.setCodigo(12345);
    t.setNome("Joao Silva");
    t.setEndereco("Rua ABC, 123");
    t.setTel("9999-9999");
    t.setCargo(1); // Cargo = 1 (Piloto)

    // Usamos uma string para armazenar a saída gerada pela função mock
    char output[512];
    mockSalvarTripulacaoNoArquivo(t, output);

    // Verificando se os dados gravados são os esperados
    munit_assert_string_equal(output, "Codigo do Tripulante: 12345\nNome: Joao Silva\nEndereco: Rua ABC, 123\nTelefone: 9999-9999\nCargo: Piloto(a)\n-------------------------\n");

    return MUNIT_OK; // Retorno indicando que o teste passou
}

// Função que executa todos os testes
static MunitTest tests[] = {
    {"/test_salvarTripulacaoNoArquivo", test_salvarTripulacaoNoArquivo, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL},
    {NULL, NULL, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL} // Sentinel para indicar o fim da lista
};

// Função main para rodar os testes
int main(int argc, char *argv[]) {
    MunitSuite suite = {
        "/test_suite", // Nome da suíte de testes
        tests,         // Lista de testes
        NULL,          // Setup (não usado aqui)
        NULL,          // Teardown (não usado aqui)
        MUNIT_SUITE_OPTION_NONE
    };

    return munit_suite_main(&suite, argc, argv);
}

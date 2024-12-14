#include "munit/munit.h"
#include <fstream>
#include <string.h>
#include <cstdio>

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

// Mock para a função "registradoArquivo" e "erroArquivo"
void registradoArquivo() {
    // Mock vazio para evitar erros de linkagem
}

void erroArquivo() {
    // Mock vazio para evitar erros de linkagem
}

static MunitResult test_salvar_tripulacao_no_arquivo(const MunitParameter params[], void* user_data) {
    // Configurando os dados de teste
    Tripulacao tripulante;
    tripulante.setCodigo(123);
    tripulante.setNome("Joao Silva");
    tripulante.setEndereco("Rua Principal, 123");
    tripulante.setTel("(11) 1234-5678");
    tripulante.setCargo(1); // Piloto

    // Nome esperado do arquivo
    std::string nomeArquivoEsperado = "pilotos.txt";

    // Remover arquivo antes do teste para garantir um estado inicial limpo
    std::remove(nomeArquivoEsperado.c_str());

    // Chamar a função a ser testada
    salvarTripulacaoNoArquivo(tripulante);

    // Verificar se o arquivo foi criado
    std::ifstream arquivo(nomeArquivoEsperado);
    munit_assert(arquivo.is_open());

    // Verificar o conteúdo do arquivo
    std::string linha;
    std::getline(arquivo, linha);
    munit_assert_string_equal(linha.c_str(), "Codigo do Tripulante: 123");
    std::getline(arquivo, linha);
    munit_assert_string_equal(linha.c_str(), "Nome: Joao Silva");
    std::getline(arquivo, linha);
    munit_assert_string_equal(linha.c_str(), "Endereco: Rua Principal, 123");
    std::getline(arquivo, linha);
    munit_assert_string_equal(linha.c_str(), "Telefone: (11) 1234-5678");
    std::getline(arquivo, linha);
    munit_assert_string_equal(linha.c_str(), "Cargo: Piloto(a)");

    arquivo.close();

    // Limpar o arquivo criado durante o teste
    std::remove(nomeArquivoEsperado.c_str());

    return MUNIT_OK;
}

/* Configuração do teste */
static MunitTest tests[] = {
    {(char*)"/test_salvar_tripulacao_no_arquivo", test_salvar_tripulacao_no_arquivo, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL},
    {NULL, NULL, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL}
};

/* Configuração do suite */
static const MunitSuite suite = {
    (char*)"/tripulacao_tests", /* Nome do suite */
    tests,                     /* Testes */
    NULL,                      /* Suites filhas */
    1,                         /* Número de iterações */
    MUNIT_SUITE_OPTION_NONE    /* Opções */
};

/* Main do teste */
int main(int argc, char* argv[MUNIT_ARRAY_PARAM(argc + 1)]) {
    return munit_suite_main(&suite, NULL, argc, argv);
}
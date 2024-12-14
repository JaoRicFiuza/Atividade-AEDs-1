#include "munit.h"
#include <fstream>
#include <sstream>
#include <string>
#include <cstdio> // Para remover o arquivo no final do teste
using namespace std;

class Passageiro {
public:
    int getCodPassageiro() const { return 1; }
    string getNome() const { return "Joao Silva"; }
    string getEndereco() const { return "Rua A, 123"; }
    string getTel() const { return "(11) 98765-4321"; }
    bool getFidelidade() const { return true; }
    int getPontosFidelidade() const { return 100; }
};

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
        arquivo << "Pontos de Fidelidade: " << p.getPontosFidelidade() << endl;
        arquivo << "-------------------------" << endl;
        arquivo.close();
    }
}

MunitResult test_consultarProgramaFidelidade(const MunitParameter params[], void* data) {
    // Arrange
    Passageiro p;

    // Remove o arquivo antes do teste para garantir um estado limpo
    remove("passageiros.txt");

    // Salva o passageiro no arquivo
    salvarPassageiroNoArquivo(p);

    // Act
    ifstream arquivo("passageiros.txt");
    munit_assert(arquivo.is_open());

    stringstream conteudo;
    conteudo << arquivo.rdbuf();
    arquivo.close();

    string esperado =
        "Codigo do Passageiro: 1\n"
        "Nome: Joao Silva\n"
        "Endereco: Rua A, 123\n"
        "Telefone: (11) 98765-4321\n"
        "Fidelidade: Sim\n"
        "Pontos de Fidelidade: 100\n"
        "-------------------------\n";

    // Assert
    munit_assert_string_equal(conteudo.str().c_str(), esperado.c_str());

    // Limpa o arquivo gerado
    remove("passageiros.txt");

    return MUNIT_OK;
}

/* Configuracao dos testes */
static MunitTest tests[] = {
    { (char*)"/consultarProgramaFidelidade", test_consultarProgramaFidelidade, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
    { NULL, NULL, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL }
};

static const MunitSuite suite = {
    (char*)"/testeProgramaFidelidade",
    tests,
    NULL,
    1,
    MUNIT_SUITE_OPTION_NONE
};

/* Funcao principal */
int main(int argc, char* argv[]) {
    return munit_suite_main(&suite, NULL, argc, argv);
}

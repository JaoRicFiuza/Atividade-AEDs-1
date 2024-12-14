#include "munit.h"
#include "../src/modulos/main.cpp"

using namespace std;

// Função de setup para inicializar o ambiente de teste
static void* test_setup(const MunitParameter params[], void* user_data) {
    // Inicializa o ambiente de teste, se necessário
    return NULL;
}

// Função de teardown para limpar o ambiente de teste
static void test_tear_down(void* fixture) {
    // Limpa o ambiente de teste, se necessário
}

// Teste para o menu principal
static MunitResult test_menu(const MunitParameter params[], void* fixture) {
    // Redirecionar a saída padrão para um buffer
    streambuf* originalCoutBuffer = cout.rdbuf();
    ostringstream oss;
    cout.rdbuf(oss.rdbuf());

    // Chamar a função do menu
    menu();

    // Restaurar o buffer original
    cout.rdbuf(originalCoutBuffer);

    // Verificar se a saída contém as opções do menu
    string output = oss.str();
    munit_assert_string_contains(output.c_str(), "==== MENU ==========");
    munit_assert_string_contains(output.c_str(), "1. Cadastrar Passageiro");
    munit_assert_string_contains(output.c_str(), "2. Cadastrar Tripulacao");
    munit_assert_string_contains(output.c_str(), "3. Cadastrar Voo");
    munit_assert_string_contains(output.c_str(), "4. Realizar Reserva");
    munit_assert_string_contains(output.c_str(), "5. Baixa em Reservas");
    munit_assert_string_contains(output.c_str(), "6. Pesquisa");
    munit_assert_string_contains(output.c_str(), "7. Consultar Programa de Fidelidade");
    munit_assert_string_contains(output.c_str(), "8. Sair");

    return MUNIT_OK;
}

// Definição dos testes
static MunitTest tests[] = {
    { (char*) "/test_menu", test_menu, test_setup, test_tear_down, MUNIT_TEST_OPTION_NONE, NULL },
    // ... outros testes ...
    { NULL, NULL, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL }
};

// Definição da suíte de testes
static const MunitSuite suite = {
    (char*) "/test_suite", tests, NULL, 1, MUNIT_SUITE_OPTION_NONE
};

// Função principal para executar os testes
int main(int argc, char* argv[MUNIT_ARRAY_PARAM(argc + 1)]) {
    return munit_suite_main(&suite, NULL, argc, argv);
}

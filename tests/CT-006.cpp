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

// Teste para a função de baixa de reserva
static MunitResult test_baixa_reserva(const MunitParameter params[], void* fixture) {
    // Configurar dados de teste
    Reserva reserva;
    reserva.setCodReserva(1);
    reserva.setCodPassageiro(1);
    reserva.setCodVoo(1);
    reserva.setNumAssento(1);

    // Salvar a reserva no arquivo
    salvarReservaNoArquivo(reserva);

    // Chamar a função de baixa de reserva
    baixaReserva();

    // Verificar se a reserva foi removida corretamente
    ifstream arquivo("reservas.txt");
    bool reservaEncontrada = false;
    string linha;
    while (getline(arquivo, linha)) {
        if (linha.find("Codigo da Reserva: 1") != string::npos) {
            reservaEncontrada = true;
            break;
        }
    }
    arquivo.close();

    // Verificar se a reserva não foi encontrada
    munit_assert_false(reservaEncontrada);

    return MUNIT_OK;
}

// Definição dos testes
static MunitTest tests[] = {
    { (char*) "/test_baixa_reserva", test_baixa_reserva, test_setup, test_tear_down, MUNIT_TEST_OPTION_NONE, NULL },
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

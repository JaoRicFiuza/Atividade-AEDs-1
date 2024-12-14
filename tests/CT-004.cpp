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

// Função mock para simular a escrita no arquivo
void mockSalvarReservaNoArquivo(Reserva &r, char *output) {
    // Simulando a gravação de dados em uma string (em vez de um arquivo)
    sprintf(output, "Codigo da Reserva: %d\nCodigo do Passageiro: %d\nCodigo do Voo: %d\nNumero do Assento: %d\n------------------------\n",
            r.getCodReserva(), r.getCodPassageiro(), r.getCodVoo(), r.getNumAssento());
}

// Teste unitário para a função salvarReservaNoArquivo
static MunitResult test_salvarReservaNoArquivo(const MunitParameter params[], void *data) {
    Reserva r;
    // Inicializando o objeto Reserva com dados de teste
    r.setCodReserva(98765);
    r.setCodPassageiro(12345);
    r.setCodVoo(54321);
    r.setNumAssento(12);

    // Usamos uma string para armazenar a saída gerada pela função mock
    char output[256];
    mockSalvarReservaNoArquivo(r, output);

    // Verificando se os dados gravados são os esperados
    munit_assert_string_equal(output, "Codigo da Reserva: 98765\nCodigo do Passageiro: 12345\nCodigo do Voo: 54321\nNumero do Assento: 12\n------------------------\n");

    return MUNIT_OK; // Retorno indicando que o teste passou
}

// Definindo o conjunto de testes
static MunitTest tests[] = {
    {"/test_salvarReservaNoArquivo", test_salvarReservaNoArquivo, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL},
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

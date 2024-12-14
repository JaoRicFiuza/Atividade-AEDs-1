#include <iostream>
#include <fstream>
#include <string.h>
#include <cassert>
#include "munit.h"

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

// Função mock para simular a escrita no arquivo
void mockSalvarVooNoArquivo(Voo &v, std::string &output) {
    output = "";
    output += "Codigo do Voo: " + std::to_string(v.getCodVoo()) + "\n";
    output += "Data do Voo: " + v.getData() + "\n";
    output += "Hora do Voo: " + v.getHora() + "\n";
    output += "Origem do Voo: " + v.getOrigem() + "\n";
    output += "Destino do Voo: " + v.getDestino() + "\n";
    output += "Codigo do Avião: " + v.getCodAviao() + "\n";
    output += "Codigo do Piloto: " + v.getCodPiloto() + "\n";
    output += "Codigo do Copiloto: " + v.getCodCopiloto() + "\n";
    output += "Codigo do Comissario(a): " + v.getCodComisario() + "\n";
    output += "Status do Voo: " + (v.getStatus() ? "Ativo" : "Inativo") + "\n";
    output += "Tarifa do Voo: " + std::to_string(v.getTarifa()) + "\n";
    output += "-------------------------\n";
}

// Teste unitário
static char *test_salvarVooNoArquivo() {
    Voo v;
    // Inicializando o objeto Voo com dados de teste
    v.setCodVoo(12345);
    v.setData("2024-12-13");
    v.setHora("14:30");
    v.setOrigem("São Paulo");
    v.setDestino("Rio de Janeiro");
    v.setCodAviao("A321");
    v.setCodPiloto("P123");
    v.setCodCopiloto("C456");
    v.setCodComisario("M789");
    v.setStatus(true);
    v.setTarifa(350.75);

    std::string output;
    mockSalvarVooNoArquivo(v, output);

    // Verificar se os dados foram escritos corretamente
    mu_assert("Erro: Código do voo não corresponde", output.find("Codigo do Voo: 12345") != std::string::npos);
    mu_assert("Erro: Data do voo não corresponde", output.find("Data do Voo: 2024-12-13") != std::string::npos);
    mu_assert("Erro: Hora do voo não corresponde", output.find("Hora do Voo: 14:30") != std::string::npos);
    mu_assert("Erro: Origem do voo não corresponde", output.find("Origem do Voo: São Paulo") != std::string::npos);
    mu_assert("Erro: Destino do voo não corresponde", output.find("Destino do Voo: Rio de Janeiro") != std::string::npos);
    mu_assert("Erro: Código do avião não corresponde", output.find("Codigo do Avião: A321") != std::string::npos);
    mu_assert("Erro: Código do piloto não corresponde", output.find("Codigo do Piloto: P123") != std::string::npos);
    mu_assert("Erro: Código do copiloto não corresponde", output.find("Codigo do Copiloto: C456") != std::string::npos);
    mu_assert("Erro: Código do comissário não corresponde", output.find("Codigo do Comissario(a): M789") != std::string::npos);
    mu_assert("Erro: Status do voo não corresponde", output.find("Status do Voo: Ativo") != std::string::npos);
    mu_assert("Erro: Tarifa do voo não corresponde", output.find("Tarifa do Voo: 350.75") != std::string::npos);

    return 0;
}

static char *all_tests() {
    mu_run_test(test_salvarVooNoArquivo);
    return 0;
}

int main() {
    char *result = all_tests();
    if (result != 0) {
        std::cerr << result << std::endl;
    } else {
        std::cout << "Todos os testes passaram!" << std::endl;
    }
    return 0;
}

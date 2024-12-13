# **✈️Sistema de Gerenciamento de Reservas de Voos**

Este software é um sistema de gerenciamento de reservas de voos, permitindo o cadastro de passageiros, tripulação, voos e reservas. A seguir, estão as principais funcionalidades do sistema.

# Funcionalidades

## Classes

### Pessoa
Classe base para representar informações básicas de uma pessoa.
#### Atributos:
- **codigo:** Código único da pessoa.
- **nome:** Nome da pessoa.
- **endereco:** Endereço da pessoa.
- **tel:** Telefone de contato.
#### Métodos:
Getters e setters para todos os atributos.

### Passageiro (herda de Pessoa)
Representa um passageiro com informações adicionais.
#### Atributos:
- **codPassageiro:** Código único do passageiro.
- **fidelidade:** Indica se o passageiro participa do programa de fidelidade.
#### Métodos:
Getters e setters para os atributos adicionais.

### Tripulacao (herda de Pessoa)
Representa um membro da tripulação.
#### Atributos:
- **cargo:** Tipo de cargo (1 = Piloto, 2 = Copiloto, 3 = Comissário).
#### Métodos:
Getters e setters para o cargo.

### Voo
Representa um voo com detalhes específicos.
#### Atributos:
- **codAviao, codComisario, codPiloto, codCopiloto, codVoo:** Códigos relacionados ao voo.
- **data, hora, origem, destino:** Informações de tempo e local do voo.
- **status:** Indica se o voo está ativo.
- **tarifa:** Preço do voo.
#### Métodos:
Getters e setters para todos os atributos.

### Assento
Representa um assento em um voo.
#### Atributos:
- **numAssento:** Número do assento.
- **status:** Indica se o assento está ocupado.
#### Métodos:
Getters e setters para os atributos.

### Reserva (herda de Passageiro, Voo, Assento)
Representa uma reserva vinculando passageiro, voo e assento. (não possui métodos ou atributos próprios no código fornecido)

## Funções Principais

### Gerenciamento de Passageiros

## **1. 📋Cadastro de Passageiro**
**Descrição:** Permite ao usuário cadastrar um novo passageiro no sistema.

**Informações solicitadas:**
- Nome
- Endereço
- Telefone
- Deseja participar do programa de fidelidade? (Sim/Não)

- **gerarCodigoPassageiro():** Gera e salva um código único para um passageiro.
- **salvarPassageiroNoArquivo(Passageiro&):** Salva informações de um passageiro em um arquivo de texto.
- **cadastroPassageiro():** Realiza o cadastro de um novo passageiro.
### Gerenciamento de Tripulação

## **2. 👩‍✈️Cadastro de Tripulação**
**Descrição:** Permite ao usuário cadastrar um novo membro da tripulação (piloto, copiloto ou comissário).

**Informações solicitadas:**
- Nome
- Endereço
- Telefone
- Cargo (1-Piloto, 2-Copiloto, 3-Comissário)

- **gerarCodigoTripulante():** Gera e salva um código único para um tripulante.
- **salvarTripulacaoNoArquivo(Tripulacao&):** Salva informações de um tripulante em um arquivo.
- **cadastroTripulacao():** Cadastra um novo membro da tripulação.
- **verificarCodigoTripulacao(int):** Verifica a existência de um tripulante pelo código.
### Gerenciamento de Voos

## **3. 🛬Cadastro de Voo**
**Descrição:** Permite ao usuário cadastrar um novo voo, incluindo detalhes da tripulação.

**Informações solicitadas:**
- Origem
- Destino
- Data do voo (DD/MM/AAAA)
- Hora do voo (HH:MM)
- Tarifa
- Quantidade de assentos
- Códigos dos tripulantes (piloto, copiloto e comissário)

- **cadastroVoo():** Cadastra um novo voo, associando tripulação e informações gerais.
- **verificarCodigoVoo(int):** Verifica a existência de um voo pelo código.
### Gerenciamento de Assentos
- **criarAssento(int, vector<Assento>&):** Cria um conjunto de assentos para um voo.
- **cadastroAssento():** Permite cadastrar assentos para um voo específico.
### Outras Funcionalidades
- **reserva():** (incompleta) Planejada para gerenciar reservas de assentos.

## **4. ✅Realizar Reserva**
**Descrição:** Permite ao usuário realizar uma reserva de assento em um voo.

**Informações solicitadas:**
- Código do passageiro
- Código do voo
- Número do assento

**Validações:**
- Verifica se o passageiro e o voo existem.
- Verifica se o assento está disponível.

- **baixaReserva():** (incompleta) Planejada para cancelar ou baixar reservas.

## **5. ❌Baixa em Reservas**
**Descrição:** Permite ao usuário cancelar uma reserva existente.

**Informações solicitadas:**
- Código da reserva

**Processo:**
- Atualiza o status do assento para disponível.
- Adiciona pontos de fidelidade ao passageiro.


- **pesquisa():** (incompleta) Planejada para pesquisa de informações.

## **6. 🔎Pesquisa**
**Descrição:** Permite ao usuário pesquisar informações sobre passageiros ou tripulantes.

**Opções de pesquisa:**
- Código do passageiro
- Código do tripulante


- **programaFid():** (incompleta) Planejada para consultar o programa de fidelidade.

## **7. 💲Consultar Programa de Fidelidade**
**Descrição:** Exibe todos os passageiros que participam do programa de fidelidade.

### Função main
- Exibe o menu principal.
- Permite o acesso às funções mencionadas de acordo com a escolha do usuário.

## **8. 🌐Menu Principal**
**Descrição:** O usuário pode acessar as funcionalidades do sistema através de um menu interativo.

**Opções disponíveis:**
- Cadastrar Passageiro
- Cadastrar Tripulação
- Cadastrar Voo
- Realizar Reserva
- Baixa em Reservas
- Pesquisa
- Consultar Programa de Fidelidade
- Sair

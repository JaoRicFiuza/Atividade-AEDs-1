# **Sistema de Gerenciamento de Reservas de Voos**

Este software é um sistema de gerenciamento de reservas de voos, permitindo o cadastro de passageiros, tripulação, voos e reservas. A seguir, estão as principais funcionalidades do sistema.

## **1. Cadastro de Passageiro**
**Descrição:** Permite ao usuário cadastrar um novo passageiro no sistema.

**Informações solicitadas:**
- Nome
- Endereço
- Telefone
- Deseja participar do programa de fidelidade? (Sim/Não)

**Armazenamento:** Os dados são salvos em um arquivo chamado `passageiros.txt`.

---

## **2. Cadastro de Tripulação**
**Descrição:** Permite ao usuário cadastrar um novo membro da tripulação (piloto, copiloto ou comissário).

**Informações solicitadas:**
- Nome
- Endereço
- Telefone
- Cargo (1-Piloto, 2-Copiloto, 3-Comissário)

**Armazenamento:** Os dados são salvos em um arquivo chamado `tripulacao.txt`.

---

## **3. Cadastro de Voo**
**Descrição:** Permite ao usuário cadastrar um novo voo, incluindo detalhes da tripulação.

**Informações solicitadas:**
- Origem
- Destino
- Data do voo (DD/MM/AAAA)
- Hora do voo (HH:MM)
- Tarifa
- Quantidade de assentos
- Códigos dos tripulantes (piloto, copiloto e comissário)

**Armazenamento:** Os dados são salvos em um arquivo chamado `voo.txt`, e os assentos são salvos em `assentos_voo.txt`.

---

## **4. Realizar Reserva**
**Descrição:** Permite ao usuário realizar uma reserva de assento em um voo.

**Informações solicitadas:**
- Código do passageiro
- Código do voo
- Número do assento

**Validações:**
- Verifica se o passageiro e o voo existem.
- Verifica se o assento está disponível.

**Armazenamento:** Os dados da reserva são salvos em `reservas.txt`.

---

## **5. Baixa em Reservas**
**Descrição:** Permite ao usuário cancelar uma reserva existente.

**Informações solicitadas:**
- Código da reserva

**Processo:**
- Atualiza o status do assento para disponível.
- Adiciona pontos de fidelidade ao passageiro.

**Armazenamento:** Atualiza o arquivo `reservas.txt`.

---

## **6. Pesquisa**
**Descrição:** Permite ao usuário pesquisar informações sobre passageiros ou tripulantes.

**Opções de pesquisa:**
- Código do passageiro
- Código do tripulante

**Armazenamento:** Busca nos arquivos `passageiros.txt` e `tripulacao.txt`.

---

## **7. Consultar Programa de Fidelidade**
**Descrição:** Exibe todos os passageiros que participam do programa de fidelidade.

**Armazenamento:** Busca no arquivo `passageiros.txt`.

---

## **8. Menu Principal**
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

---

## **Considerações Finais**
O sistema é projetado para ser fácil de usar e fornecer um gerenciamento eficiente de reservas de voos. Todos os dados são armazenados em arquivos de texto, permitindo fácil acesso e manipulação.

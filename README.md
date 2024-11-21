# ✈️ Sistema de Gerenciamento de Voos - Voo Seguro

![Status](https://img.shields.io/badge/Status-Em%20Andamento-yellow)
![Linguagens](https://img.shields.io/badge/Linguagens-C%20%2F%20C++-blue)

Este projeto foi desenvolvido como parte das disciplinas Fundamentos de Engenharia de Software (FES) e Algoritmos e Estruturas de Dados I (AED1) do curso de Engenharia de Software do [Instituto de Ciências Exatas e Informática](https://icei.pucminas.br/?gad_source=1&gclid=CjwKCAiArva5BhBiEiwA-oTnXdCnMa9BwftKnp9VrxYLVeUk7vv-kEKfbODp7snA781vZwaL6BVa8RoCN7sQAvD_BwE) da [Pontifícia Universidade Católica de Minas Gerais](https://www.pucminas.br/destaques/Paginas/default.aspx). O objetivo é criar um sistema para gerenciar voos, tripulação e reservas, otimizando os processos da companhia aérea fictícia Voo Seguro.

---

## 📖 Tabela de Conteúdo
1. [Professores Responsáveis](#professores-responsáveis)
2. [Equipe](#equipe)
3. [Descrição do Sistema](#descrição-do-sistema)
4. [Funcionalidades](#funcionalidades)
5. [Tecnologias Utilizadas](#tecnologias-utilizadas)
6. [Contribuições](#contribuições)

---

## 👨‍🏫 Professores Responsáveis
* Gabriel Souza Gomes
* Jose Laerte Pires Xavier Junior 

---

## 🧑‍💻 Equipe
| Nome                        | Função no Projeto                          |
|-----------------------------|-------------------------------------------|
| Gabriel Victor Souza Lopes  | Desenvolvimento do módulo de reservas e fidelidade |
| João Ricardo Fiuza          | Cadastro de passageiros e testes          |
| João Pedro Maciel           | Gerenciamento de voos                     |
| Felipe                      | Persistência de dados e integração        |

---

## ✍️ Descrição do Sistema
O sistema gerencia as seguintes informações da companhia aérea:

1. **Passageiros:** Cadastro, pesquisa e gerenciamento de dados.
2. **Tripulação:** Cadastro de pilotos, copilotos e comissários.
3. **Voos:** Controle de informações como data, hora, origem, destino e tripulação.
4. **Assentos:** Controle de reservas e disponibilidade.
5. **Reservas:** Gerenciamento de assentos e cálculo de valores pagos.
6. **Fidelidade:** Programa de pontos para passageiros frequentes.

---

## ⚙️ Funcionalidades

### 1. **Cadastro**
- Cadastro de passageiros, tripulação e voos.
- Geração de código automática para evitar duplicatas.

### 2. **Reservas**
- Verifica disponibilidade de assentos antes de reservar.
- Evita reservas duplicadas para o mesmo voo.

### 3. **Fidelidade**
- Pontuação automática (10 pontos por voo).
- Relatório de pontos acumulados.

### 4. **Persistência**
- Dados armazenados em arquivos binários para maior segurança.

---

## 🛠 Tecnologias Utilizadas
- **Linguagens:** C/C++
- **Armazenamento:** Arquivos binários
- **Metodologia:** Scrum, com planejamento em sprints.


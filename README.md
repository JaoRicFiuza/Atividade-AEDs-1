# Sistema de Gerenciamento de Voos - Voo Seguro
Este projeto foi desenvolvido como parte das disciplinas Fundamentos de Engenharia de Software (FES) e Algoritmos e Estruturas de Dados I (AED1) do curso de Engenharia de Software da Pontifícia Universidade Católica de Minas Gerais. O objetivo é criar um sistema para gerenciar voos, tripulação e reservas, otimizando os processos da companhia aérea fictícia Voo Seguro.

# Professores Responsáveis
[Nome do Professor 1]
[Nome do Professor 2]

# Integrantes do Grupo
[Nome do Aluno 1]
[Nome do Aluno 2]
[Nome do Aluno 3]
[Nome do Aluno 4]

# Descrição do Sistema
O sistema gerencia as seguintes informações da companhia aérea:

Passageiros: Cadastro, pesquisa e gerenciamento de dados.
Tripulação: Cadastro de pilotos, copilotos e comissários.
Voos: Controle de informações como data, hora, origem, destino, e tripulação.
Assentos: Controle de reservas e disponibilidade.
Reservas: Gerenciamento de reservas de assentos e cálculo de valores pagos.
Programa de Fidelidade: Acúmulo de pontos para passageiros.

# Funcionalidades
Cadastro de Passageiros, Tripulação e Voos.
Reservas de Assentos:
Verifica a disponibilidade antes de concluir.
Impede reservas duplicadas.
Pesquisa:
Busca por passageiros ou tripulação pelo nome ou código.
Listagem de todos os voos de um passageiro.
Gerenciamento de Fidelidade:
Pontuação automática de passageiros com base nos voos realizados.
Validação de Restrições:
Cada voo requer ao menos um piloto e um copiloto.
Assentos não podem ser duplicados em um mesmo voo.
Armazenamento Persistente:
Todas as informações são salvas em arquivos binários para garantir a integridade dos dados.

# Tecnologias Utilizadas
Linguagens: C/C++
Armazenamento: Arquivos binários para leitura e escrita.
Metodologia: Scrum, com planejamento em sprints.

# Contribuições de Cada Integrante
[Nome do Aluno 1]: Implementação do módulo de cadastro de passageiros e testes.
[Nome do Aluno 2]: Desenvolvimento do módulo de reservas e fidelidade.
[Nome do Aluno 3]: Gerenciamento de voos e validação de tripulação.
[Nome do Aluno 4]: Persistência de dados e integração dos módulos.
Instruções para Teste


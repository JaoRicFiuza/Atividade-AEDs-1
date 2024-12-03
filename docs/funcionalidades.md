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
- **gerarCodigoPassageiro():** Gera e salva um código único para um passageiro.
- **salvarPassageiroNoArquivo(Passageiro&):** Salva informações de um passageiro em um arquivo de texto.
- **cadastroPassageiro():** Realiza o cadastro de um novo passageiro.
### Gerenciamento de Tripulação
- **gerarCodigoTripulante():** Gera e salva um código único para um tripulante.
- **salvarTripulacaoNoArquivo(Tripulacao&):** Salva informações de um tripulante em um arquivo.
- **cadastroTripulacao():** Cadastra um novo membro da tripulação.
- **verificarCodigoTripulacao(int):** Verifica a existência de um tripulante pelo código.
### Gerenciamento de Voos
- **cadastroVoo():** Cadastra um novo voo, associando tripulação e informações gerais.
- **verificarCodigoVoo(int):** Verifica a existência de um voo pelo código.
### Gerenciamento de Assentos
- **criarAssento(int, vector<Assento>&):** Cria um conjunto de assentos para um voo.
- **cadastroAssento():** Permite cadastrar assentos para um voo específico.
### Outras Funcionalidades
- **reserva():** (incompleta) Planejada para gerenciar reservas de assentos.
- **baixaReserva():** (incompleta) Planejada para cancelar ou baixar reservas.
- **pesquisa():** (incompleta) Planejada para pesquisa de informações.
- **programaFid():** (incompleta) Planejada para consultar o programa de fidelidade.
### Função main
- Exibe o menu principal.
- Permite o acesso às funções mencionadas de acordo com a escolha do usuário.

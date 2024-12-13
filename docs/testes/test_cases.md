# Planejamento dos Casos de Teste

## Introdução
Descreva brevemente o objetivo dos testes e o escopo do sistema a ser testado.

## Estrutura dos Casos de Teste
Cada caso de teste será descrito usando o seguinte formato:
- **ID**: Identificador único do caso de teste.
- **Descrição**: O que será testado.
- **Entradas**: Os dados necessários para o teste.
- **Procedimento de Teste**: As etapas para executar o teste.
- **Saídas Esperadas**: Os resultados esperados.

---

## Casos de Teste

### Caso de Teste 1
- **ID**: CT-001
- **Descrição**: Realizar cadastro de Passageiro
- **Entradas**:
  - Nome: `testuser`
  - Endereço: `enderecoTest`
  - Telefone: `(31) 9 9999-9999`
  - Fidelidade: `s`
- **Procedimento de Teste**:
  1. Selecionar a opção 1 no menu.
  2. Inserir as informações.
- **Saídas Esperadas**:
  - Criação do código unico do passageiro.
  - Salvar as informações no arquivo.

### Caso de Teste 2
- **ID**: CT-002
- **Descrição**: Realizar cadastro de Tripulante (Piloto)
- **Entradas**:
  - Nome: `testuser`
  - Endereço: `enderecoTest`
  - Telefone: `(31) 9 9999-9999`
  - Cargo: `1`
- **Procedimento de Teste**:
  1. Selecionar a opção 2 no menu.
  2. Inserir as informações.
- **Saídas Esperadas**:
  - Criação do código unico do tripulante.
  - Salvar as informações no arquivo.

### Caso de Teste 3
- **ID**: CT-003
- **Descrição**: Realizar cadastro de Tripulante (Copiloto)
- **Entradas**:
  - Nome: `testuser`
  - Endereço: `enderecoTest`
  - Telefone: `(31) 9 9999-9999`
  - Cargo: `2`
- **Procedimento de Teste**:
  1. Selecionar a opção 2 no menu.
  2. Inserir as informações.
- **Saídas Esperadas**:
  - Criação do código unico do tripulante.
  - Salvar as informações no arquivo.

### Caso de Teste 4
- **ID**: CT-004
- **Descrição**: Realizar cadastro de Tripulante (Comissário)
- **Entradas**:
  - Nome: `testuser`
  - Endereço: `enderecoTest`
  - Telefone: `(31) 9 9999-9999`
  - Cargo: `3`
- **Procedimento de Teste**:
  1. Selecionar a opção 2 no menu.
  2. Inserir as informações.
- **Saídas Esperadas**:
  - Criação do código unico do tripulante.
  - Salvar as informações no arquivo.
 
### Caso de Teste 5
- **ID**: CT-005
- **Descrição**: Cadastro de Voo
- **Entradas**:
  - Origem: `Belo Horizonte`
  - Destino: `Paris`
  - Data: `31/12/2024`
  - Hora: `13:00`
  - Tarifa: `1000.00`
  - Numero de Assentos: `100`
  - Código do Piloto: `1`
  - Código do Copiloto: `1`
  - Código do Comissario: `1`
- **Procedimento de Teste**:
  1. Selecionar a opção 3 no menu.
  2. Inserir as informações.
- **Saídas Esperadas**:
  - Criação do código unico do voo.
  - Salvar as informações no arquivo.
 
### Caso de Teste 6
- **ID**: CT-006
- **Descrição**: Realizar reserva
- **Entradas**:
  - Código do passageiro: `1`
  - Código do voo: `1`
  - Número do assento: `1`
- **Procedimento de Teste**:
  1. Selecionar a opção 4 no menu.
  2. Inserir as informações.
- **Saídas Esperadas**:
  - Salvar as informações no arquivo.
 
### Caso de Teste 7
- **ID**: CT-007
- **Descrição**: Baixa em reserva
- **Entradas**:
  - Código do reserva: `1`
- **Procedimento de Teste**:
  1. Selecionar a opção 5 no menu.
  2. Inserir as informações.
- **Saídas Esperadas**:
  - Salvar as informações no arquivo.
 
### Caso de Teste 8
- **ID**: CT-008
- **Descrição**: Pesquisa Passageiro
- **Entradas**:
  - Código do passageiro: `1`
- **Procedimento de Teste**:
  1. Selecionar a opção 6 no menu.
  2. Selecionar a opção 1.
  3. Inserir as informações.
- **Saídas Esperadas**:
  - Retornar informações.
 
### Caso de Teste 9
- **ID**: CT-009
- **Descrição**: Pesquisa Tripulante
- **Entradas**:
  - Código do passageiro: `1`
- **Procedimento de Teste**:
  1. Selecionar a opção 6 no menu.
  2. Selecionar a opção 2.
  3. Inserir as informações.
- **Saídas Esperadas**:
  - Retornar informações.

---

## Observações
Inclua aqui quaisquer considerações ou notas relevantes sobre o processo de teste.

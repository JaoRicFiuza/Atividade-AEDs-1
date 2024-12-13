# Test Cases

## Caso de Teste 1  
**ID:** CT-001  
**Descrição:** Testar a funcionalidade de cadastro de um passageiro com informações válidas.  

### Entradas:
- **Nome:** testuser  
- **Endereço:** enderecoTest  
- **Telefone:** (31) 9 9999-9999  
- **Fidelidade:** s (Sim)  

### Procedimento de Teste:
1. Iniciar o sistema.
2. Selecionar a opção "1 - Cadastrar Passageiro".
3. Inserir os seguintes dados nos respectivos campos:
   - Nome: testuser
   - Endereço: enderecoTest
   - Telefone: (31) 9 9999-9999
   - Fidelidade: s

### Saídas Esperadas:
1. Exibição de uma mensagem confirmando o cadastro, incluindo o código único do passageiro no formato "X" (onde "X" é um número sequencial).
2. Persistência dos dados inseridos no arquivo `passageiros.txt`.
3. O arquivo deve conter os seguintes dados, separados por linha:
   ```
   Código, Nome, Endereço, Telefone, Fidelidade
   ```

---

## Caso de Teste 2  
**ID:** CT-002  
**Descrição:** Testar a funcionalidade de cadastro de um tripulante com cargo de Piloto, utilizando dados válidos.  

### Entradas:  
- **Nome:** testuser  
- **Endereço:** enderecoTest  
- **Telefone:** (31) 9 9999-9999  
- **Cargo:** 1 (Piloto)  

### Procedimento de Teste:
1. Iniciar o sistema e navegar até o menu principal.
2. Selecionar a opção "2 - Cadastrar Tripulante".
3. Inserir os seguintes dados nos respectivos campos:
   - Nome: testuser
   - Endereço: enderecoTest
   - Telefone: (31) 9 9999-9999
   - Cargo: 1 (Piloto)
4. Confirmar o cadastro.

### Saídas Esperadas:
1. Exibição de uma mensagem confirmando o cadastro, incluindo o código único do tripulante no formato "X" (onde "X" é um número sequencial).
2. Persistência dos dados inseridos no arquivo `pilotos.txt`.
3. O arquivo deve conter os seguintes dados, separados por linha:
   ```
   Código, Nome, Endereço, Telefone, Cargo
   ```
4. O valor do campo Cargo deve ser traduzido no arquivo como "Piloto".

---

## Caso de Teste 3  
**ID:** CT-003  
**Descrição:** Testar a funcionalidade de cadastro de um tripulante com cargo de Copiloto, utilizando dados válidos.  

### Entradas:
- **Nome:** testuser  
- **Endereço:** enderecoTest  
- **Telefone:** (31) 9 9999-9999  
- **Cargo:** 2 (Copiloto)  

### Procedimento de Teste:
1. Iniciar o sistema e navegar até o menu principal.
2. Selecionar a opção "2 - Cadastrar Tripulante".
3. Inserir os seguintes dados nos respectivos campos:
   - Nome: testuser
   - Endereço: enderecoTest
   - Telefone: (31) 9 9999-9999
   - Cargo: 2 (Copiloto)
4. Confirmar o cadastro.

### Saídas Esperadas:
1. Exibição de uma mensagem confirmando o cadastro, incluindo o código único do tripulante no formato "X" (onde "X" é um número sequencial).
2. Persistência dos dados inseridos no arquivo `copilotos.txt`.
3. O arquivo deve conter os seguintes dados, separados por linha:
   ```
   Código, Nome, Endereço, Telefone, Cargo
   ```
4. O valor do campo Cargo deve ser traduzido no arquivo como "Copiloto".

---

## Caso de Teste 4  
**ID:** CT-004  
**Descrição:** Testar a funcionalidade de cadastro de um tripulante com cargo de Comissário, utilizando dados válidos.  

### Entradas:
- **Nome:** testuser  
- **Endereço:** enderecoTest  
- **Telefone:** (31) 9 9999-9999  
- **Cargo:** 3 (Comissário)  

### Procedimento de Teste:
1. Iniciar o sistema e acessar o menu principal.
2. Selecionar a opção "2 - Cadastrar Tripulante".
3. Preencher os campos solicitados com os seguintes valores:
   - Nome: testuser
   - Endereço: enderecoTest
   - Telefone: (31) 9 9999-9999
   - Cargo: 3 (Comissário).
4. Confirmar o cadastro.

### Saídas Esperadas:
1. Exibição de uma mensagem confirmando o cadastro do tripulante, incluindo o código único gerado no formato "X" (onde "X" é um número sequencial).
2. Persistência dos dados no arquivo `comissarios.txt`.
3. O arquivo deve conter os seguintes dados, separados por linha:
   ```
   Código, Nome, Endereço, Telefone, Cargo
   ```
4. O valor do campo Cargo deve ser traduzido no arquivo como "Comissário".

---

## Caso de Teste 5  
**ID:** CT-005  
**Descrição:** Testar a funcionalidade de cadastro de um voo com dados válidos fornecidos pelo usuário.  

### Entradas:
- **Origem:** Belo Horizonte  
- **Destino:** Paris  
- **Data:** 31/12/2024  
- **Hora:** 13:00  
- **Tarifa:** 1000.00  
- **Número de Assentos:** 100  
- **Código do Piloto:** 1  
- **Código do Copiloto:** 1  
- **Código do Comissário:** 1  

### Procedimento de Teste:
1. Iniciar o sistema e acessar o menu principal.
2. Selecionar a opção "3 - Cadastrar Voo".
3. Preencher os campos solicitados com os seguintes valores:
   - Origem: Belo Horizonte
   - Destino: Paris
   - Data: 31/12/2024
   - Hora: 13:00
   - Tarifa: 1000.00
   - Número de Assentos: 100
   - Código do Piloto: 1
   - Código do Copiloto: 1
   - Código do Comissário: 1
4. Confirmar o cadastro.

### Saídas Esperadas:
1. Exibição de uma mensagem confirmando o cadastro do voo, incluindo o código único gerado no formato "X" (onde "X" é um número sequencial).
2. Persistência dos dados no arquivo `voo.txt` (ou equivalente configurado no sistema).
3. O arquivo deve conter os seguintes dados, separados por linha:
   ```
   Código, Origem, Destino, Data, Hora, Tarifa, Número de Assentos, Código do Piloto, Código do Copiloto, Código do Comissário
   ```
4. A verificação deve confirmar que os dados armazenados correspondem exatamente às informações inseridas pelo usuário.

---

## Caso de Teste 6  
**ID**: CT-006  
**Descrição**: Testar a funcionalidade de reserva de assento para um passageiro em um voo já cadastrado no sistema.  

### Entradas:  
- Código do Passageiro: 1  
- Código do Voo: 1  
- Número do Assento: 1  

### Procedimento de Teste:  
1. Iniciar o sistema e acessar o menu principal.  
2. Selecionar a opção "4 - Realizar Reserva".  
3. Preencher os campos solicitados com os seguintes valores:  
   - Código do Passageiro: 1  
   - Código do Voo: 1  
   - Número do Assento: 1  
4. Confirmar a reserva.  

### Saídas Esperadas:  
1. Exibição de uma mensagem de sucesso, confirmando a reserva com os detalhes inseridos.  
2. Persistência dos dados no arquivo `reservas.txt`.
3. O arquivo deve conter os seguintes dados, separados por linha:  
   `Código da Reserva, Código do Passageiro, Código do Voo, Número do Assento`. 
4. Persistência dos dados no arquivo `assentos.txt`.
5. Atualização do arquivo `assentos.txt` para refletir a mudança no status do assento:  
   - O número do assento associado à reserva cancelada deve ser marcado como "Ocupado" no arquivo `assentos.txt`.  
   `Código do Voo: X`
   `Assento 1: Disponivel`
   `Assento 2: Ocupado`  
   - O **Código da Reserva** deve ser único e gerado automaticamente pelo sistema no formato "X" (onde "X" é um número sequencial).  
6. A verificação deve confirmar que os dados armazenados correspondem exatamente às informações inseridas pelo usuário.  
7. Garantia de que o número do assento não está duplicado no mesmo voo. Caso já esteja reservado, exibir uma mensagem de erro informando o conflito.  

---

## Caso de Teste 7  
**ID**: CT-007  
**Descrição**: Testar a funcionalidade de cancelamento (baixa) de uma reserva existente no sistema.  

### Entradas:  
- Código da Reserva: 1  

### Procedimento de Teste:  
1. Iniciar o sistema e acessar o menu principal.  
2. Selecionar a opção "5 - Cancelar Reserva".  
3. Inserir o **Código da Reserva** solicitado com o valor: `1`.  
4. Confirmar a operação de cancelamento.  

### Saídas Esperadas:  
1. Exibição de uma mensagem de sucesso informando que a reserva foi cancelada com sucesso:  
   - Exemplo: *"Reserva 1 cancelada com sucesso."*  
2. Atualização do arquivo `reservas.txt` para refletir o cancelamento:  
   - A linha correspondente à reserva cancelada deve ser removida ou marcada como cancelada (dependendo da implementação do sistema).  
   - Se marcada como cancelada, adicionar um campo "Status" com o valor "Cancelada".  
3. Atualização do arquivo `assentos.txt` para refletir a mudança no status do assento:  
   - O número do assento associado à reserva cancelada deve ser marcado como "Disponível" no arquivo `assentos.txt`.  
   - Exemplo:  
     ```
     Código do Voo: 1
     Assento 1: Disponível
     Assento 2: Ocupado
     ```  
4. Garantia de que a reserva não estará mais disponível para uso (ou seja, o número do assento associado à reserva será liberado para novas reservas).  
5. Em caso de erro (reserva não encontrada), exibição de uma mensagem informando que o **Código da Reserva** não existe.  
   - Exemplo: *"Erro: Reserva 1 não encontrada."*  

---

## Caso de Teste 8  
**ID**: CT-008  
**Descrição**: Testar a funcionalidade de pesquisa e exibição das informações de um passageiro cadastrado no sistema.  

### Entradas:  
- Código do Passageiro: 1  

### Procedimento de Teste:  
1. Iniciar o sistema e acessar o menu principal.  
2. Selecionar a opção "6 - Pesquisar".  
3. Escolher a subopção "1 - Pesquisar Passageiro".  
4. Inserir o **Código do Passageiro** solicitado com o valor: `1`.  
5. Confirmar a operação de pesquisa.  

### Saídas Esperadas:  
1. Exibição das informações completas do passageiro correspondente ao código informado, incluindo:  
   - Código do Passageiro (exemplo: `1`)  
   - Nome (exemplo: `testuser`)  
   - Endereço (exemplo: `enderecoTest`)  
   - Telefone (exemplo: `(31) 9 9999-9999`)  
   - Status de Fidelidade (exemplo: `Sim` ou `Não`).  
2. Caso o **Código do Passageiro** não exista, exibição de uma mensagem de erro:  
   - Exemplo: *"Erro: Passageiro P0001 não encontrado."*  

---

## Caso de Teste 9  
**ID**: CT-009  
**Descrição**: Testar a funcionalidade de pesquisa e exibição das informações de um tripulante cadastrado no sistema.  

### Entradas:  
- Código do Tripulante: 1  

### Procedimento de Teste:  
1. Iniciar o sistema e acessar o menu principal.  
2. Selecionar a opção "6 - Pesquisar".  
3. Escolher a subopção "2 - Pesquisar Tripulante".  
4. Inserir o **Código do Tripulante** solicitado com o valor: `1`.  
5. Confirmar a operação de pesquisa.  

### Saídas Esperadas:  
1. Exibição das informações completas do tripulante correspondente ao código informado, incluindo:  
   - Código do Tripulante (exemplo: `1`)  
   - Nome (exemplo: `testuser`)  
   - Endereço (exemplo: `enderecoTest`)  
   - Telefone (exemplo: `(31) 9 9999-9999`)  
   - Cargo (exemplo: `Piloto`, `Copiloto` ou `Comissário`).  
2. Caso o **Código do Tripulante** não exista, exibição de uma mensagem de erro:  
   - Exemplo: *"Erro: Tripulante 1 não encontrado."*  

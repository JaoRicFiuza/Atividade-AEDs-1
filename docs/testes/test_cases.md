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
- **Descrição**: Verificar se o login é realizado com sucesso para credenciais válidas.
- **Entradas**:
  - Usuário: `testuser`
  - Senha: `password123`
- **Procedimento de Teste**:
  1. Navegar para a página de login.
  2. Inserir as credenciais válidas.
  3. Clicar no botão "Login".
- **Saídas Esperadas**:
  - O usuário é redirecionado para a página inicial.
  - Uma mensagem de boas-vindas é exibida: "Bem-vindo, testuser!".

### Caso de Teste 2
- **ID**: CT-002
- **Descrição**: Testar comportamento do login com credenciais inválidas.
- **Entradas**:
  - Usuário: `wronguser`
  - Senha: `wrongpassword`
- **Procedimento de Teste**:
  1. Navegar para a página de login.
  2. Inserir credenciais inválidas.
  3. Clicar no botão "Login".
- **Saídas Esperadas**:
  - Uma mensagem de erro é exibida: "Usuário ou senha incorretos".
  - O campo de senha é limpo.

---

## Observações
Inclua aqui quaisquer considerações ou notas relevantes sobre o processo de teste.

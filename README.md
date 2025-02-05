# Gerenciador de Contatos

Este é um projeto em C (Programação Estruturada) que implementa um **Gerenciador de Contatos** 
com registro, listagem, pesquisa, edição, remoção e ordenação.

## Funcionalidades

1. **Adicionar Contato**  
2. **Listar Contatos**  
3. **Gerenciar Contatos**  
   - Pesquisar por nome (ou parte dele)
   - Editar dados de um contato
   - Remover um contato
   - Ordenar contatos por nome
4. **Persistência de Dados**  
   - Todos os dados são salvos em `contacts.txt`, sendo recarregados a cada execução.

## Estrutura de Arquivos

- `CMakeLists.txt`: Script de configuração do CMake para facilitar a compilação.  
- `src/main.c`: Ponto de entrada do programa (menu principal + submenu).  
- `src/contacts.c` e `src/contacts.h`: Implementação e cabeçalho das funções de manipulação de contatos (CRUD, ordenação etc.).  
- `contacts.txt`: Arquivo onde os contatos são armazenados (criado automaticamente, caso não exista).

## Como Compilar

1. Crie a pasta de compilação e navegue até ela:
   ```bash
   mkdir build
   cd build
   ```
2. Gere os arquivos de build:
   ```bash
   cmake ..
   ```
3. Compile:
   ```bash
   cmake --build .
   ```
4. Será gerado um executável (em Windows, `ContactManager.exe`; em Linux, `ContactManager`) dentro da pasta `build`.

## Como Executar

- **Windows**:
  ```bash
  .\ContactManager.exe
  ```
- **Linux/Mac**:
  ```bash
  ./ContactManager
  ```

## Contribuindo

1. Faça um fork do projeto.
2. Crie um branch para sua feature (`git checkout -b feature-minha-melhoria`).
3. Commit e push suas alterações.
4. Abra um Pull Request e descreva suas mudanças.

## Licença

CContacts © 2025 por Jorge Hermes está licenciado sob a licença [CC BY-SA 4.0](https://creativecommons.org/licenses/by-sa/4.0/).

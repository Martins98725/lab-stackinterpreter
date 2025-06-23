# Laboratório -  Um REPL para uma máquina baseada em pilha - Etapa 1

> Algoritmos e Estruturas de Dados  
> Bacharelado Interdisciplinar em Ciência e Tecnologia (BICT)  
> Universidade Federal do Maranhão (UFMA) <br>
> Prof. Dr. Sergio Souza Costa

## Objetivo
Desenvolver um interpretador interativo (REPL) em linguagem C que simula uma máquina virtual com arquitetura de pilha, comum em linguagens como Python e Java. O programa deve ser capaz de ler comandos do usuário, avaliá-los e imprimir o resultado de forma contínua.

> Contexto do projeto: <br> Diversas linguagens de programação são compiladas para uma máquina abstrata baseada em Pilha. <br> Nessa máquina, os operandos e os resultados das operações são armazenados em um pilha.

Neste laboratório, construiremos um interpretador para uma linguagem simples que opera sobre uma pilha de inteiros, com suporte posterior a variáveis.

## Desenvolvimento em Etapas
O desenvolvimento deste laboratório foi estruturado em duas etapas principais para facilitar a construção e a compreensão do sistema:

- Etapa 1: Foca na criação do interpretador básico com as operações aritméticas fundamentais utilizando uma pilha.
- Etapa 2: Expande o interpretador, adicionando uma memória de variáveis implementada com uma lista encadeada, permitindo salvar e reutilizar valores.



## 👥 Integrantes
- FABIO DUARTE RIBEIRO
- ICARO GABRYEL ARAUJO MARTINS
- BRENDO HENRY RAIOL FERNANDES
- LUCAS SERRA MELONIO
- CAUA GABRIEL SANTOS BARROS

## 📂 Organização do Projeto (Etapa 1)
O projeto foi organizado seguindo a estrutura sugerida na descrição do laboratório. A separação de responsabilidades é a seguinte:
```shell
  $ tree
 /lab-stackinterpreter
│
├── main.c            // Loop principal REPL
├── interpret.c       // Processamento dos comandos
├── interpret.h
├── stack.c           // Implementação da pilha
├── stack.h
├── README.md
```


## Instruções de Compilação, comandos e Uso
### Pré-requisitos
- Um compilador C (como GCC)

### Instruções de Compilação
1. Abra seu terminal na pasta raiz do projeto.
2. Execute o comando abaixo para compilar todos os arquivos e gerar o executável:
   ```shell
    gcc *.c -o main
   ```
### Como Usar
1. Após a compilação, execute o programa com o seguinte comando:
   ```shell
    ./main
   ```
2. O programa iniciará o modo interativo (REPL). Digite os comandos desejados e pressione Enter.
3. Para encerrar a execução, digite exit.

### Comandos Disponíveis (Etapa 1):
O interpretador suporta os seguintes comandos:

| Comando        | Descrição                                                                               |
| :------------- | :-------------------------------------------------------------------------------------- |
| `push <valor>` | Adiciona (empilha) um número inteiro no topo da pilha.                                  | 
| `add`          | Desempilha dois valores, soma-os e empilha o resultado.                                 | 
| `sub`          | Desempilha dois valores, subtrai o segundo do primeiro e empilha o resultado.            |
| `mul`          | Desempilha dois valores, multiplica-os e empilha o resultado.                           |
| `div`          | Desempilha dois valores, realiza a divisão inteira do primeiro pelo segundo e empilha o resultado. |
| `print`        | Desempilha o valor do topo da pilha e o imprime no console.                             |
| `exit`         | Encerra a execução do programa de forma segura.                                         | 

### 🧪 Exemplo de Interação

```shell
> push 10
> push 5
> add
> print
15
> push 8
> push 2
> div
> print
4
> exit
```

# Máquina baseada em pilha - Etapa 2
## Objetivo
Ampliar a funcionalidade do interpretador da máquina virtual baseado em pilha, implementando uma memória de variáveis usando uma lista encadeada. Esta etapa introduz o uso de variáveis nomeadas e operações entre elas.

**Conceitos Praticados**
- Implementação e uso de **lista encadeada**
- Armazenamento e atualização de variáveis
- Integração entre estruturas de dados: **pilha** e **lista**

## Novos Comandos
push <valor | nome_variável>
- Se for um número inteiro: empilha normalmente.
- Se for o nome de uma variável:
  - Busca na lista encadeada pelo nome.
  - Se encontrada, empilha o valor.
- Se não encontrada, exibe erro: **Variável não encontrada.**
```shell
push a
```
​
pop <nome_variável>
Desempilha um valor da pilha.
Se a variável existir na lista, atualiza o valor.
Se não existir, cria um novo nó com o nome e o valor.
```shell
pop resultado
```
## 🗂️ Estrutura Esperada do Projeto (Etapa 2)
```shell
  $ tree
/lab-stackinterpreter
│
├── main.c             # REPL principal
├── interpret.c        # Interpretador de comandos
├── interpret.h
├── stack.c            # Pilha
├── stack.h
├── lista.c            # Lista encadeada (variáveis)
├── lista.h
└── README.md
```

## **🧪 Exemplo de Interação**
```shell
> push 42
> push 5
> add
> push 8
> sub
> pop a
> push 56
> push 8
> add
> pop b
> push a
> push b
> add
> push 6
> add
> print
```

**Explicação resumida do que esse código faz:**

- Empilha 42 e 5 → soma = 47
- Empilha 8 → subtrai: 47 - 8 = 39 → guarda em `a`
- Empilha 56 e 8 → soma = 64 → guarda em `b`
- Empilha `a` e `b` (valores 39 e 64) → soma = 103
- Empilha 6 → soma final = 109
- Imprime: `109`

## 🤝 Autores
<table>
  <tr>
    <td align="center">
      <a href="https://github.com/Martins98725" title="defina o título do link">
        <img src="https://avatars.githubusercontent.com/u/114537757?v=4" width="100px;" alt="Foto do Ícaro Martins no GitHub"/><br>
        <sub>
          <b>Ícaro Martins</b>
        </sub>
      </a>
    </td>
  <td align="center">
      <a href="https://github.com/FabinDr" title="defina o título do link">
        <img src="https://avatars.githubusercontent.com/u/124143933?v=4" width="100px;" alt="Foto do Fabio Duarte"/><br>
        <sub>
          <b>Fabio Duarte</b>
        </sub>
      </a>
    </td>
    
</table>

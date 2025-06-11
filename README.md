# Laboratório -  Um REPL para uma máquina baseada em pilha

> **Disciplina** <br>
>
> Algoritmos e Estruturas de Dados  
> Curso: Bacharelado Interdisciplinar em Ciência e Tecnologia (BICT)  
> Universidade Federal do Maranhão (UFMA)

## Objetivo
Desenvolver um interpretador interativo (REPL) em linguagem C que simula uma máquina virtual com arquitetura de pilha, comum em linguagens como Python e Java. O programa deve ser capaz de ler comandos do usuário, avaliá-los e imprimir o resultado de forma contínua.

> Contexto do projeto: <br> Diversas linguagens de programação são compiladas para uma máquina abstrata baseada em Pilha. <br> Nessa máquina, os operandos e os resultados das operações são armazenados em um pilha.

Neste laboratório, construiremos um interpretador para uma linguagem simples que opera sobre uma pilha de inteiros, com suporte posterior a variáveis.

## 👥 Integrantes
- FABIO DUARTE RIBEIRO
- ICARO GABRYEL ARAUJO MARTINS
- BRENDO HENRY RAIOL FERNANDES
- LUCAS SERRA MELONIO
- CAUA GABRIEL SANTOS BARROS

## 📂 Organização do Projeto
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


## Instruções de Compilação
### Pré-requisitos
- Um compilador C (como GCC)

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

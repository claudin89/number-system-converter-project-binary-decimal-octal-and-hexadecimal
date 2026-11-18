# 🔢 Conversor Numérico em C++

Projeto desenvolvido para a disciplina de **Arquitetura e Organização de Computadores** (ADS), aplicando os fundamentos de **Algoritmos e Lógica de Programação**.

O programa realiza a conversão bidirecional entre os principais sistemas de numeração utilizados na computação: **Binário (Base 2)**, **Decimal (Base 10)**, **Octal (Base 8)** e **Hexadecimal (Base 16)**, implementando a lógica matemática manualmente sem uso de bibliotecas prontas de conversão.

---

## 🚀 Funcionalidades

* **Conversão entre 4 bases:** Suporta qualquer combinação entre Binário, Decimal, Octal e Hexadecimal por meio de dois menus interativos (`switch`).
* **Lógica Manual (Padrão Pivô):** Converte a base de entrada para Decimal (utilizando potências sucessivas) e, em seguida, converte para a base de saída escolhida (utilizando divisões sucessivas e vetores invertidos).
* **Validação e Blindagem de Entrada:**
  * Limite de até **10 dígitos** na entrada.
  * Leitura segura via vetor de caracteres (`char[]`), impedindo travamentos caso o usuário digite letras ou símbolos inválidos.
  * Validação específica por base (ex: aceita apenas `0` e `1` no Binário, `0` a `7` no Octal, e `0-9` / `A-F` no Hexadecimal).
* **Execução Direta no Windows:** Pausa final nativa em português (`Pressione ENTER para sair...`) para visualização dos resultados ao abrir o executável (`.exe`) diretamente.

---

## 🛠️ Tecnologias e Conceitos Aplicados

* **Linguagem:** C++ (padrão `<iostream>`)
* **Estruturas utilizadas:**
  * Vetores (`int[]` e `char[]`)
  * Laços de repetição (`for`, `while`, `do...while`)
  * Estruturas condicionais (`if/else`, `switch`)
  * Manipulação de caracteres via Tabela ASCII

---

## 💻 Como Compilar e Executar

### Pelo Terminal (GCC / MinGW)
```bash
g++ conversor.cpp -o conversor
./conversor

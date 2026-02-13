# DNA FASTA Analyzer

Mini-projeto em C para análise de sequências no formato FASTA.

## 📌 Objetivo

O programa:

-   Lê arquivos FASTA
-   Separa múltiplas sequências
-   Conta apenas bases válidas (A, T, C, G maiúsculas)
-   Considera letras minúsculas como inválidas
-   Calcula:
    -   Total de caracteres lidos
    -   Tamanho válido (excluindo inválidos)
    -   Quantidade de A, T, C, G
    -   Porcentagem de GC
    -   Total de caracteres inválidos

## 🔬 Regras de validação

-   Apenas `A`, `T`, `C`, `G` (maiúsculos) são considerados válidos
-   Qualquer outro caractere é contabilizado como inválido
-   O tamanho válido é:

tamanho_total - caracteres_inválidos

## ⚙️ Compilação

``` bash
gcc main.c dna.c -o dna
```

## ▶️ Execução

``` bash
./dna arquivo.fasta
```

## 🧪 Exemplos de teste

Coloque arquivos FASTA na pasta `exemplos/`.

Exemplo:

``` bash
./dna exemplos/teste1.fasta
```

## 📂 Estrutura

    main.c
    dna.c
    dna.h

## 🧠 Conceitos aplicados

-   Manipulação de arquivos em C
-   Structs
-   Modularização
-   Parsing de FASTA
-   Controle de qualidade de dados biológicos

------------------------------------------------------------------------

Projeto desenvolvido para prática de programação em C aplicada à
bioinformática.

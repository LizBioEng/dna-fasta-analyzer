#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "dna.h"

#define BUFFER 1024

void imprimir_resultado(Resultado r)
{
    float gc = 0.0;

    if (r.tamanho_valido > 0)
        gc = ((float)(r.G + r.C) / r.tamanho_valido) * 100;

    printf("\n--- %s ---\n", r.nome);
    printf("Total lido: %d\n", r.total_lido);
    printf("Tamanho válido (sem inválidos): %d\n", r.tamanho_valido);
    printf("A: %d\n", r.A);
    printf("T: %d\n", r.T);
    printf("C: %d\n", r.C);
    printf("G: %d\n", r.G);
    printf("GC: %.2f%%\n", gc);
    printf("Caracteres inválidos: %d\n", r.invalidos);
}

void analisar_fasta(const char *nome_arquivo)
{
    FILE *arquivo = fopen(nome_arquivo, "r");

    if (arquivo == NULL)
    {
        printf("Erro ao abrir o arquivo.\n");
        exit(1);
    }

    char linha[BUFFER];
    Resultado r = {"", 0, 0, 0, 0, 0, 0, 0};
    int tem_sequencia = 0;

    while (fgets(linha, sizeof(linha), arquivo))
    {
        if (linha[0] == '>')
        {
            if (tem_sequencia)
            {
                imprimir_resultado(r);
                r = (Resultado){"", 0, 0, 0, 0, 0, 0, 0};
            }

            sscanf(linha, ">%99s", r.nome);
            tem_sequencia = 1;
            continue;
        }

        for (int i = 0; i < strlen(linha); i++)
        {
            char base = linha[i];

            if (base == '\n')
                continue;

            r.total_lido++;

            switch (base)
            {
                case 'A': r.A++; r.tamanho_valido++; break;
                case 'T': r.T++; r.tamanho_valido++; break;
                case 'C': r.C++; r.tamanho_valido++; break;
                case 'G': r.G++; r.tamanho_valido++; break;
                default: r.invalidos++; break;
            }
        }
    }

    if (tem_sequencia)
        imprimir_resultado(r);

    fclose(arquivo);
}

#ifndef DNA_H
#define DNA_H

typedef struct
{
    char nome[100];
    int total_lido;
    int tamanho_valido;
    int A;
    int T;
    int C;
    int G;
    int invalidos;
} Resultado;

void analisar_fasta(const char *nome_arquivo);

#endif

#include <stdio.h>
#include "dna.h"

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Uso: ./dna arquivo.fasta\n");
        return 1;
    }

    analisar_fasta(argv[1]);

    return 0;
}

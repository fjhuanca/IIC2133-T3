#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <sys/resource.h>

#include "algorithms.h"
#include "heapsort.h"

int main(int argc, char** argv)
{
    
    // bloque de código para aumentar el stack size, obtenido de stack overflow.
    
    const rlim_t kStackSize = 4000 * 1024 * 1024;   // min stack size = 24 MB
    struct rlimit rl;
    int result;

    result = getrlimit(RLIMIT_STACK, &rl);
    if (result == 0){
        if (rl.rlim_cur < kStackSize){
            rl.rlim_cur = kStackSize;
            result = setrlimit(RLIMIT_STACK, &rl);
            if (result != 0){
                fprintf(stderr, "setrlimit returned result = %d\n", result);
            }
        }
    }
    
    // Revisamos los argumentos
    if(argc != 3) {
        printf("Modo de uso: %s <network.txt> <output.txt>\n", argv[0]);
        return 1;
    }

    /* ------------- POR IMPLEMENTAR -------------- */
    /* El código de tu tarea va aquí.               */
    FILE *input_file = fopen(argv[1], "r");
    FILE *output_file = fopen(argv[2], "w");
    int C;
    int D;
    int H;
    int i;
    int j;
    int p;
    fscanf(input_file, "%d", &C);
    fscanf(input_file, "%d", &D);
    fscanf(input_file, "%d", &H);
    int** rutas = (int**) malloc((H) * sizeof(int**));
    for (int x=0; x<H; x++){
        rutas[x] = (int*)calloc(4, sizeof(int*));
    }
    // memset(matriz, 0, sizeof(matriz));
    for (int h=0; h<H; h++){
        fscanf(input_file, "%d", &i);
        fscanf(input_file, "%d", &j);
        fscanf(input_file, "%d", &p);
        rutas[h][0] = i;
        rutas[h][1] = j;
        rutas[h][2] = p;
        rutas[h][3] = h;
    }
    
    printf("%d\n", C);
    printf("%d\n", D);
    printf("%d\n", H);
    int* rutas_out = (int*) malloc((H) * sizeof(int*));
    int n_rutas;
    int costo;
    kruskal(rutas, C, D, H, rutas_out, &n_rutas, &costo);
    fprintf(output_file, "%d\n", costo);
    for (int x=0; x<n_rutas; x++){
        fprintf(output_file, "%d\n", rutas_out[x]);
    }
    // printf("(%d) ", n_rutas);
    free(rutas_out);
    for (int x=0; x<H; x++){
        free(rutas[x]);
    }
    free(rutas);
    fclose(input_file);
    fclose(output_file);
    // Terminamos exitosamente
    return 0;
}
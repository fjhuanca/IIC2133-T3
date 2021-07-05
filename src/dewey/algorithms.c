#include "algorithms.h"


void kruskal(int** rutas, int C, int D, int H, int* rutas_out, int* n_rutas, int* costo){
    const int V = C + D;
    heapSort(rutas, H);
    int len_conjuntos[V];
    int conjuntos[V][V];
    int productores[V];
    *n_rutas = 0;
    *costo = 0;
    int suma = 0;
    int n_conjuntos = V;
    for (int i=0; i<V; i++){
        if (i<C) productores[i] = 0;
        else productores[i] = 1;
        conjuntos[i][0] = i;
        len_conjuntos[i] = 1;
        for (int j=1; j<V; j++){
            conjuntos[i][j] = -1;
        }
    }
    for(int h=0; h<H; h++){
        int* ruta = rutas[h];
        bool is_in = false;
        int id_conj1 = -1;
        int id_conj2 = -1;
        // printf("[%d - %d]\n", ruta[0], ruta[1]);
        for (int i=0; i<V; i++){
            int* conj = conjuntos[i];
            // bool init_in_conj = false;
            // bool end_in_conj = false;
            for (int l=0; l<len_conjuntos[i]; l++){
                // printf("(%d - %d - %d)\n", ruta[0], ruta[1], conj[l]);
                if (ruta[0] == conj[l]) id_conj1 = i;
                if (ruta[1] == conj[l]) id_conj2 = i;
                if (id_conj1 >= 0 && id_conj2 >= 0){
                    break;
                }
            }
            if (id_conj1 >= 0 && id_conj2 >= 0 && id_conj1 == id_conj2){
                is_in = true;
                int l1 = len_conjuntos[id_conj1];
                for (int c=l1; c<l1; c++){
                    // printf("%d-",conjuntos[id_conj1][c]);
                }
                // printf("%d\n", l1);
                break;
            }
        }
        // int l1 = len_conjuntos[id_conj1];
        // printf("%d\n", l1);
        // printf("*(%d-%d)*\n", id_conj1, id_conj2);
        if (is_in) continue;
        else {
            if (productores[id_conj1] + productores[id_conj2] <= 1){

                rutas_out[*n_rutas] = ruta[3];
                *costo = *costo + ruta[2];
                // printf("%d - %d - %d\n", rutas_out[0], *n_rutas, ruta[3]);
                *n_rutas = *n_rutas + 1;
                // printf("here\n");
                int l1 = len_conjuntos[id_conj1];
                int l2 = len_conjuntos[id_conj2];
                // printf("l1: %d, l2:%d\n", l1, l2);
                len_conjuntos[id_conj2] = 0;
                if (productores[id_conj2] == 1){
                    productores[id_conj1] = productores[id_conj1] + 1;
                    suma = suma + 1;
                }
                suma -= productores[id_conj2];
                productores[id_conj2] = 0;
                n_conjuntos = n_conjuntos - 1;
                for (int c=l1; c<l1+l2; c++){
                    conjuntos[id_conj1][c] = conjuntos[id_conj2][c-l1];
                }
                len_conjuntos[id_conj1] = l1 + l2;
            }
        }
        // printf("{%d - %d}\n", suma, n_conjuntos);
        if (suma == n_conjuntos) break;
    }
    // printf("*(%d)\n ", *n_rutas);
}
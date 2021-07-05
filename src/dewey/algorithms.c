#include "algorithms.h"


void kruskal(int** rutas, int C, int D, int H, int* rutas_out, int* n_rutas, int* costo){
    const int V = C + D;
    heapSort(rutas, H);
    int conjuntos[V];
    int productores[V];
    int len_conjuntos[V];
    *n_rutas = 0;
    *costo = 0;
    int suma = 0;
    int n_conjuntos = V;
    for (int i=0; i<V; i++){
        len_conjuntos[i] = 1;
        if (i<C) productores[i] = 0;
        else productores[i] = 1;
        conjuntos[i] = i;
    }
    int id_conj1;
    int id_conj2; 
    int temp_conj1;
    int temp_conj2;
    int* ruta;
    for(int h=0; h<H; h++){
        ruta = rutas[h];
        // bool is_in = false;
        temp_conj1 = conjuntos[ruta[0]];
        temp_conj2 = conjuntos[ruta[1]];
        if (temp_conj1 <= temp_conj2){
            id_conj1 = temp_conj1;
            id_conj2 = temp_conj2;
        }
        else{
            id_conj1 = temp_conj2;
            id_conj2 = temp_conj1;
        }
        // printf("[%d - %d]\n", ruta[0], ruta[1]);
        
        // int l1 = len_conjuntos[id_conj1];
        // printf("%d\n", l1);
        // printf("*(%d-%d)*\n", id_conj1, id_conj2);
        if (id_conj1 == id_conj2) continue;
        else {
            if (productores[id_conj1] + productores[id_conj2] <= 1){

                rutas_out[*n_rutas] = ruta[3];
                *costo = *costo + ruta[2];
                // printf("%d - %d - %d\n", rutas_out[0], *n_rutas, ruta[3]);
                *n_rutas = *n_rutas + 1;
                // printf("here\n");

                // printf("l1: %d, l2:%d\n", l1, l2);

                if (productores[id_conj2] == 1){
                    productores[id_conj1] = productores[id_conj1] + 1;
                    suma = suma + 1;
                }
                suma -= productores[id_conj2];
                productores[id_conj2] = 0;
                n_conjuntos = n_conjuntos - 1;
                int largo = len_conjuntos[id_conj2];
                len_conjuntos[id_conj1] = len_conjuntos[id_conj1] + len_conjuntos[id_conj2];
                len_conjuntos[id_conj2] = 0; 
                int contador = 0;
                for (int i=0; i<V; i++){
                    if (conjuntos[i] == id_conj2){
                        conjuntos[i] = id_conj1;
                        contador += 1;
                    }
                    if (contador == largo) break;
                }
            }
        }
        // printf("{%d - %d}\n", suma, n_conjuntos);
        if (suma == n_conjuntos) break;
    }
    // printf("*(%d)\n ", *n_rutas);
}
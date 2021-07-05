#pragma once
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <stdbool.h>

#include "heapsort.h"

void kruskal(int** rutas, int C, int D, int H, int* rutas_out, int* n_rutas, int* costo);
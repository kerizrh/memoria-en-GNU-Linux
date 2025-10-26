#include <stdio.h>
#include <stdlib.h>

// Algoritmo FIFO con visualización
int fifo_detallado(int paginas[], int n, int marcos) {
    int memoria[marcos];
    int puntero = 0, fallos = 0;
    
    for (int i = 0; i < marcos; i++) memoria[i] = -1;
    
    printf("\n=== ALGORITMO FIFO ===\n");
    for (int i = 0; i < n; i++) {
        int encontrado = 0;
        
        // Verificar si ya está en memoria
        for (int j = 0; j < marcos; j++) {
            if (memoria[j] == paginas[i]) {
                encontrado = 1;
                break;
            }
        }
        
        // Mostrar estado actual
        printf("Referencia %d: ", paginas[i]);
        for (int j = 0; j < marcos; j++) {
            if (memoria[j] == -1) printf("[ ] ");
            else printf("[%d] ", memoria[j]);
        }
        
        // Si no está, hay fallo de página
        if (!encontrado) {
            memoria[puntero] = paginas[i];
            puntero = (puntero + 1) % marcos;
            fallos++;
            printf("-> FALLO (insertar en pos %d)", (puntero-1+marcos)%marcos);
        } else {
            printf("-> ACIERTO");
        }
        printf("\n");
    }
    return fallos;
}

// Algoritmo LRU con visualización
int lru_detallado(int paginas[], int n, int marcos) {
    int memoria[marcos];
    int contador[marcos];
    int fallos = 0;
    
    for (int i = 0; i < marcos; i++) {
        memoria[i] = -1;
        contador[i] = 0;
    }
    
    printf("\n=== ALGORITMO LRU ===\n");
    for (int i = 0; i < n; i++) {
        int encontrado = 0;
        
        // Verificar si ya está en memoria
        for (int j = 0; j < marcos; j++) {
            if (memoria[j] == paginas[i]) {
                encontrado = 1;
                contador[j] = i; // Actualizar tiempo de uso
                break;
            }
        }
        
        // Mostrar estado actual
        printf("Referencia %d: ", paginas[i]);
        for (int j = 0; j < marcos; j++) {
            if (memoria[j] == -1) printf("[ ] ");
            else printf("[%d] ", memoria[j]);
        }
        
        // Si no está, hay fallo de página
        if (!encontrado) {
            // Encontrar el menos recientemente usado
            int lru_index = 0;
            for (int j = 1; j < marcos; j++) {
                if (contador[j] < contador[lru_index]) {
                    lru_index = j;
                }
            }
            
            memoria[lru_index] = paginas[i];
            contador[lru_index] = i;
            fallos++;
            printf("-> FALLO (reemplazar pos %d)", lru_index);
        } else {
            printf("-> ACIERTO");
        }
        printf("\n");
    }
    return fallos;
}

int main() {
    int paginas[] = {1, 2, 3, 4, 1, 2, 5, 1, 2, 3, 4, 5};
    int n = sizeof(paginas) / sizeof(paginas[0]);
    int marcos = 3;
    
    printf("Secuencia de referencias: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", paginas[i]);
    }
    printf("\n");
    printf("Número de marcos: %d\n\n", marcos);
    
    int fallos_fifo = fifo_detallado(paginas, n, marcos);
    int fallos_lru = lru_detallado(paginas, n, marcos);
    
    printf("\n=== RESUMEN ===\n");
    printf("Fallos de página - FIFO: %d\n", fallos_fifo);
    printf("Fallos de página - LRU: %d\n", fallos_lru);
    
    // Análisis adicional
    printf("\n=== ANÁLISIS ===\n");
    if (fallos_lru < fallos_fifo) {
        printf("LRU es más eficiente en esta secuencia (como se esperaba)\n");
    } else if (fallos_lru > fallos_fifo) {
        printf("FIFO es más eficiente en esta secuencia (caso particular)\n");
        printf("Esto ocurre cuando el patrón de acceso es 'antagonista' para LRU\n");
    } else {
        printf("Ambos algoritmos tienen el mismo desempeño\n");
    }
    
    return 0;
}

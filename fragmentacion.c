#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    printf("PID: %d\n", getpid());
    printf("Simulando fragmentación de memoria...\n");
    
    // Reservar 10 bloques de diferentes tamaños
    void* bloques[10];
    int tamanios[] = {1024, 2048, 4096, 8192, 16384, 32768, 65536, 131072, 262144, 524288};
    
    printf("=== RESERVANDO MEMORIA ===\n");
    for (int i = 0; i < 10; i++) {
        bloques[i] = malloc(tamanios[i]);
        if (bloques[i] != NULL) {
            printf("Bloque %d: %d bytes reservados en %p\n", i, tamanios[i], bloques[i]);
        }
    }
    
    printf("\n=== LIBERANDO INTERCALADAMENTE ===\n");
    for (int i = 0; i < 10; i += 2) {
        free(bloques[i]);
        printf("Bloque %d liberado\n", i);
    }
    
    printf("Quedan bloques 1,3,5,7,9 en memoria\n");
    printf("Presiona Enter para continuar...");
    getchar();
    
    // Liberar el resto
    for (int i = 1; i < 10; i += 2) {
        free(bloques[i]);
    }
    
    return 0;
}

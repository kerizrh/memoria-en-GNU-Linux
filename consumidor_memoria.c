#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>  // ¡AGREGAR ESTA LÍNEA!

int main() {
    printf("Iniciando consumo de memoria...\n");
    printf("PID: %d\n", getpid());
    
    int mb = 0;
    char* bloques[100];
    
    while (mb < 100) {
        // Reservar 10 MB a la vez
        bloques[mb/10] = malloc(10 * 1024 * 1024);
        if (bloques[mb/10] == NULL) {
            printf("❌ Error al asignar memoria en %d MB\n", mb);
            perror("malloc");
            break;
        }
        
        // Escribir en la memoria para asegurar asignación
        memset(bloques[mb/10], 0, 10 * 1024 * 1024);
        
        mb += 10;
        printf("✅ Memoria asignada: %d MB\n", mb);
    }
    
    printf("Presiona Enter para liberar memoria y terminar...");
    getchar();
    
    // Liberar memoria
    for (int i = 0; i < mb/10; i++) {
        free(bloques[i]);
    }
    
    return 0;
}

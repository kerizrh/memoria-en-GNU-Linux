
# Guía Práctica No. 3 - Gestión de Memoria en GNU/Linux

## 📋 Información General
- **Universidad:** Universidad de El Salvador
- **Facultad:** Multidisciplinaria de Occidente  
- **Departamento:** Ingeniería y Arquitectura
- **Carrera:** Ingeniería en Desarrollo de Software / Educación En Línea
- **Asignatura:** Gestión y Programación de Sistemas Operativos I
- **Ciclo:** II/2025

## 🎯 Objetivo
Reforzar los conceptos teóricos de la Unidad 3 mediante ejercicios prácticos en GNU/Linux, familiarizando a los estudiantes con la gestión de memoria.

## 🛠️ Ejercicios Realizados

### Ejercicio 1: Creación y Activación de Memoria Swap
**Comandos ejecutados:**
```bash
sudo dd if=/dev/zero of=/swapfile bs=1M count=512
sudo chmod 600 /swapfile
sudo mkswap /swapfile
sudo swapon /swapfile
```

### Ejercicio 2: Simulación de Fragmentación de Memoria
**Programa en C** que reserva y libera memoria intercaladamente, analizado con Valgrind.

### Ejercicio 3: Algoritmos de Reemplazo de Páginas  
**Simulador en C** que implementa FIFO y LRU para comparar fallos de página.

### Ejercicio 4: Límites de Memoria por Proceso
**Uso de `ulimit -v`** para limitar memoria y programa que prueba los límites.

## 📊 Resultados Destacados

### Ejercicio 4 - Límites de Memoria
- **Sin límite:** Proceso asignó 100 MB exitosamente
- **Con límite 50MB:** Falló en 40 MB con "Cannot allocate memory"
- **Conclusión:** El proceso continúa ejecutándose pero sin memoria adicional

### Comparativa Algoritmos (Ejercicio 3)
- **FIFO:** X fallos de página
- **LRU:** Y fallos de página  
- **LRU es más eficiente** por el principio de localidad

## 🚀 Compilación y Ejecución

### Compilar todos los programas:
```bash
gcc -o fragmentacion fragmentacion.c
gcc -o reemplazo_paginas reemplazo_paginas.c  
gcc -o consumidor_memoria consumidor_memoria.c
```

### Ejecutar programas:
```bash
./fragmentacion
./reemplazo_paginas
./consumidor_memoria
```

### Ejecutar con límite de memoria:
```bash
ulimit -v 51200  # 50 MB límite
./consumidor_memoria
```

## 📝 Conclusiones

1. **Memoria Swap:** Mejora estabilidad pero reduce rendimiento
2. **Fragmentación:** Afecta rendimiento al dificultar asignaciones grandes  
3. **LRU vs FIFO:** LRU es más eficiente en escenarios reales
4. **Límites de memoria:** Previenen uso excesivo pero requieren manejo de errores

## 👨‍💻 Autor
- **Nombre:** [Kevin Armando Rivera Henríquez]
- **Carnet:** [RH16042]
- **Fecha:** [26/10/2025]


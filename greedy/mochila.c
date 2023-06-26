#include <stdio.h>

struct Elemento {
    int valor;
    int peso;
    double relacion;
};

void mochila_greedy(struct Elemento elementos[], int num_elementos, int capacidad) {
    // Calcular la relación valor/peso para cada elemento
    for (int i = 0; i < num_elementos; i++) {
        elementos[i].relacion = (double)elementos[i].valor / elementos[i].peso;
    }

    // Ordenar los elementos en orden descendente según la relación valor/peso (usando el algoritmo de burbuja)
    for (int i = 0; i < num_elementos - 1; i++) {
        for (int j = 0; j < num_elementos - i - 1; j++) {
            if (elementos[j].relacion < elementos[j + 1].relacion) {
                struct Elemento temp = elementos[j];
                elementos[j] = elementos[j + 1];
                elementos[j + 1] = temp;
            }
        }
    }

    int capacidad_restante = capacidad;
    int valor_total = 0;

    for (int i = 0; i < num_elementos; i++) {
        if (elementos[i].peso <= capacidad_restante) {
            valor_total += elementos[i].valor;
            capacidad_restante -= elementos[i].peso;
        } else {
            double fraccion = (double)capacidad_restante / elementos[i].peso;
            valor_total += fraccion * elementos[i].valor;
            capacidad_restante = 0;
            break;
        }
    }

    printf("Valor total obtenido: %d\n", valor_total);
}

int main() {
    struct Elemento elementos[] = {
        {60, 10},
        {100, 20},
        {120, 30}
    };
    int num_elementos = sizeof(elementos) / sizeof(elementos[0]);
    int capacidad = 50;

    mochila_greedy(elementos, num_elementos, capacidad);

    return 0;
}

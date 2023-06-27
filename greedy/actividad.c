#include <stdio.h>

struct actividad {
    int inicio;
    int fin;
};

typedef struct actividad act;

void actividades(act acts[], int num_acts) {
    // Ordenar las actividades en orden ascendente según el tiempo de finalización (usando el algoritmo de burbuja)
    for (int i = 0; i < num_acts - 1; i++) {
        for (int j = 0; j < num_acts - i - 1; j++) {
            if (acts[j].fin > acts[j + 1].fin) {
                act temp = acts[j];
                acts[j] = acts[j + 1];
                acts[j + 1] = temp;
            }
        }
    }

    printf("Actividades seleccionadas: ");
    printf("(%d, %d) ", acts[0].inicio, acts[0].fin);

    int ultima_act = 0;

    for (int i = 1; i < num_acts; i++) {
        if (acts[i].inicio >= acts[ultima_act].fin) {
            printf("(%d, %d) ", acts[i].inicio, acts[i].fin);
            ultima_act = i;
        }
    }
}

int main() {
    act acts[] = {
        {1, 4},
        {3, 5},
        {0, 6},
        {5, 7},
        {3, 8},
        {5, 9},
        {6, 10},
        {8, 11},
        {8, 12},
        {2, 13},
        {12, 14}
    };
    int num_actividades = sizeof(acts) / sizeof(acts[0]);

    actividades (acts, num_actividades);

    return 0;
}

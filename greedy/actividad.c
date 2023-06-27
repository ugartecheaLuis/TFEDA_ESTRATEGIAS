#include <stdio.h>

struct actividad {
    int inicio;
    int fin;
};

typedef struct actividad act;

void actividades(act acts[], int num_acts) {
    for (int i = 0; i < num_acts - 1; i++) { //Ordena por burbuja
        for (int j = 0; j < num_acts - i - 1; j++) {
            if (acts[j].fin > acts[j + 1].fin) {
                act temp = acts[j];
                acts[j] = acts[j + 1];
                acts[j + 1] = temp;
            }
        }
    }
    printf("Actividades: ");
    printf("(%d, %d) ", acts[0].inicio, acts[0].fin); //Imprime la más temprana actividad
    
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
        {4, 5},
        {5, 8},
        {6, 7},
        {5, 10},
        {6, 7},
        {9, 12},
        {14, 16},
        {1, 6},
        {15, 21}
    };
    
    int num_actividades = sizeof(acts) / sizeof(acts[0]); //esto es para saber la cantidad de actividades que hay
    actividades (acts, num_actividades);

    return 0;
}

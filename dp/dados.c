#include <stdio.h>

int sumaDados(int numDados, int n) {
    int info[numDados + 1][n + 1]; // crea una matriz para almacenar los subproblemas
    info[0][0] = 1;

    for (int i = 1; i <= numDados; i++) {
        for (int j = 1; j <= n; j++) {
            if (j <= 6) { // verifica si el dado actual puede contribuir a la suma actual
                info[i][j] = info[i - 1][j];
            }
            info[i][j] += (j > 6) ? info[i][j - 1] : 0; // Suma las soluciones anteriores para obtener el resultado
        }
    } // este for tiene como objetivo calcular las soluciones a los subproblemas

    return info[numDados][n]; //devuelve el resultado final
}

int main() {
    int cantidad_dados = 3;
    int numero = 10;
    int res = sumaDados(cantidad_dados, numero);
    printf("El numero de formas de obtener la suma %d con %d dados es: %d\n", numero, cantidad_dados, res);

    return 0;
}


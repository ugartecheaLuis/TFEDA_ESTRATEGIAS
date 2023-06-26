#include <stdio.h>

int sumaDados(int numDados, int n) {
    // Crear una matriz para almacenar los subproblemas
    int info[numDados + 1][n + 1];
    // Caso base: si no hay dados, no hay suma posible
    info[0][0] = 1;

    // Calcular las soluciones a los subproblemas
    for (int i = 1; i <= numDados; i++) {
        for (int j = 1; j <= n; j++) {
            // Verificar si el dado actual puede contribuir a la suma actual
            if (j <= 6) {
                info[i][j] = info[i - 1][j];
            }
            // Sumar las soluciones anteriores para obtener la solución actual
            info[i][j] += (j > 6) ? info[i][j - 1] : 0;
        }
    }

    // Devolver el resultado final
    return info[numDados][n];
}

int main() {
    int cantidad_dados = 3;
    int numero = 10;
    int res = sumaDados(cantidad_dados, numero);
    printf("El número de formas de obtener la suma %d con %d dados es: %d\n", numero, cantidad_dados, res);

    return 0;
}

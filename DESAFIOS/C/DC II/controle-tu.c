#include <stdio.h>
#include <math.h>

// Função para calcular a média de veículos por hora
double calcular_media(int veiculos[], int tamanho) {
    int soma = 0;
    for (int i = 0; i < tamanho; i++) {
        soma += veiculos[i];
    }
    return round((double)soma / tamanho);
}

int main() {
    int n;
    
    // Solicitando a entrada do usuário
    //printf("Digite o número de horas registradas (0 < n ≤ 24): ");
    scanf("%d", &n);
    
    if (n <= 0 || n > 24) {
        printf("Número de horas inválido!\n");
        return 1;
    }

    int veiculos[n];
    
   // printf("Digite os números de veículos que passaram em cada hora, separados por espaço:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &veiculos[i]);
    }
    
    double media = calcular_media(veiculos, n);
    
    // Exibindo a média de veículos por hora
    printf("Média de veículos por hora: %.0f\n", media);
    
    return 0;
}

#include <stdio.h>
#include <math.h> // Para usar a função ceil

int main() {
    int largura, comprimento;
    double area, tempo;

    // Entrada dos valores
    scanf("%d", &largura);
    scanf("%d", &comprimento);

    // Cálculo da área
    area = largura * comprimento;

    // Cálculo do tempo necessário para limpar a área
    // O robô limpa 5 metros quadrados por minuto
    tempo = ceil(area / 5.0);

    // Exibir o resultado
    printf("O robô de limpeza levará %.0f minutos para limpar a sala.\n", tempo);

    return 0;
}

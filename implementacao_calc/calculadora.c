#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Funções de operações básicas
float adicionar(float a, float b) {
    return a + b;
}

float subtrair(float a, float b) {
    return a - b;
}

float multiplicar(float a, float b) {
    return a * b;
}

float dividir(float a, float b) {
    if (b == 0) {
        printf("Erro: Divisão por zero!\n");
        return 0;
    }
    return a / b;
}

// Funções de conversão
int binarioParaDecimal(char *binario) {
    return strtol(binario, NULL, 2);
}

void decimalParaBinario(int decimal, char *binario) {
    itoa(decimal, binario, 2);
}

int hexadecimalParaDecimal(char *hexadecimal) {
    return strtol(hexadecimal, NULL, 16);
}

void decimalParaHexadecimal(int decimal, char *hexadecimal) {
    sprintf(hexadecimal, "%X", decimal);
}

// Função principal
int main() {
    int escolha;
    float num1, num2;
    char binario[32], hexadecimal[32];
    int decimal;

    do {
        printf("\nCalculadora\n");
        printf("1. Adição\n");
        printf("2. Subtração\n");
        printf("3. Multiplicação\n");
        printf("4. Divisão\n");
        printf("5. Binário para Decimal\n");
        printf("6. Decimal para Binário\n");
        printf("7. Hexadecimal para Decimal\n");
        printf("8. Decimal para Hexadecimal\n");
        printf("9. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &escolha);

        switch (escolha) {
            case 1:
                printf("Digite dois números: ");
                scanf("%f %f", &num1, &num2);
                printf("Resultado: %.2f\n", adicionar(num1, num2));
                break;
            case 2:
                printf("Digite dois números: ");
                scanf("%f %f", &num1, &num2);
                printf("Resultado: %.2f\n", subtrair(num1, num2));
                break;
            case 3:
                printf("Digite dois números: ");
                scanf("%f %f", &num1, &num2);
                printf("Resultado: %.2f\n", multiplicar(num1, num2));
                break;
            case 4:
                printf("Digite dois números: ");
                scanf("%f %f", &num1, &num2);
                printf("Resultado: %.2f\n", dividir(num1, num2));
                break;
            case 5:
                printf("Digite um número binário: ");
                scanf("%s", binario);
                printf("Resultado: %d\n", binarioParaDecimal(binario));
                break;
            case 6:
                printf("Digite um número decimal: ");
                scanf("%d", &decimal);
                decimalParaBinario(decimal, binario);
                printf("Resultado: %s\n", binario);
                break;
            case 7:
                printf("Digite um número hexadecimal: ");
                scanf("%s", hexadecimal);
                printf("Resultado: %d\n", hexadecimalParaDecimal(hexadecimal));
                break;
            case 8:
                printf("Digite um número decimal: ");
                scanf("%d", &decimal);
                decimalParaHexadecimal(decimal, hexadecimal);
                printf("Resultado: %s\n", hexadecimal);
                break;
            case 9:
                printf("Saindo...\n");
                break;
            default:
                printf("Opção inválida!\n");
        }
    } while (escolha != 9);

    return 0;
}

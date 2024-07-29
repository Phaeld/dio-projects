#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Funções de operações básicas
float adicionar(float a, float b) {
    return a + b;  // Retorna a soma de 'a' e 'b'
}

float subtrair(float a, float b) {
    return a - b;  // Retorna a diferença entre 'a' e 'b'
}

float multiplicar(float a, float b) {
    return a * b;  // Retorna o produto de 'a' e 'b'
}

float dividir(float a, float b) {
    if (b == 0) {  // Verifica se o divisor é zero
        printf("Erro: Divisão por zero!\n");
        return 0;  // Retorna 0 em caso de divisão por zero
    }
    return a / b;  // Retorna o quociente de 'a' por 'b'
}

// Funções de conversão
int binarioParaDecimal(char *binario) {
    return strtol(binario, NULL, 2);  // Converte uma string binária para um número decimal
}

void decimalParaBinario(int decimal, char *binario) {
    itoa(decimal, binario, 2);  // Converte um número decimal para uma string binária
}

int hexadecimalParaDecimal(char *hexadecimal) {
    return strtol(hexadecimal, NULL, 16);  // Converte uma string hexadecimal para um número decimal
}

void decimalParaHexadecimal(int decimal, char *hexadecimal) {
    sprintf(hexadecimal, "%X", decimal);  // Converte um número decimal para uma string hexadecimal
}

// Função principal
int main() {
    int escolha;            // Variável para armazenar a escolha do usuário no menu
    float num1, num2;       // Variáveis para armazenar os números para operações matemáticas
    char binario[32],       // Variável para armazenar a string binária
         hexadecimal[32];   // Variável para armazenar a string hexadecimal
    int decimal;            // Variável para armazenar o número decimal

    // Loop do menu
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
        scanf("%d", &escolha);  // Lê a escolha do usuário

        // Executa a operação com base na escolha do usuário
        switch (escolha) {
            case 1:
                printf("Digite dois números: ");
                scanf("%f %f", &num1, &num2);
                printf("Resultado: %.2f\n", adicionar(num1, num2));  // Chama a função de adição e imprime o resultado
                break;
            case 2:
                printf("Digite dois números: ");
                scanf("%f %f", &num1, &num2);
                printf("Resultado: %.2f\n", subtrair(num1, num2));  // Chama a função de subtração e imprime o resultado
                break;
            case 3:
                printf("Digite dois números: ");
                scanf("%f %f", &num1, &num2);
                printf("Resultado: %.2f\n", multiplicar(num1, num2));  // Chama a função de multiplicação e imprime o resultado
                break;
            case 4:
                printf("Digite dois números: ");
                scanf("%f %f", &num1, &num2);
                printf("Resultado: %.2f\n", dividir(num1, num2));  // Chama a função de divisão e imprime o resultado
                break;
            case 5:
                printf("Digite um número binário: ");
                scanf("%s", binario);  // Lê uma string binária do usuário
                printf("Resultado: %d\n", binarioParaDecimal(binario));  // Converte binário para decimal e imprime o resultado
                break;
            case 6:
                printf("Digite um número decimal: ");
                scanf("%d", &decimal);  // Lê um número decimal do usuário
                decimalParaBinario(decimal, binario);  // Converte decimal para binário
                printf("Resultado: %s\n", binario);  // Imprime o resultado binário
                break;
            case 7:
                printf("Digite um número hexadecimal: ");
                scanf("%s", hexadecimal);  // Lê uma string hexadecimal do usuário
                printf("Resultado: %d\n", hexadecimalParaDecimal(hexadecimal));  // Converte hexadecimal para decimal e imprime o resultado
                break;
            case 8:
                printf("Digite um número decimal: ");
                scanf("%d", &decimal);  // Lê um número decimal do usuário
                decimalParaHexadecimal(decimal, hexadecimal);  // Converte decimal para hexadecimal
                printf("Resultado: %s\n", hexadecimal);  // Imprime o resultado hexadecimal
                break;
            case 9:
                printf("Saindo...\n");  // Mensagem de saída
                break;
            default:
                printf("Opção inválida!\n");  // Mensagem para opção inválida
        }
    } while (escolha != 9);  // Repete o loop até o usuário escolher sair

    return 0;  // Retorna 0 para indicar que o programa terminou com sucesso
}

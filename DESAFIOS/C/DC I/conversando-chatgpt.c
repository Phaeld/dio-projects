#include <stdio.h>
#include <string.h>

int main() {
    char mensagem[256];  // Buffer para armazenar a mensagem do usuário
    char *palavra;       // Ponteiro para armazenar cada palavra da mensagem

    // Solicitando a entrada do usuário
    //printf("Digite uma mensagem: ");
    scanf("%[^\n]", mensagem);

    // Dividindo a mensagem em palavras usando strtok()
    palavra = strtok(mensagem, " ");
    while (palavra != NULL) {
        // Imprimindo a palavra duas vezes
        printf("%s %s ", palavra, palavra);

        // Obtendo a próxima palavra
        palavra = strtok(NULL, " ");
    }

    return 0;
}

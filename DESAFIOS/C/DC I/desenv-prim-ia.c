#include <stdio.h>

void classificar_animal(float peso, float altura, char pelos, char mamifero) {
    if (peso >= 2000 && altura >= 300) {
        printf("O animal é um elefante!\n");
    } else if (pelos == 's' && mamifero == 's' && altura == 150) {
        printf("O animal é um cavalo!\n");
    } else if (mamifero == 's' && pelos == 's' && altura <= 100) {
        printf("O animal é um cachorro!\n");
    } else if (pelos == 'n' && mamifero == 'n') {
        printf("O animal é uma serpente!\n");
    } else if (mamifero == 's' && pelos == 'n') {
        printf("O animal é uma tartaruga!\n");
    } else {
        printf("Não foi possível classificar o animal!\n");
    }
}

int main() {
    float peso, altura;
    char pelos, mamifero;

    // Solicitando as entradas do usuário
    
    scanf("%f", &peso);
    
    scanf("%f", &altura);
    
    scanf(" %c", &pelos); // Note o espaço antes de %c para ignorar espaços em branco
    
    scanf(" %c", &mamifero); // Note o espaço antes de %c para ignorar espaços em branco

    // Classificando o animal com base nas características fornecidas
    classificar_animal(peso, altura, pelos, mamifero);

    return 0;
}

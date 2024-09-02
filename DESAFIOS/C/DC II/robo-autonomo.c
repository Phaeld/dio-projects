#include <stdio.h>

// Função para encontrar o índice do robô que percorreu a maior distância
int maiorDistancia(int posicoes[], int tamanho) {
    int maiorDistancia = posicoes[0];
    int indice = 0;
    
    for (int i = 1; i < tamanho; i++) {
        if (posicoes[i] > maiorDistancia) {
            maiorDistancia = posicoes[i];
            indice = i;
        }
    }
    
    return indice + 1; // Para retornar o índice considerando a base 1
}

int main() {
    int n;
    
    // Solicitando a entrada do usuário
    //printf("Digite o número de robôs (1 <= N <= 10): ");
    scanf("%d", &n);
    
    if (n < 1 || n > 10) {
        printf("Número inválido de robôs!\n");
        return 1;
    }

    int posicoes[n];
    
    //printf("Digite as posições dos robôs separadas por espaço:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &posicoes[i]);
    }
    
    int indice = maiorDistancia(posicoes, n);
    
    // Exibindo o índice do robô que percorreu a maior distância
    printf("O robô que percorreu a maior distância é o robô %d\n", indice);
    
    return 0;
}

#include <stdio.h>

// Função que verifica se o robô está próximo ou longe do objeto
const char* verificar_distancia(int distancia) {
    if (distancia <= 10) {
        return "O robô está próximo!";
    } else {
        return "O robô está longe!";
    }
}

int main() {
    int distancia;

    // Solicitando a entrada do usuário
    //printf("Digite a distância medida pelo sensor (em metros): ");
    scanf("%d", &distancia);

    // Verificando a distância e exibindo a mensagem apropriada
    printf("%s\n", verificar_distancia(distancia));

    return 0;
}

#include <stdio.h>
#include <string.h>

// Definindo a estrutura Mushroom (Cogumelo)
typedef struct {
    char nome[20];
    int valor;
} Cogumelo;

int main() {
    // Lista de cogumelos oferecidos pela loja, ordenados por prioridade
    Cogumelo listaDeCogumelos[] = {
        {"Shitake", 10},
        {"Portobello", 8},
        {"Shimeji", 6},
        {"Champignon", 12},
        {"Funghi", 16},
        {"Porcini", 16}
    };
    
    // Número total de cogumelos na lista
    int totalCogumelos = sizeof(listaDeCogumelos) / sizeof(listaDeCogumelos[0]);
    char cogumeloDesejado[20];
    
    // Solicitando o nome do cogumelo desejado pelo usuário
    //printf("Digite o nome do cogumelo desejado: ");
    scanf("%s", cogumeloDesejado);
    
    int indiceCogumelo = -1;
    int valorCogumeloDesejado = 0;
    
    // Procurando pelo cogumelo desejado na lista
    for (int i = 0; i < totalCogumelos; i++) {
        if (strcmp(listaDeCogumelos[i].nome, cogumeloDesejado) == 0) {
            valorCogumeloDesejado = listaDeCogumelos[i].valor;
            indiceCogumelo = i;
            break;
        }
    }
    
    // Verificando se o cogumelo desejado foi encontrado
    if (indiceCogumelo == -1) {
        printf("Cogumelo não encontrado.\n");
        return 1;
    }
    
    // Sugestão de cogumelos mais baratos
    int sugeridos = 0;
    for (int i = 0; i < totalCogumelos; i++) {
        // Verificando se o preço do cogumelo é menor ou igual ao do cogumelo desejado e não é o mesmo cogumelo desejado
        if (listaDeCogumelos[i].valor <= valorCogumeloDesejado && i != indiceCogumelo) {
            printf("%s - Valor: %d\n", listaDeCogumelos[i].nome, listaDeCogumelos[i].valor);
            sugeridos++;
            // Limitando o número de sugestões a no máximo 2
            if (sugeridos == 2) break;
        }
    }
    
    // Se não houver sugestões disponíveis
    if (sugeridos == 0) {
        printf("Desculpe, não há sugestões disponíveis.\n");
    }
    
    return 0;
}

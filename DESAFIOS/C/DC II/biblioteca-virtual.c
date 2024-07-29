#include <stdio.h>
#include <string.h>

// Definindo a estrutura Livro
typedef struct {
    char titulo[100];
    char autor[100];
    int anoDePublicacao;
} Livro;

int main() {
    int n;
    
    // Solicitando a entrada do número de livros
    //printf("Digite o número de livros na biblioteca (1 ≤ N ≤ 100): ");
    scanf("%d", &n);
    getchar();  // Consumir a nova linha após o número de livros
    
    if (n < 1 || n > 100) {
        printf("Número de livros inválido!\n");
        return 1;
    }

    Livro biblioteca[n];
    
    // Lendo as informações de cada livro
    for (int i = 0; i < n; i++) {
       // printf("%d", i + 1);
        fgets(biblioteca[i].titulo, 100, stdin);
        biblioteca[i].titulo[strcspn(biblioteca[i].titulo, "\n")] = '\0';  // Remover a nova linha

       // printf("%d", i + 1);
        fgets(biblioteca[i].autor, 100, stdin);
        biblioteca[i].autor[strcspn(biblioteca[i].autor, "\n")] = '\0';  // Remover a nova linha

        //printf("%d", i + 1);
        scanf("%d", &biblioteca[i].anoDePublicacao);
        getchar();  // Consumir a nova linha após o ano
    }
    
    // Encontrando o índice do livro mais antigo
    int indiceLivroMaisAntigo = 0;
    for (int i = 1; i < n; i++) {
        if (biblioteca[i].anoDePublicacao < biblioteca[indiceLivroMaisAntigo].anoDePublicacao) {
            indiceLivroMaisAntigo = i;
        }
    }
    
    // Imprimindo as informações do livro mais antigo
    printf("%s\n", biblioteca[indiceLivroMaisAntigo].titulo);
    printf("%s\n", biblioteca[indiceLivroMaisAntigo].autor);
    printf("%d\n", biblioteca[indiceLivroMaisAntigo].anoDePublicacao);
    
    return 0;
}



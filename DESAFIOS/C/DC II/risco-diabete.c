#include <stdio.h>

// Função para avaliar o risco de diabetes
void avaliarDiabetes(int idade, int concentracaoGlicose, float imc) {
    if (concentracaoGlicose >= 126) {
        printf("É altamente recomendável que você procure um médico para avaliação\n");
    } else if (concentracaoGlicose >= 120 && concentracaoGlicose <= 125 && imc > 27) {
        printf("Você tem uma probabilidade de adquirir diabetes. Procure um médico\n");
    } else if (concentracaoGlicose < 120) {
        if (idade > 40) {
            printf("Não tem diabetes. IMPORTANTE: cuide da sua saúde por estar acima dos 40 anos\n");
        } else {
            printf("Você não corre risco de diabetes\n");
        }
    }
}

int main() {
    int idade, concentracaoGlicose;
    float imc;

    // Solicitando a entrada do usuário
    //printf("Digite a sua idade: ");
    scanf("%d", &idade);

    //printf("Digite a concentração de glicose no sangue (mg/dL): ");
    scanf("%d", &concentracaoGlicose);

    //printf("Digite o seu IMC: ");
    scanf("%f", &imc);

    // Avaliando o risco de diabetes
    avaliarDiabetes(idade, concentracaoGlicose, imc);

    return 0;
}

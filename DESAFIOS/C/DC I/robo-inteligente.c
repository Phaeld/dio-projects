#include <stdio.h>

int main() {
   int numero;
   int positivo = 0, negativo = 0, zero = 0;

   scanf("%d", &numero);

   while(numero != 0) {
       if(numero > 0) {
           printf("positivo!\n");
           positivo++;
       } else if(numero < 0) {
           printf("negativo!\n");
           negativo++;
       } else {
           zero++;
       }

       scanf("%d", &numero);
   }

      printf(" %d números positivos, %d números negativos \n", positivo, negativo);

   return 0;
}
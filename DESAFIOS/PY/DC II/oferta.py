def calcular_garrafas_cheias(N, K):
    garrafas_cheias = N  # representa as garrafas cheias.
    garrafas_para_troca = K # representa a quantidade de garrafas para realizar a troca.
    if (garrafas_cheias >= garrafas_para_troca): #calcula se a quantidade comprada for maior que a quantidade troca.
      quantidade_garrafas = ((N//K) + (N%K)) #pega o inteiro da divisão da troca e soma com o que sobrou
    else:
      quantidade_garrafas = N #se a quantidade comprada for menor, apenas repete o valor.
    return(quantidade_garrafas)
# Lê o número de casos de teste
T = int(input())

# Para cada caso de teste
for i in range(T):
    # Lê o número de refrigerantes comprados e o número de garrafas vazias necessárias para ganhar uma cheia
    N, K = map(int, input().split())
    
    # funcao para calcular as garrafas totais
    resultado = calcular_garrafas_cheias(N, K)
    
    # Imprime o resultado
    print(resultado)
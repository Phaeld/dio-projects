# Número de casos de teste
C = int(input())

# Iterando por cada caso de teste
for _ in range(C):
    # Nível de energia de um ser vivo
    N = int(input())
    
    # Verificando se o nível de energia é maior que 8000
    if N > 8000:
        print("Mais de 8000!")
    else:
        print("Inseto!")

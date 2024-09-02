def verifica_encaixe(A, B):
    if A.endswith(B):
        return "encaixa"
    else:
        return "nao encaixa"

# Entrada
N = int(input())

for _ in range(N):
    A, B = input().split()
    
    # Saída
    print(verifica_encaixe(A, B))
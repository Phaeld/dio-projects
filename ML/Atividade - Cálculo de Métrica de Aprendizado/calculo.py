# Valores da matriz de confusão
VP = 50  # Verdadeiros Positivos
VN = 100 # Verdadeiros Negativos
FP = 5   # Falsos Positivos
FN = 10  # Falsos Negativos

# Cálculo das métricas
acurácia = (VP + VN) / (VP + VN + FP + FN)
sensibilidade = VP / (VP + FN)
especificidade = VN / (VN + FP)
precisão = VP / (VP + FP)
f_score = 2 * (precisão * sensibilidade) / (precisão + sensibilidade)

# Exibição dos resultados
print(f"Acurácia: {acurácia:.2f}")
print(f"Sensibilidade: {sensibilidade:.2f}")
print(f"Especificidade: {especificidade:.2f}")
print(f"Precisão: {precisão:.2f}")
print(f"F-Score: {f_score:.2f}")

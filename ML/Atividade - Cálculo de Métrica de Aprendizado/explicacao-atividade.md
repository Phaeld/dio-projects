# EXPLICAÇÃO DA ATIVDADE
## Cálculo de Métrica de Avaliação de Apredizado

Para calcular as principais métricas de avaliação de modelos de classificação de dados, vamos usar uma matriz de confusão. Vou criar uma matriz de confusão arbitrária e, a partir dela, calcular as métricas: sensibilidade (recall), especificidade, acurácia, precisão e F-score.

|   | Previsão Positiva | Previsão Negativa |
| - | ----------------- | ----------------- |
| Classe Positiva | VP = 50 | FN = 10 |
| Classe Negativa | FP = 5 | VN = 100 |

### Fórmulas das Métricas:
<br>
1. Acurácia _(Accuracy)_

> <br>Acurácia = (VP + VN) / (VP + VN + FP + FN)<br><br>

<br><br>
2. Sensibilidade _(Recall)_

> <br>Sensibilidade = VP / (VP + FN) <br><br>

<br><br>
3. Especificidade _(Specificity)_

> <br>Especificidade = VN / (VN + FP) <br><br>

<br><br>
4. Precisão _(Precision)_

> <br>Precisão = VP / (VP + FP)<br><br>

<br><br>
5. _F-Score_

> <br>F-Score = 2 * (Precisão * Sensibilidade) / (Precisão * Sensibilidade)<br><br>

<br>
Agora, vamos implementar estas fórmulas em Python para calcular as métricas com base na matriz de confusão fornecida nessa pasta ** calculo.py. **

<br>
<hr>

### Explicação do Código

1. Valores da Matriz de Confusão: São definidos os valores VP, VN, FP e FN.

2. Cálculo das Métricas: Usando as fórmulas matemáticas, calculamos cada métrica.

3. Exibição dos Resultados: Os valores calculados são impressos com duas casas decimais.

Resultado Esperado:
Executando o código acima, você deve obter as seguintes métricas para a matriz de confusão fornecida:
<center>
<p style="background-color:black; border-radius:15px;"><br>
Acurácia: 0.91<br>
Sensibilidade: 0.83<br>
Especificidade: 0.95<br>
Precisão: 0.91<br>
F-Score: 0.87<br>
<br>
</p>
</center>

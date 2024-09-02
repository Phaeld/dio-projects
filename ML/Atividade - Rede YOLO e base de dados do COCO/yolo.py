import torch
from ultralytics import YOLO

# Carregar o modelo pré-treinado
model = YOLO('yolov5s')  # Carrega o modelo YOLOv5s

# Fazer uma predição em uma imagem
results = model('https://ultralytics.com/images/zidane.jpg')

# Visualizar os resultados
results.print()
results.show()
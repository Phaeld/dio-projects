def se_vertebrados (dado1,dado2): 
  if dado1 == "ave":
    if dado2 == "carnivoro":
      return("aguia")
    elif dado2 == "onivoro": 
      return("pomba")
  elif dado1 == "mamifero":
    if dado2 == "onivoro":
      return("homem")
    elif dado2 == "herbivoro":
      return("vaca")
      
      
      
def se_invertebrados(dado1, dado2): 
  if dado1 == "inseto":
    if dado2 == "hematofago":
      return("pulga")
    elif dado2 == "herbivoro": 
      return("lagarta")
  elif dado1 == "anelideo":
    if dado2 == "hematofago":
      return("sanguessuga")
    elif dado2 == "onivoro":
      return("minhoca")
      
      
      
a = input() 
b = input() 
c = input() 

if a == 'vertebrado': 
  resultado = se_vertebrados(b,c)
  print(resultado)
    
elif a == 'invertebrado':
  resultado = se_invertebrados(b,c)
  print(resultado)
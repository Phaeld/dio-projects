def verificar_tweet(texto):
    if len(texto) <= 140:
        return "TWEET"
    else:
        return "MUTE"

# Entrada
texto = input()

# Saída
print(verificar_tweet(texto))
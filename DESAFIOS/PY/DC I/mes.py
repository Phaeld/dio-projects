def nome_do_mes(numero):
    meses = {
        1: "January",
        2: "February",
        3: "March",
        4: "April",
        5: "May",
        6: "June",
        7: "July",
        8: "August",
        9: "September",
        10: "October",
        11: "November",
        12: "December"
    }
    return meses.get(numero, "Invalid month")

# Entrada
numero_mes = int(input())

# Saída
print(nome_do_mes(numero_mes))
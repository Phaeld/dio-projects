menu = '''

[d] Depositar
[s] Sacar
[e] Extrato
[q] Sair

=> '''

saldo = 0  # Inicializa o saldo da conta como zero
limite = 500  # Define o limite de saque como 500
extrato = ''  # Inicializa o extrato vazio
numero_saques = 0  # Inicializa o número de saques realizados como zero
LIMITE_SAQUES = 3  # Define o limite máximo de saques permitidos como 3

# Loop infinito para execução do menu até que o usuário escolha sair
while True:

    opcao = input(menu)  # Exibe o menu e lê a opção escolhida pelo usuário

    if opcao == 'd':  # Se a opção for 'd' (Depositar)
        valor = float(input('Informe o valor do depósito: '))  # Solicita o valor do depósito

        if valor > 0:  # Verifica se o valor do depósito é maior que zero
            saldo += valor  # Adiciona o valor do depósito ao saldo
            extrato += f"Depósito: R$ {valor:.2f}\n"  # Adiciona a operação de depósito ao extrato

        else:
            print("Operação falhou: O valor informado é inválido.")  # Mensagem de erro para valor inválido

    elif opcao == 's':  # Se a opção for 's' (Sacar)
        valor = float(input('Informe o valor do saque: '))  # Solicita o valor do saque

        excedeu_saldo = valor > saldo  # Verifica se o valor do saque excede o saldo disponível
        excedeu_limite = valor > limite  # Verifica se o valor do saque excede o limite permitido
        excedeu_saques = numero_saques >= LIMITE_SAQUES  # Verifica se o número de saques excedeu o limite diário

        if excedeu_saldo:
            print('Operação falhou: Você não tem saldo suficiente.')  # Mensagem de erro para saldo insuficiente

        elif excedeu_limite:
            print('Operação falhou: O valor do saque excede o limite.')  # Mensagem de erro para saque acima do limite

        elif excedeu_saques:
            print('Operação falhou: Números máximos de saques excederam.')  # Mensagem de erro para excesso de saques

        elif valor > 0:  # Verifica se o valor do saque é maior que zero
            saldo -= valor  # Subtrai o valor do saque do saldo
            extrato += f"Saque: R$ {valor:.2f}\n"  # Adiciona a operação de saque ao extrato
            numero_saques += 1  # Incrementa o número de saques realizados

        else:
            print('Operação falhou: O valor informado é inválido.')  # Mensagem de erro para valor inválido

    elif opcao == 'e':  # Se a opção for 'e' (Extrato)
        print("\n=============== EXTRATO ===============")
        # Exibe o extrato se houver operações registradas, caso contrário, informa que não houve movimentações
        print("Não foram realizados movimentações. " if not extrato else extrato)
        print(f"\nSaldo: R$ {saldo:.2f}")  # Exibe o saldo atual da conta
        print("=========================================")

    elif opcao == 'q':  # Se a opção for 'q' (Sair)
        break  # Encerra o loop e sai do programa

    else:
        print('Operação inválida, por favor selecione novamente a operação desejada.')  # Mensagem de erro para opção inválida

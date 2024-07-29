import textwrap

# Função para exibir o menu e obter a opção do usuário
def menu():
    # Menu de opções para o usuário
    menu = """\n
    ================ MENU ================
    [d] Depositar
    [s] Sacar
    [e] Extrato
    [nc] Nova conta
    [lc] Listar contas
    [nu] Novo usuário
    [q] Sair
    => """
    # Retorna a opção escolhida pelo usuário
    return input(textwrap.dedent(menu))

# Função para realizar depósitos
def depositar(saldo, valor, extrato, /):
    # Verifica se o valor do depósito é positivo
    if valor > 0:
        saldo += valor  # Adiciona o valor ao saldo
        extrato += f"Depósito:\tR$ {valor:.2f}\n"  # Registra o depósito no extrato
        print("\n=== Depósito realizado com sucesso! ===")
    else:
        print("\n@@@ Operação falhou! O valor informado é inválido. @@@")
    # Retorna o saldo atualizado e o extrato atualizado
    return saldo, extrato

# Função para realizar saques
def sacar(*, saldo, valor, extrato, limite, numero_saques, limite_saques):
    # Verifica se o valor do saque excede o saldo
    excedeu_saldo = valor > saldo
    # Verifica se o valor do saque excede o limite
    excedeu_limite = valor > limite
    # Verifica se o número de saques excedeu o limite
    excedeu_saques = numero_saques >= limite_saques

    # Condições de falha na operação de saque
    if excedeu_saldo:
        print("\n@@@ Operação falhou! Você não tem saldo suficiente. @@@")
    elif excedeu_limite:
        print("\n@@@ Operação falhou! O valor do saque excede o limite. @@@")
    elif excedeu_saques:
        print("\n@@@ Operação falhou! Número máximo de saques excedido. @@@")
    elif valor > 0:
        saldo -= valor  # Subtrai o valor do saque do saldo
        extrato += f"Saque:\t\tR$ {valor:.2f}\n"  # Registra o saque no extrato
        numero_saques += 1  # Incrementa o número de saques realizados
        print("\n=== Saque realizado com sucesso! ===")
    else:
        print("\n@@@ Operação falhou! O valor informado é inválido. @@@")
    # Retorna o saldo atualizado, o extrato atualizado e o número de saques
    return saldo, extrato, numero_saques

# Função para exibir o extrato
def exibir_extrato(saldo, /, *, extrato):
    print("\n================ EXTRATO ================")
    # Verifica se houve movimentações e exibe o extrato
    print("Não foram realizadas movimentações." if not extrato else extrato)
    # Exibe o saldo atual
    print(f"\nSaldo:\t\tR$ {saldo:.2f}")
    print("==========================================")

# Função para criar um novo usuário
def criar_usuario(usuarios):
    # Solicita o CPF do novo usuário
    cpf = input("Informe o CPF (somente número): ")
    usuario = filtrar_usuario(cpf, usuarios)  # Verifica se o usuário já existe

    if usuario:
        print("\n@@@ Já existe usuário com esse CPF! @@@")
        return

    # Solicita os dados do novo usuário
    nome = input("Informe o nome completo: ")
    data_nascimento = input("Informe a data de nascimento (dd-mm-aaaa): ")
    endereco = input("Informe o endereço (logradouro, nro - bairro - cidade/sigla estado): ")

    # Adiciona o novo usuário à lista de usuários
    usuarios.append({"nome": nome, "data_nascimento": data_nascimento, "cpf": cpf, "endereco": endereco})

    print("=== Usuário criado com sucesso! ===")

# Função para filtrar usuário pelo CPF
def filtrar_usuario(cpf, usuarios):
    # Procura pelo usuário na lista de usuários pelo CPF
    usuarios_filtrados = [usuario for usuario in usuarios if usuario["cpf"] == cpf]
    # Retorna o usuário encontrado ou None se não encontrado
    return usuarios_filtrados[0] if usuarios_filtrados else None

# Função para criar uma nova conta
def criar_conta(agencia, numero_conta, usuarios):
    # Solicita o CPF do usuário para associar a conta
    cpf = input("Informe o CPF do usuário: ")
    usuario = filtrar_usuario(cpf, usuarios)  # Verifica se o usuário existe

    if usuario:
        print("\n=== Conta criada com sucesso! ===")
        # Retorna a nova conta com os dados do usuário
        return {"agencia": agencia, "numero_conta": numero_conta, "usuario": usuario}

    print("\n@@@ Usuário não encontrado, fluxo de criação de conta encerrado! @@@")

# Função para listar todas as contas
def listar_contas(contas):
    # Percorre a lista de contas e exibe as informações de cada conta
    for conta in contas:
        linha = f"""\
            Agência:\t{conta['agencia']}
            C/C:\t\t{conta['numero_conta']}
            Titular:\t{conta['usuario']['nome']}
        """
        print("=" * 100)
        print(textwrap.dedent(linha))

# Função principal
def main():
    LIMITE_SAQUES = 3  # Define o limite de saques por dia
    AGENCIA = "0001"  # Define o número da agência

    # Inicializa variáveis
    saldo = 0
    limite = 500
    extrato = ""
    numero_saques = 0
    usuarios = []
    contas = []

    while True:
        opcao = menu()  # Exibe o menu e obtém a opção do usuário

        # Opção de depósito
        if opcao == "d":
            valor = float(input("Informe o valor do depósito: "))
            saldo, extrato = depositar(saldo, valor, extrato)

        # Opção de saque
        elif opcao == "s":
            valor = float(input("Informe o valor do saque: "))
            saldo, extrato, numero_saques = sacar(
                saldo=saldo,
                valor=valor,
                extrato=extrato,
                limite=limite,
                numero_saques=numero_saques,
                limite_saques=LIMITE_SAQUES,
            )

        # Opção de extrato
        elif opcao == "e":
            exibir_extrato(saldo, extrato=extrato)

        # Opção de criar novo usuário
        elif opcao == "nu":
            criar_usuario(usuarios)

        # Opção de criar nova conta
        elif opcao == "nc":
            numero_conta = len(contas) + 1
            conta = criar_conta(AGENCIA, numero_conta, usuarios)
            if conta:
                contas.append(conta)

        # Opção de listar contas
        elif opcao == "lc":
            listar_contas(contas)

        # Opção de sair
        elif opcao == "q":
            break

        # Opção inválida
        else:
            print("Operação inválida, por favor selecione novamente a operação desejada.")

# Executa a função principal
main()

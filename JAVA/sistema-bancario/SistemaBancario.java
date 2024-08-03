/**
 *  SISTEMA BANCÁRIO EM JAVA
 * 
 *  Nesse arquivo, fiz um sistema bancário como atividade da DIO. Ele tem uma função básica de todo sistema bancário sem a utilização
 *  de POO (Programação Orientada à Objetos).
 */

import java.util.Scanner; // Importa a classe Scanner para leitura de dados do usuário

public class SistemaBancario {
    // Variáveis estáticas para armazenar as contas
    static int numeroContas = 0; // Contador do número de contas criadas
    static int[] numeros = new int[100]; // Array para armazenar os números das contas
    static String[] titulares = new String[100]; // Array para armazenar os nomes dos titulares das contas
    static double[] saldos = new double[100]; // Array para armazenar os saldos das contas

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in); // Cria um objeto Scanner para leitura de dados do usuário
        int opcao; // Variável para armazenar a opção escolhida pelo usuário

        // Loop principal do menu
        do {
            // Exibe o menu de opções
            System.out.println("\n--- Sistema Bancário ---");
            System.out.println("1. Criar Conta");
            System.out.println("2. Depositar");
            System.out.println("3. Sacar");
            System.out.println("4. Verificar Saldo");
            System.out.println("5. Sair");
            System.out.print("Escolha uma opção: ");
            opcao = scanner.nextInt(); // Lê a opção escolhida pelo usuário

            // Executa a ação correspondente à opção escolhida
            switch (opcao) {
                case 1:
                    criarConta(scanner); // Chama a função para criar uma nova conta
                    break;
                case 2:
                    depositar(scanner); // Chama a função para depositar dinheiro em uma conta
                    break;
                case 3:
                    sacar(scanner); // Chama a função para sacar dinheiro de uma conta
                    break;
                case 4:
                    verificarSaldo(scanner); // Chama a função para verificar o saldo de uma conta
                    break;
                case 5:
                    System.out.println("Saindo do sistema..."); // Mensagem de saída do sistema
                    break;
                default:
                    System.out.println("Opção inválida! Tente novamente."); // Mensagem para opção inválida
            }
        } while (opcao != 5); // Repete o loop até que a opção 5 (sair) seja escolhida

        scanner.close(); // Fecha o objeto Scanner
    }

    // Função para criar uma nova conta
    public static void criarConta(Scanner scanner) {
        if (numeroContas >= 100) { // Verifica se o limite de contas foi atingido
            System.out.println("Limite de contas atingido!");
            return; // Sai da função se o limite foi atingido
        }
        System.out.print("Digite o número da conta: ");
        numeros[numeroContas] = scanner.nextInt(); // Lê o número da nova conta
        scanner.nextLine(); // Consumir a nova linha
        System.out.print("Digite o nome do titular: ");
        titulares[numeroContas] = scanner.nextLine(); // Lê o nome do titular da nova conta
        saldos[numeroContas] = 0.0; // Inicializa o saldo da nova conta como 0.0
        numeroContas++; // Incrementa o contador de contas
        System.out.println("Conta criada com sucesso!"); // Mensagem de sucesso
    }

    // Função para depositar dinheiro em uma conta
    public static void depositar(Scanner scanner) {
        System.out.print("Digite o número da conta: ");
        int numero = scanner.nextInt(); // Lê o número da conta
        int index = encontrarConta(numero); // Encontra o índice da conta no array
        if (index == -1) { // Verifica se a conta não foi encontrada
            System.out.println("Conta não encontrada!");
            return; // Sai da função se a conta não foi encontrada
        }
        System.out.print("Digite o valor do depósito: ");
        double valor = scanner.nextDouble(); // Lê o valor do depósito
        if (valor <= 0) { // Verifica se o valor do depósito é inválido
            System.out.println("Valor inválido!");
            return; // Sai da função se o valor for inválido
        }
        saldos[index] += valor; // Adiciona o valor do depósito ao saldo da conta
        System.out.println("Depósito realizado com sucesso!"); // Mensagem de sucesso
    }

    // Função para sacar dinheiro de uma conta
    public static void sacar(Scanner scanner) {
        System.out.print("Digite o número da conta: ");
        int numero = scanner.nextInt(); // Lê o número da conta
        int index = encontrarConta(numero); // Encontra o índice da conta no array
        if (index == -1) { // Verifica se a conta não foi encontrada
            System.out.println("Conta não encontrada!");
            return; // Sai da função se a conta não foi encontrada
        }
        System.out.print("Digite o valor do saque: ");
        double valor = scanner.nextDouble(); // Lê o valor do saque
        if (valor <= 0 || valor > saldos[index]) { // Verifica se o valor do saque é inválido ou se o saldo é insuficiente
            System.out.println("Valor inválido ou saldo insuficiente!");
            return; // Sai da função se o valor for inválido ou saldo insuficiente
        }
        saldos[index] -= valor; // Subtrai o valor do saque do saldo da conta
        System.out.println("Saque realizado com sucesso!"); // Mensagem de sucesso
    }

    // Função para verificar o saldo de uma conta
    public static void verificarSaldo(Scanner scanner) {
        System.out.print("Digite o número da conta: ");
        int numero = scanner.nextInt(); // Lê o número da conta
        int index = encontrarConta(numero); // Encontra o índice da conta no array
        if (index == -1) { // Verifica se a conta não foi encontrada
            System.out.println("Conta não encontrada!");
            return; // Sai da função se a conta não foi encontrada
        }
        System.out.println("Saldo da conta " + numero + ": " + saldos[index]); // Exibe o saldo da conta
    }

    // Função para encontrar o índice de uma conta no array
    public static int encontrarConta(int numero) {
        for (int i = 0; i < numeroContas; i++) { // Itera sobre todas as contas
            if (numeros[i] == numero) { // Verifica se o número da conta corresponde
                return i; // Retorna o índice da conta
            }
        }
        return -1; // Retorna -1 se a conta não foi encontrada
    }
}

#include <iostream>
#include <string>

class Robo {
public:
    int velocidadeAtual = 0;
    int velocidadeMaxima;
    int velocidadeMinima;
    
    Robo(int vmin, int vmax) : velocidadeMinima(vmin), velocidadeMaxima(vmax) {
        velocidadeAtual = vmin;
    }
    
    void acelerar() {
        if (velocidadeAtual < velocidadeMaxima) {
            velocidadeAtual++;
        }
    }
    
    void desacelerar() {
        if (velocidadeAtual > velocidadeMinima) {
            velocidadeAtual--;
        }
    }
};

int main() {
    int vmin, vmax;
    std::string comandos;
    
    std::cin >> vmin >> vmax;
    std::cin >> comandos;
    
    Robo robo(vmin, vmax);
    for (char comando : comandos) {
        if (comando == 'A') {
            robo.acelerar();
        } else if (comando == 'D') {
            robo.desacelerar();
        }
    }
    
    std::cout << robo.velocidadeAtual << std::endl;
    
    return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int calcularPremio(int aposta, int numeroApostado, int numeroSorteado) {
    int lucro = 0;

    if (numeroApostado == numeroSorteado) {
        lucro = 5 * aposta;
    } else if (numeroApostado == ((numeroSorteado % 10) * 10 + (numeroSorteado / 10))) {
        lucro = 2 * aposta;
    } else if (numeroApostado / 10 == (numeroSorteado / 10) % 10) {
        lucro = 2 * aposta;
    } else if (numeroApostado % 10 == numeroSorteado % 10) {
        lucro = 3 * aposta;
	} else if (numeroApostado == (numeroSorteado % 10) + (numeroSorteado / 10)) {
        lucro = 2 * aposta;
    } else if (numeroApostado % 2 == numeroSorteado % 2) {
        lucro = aposta;
    }

    return lucro;
}

int main() {
    srand(time(NULL));  // Inicializa a semente para a função rand()

    int aposta, numeroApostado, numeroSorteado;

    while (1) {
        // Sorteia um novo número
        //numeroSorteado = rand() % 50 + 1;  // Números de 1 a 50
		numeroSorteado = 22;
        // Solicita ao usuário o valor em Kwanzas para a aposta e o número a ser apostado
        printf("Digite o valor em Kwanzas para a aposta (ou 0 para sair): ");
        scanf("%d", &aposta);

        // Verifica se o usuário deseja sair do jogo
        if (aposta == 0) {
            printf("Jogo encerrado. Obrigado por jogar!\n");
            break;
        }

        printf("Digite o número apostado (entre 1 e 50): ");
        scanf("%d", &numeroApostado);

        // Verifica se o número apostado está dentro do intervalo permitido
        if (numeroApostado < 1 || numeroApostado > 50) {
            printf("Número apostado fora do intervalo permitido. Tente novamente.\n");
            continue;
        }

        // Calcula o prêmio e imprime o resultado
        int premio = calcularPremio(aposta, numeroApostado, numeroSorteado);

        if (premio > aposta) {
            printf("Parabéns! Você ganhou Kz %d. Número sorteado: %d\n", premio - aposta, numeroSorteado);
        } else {
            printf("Infelizmente, você perdeu Kz %d. Número sorteado: %d\n", aposta - premio, numeroSorteado);
        }
    }

    return 0;
}


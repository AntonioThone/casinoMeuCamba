#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL));  // Inicializa a semente para a função rand()

    int aposta, numeroApostado, numeroSorteado, lucro = 0, jogada = 1;

    while (1) {
        for (int i = 0; ; i++) {
            jogada = jogada + i;
            printf("Jogada %d\n", jogada);

            // numeroSorteado = rand() % 50 + 1;  // Números de 1 a 50
            numeroSorteado = 21;
            printf("Quantia Apostada: KZ ");
            scanf("%d", &aposta);

            // Verifica se o usuário deseja sair do jogo
            if (aposta == 0) {
                printf("Jogo encerrado. Obrigado por jogar!\n");
                return 0;
            }

            printf("Numero Apostado: ");
            scanf("%d", &numeroApostado);

            printf("Numero Sorteado: \n %d", numeroSorteado);

            // Verifica se o número apostado está dentro do intervalo permitido
            if (numeroApostado < 1 || numeroApostado > 50) {
                printf("Número apostado fora do intervalo permitido. Tente novamente.\n");
                continue;
            }

            // Calcula o prêmio
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

            // Imprime o resultado
            printf("Prêmio = %d\n", lucro);
        }
    }

    return 0;
}



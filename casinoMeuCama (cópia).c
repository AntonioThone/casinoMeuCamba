#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL));  // Inicializa a semente para a função rand()

    int aposta, casinoPaga, numeroApostado, numeroSorteado, lucro, jogada = 1;

    while (1) {
        for (int i = 1; ; i++) {
            jogada = i;

            printf("-------------------------------------------------\n");
            printf("Jogada %d\n", jogada);

            numeroSorteado = rand() % 50 + 1;  // Números de 1 a 50
            //numeroSorteado = 12;
            printf("Quantia Apostada: KZ ");
            scanf("%d", &aposta);

            // Verifica se o usuário deseja sair do jogo
            if (aposta == 0) {
                printf("Jogo encerrado. Obrigado por jogar!\n");
                return 0;
            }

            printf("Numero Apostado: ");
            scanf("%d", &numeroApostado);

            printf("Numero Sorteado:%d\n", numeroSorteado);

            // Verifica se o número apostado está dentro do intervalo permitido
            if (numeroApostado < 1 || numeroApostado > 50) {
                printf("Número apostado fora do intervalo permitido. Tente novamente.\n");
                continue;
            }

            // Calcula o prêmio
            if (numeroApostado == numeroSorteado) {
                casinoPaga = 5 * aposta;
                printf("Jogador acertou no numero sorteado\n");
            } else if (numeroApostado == ((numeroSorteado % 10) * 10 + (numeroSorteado / 10))) {
                casinoPaga = 2 * aposta;
                printf("Jogo encerrado. Ob\n");
            } else if (numeroApostado / 10 == (numeroSorteado / 10) % 10) {
                casinoPaga = 2 * aposta;
            } else if (numeroApostado % 10 == numeroSorteado % 10) {
                casinoPaga = 3 * aposta;
            } else if (numeroApostado == (numeroSorteado % 10) + (numeroSorteado / 10)) {
                casinoPaga = 2 * aposta;
            } else if (numeroApostado % 2 == numeroSorteado % 2) {
                casinoPaga = aposta;
            }

            lucro = casinoPaga - aposta;
            printf("-------------------------------------------------\n");
            printf("Casino Pagou: Kz%d\n", casinoPaga);
            printf("Jogador Ganhou: Kz%d\n", lucro);

        }
    }

    return 0;
}



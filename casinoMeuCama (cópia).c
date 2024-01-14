#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL));

    int aposta, casinoPaga, numeroApostado, numeroSorteado, lucroJogada = 0, jogada = 1, prejuizoTotal = 0;

    while (1) {
        printf("-------------------------------------------------\n");
        printf("Jogada %d\n", jogada);
        printf("\n");

        numeroSorteado = rand() % 50 + 1;
        printf("Quantia Apostada: KZ ");
        scanf("%d", &aposta);

        if (aposta == 0) {
            printf("Apos uma sequencia de %d jogadas, o jogador tem um lucro de Kz%d\n", jogada - 1, lucroJogada);
            return 0;
        }

        printf("Numero Apostado: ");
        scanf("%d", &numeroApostado);

        printf("Numero Sorteado:%d\n", numeroSorteado);
        printf("\n");

        if (numeroApostado < 1) {
            printf("Número apostado abaixo do intervalo permitido. Tente novamente.\n");
            continue;
        } else if (numeroApostado > 50) {
            printf("Número apostado acima do intervalo permitido. Tente novamente.\n");
            continue;
        }

        int dezenaApostado = numeroApostado / 10;
        int dezenaSorteado = numeroSorteado / 10;

        casinoPaga = 0;

        if (numeroApostado == numeroSorteado) {
            casinoPaga += 5 * aposta;
            lucroJogada += casinoPaga - aposta;
            printf("Jogador acertou no numero sorteado. Lucro na jogada: Kz%d\n", casinoPaga - aposta);
        } else if (numeroApostado == (numeroSorteado % 10) * 10 + (numeroSorteado / 10)) {
            casinoPaga += 3 * aposta;
            printf("Jogador acertou na ordem inversa. Lucro na jogada: Kz%d\n", casinoPaga - aposta);
        } else if (dezenaApostado == dezenaSorteado) {
            casinoPaga += 2 * aposta;
            printf("Jogador acertou na dezena. Lucro na jogada: Kz%d\n", casinoPaga - aposta);
        } else if (numeroApostado % 10 == numeroSorteado % 10) {
            casinoPaga += 2 * aposta;
            printf("Jogador acertou na unidade. Lucro na jogada: Kz%d\n", casinoPaga - aposta);
        } else if (numeroApostado == (numeroSorteado % 10) + (numeroSorteado / 10)) {
            casinoPaga += 2 * aposta;
            printf("Jogador acertou na soma dos digitos. Lucro na jogada: Kz%d\n", casinoPaga - aposta);
        } else if (numeroApostado % 2 == numeroSorteado % 2) {
            casinoPaga += aposta;
            lucroJogada += casinoPaga - aposta;
            printf("Jogador acertou na paridade. Lucro na jogada: Kz%d\n", casinoPaga - aposta);
        } else {
            prejuizoTotal += aposta;
            printf("Prejuizo na jogada: Kz%d\n", aposta);
            printf("---------------------------------------------\n");
            printf("Ate agora o jogador tem prejuizo total de: Kz%d\n", prejuizoTotal);
        }

        printf("-------------------------------------------------\n");
        printf("Casino Pagou: Kz%d\n", casinoPaga);
        printf("Jogador Ganhou: Kz%d\n", lucroJogada);
        printf("-------------------------------------------------\n");
        printf("Ate agora o jogador tem em lucro: KZ %d\n", lucroJogada);

        jogada++;
    }

    return 0;
}

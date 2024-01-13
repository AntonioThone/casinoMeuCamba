#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL));  // Inicializa a semente para a função rand()

    int aposta, casinoPaga, numeroApostado, numeroSorteado, lucro, lucroJogada = 0, jogada = 1, prejuizo = 0;

    while (1) {
        for (int i = 1; ; i++) {
            jogada = i;

            printf("-------------------------------------------------\n");
            printf("Jogada %d\n", jogada);
            printf("\n");

            numeroSorteado = rand() % 50 + 1;  // Números de 1 a 50
            //numeroSorteado = 12;
            printf("Quantia Apostada: KZ ");
            scanf("%d", &aposta);

            // Verifica se o usuário deseja sair do jogo
            if (aposta == 0) {
                printf("Apos uma sequencia de %d jogadas, o jogador ganhou %d\n", jogada, lucroJogada);
                return 0;
            }

            printf("Numero Apostado: ");
            scanf("%d", &numeroApostado);

            printf("Numero Sorteado:%d\n", numeroSorteado);

            printf("\n");

            // Verifica se o número apostado está dentro do intervalo permitido
            if (numeroApostado < 1 || numeroApostado > 50) {
                printf("Número apostado fora do intervalo permitido. Tente novamente.\n");
                continue;
            }

            //calculo do prejuizo

            //calculo do lucro
            lucroJogada = (lucroJogada + aposta);

            // Calcula o prêmio
            if (numeroApostado == numeroSorteado) {
                casinoPaga = 5 * aposta;
                printf("Jogador acertou no numero sorteado\n");
            } else if (numeroApostado == ((numeroSorteado % 10) * 10 + (numeroSorteado / 10))) {
                casinoPaga = 3 * aposta;
                printf("Jogador acertou na ordem inversa.\n");
            } else if (numeroApostado / 10 == (numeroSorteado / 10)) {
                casinoPaga = 2 * aposta;
                printf("Jogador acertou na dezena.\n");
            } else if (numeroApostado % 10 == numeroSorteado % 10) {
                casinoPaga = 2 * aposta;
                printf("Jogador acertou na unidade.\n");
            } else if (numeroApostado == (numeroSorteado % 10) + (numeroSorteado / 10)) {
                casinoPaga = 2 * aposta;
                printf("Jogador acertou na soma dos digitos\n");
            } else if (numeroApostado % 2 == numeroSorteado % 2) {
                casinoPaga = aposta - aposta;
                printf("Jogador acertou na paridade.\n");
            }
            else if(numeroApostado != numeroApostado){
                prejuizo = prejuizo + aposta;
                printf("Jogador nao acertou no numero sorteado.\n");
                printf("---------------------------------------------\n");
                printf("Ate agora o jogador tem prejuizo de: Kz%d\n", prejuizo);
            }

            lucro = casinoPaga - aposta;
            printf("-------------------------------------------------\n");
            printf("Casino Pagou: Kz%d\n", casinoPaga);
            printf("Jogador Ganhou: Kz%d\n", lucro);
            printf("-------------------------------------------------\n");
            printf("Ate agora o jogador tem em lucro: KZ %d\n", lucroJogada);

        }
    }

    return 0;
}



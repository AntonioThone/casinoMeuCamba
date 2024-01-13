#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL));  // Inicializa a semente para a função rand()

    int aposta, casinoPaga, numeroApostado, numeroSorteado,lucroJogada = 0, jogada = 1, prejuizoTotal = 0;

    while (1) {
        printf("-------------------------------------------------\n");
        printf("Jogada %d\n", jogada);
        printf("\n");

        numeroSorteado = rand() % 50 + 1;  // Números de 1 a 50
        printf("Quantia Apostada: KZ ");
        scanf("%d", &aposta);

        // Verifica se o usuário deseja sair do jogo
        if (aposta == 0) {
            printf("Apos uma sequencia de %d jogadas, o jogador tem um lucro de Kz%d\n", jogada - 1, lucroJogada);
            return 0;
        }

        printf("Numero Apostado: ");
        scanf("%d", &numeroApostado);

        printf("Numero Sorteado:%d\n", numeroSorteado);
        printf("\n");

        // Verifica se o número apostado está dentro do intervalo permitido
        if (numeroApostado < 1) {
            printf("Número apostado abaixo do intervalo permitido. Tente novamente.\n");
        } else if (numeroApostado > 50) {
            printf("Número apostado acima do intervalo permitido. Tente novamente.\n");
        }


        // Calcula a dezena dos números
        int dezenaApostado = numeroApostado / 10;
        int dezenaSorteado = numeroSorteado / 10;

        // Inicializa o prêmio para a jogada atual
        casinoPaga = 0;

        // Verifica acertos e atualiza o prêmio
        if (numeroApostado == numeroSorteado) {
            casinoPaga += 5 * aposta;
            printf("Jogador acertou no numero sorteado. ");
        }
        if (numeroApostado == (numeroSorteado % 10) * 10 + (numeroSorteado / 10)) {
            casinoPaga += 3 * aposta;
            printf("Jogador acertou na ordem inversa. ");
        }
        if (dezenaApostado == dezenaSorteado) {
            casinoPaga += 2 * aposta;
            printf("Jogador acertou na dezena. ");
        }
        if (numeroApostado % 10 == numeroSorteado % 10) {
            casinoPaga += 2 * aposta;
            printf("Jogador acertou na unidade. ");
        }
        if (numeroApostado == (numeroSorteado % 10) + (numeroSorteado / 10)) {
            casinoPaga += 2 * aposta;
            printf("Jogador acertou na soma dos digitos. ");
        }
        if (numeroApostado % 2 == numeroSorteado % 2) {
            casinoPaga += aposta;
            printf("Jogador acertou na paridade. ");
        }

        // Calcula lucro ou prejuízo e atualiza os acumuladores
        int resultado = casinoPaga - aposta;
        lucroJogada += resultado;
        prejuizoTotal += (resultado < 0) ? aposta : 0;

        // Imprime os resultados
        if (resultado >= 0) {
            printf("Lucro na jogada: Kz%d\n", abs(resultado));
        } else {
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

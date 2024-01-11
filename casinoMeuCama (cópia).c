#include <stdio.h>
#include <stdlib.h>
#include <time.h>


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



int main() {
    srand(time(NULL));  // Inicializa a semente para a fun��o rand()

    int aposta, numeroApostado, numeroSorteado, lucro = 0;

    while (1) {
        //numeroSorteado = rand() % 50 + 1;  // N�meros de 1 a 50
		numeroSorteado = 22;
        printf("Digite o valor em Kwanzas para a aposta (ou 0 para sair): ");
        scanf("%d", &aposta);

        // Verifica se o usu�rio deseja sair do jogo
        if (aposta == 0) {
            printf("Jogo encerrado. Obrigado por jogar!\n");
            break;
        }

        printf("Digite o n�mero apostado (entre 1 e 50): ");
        scanf("%d", &numeroApostado);

        // Verifica se o n�mero apostado est� dentro do intervalo permitido
        if (numeroApostado < 1 || numeroApostado > 50) {
            printf("N�mero apostado fora do intervalo permitido. Tente novamente.\n");
            continue;
        }

        // Calcula o pr�mio e imprime o resultado
        int premio = calcularPremio(aposta, numeroApostado, numeroSorteado);

        if (premio > aposta) {
            printf("Parab�ns! Voc� ganhou Kz %d. N�mero sorteado: %d\n", premio - aposta, numeroSorteado);
        } else {
            printf("Infelizmente, voc� perdeu Kz %d. N�mero sorteado: %d\n", aposta - premio, numeroSorteado);
        }
    }

    return 0;
}


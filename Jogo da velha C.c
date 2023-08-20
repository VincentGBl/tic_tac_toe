#include<stdio.h>

void jogada(char *p1, char *p2, char *p3, char *p4, char *p5, char *p6, char *p7, char *p8, char *p9, int posp, char play) {
    switch (posp) {
        case 1:
            *p1 = play;
            break;
        case 2:
            *p2 = play;
            break;
        case 3:
            *p3 = play;
            break;
        case 4:
            *p4 = play;
            break;
        case 5:
            *p5 = play;
            break;
        case 6:
            *p6 = play;
            break;
        case 7:
            *p7 = play;
            break;
        case 8:
            *p8 = play;
            break;
        case 9:
            *p9 = play;
            break;
    }
}

void mostrarjogo(char p1, char p2, char p3, char p4, char p5, char p6, char p7, char p8, char p9) {
    printf("%c / %c / %c\n%c / %c / %c\n%c / %c / %c\n", p1, p2, p3, p4, p5, p6, p7, p8, p9);
}

char testedevitoria(char p1, char p2, char p3, char p4, char p5, char p6, char p7, char p8, char p9) {
    if ((p1 == p2 && p2 == p3) || (p4 == p5 && p5 == p6) || (p7 == p8 && p8 == p9) ||
        (p1 == p4 && p4 == p7) || (p2 == p5 && p5 == p8) || (p3 == p6 && p6 == p9) ||
        (p1 == p5 && p5 == p9) || (p3 == p5 && p5 == p7)) {
        return '1';  // Player ganhou
    } else {
        return '0';  // sem vencedor ainda
    }
}

int main() {
    // Tentativa de fazer um jogo da velha
    int posplay1, posplay2;
    char play1, play2, resultado;
    char pos1 = '1', pos2 = '2', pos3 = '3', pos4 = '4', pos5 = '5', pos6 = '6', pos7 = '7', pos8 = '8', pos9 = '9';
    resultado = '0';

    printf("%c / %c / %c\n%c / %c / %c\n%c / %c / %c\n", pos1, pos2, pos3, pos4, pos5, pos6, pos7, pos8, pos9); // Corpo do jogo

    printf("\nVoce quer jogar com o '%c' ou com o '%c'? ", 'X', 'O');
    scanf(" %c", &play1);

    if (play1 == 'x' || play1 == 'X') {
        play2 = 'O';
        printf("\nOK!, entao o segundo jogador sera o '%c'.\n", play2);
    } else {
        play2 = 'X';
        printf("\nOK!, entao o segundo jogador sera o '%c'.\n", play2);
    }

    while (resultado == '0') {
        printf("\nOk, fale em que posicao voce quer colocar o '%c': ", play1);
        scanf("%d", &posplay1);
        jogada(&pos1, &pos2, &pos3, &pos4, &pos5, &pos6, &pos7, &pos8, &pos9, posplay1, play1);
        mostrarjogo(pos1, pos2, pos3, pos4, pos5, pos6, pos7, pos8, pos9);
        resultado = testedevitoria(pos1, pos2, pos3, pos4, pos5, pos6, pos7, pos8, pos9);

        if (resultado != '0') {
            break;  // Player 1 ganhou ou empatou
        }

        printf("\nAgora e a vez do jogador 2: qual posicao voce quer o '%c'? ", play2);
        scanf("%d", &posplay2);
        jogada(&pos1, &pos2, &pos3, &pos4, &pos5, &pos6, &pos7, &pos8, &pos9, posplay2, play2);
        mostrarjogo(pos1, pos2, pos3, pos4, pos5, pos6, pos7, pos8, pos9);
        resultado = testedevitoria(pos1, pos2, pos3, pos4, pos5, pos6, pos7, pos8, pos9);
    }

    if (resultado == '1') {
        printf("\nParabens, voce ganhou!\n");
    } else {
        printf("\nEmpate!\n");
    }

    return 0;
}

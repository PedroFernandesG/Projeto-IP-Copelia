#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define SERVER_ADDRESS "127.0.0.1"
#define SERVER_PORT 8888
#define OPEN 1
#define CLOSE 0

void delay(int delayTime) {
    usleep(delayTime * 1000);
}

void initSocket(int* sock, char* buffer) {

    struct sockaddr_in serv_addr;

    // Create a socket
    if ((*sock = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        printf("\n Socket creation error \n");
        exit(1);
    }

    // Set the server address and port
    memset(&serv_addr, '0', sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(SERVER_PORT);

    // Convert IPv4 and IPv6 addresses from text to binary form
    if (inet_pton(AF_INET, SERVER_ADDRESS, &serv_addr.sin_addr) <= 0) {
        printf("\n Invalid address/ Address not supported \n");
        exit(1);
    }

    // Connect to the server
    if (connect(*sock, (struct sockaddr*)&serv_addr, sizeof(serv_addr)) < 0) {
        printf("\n Connection Failed \n");
        exit(1);
    }
}

void movJoints(int sock, char* buffer, float j1, float j2, float j3, float j4, float j5, float j6, int state) {
    sprintf(buffer, "%f,%f,%f,%f,%f,%f,%d", j1, j2, j3, j4, j5, j6, state);
    send(sock, buffer, strlen(buffer), 0);
    int valread = read(sock, buffer, 2048);
    printf("Result: %s\n", buffer);
}
void pickPiece(int sock, char buffer[2048], float coordenadasPeca[6], float coordenadasSubir[6]) {

    movJoints(sock, buffer, coordenadasSubir[0], coordenadasSubir[1], coordenadasSubir[2], coordenadasSubir[3], coordenadasSubir[4], coordenadasSubir[5], OPEN);

    delay(2000);

    movJoints(sock, buffer, coordenadasPeca[0], coordenadasPeca[1], coordenadasPeca[2], coordenadasPeca[3], coordenadasPeca[4], coordenadasPeca[5], CLOSE);

    delay(2000);

    movJoints(sock, buffer, coordenadasSubir[0], coordenadasSubir[1], coordenadasSubir[2], coordenadasSubir[3], coordenadasSubir[4], coordenadasSubir[5], CLOSE);
}

void movTo00(float coordenadasPeca[6], int sock, char buffer[2048]) {

    movJoints(sock, buffer, coordenadasPeca[0], coordenadasPeca[1], coordenadasPeca[2], coordenadasPeca[3], coordenadasPeca[4], coordenadasPeca[5], OPEN);

}
void movTo01(float coordenadasPeca[6], int sock, char buffer[2048]) {

    movJoints(sock, buffer, coordenadasPeca[0], coordenadasPeca[1], coordenadasPeca[2], coordenadasPeca[3], coordenadasPeca[4], coordenadasPeca[5], OPEN);

}
void movTo02(float coordenadasPeca[6], int sock, char buffer[2048]) {

    movJoints(sock, buffer, coordenadasPeca[0], coordenadasPeca[1], coordenadasPeca[2], coordenadasPeca[3], coordenadasPeca[4], coordenadasPeca[5], OPEN);

}
void movTo10(float coordenadasPeca[6], int sock, char buffer[2048]) {

    movJoints(sock, buffer, coordenadasPeca[0], coordenadasPeca[1], coordenadasPeca[2], coordenadasPeca[3], coordenadasPeca[4], coordenadasPeca[5], OPEN);

}
void movTo11(float coordenadasPeca[6], int sock, char buffer[2048]) {

    movJoints(sock, buffer, coordenadasPeca[0], coordenadasPeca[1], coordenadasPeca[2], coordenadasPeca[3], coordenadasPeca[4], coordenadasPeca[5], OPEN);

}
void movTo12(float coordenadasPeca[6], int sock, char buffer[2048]) {

    movJoints(sock, buffer, coordenadasPeca[0], coordenadasPeca[1], coordenadasPeca[2], coordenadasPeca[3], coordenadasPeca[4], coordenadasPeca[5], OPEN);

}
void movTo20(float coordenadasPeca[6], int sock, char buffer[2048]) {

    movJoints(sock, buffer, coordenadasPeca[0], coordenadasPeca[1], coordenadasPeca[2], coordenadasPeca[3], coordenadasPeca[4], coordenadasPeca[5], OPEN);

}
void movTo21(float coordenadasPeca[6], int sock, char buffer[2048]) {

    movJoints(sock, buffer, coordenadasPeca[0], coordenadasPeca[1], coordenadasPeca[2], coordenadasPeca[3], coordenadasPeca[4], coordenadasPeca[5], OPEN);

}
void movTo22(float coordenadasPeca[6], int sock, char buffer[2048]) {

    movJoints(sock, buffer, coordenadasPeca[0], coordenadasPeca[1], coordenadasPeca[2], coordenadasPeca[3], coordenadasPeca[4], coordenadasPeca[5], OPEN);

}
void BackToHome(float coordenadasPeca[6], int sock, char buffer[2048]) {

    movJoints(sock, buffer, coordenadasPeca[0], coordenadasPeca[1], coordenadasPeca[2], coordenadasPeca[3], coordenadasPeca[4], coordenadasPeca[5], OPEN);

}

//Conversão das entradas da forma X:(A,B)
void convertInput(char entrada[7], int* linha, int* coluna, char* marca) {

    (*marca) = entrada[0];
    (*linha) = entrada[3] - '0';
    (*coluna) = entrada[5] - '0';
}

void imprimir_tabuleiro(char tabuleiro[3][3]) {

    //Mostrar tabuleiro para fins de visualização
    printf("\n");
    for (int i = 0; i < 3; i++) {
        printf(" %c | %c | %c \n", tabuleiro[i][0], tabuleiro[i][1], tabuleiro[i][2]);
        if (i < 2)
            printf("-----------\n");
    }
    printf("\n");
}

char verificar_vencedor(char tabuleiro[3][3]) {

    for (int i = 0; i < 3; i++) {
        //Faz uma verificação em todas as linhas verticais e horizontais para verificar
        //se existe um vencedor, ou seja uma linha com apenas uma marca

        if (tabuleiro[i][0] == tabuleiro[i][1] && tabuleiro[i][1] == tabuleiro[i][2])
            return tabuleiro[i][0];
        if (tabuleiro[0][i] == tabuleiro[1][i] && tabuleiro[1][i] == tabuleiro[2][i])
            return tabuleiro[0][i];
    }

    //Aqui faz a verificação da diagonal principal e secundaria da matriz
    if (tabuleiro[0][0] == tabuleiro[1][1] && tabuleiro[1][1] == tabuleiro[2][2])
        return tabuleiro[0][0];
    if (tabuleiro[0][2] == tabuleiro[1][1] && tabuleiro[1][1] == tabuleiro[2][0])
        return tabuleiro[0][2];

    //No final da verificação se houver um vencedor,ele retorna a marca

    return ' ';
}

int tabuleiro_cheio(char tabuleiro[3][3]) {

    //Processo para verificar se o tabuleiro ja esta cheio
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (tabuleiro[i][j] == ' ')
                return 0;
        }
    }
    return 1;
}

/*
A função cria_fork tem o objetivo de dizer se uma determinada jogada resultara em uma situação de fork para o jogador
que a está fazendo.Um fork é uma estratégia em jogos onde um jogador cria duas ou mais oportunidades de ganhar em sua próxima jogada,
o que coloca o oponente em uma situação difícil, pois ele não pode bloquear todas essas possíveis vitórias*/
int cria_fork(char tabuleiro[3][3], int linha, int coluna, char marca) {

    //primeiro ele começa invertendo a marca, para simular jogadas do adversario
    char jogador = (marca == 'X') ? 'O' : 'X';

    //Coloca a marca do robo no tabuleiro
    tabuleiro[linha][coluna] = marca;

    int count = 0;
    //Percorre um loop e verifica quais jogadas dão duas ou mais possibilidades do adversario vencer
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (tabuleiro[i][j] == ' ') {
                tabuleiro[i][j] = jogador;
                if (verificar_vencedor(tabuleiro) == jogador)
                    count++;
                tabuleiro[i][j] = ' ';
            }
        }
    }

    tabuleiro[linha][coluna] = ' ';

    return count > 1;
}

//Aqui é onde o robo(computador) ira decidir suas jogadas
void jogada_do_computador(char tabuleiro[3][3], char marca, int sock,char buffer[2048]) {

    //int sock;
    //char buffer;
    float coordenadasHome[6] = { 0.00,0.50,-1.25,0.00,0.00,0.00 };
    float coordenadasPeca[6] = { -1.56,-0.50,-0.77,-0.01,0.14,0.01 };
    float coordenadasSubir[6] = { -1.58,-0.35,-0.79,-0.05,0.03,0.12 };
    float coordenadasTab00[6] = { -0.25,-0.63,-0.50,-0.06,-0.42,-0.17 };
    float coordenadasTab01[6] = { -0.04,-0.61,-0.50,-0.09,-0.42,-0.08 };
    float coordenadasTab02[6] = {0.21,-0.59,-0.44,-0.14,-0.45,-0.10};
    float coordenadasTab10[6] = { -0.22,-0.81,-0.11,-0.02,-0.61,-0.16 };
    float coordenadasTab11[6] = { -0.04,-0.81,-0.11,-0.02,-0.61,-0.16 };
    float coordenadasTab12[6] = { 0.17,-0.81,-0.11,-0.02,-0.61,-0.16 };
    float coordenadasTab20[6] = { -0.20,-1.03,0.31,-0.01,-0.82,-0.13 };
    float coordenadasTab21[6] = { -0.02,-1.03,0.31,-0.01,-0.82,-0.13 };
    float coordenadasTab22[6] = {0.12,-0.99,0.25,0.04,-0.71,-0.61};
    //Primeiro ele faz a verificação se ele pode ganhar o jogo, se sim realiza a jogada
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (tabuleiro[i][j] == ' ') {
                tabuleiro[i][j] = marca;
                if (verificar_vencedor(tabuleiro) == marca) {
                    pickPiece(sock, buffer, coordenadasPeca, coordenadasSubir);
                    delay(1000);
                    if (i == 0 && j == 0)
                        movTo00(coordenadasTab00, sock, buffer);
                    else if (i == 0 && j == 1)
                        movTo01(coordenadasTab01, sock, buffer);
                    else if (i == 0 && j == 2)
                        movTo02(coordenadasTab02, sock, buffer);
                    else if (i == 1 && j == 0)
                        movTo10(coordenadasTab10, sock, buffer);
                    else if (i == 1 && j == 1)
                        movTo11(coordenadasTab11, sock, buffer);
                    else if (i == 1 && j == 2)
                        movTo12(coordenadasTab12, sock, buffer);
                    else if (i == 2 && j == 0)
                        movTo20(coordenadasTab20, sock, buffer);
                    else if (i == 2 && j == 1)
                        movTo21(coordenadasTab21, sock, buffer);
                    else if (i == 2 && j == 2)
                        movTo22(coordenadasTab22, sock, buffer);

                    delay(1000);
                    BackToHome(coordenadasHome, sock, buffer);
                    return;
                }
                tabuleiro[i][j] = ' ';
            }
        }
    }

    //Aqui ele verifica se o oponente pode ganhar o jogo e então ele bloqueia a jogada
    char jogador = (marca == 'X') ? 'O' : 'X';
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (tabuleiro[i][j] == ' ') {
                tabuleiro[i][j] = jogador;
                if (verificar_vencedor(tabuleiro) == jogador) {
                    tabuleiro[i][j] = marca;
                    pickPiece(sock, buffer, coordenadasPeca, coordenadasSubir);
                    delay(1000);
                    if (i == 0 && j == 0)
                        movTo00(coordenadasTab00, sock, buffer);
                    else if (i == 0 && j == 1)
                        movTo01(coordenadasTab01, sock, buffer);
                    else if (i == 0 && j == 2)
                        movTo02(coordenadasTab02, sock, buffer);
                    else if (i == 1 && j == 0)
                        movTo10(coordenadasTab10, sock, buffer);
                    else if (i == 1 && j == 1)
                        movTo11(coordenadasTab11, sock, buffer);
                    else if (i == 1 && j == 2)
                        movTo12(coordenadasTab12, sock, buffer);
                    else if (i == 2 && j == 0)
                        movTo20(coordenadasTab20, sock, buffer);
                    else if (i == 2 && j == 1)
                        movTo21(coordenadasTab21, sock, buffer);
                    else if (i == 2 && j == 2)
                        movTo22(coordenadasTab22, sock, buffer);

                    delay(1000);
                    BackToHome(coordenadasHome, sock, buffer);
                    return;
                    return;
                }
                tabuleiro[i][j] = ' ';
            }
        }
    }

    //caso não de para ganhar, ou bloquear, ele tentara criar a situação de fork
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (tabuleiro[i][j] == ' ' && cria_fork(tabuleiro, i, j, marca)) {
                tabuleiro[i][j] = marca;
                printf("O computador jogou na posição (%d, %d).\n", i, j);
                pickPiece(sock, buffer, coordenadasPeca, coordenadasSubir);
                delay(1000);
                if (i == 0 && j == 0)
                    movTo00(coordenadasTab00, sock, buffer);
                else if (i == 0 && j == 1)
                    movTo01(coordenadasTab01, sock, buffer);
                else if (i == 0 && j == 2)
                    movTo02(coordenadasTab02, sock, buffer);
                else if (i == 1 && j == 0)
                    movTo10(coordenadasTab10, sock, buffer);
                else if (i == 1 && j == 1)
                    movTo11(coordenadasTab11, sock, buffer);
                else if (i == 1 && j == 2)
                    movTo12(coordenadasTab12, sock, buffer);
                else if (i == 2 && j == 0)
                    movTo20(coordenadasTab20, sock, buffer);
                else if (i == 2 && j == 1)
                    movTo21(coordenadasTab21, sock, buffer);
                else if (i == 2 && j == 2)
                    movTo22(coordenadasTab22, sock, buffer);

                delay(1000);
                BackToHome(coordenadasHome, sock, buffer);
                return;
                return;
            }
        }
    }

    //Caso contrario ele jogara em alguma posição ainda não ocupada
    int linha, coluna;
    do {
        linha = rand() % 3;
        coluna = rand() % 3;
    } while (tabuleiro[linha][coluna] != ' ');

    tabuleiro[linha][coluna] = marca;
    printf("O computador jogou na posição (%d, %d).\n", linha, coluna);
    pickPiece(sock, buffer, coordenadasPeca, coordenadasSubir);
    delay(1000);
    if (linha == 0 && coluna == 0)
        movTo00(coordenadasTab00, sock, buffer);
    else if (linha== 0 && coluna== 1)
        movTo01(coordenadasTab01, sock, buffer);
    else if (linha== 0 && coluna== 2)
        movTo02(coordenadasTab02, sock, buffer);
    else if (linha== 1 && coluna== 0)
        movTo10(coordenadasTab10, sock, buffer);
    else if (linha== 1 && coluna== 1)
        movTo11(coordenadasTab11, sock, buffer);
    else if (linha== 1 && coluna== 2)
        movTo12(coordenadasTab12, sock, buffer);
    else if (linha== 2 && coluna== 0)
        movTo20(coordenadasTab20, sock, buffer);
    else if (linha== 2 && coluna== 1)
        movTo21(coordenadasTab21, sock, buffer);
    else if (linha== 2 && coluna == 2)
        movTo22(coordenadasTab22, sock, buffer);

    delay(1000);
    BackToHome(coordenadasHome, sock, buffer);
    return;
}

int main() {

    

    //variaveis para conexcao com o robo NAO MEXER
    int sock = 0;
    char buffer[2048] = { 0 };

    //conexao com o robo NAO MEXER
    initSocket(&sock, buffer);

    char tabuleiro[3][3] = {
        {' ', ' ', ' '},
        {' ', ' ', ' '},
        {' ', ' ', ' '}
    };

    srand(time(NULL));

    int vez_do_jogador;
    printf("Digite 1 se for começar, caso contrario digite 0\n");
    scanf("%d", &vez_do_jogador);
    char vencedor = ' ';

    printf("Bem-vindo ao Jogo da Velha!\n");

    char entrada[7];
    do {
        imprimir_tabuleiro(tabuleiro);

        if (vez_do_jogador) {
            if(verificar_vencedor(tabuleiro) == 'X' || verificar_vencedor(tabuleiro) == '0'){
                printf("Partida encerrada, vencedor -> %c", entrada[0]);
                break;
            }
            int linha, coluna;
            printf("Sua vez! Digite sua entrada no formato Y:(A,B): ");
            scanf("%s", entrada);
            char marca;
            convertInput(entrada, &linha, &coluna, &marca);

            if (linha < 0 || linha > 2 || coluna < 0 || coluna > 2 || tabuleiro[linha][coluna] != ' ') {
                printf("Posição inválida! Tente novamente.\n");
                continue;
            }

            tabuleiro[linha][coluna] = marca;
        }
        else {
             if(verificar_vencedor(tabuleiro) == 'X' || verificar_vencedor(tabuleiro) == '0'){
                printf("Partida encerrada, vencedor -> %c", entrada[0]);
                break;
            }
            printf("Vez do computador...\n");
            if (entrada[0] == 'O')
                jogada_do_computador(tabuleiro, 'X',sock,buffer);
            else
                jogada_do_computador(tabuleiro, 'O',sock,buffer);
        }

        vez_do_jogador = !vez_do_jogador;
        vencedor = verificar_vencedor(tabuleiro);

    } while (vencedor == ' ' && !tabuleiro_cheio(tabuleiro));

    imprimir_tabuleiro(tabuleiro);

    if (vencedor == 'X')
        printf("Parabéns! Você venceu!\n");
    else if (vencedor == 'O')
        printf("O robo venceu!\n");
    else
        printf("Empate!\n");

    close(sock);

    return 0;
}

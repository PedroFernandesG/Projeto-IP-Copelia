//Definição da constante PI
#define PI 3.14159265359

//Importação das bibliotecas
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

extern "C" {
#include "extApi.h"
}

//Funções utilizadas para selecionar as teclas com suas respectivas posições
void buttonNumber1(int* robotJoints, int clientID){
    //Definindo e depois percorrendo as alterações angulares das tres primeiras juntas
    float positionsJoints[6] = { (simxFloat)0.14, (simxFloat)-0.51, (simxFloat)-0.115 * PI };
    for (int i = 0; i < 3;i++) {
        simxSetJointTargetPosition(clientID, robotJoints[i], positionsJoints[i], (simxInt)simx_opmode_oneshot_wait);
        extApi_sleepMs(500);
    }
    extApi_sleepMs(1500);
}
void buttonNumber2(int* robotJoints, int clientID){
    //Definindo e depois percorrendo as alterações angulares das tres primeiras juntas
    float positionsJoints[6] = { (simxFloat)0.05,(simxFloat)-0.5,(simxFloat)-0.115 * PI };
    for (int i = 0; i < 3;i++) {
        simxSetJointTargetPosition(clientID, robotJoints[i], positionsJoints[i], (simxInt)simx_opmode_oneshot_wait);
        extApi_sleepMs(500);
    }
    extApi_sleepMs(1500);
}
void buttonNumber3(int* robotJoints, int clientID){
    //Definindo e depois percorrendo as alterações angulares das tres primeiras juntas
    float positionsJoints[6] = { (simxFloat)-0.02,(simxFloat)-0.5,(simxFloat)-0.115 * PI };
    for (int i = 0; i < 3;i++) {
        simxSetJointTargetPosition(clientID, robotJoints[i], positionsJoints[i], (simxInt)simx_opmode_oneshot_wait);
        extApi_sleepMs(500);
    }
    extApi_sleepMs(1500);
}
void buttonNumber4(int* robotJoints, int clientID){
    //Definindo e depois percorrendo as alterações angulares das tres primeiras juntas
    float positionsJoints[6] = { (simxFloat)0.1,(simxFloat)-0.50,(simxFloat)-0.143 * PI };
    for (int i = 0; i < 3;i++) {
        simxSetJointTargetPosition(clientID, robotJoints[i], positionsJoints[i], (simxInt)simx_opmode_oneshot_wait);
        extApi_sleepMs(500);
    }
    extApi_sleepMs(1500);
}
void buttonNumber5(int* robotJoints, int clientID){
    //Definindo e depois percorrendo as alterações angulares das tres primeiras juntas
    float positionsJoints[6] = { (simxFloat)0.05,(simxFloat)-0.50,(simxFloat)-0.143 * PI };
    for (int i = 0; i < 3;i++) {
        simxSetJointTargetPosition(clientID, robotJoints[i], positionsJoints[i], (simxInt)simx_opmode_oneshot_wait);
        extApi_sleepMs(500);
    }
    extApi_sleepMs(1500);
}
void buttonNumber6(int* robotJoints, int clientID){
    //Definindo e depois percorrendo as alterações angulares das tres primeiras juntas
    float positionsJoints[6] = { (simxFloat)-0.05,(simxFloat)-0.50,(simxFloat)-0.143 * PI };
    for (int i = 0; i < 3;i++) {
        simxSetJointTargetPosition(clientID, robotJoints[i], positionsJoints[i], (simxInt)simx_opmode_oneshot_wait);
        extApi_sleepMs(500);
    }
    extApi_sleepMs(1500);
}

void buttonNumber7(int* robotJoints, int clientID){
    //Definindo e depois percorrendo as alterações angulares das tres primeiras juntas
    float positionsJoints[6] = { (simxFloat)0.12,(simxFloat)-0.50,(simxFloat)-0.16 * PI };
    for (int i = 0; i < 3;i++) {
        simxSetJointTargetPosition(clientID, robotJoints[i], positionsJoints[i], (simxInt)simx_opmode_oneshot_wait);
        extApi_sleepMs(500);
    }
    extApi_sleepMs(1500);
}

void buttonNumber8(int* robotJoints, int clientID){
    //Definindo e depois percorrendo as alterações angulares das tres primeiras juntas
    float positionsJoints[6] = { (simxFloat)0.05,(simxFloat)-0.50,(simxFloat)-0.16 * PI };
    for (int i = 0; i < 3;i++) {
        simxSetJointTargetPosition(clientID, robotJoints[i], positionsJoints[i], (simxInt)simx_opmode_oneshot_wait);
        extApi_sleepMs(500);
    }
    extApi_sleepMs(1500);
}

void buttonNumber9(int* robotJoints, int clientID){
    //Definindo e depois percorrendo as alterações angulares das tres primeiras juntas
    float positionsJoints[6] = { (simxFloat)-0.05,(simxFloat)-0.50,(simxFloat)-0.16 * PI };
    for (int i = 0; i < 3;i++) {
        simxSetJointTargetPosition(clientID, robotJoints[i], positionsJoints[i], (simxInt)simx_opmode_oneshot_wait);
        extApi_sleepMs(500);
    }
    extApi_sleepMs(1500);
}

void buttonNumber0(int* robotJoints, int clientID){
    //Definindo e depois percorrendo as alterações angulares das tres primeiras juntas
    float positionsJoints[6] = { (simxFloat)0.01 * PI,(simxFloat)-0.165 * PI,(simxFloat)-0.180 * PI };
    for (int i = 0; i < 3;i++) {
        simxSetJointTargetPosition(clientID, robotJoints[i], positionsJoints[i], (simxInt)simx_opmode_oneshot_wait);
        extApi_sleepMs(500);
    }
    extApi_sleepMs(1500);
}

void buttonNumberConfirm(int* robotJoints, int clientID){
    //Definindo e depois percorrendo as alterações angulares das tres primeiras juntas
    float positionsJoints[6] = { (simxFloat)-0.03 * PI,(simxFloat)-0.170 * PI,(simxFloat)-0.190 * PI };
    for (int i = 0; i < 3;i++) {
        simxSetJointTargetPosition(clientID, robotJoints[i], positionsJoints[i], (simxInt)simx_opmode_oneshot_wait);
        extApi_sleepMs(500);
    }
    extApi_sleepMs(1500);
}
void defaultPosition(int* robotJoints, int clientID){
    //Definindo e depois percorrendo as alterações angulares das tres primeiras juntas
    float positionsJoints[6] = { (simxFloat)0, (simxFloat)0, (simxFloat)-PI / 5 };
    simxSetJointTargetPosition(clientID, robotJoints[1], (simxFloat)0, simx_opmode_oneshot_wait);
    extApi_sleepMs(500);
    for (int i = 2; i >= 0;i--) {
        simxSetJointTargetPosition(clientID, robotJoints[i], positionsJoints[i], (simxInt)simx_opmode_oneshot_wait);
        extApi_sleepMs(500);
    }
    extApi_sleepMs(1500);
}

void InitialPosition(int* robotJoints, int clientID){
    //Definindo e depois percorrendo as alterações angulares das tres primeiras juntas
    float positionsJoints[6] = { (simxFloat)0 * PI,(simxFloat)0 * PI,(simxFloat)0 * PI };
    for (int i = 0; i < 3;i++) {
        simxSetJointTargetPosition(clientID, robotJoints[i], positionsJoints[i], (simxInt)simx_opmode_oneshot_wait);
        extApi_sleepMs(500);
    }
    extApi_sleepMs(1500);
}
int main(int argc, char* argv[])
{
    // Conectar-se ao CoppeliaSim
    int clientID = simxStart((simxChar*)"127.0.0.1", 19999, true, true, 2000, 5);
    extApi_sleepMs(500);

    //Verificar a conexão com o simulador
    if (clientID == -1) {
        printf("Erro conectando ao Coppelia!\n");
        return 0;
    }
    else {
        printf("Conectado ao Coppelia!\n");
    }

    //Colocando as juntas do robo em um vetor
    int robotJoints[6];
    for (int k = 0;k < 6;k++) {
        char jointName[70];
        sprintf(jointName, "/base_link_respondable[0]/joint_%d", k + 1);
        simxGetObjectHandle(clientID, jointName, &robotJoints[k], simx_opmode_oneshot_wait);
    }
    extApi_sleepMs(800);


    //Abrindo um arquivo com os votos
    FILE* arquivo = NULL;
    arquivo = fopen("votos.txt", "r");
    //verificação de erro no arquivo
    if (arquivo == NULL) {
        printf("Erro na leitura de dados");
        exit(1);
    }

    char linhaArquivo[100];
    int indexRow = 0;
    //Loop que percorre cada linha arquivo e digita os votos na urna
    while (fgets(linhaArquivo, 100, arquivo) != NULL){

        //Pressiona cada digito com base nos numeros de cada linha
        for (indexRow = 0;indexRow < strlen(linhaArquivo);indexRow++) {

            defaultPosition(robotJoints, clientID);
            extApi_sleepMs(6000);
            if (linhaArquivo[indexRow] == '0') {
                buttonNumber0(robotJoints, clientID);
                defaultPosition(robotJoints, clientID);
            }
            else if (linhaArquivo[indexRow] == '1') {
                buttonNumber1(robotJoints, clientID);
                defaultPosition(robotJoints, clientID);
            }
            else if (linhaArquivo[indexRow] == '2') {
                buttonNumber2(robotJoints, clientID);
                defaultPosition(robotJoints, clientID);
            }
            else if (linhaArquivo[indexRow] == '3') {
                buttonNumber3(robotJoints, clientID);
                defaultPosition(robotJoints, clientID);
            }
            else if (linhaArquivo[indexRow] == '4') {
                buttonNumber4(robotJoints, clientID);
                defaultPosition(robotJoints, clientID);
            }
            else if (linhaArquivo[indexRow] == '5') {
                buttonNumber5(robotJoints, clientID);
                defaultPosition(robotJoints, clientID);
            }
            else if (linhaArquivo[indexRow] == '6') {
                buttonNumber6(robotJoints, clientID);
                defaultPosition(robotJoints, clientID);
            }
            else if (linhaArquivo[indexRow] == '7') {
                buttonNumber7(robotJoints, clientID);
                defaultPosition(robotJoints, clientID);
            }
            else if (linhaArquivo[indexRow] == '8') {
                buttonNumber8(robotJoints, clientID);
                defaultPosition(robotJoints, clientID);
            }
            else if (linhaArquivo[indexRow] == '9') {
                buttonNumber9(robotJoints, clientID);
                defaultPosition(robotJoints, clientID);
            }

        }
        //Confirma depois do fim da linha
        buttonNumberConfirm(robotJoints, clientID);
        defaultPosition(robotJoints, clientID);
    }

    //Volta para a posição inicial
    InitialPosition(robotJoints, clientID);

    //Fecha o arquivo
    fclose(arquivo);

    // Fechar a conexão
    simxFinish(clientID);

    return 0;
}

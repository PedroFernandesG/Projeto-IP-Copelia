//Definição da constante PI
#define PI 3.14159265359

//Importação das bibliotecas
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

extern "C" {
#include "extApi.h"
}

//Funções utilizadas para selecionar as teclas
void buttonNumber5(int* robotJoints, int clientID) {
    float positionsJoints[6] = {(simxFloat)0.05,(simxFloat)-0.50,(simxFloat)-0.143 * PI };
    for (int i = 0; i < 3;i++) {
        simxSetJointTargetPosition(clientID, robotJoints[i], positionsJoints[i], (simxInt)simx_opmode_oneshot_wait);
        extApi_sleepMs(500);
    }
    extApi_sleepMs(2000);
}
void buttonNumber4(int* robotJoints, int clientID) {
    float positionsJoints[6] = { (simxFloat)0.1,(simxFloat)-0.50,(simxFloat)-0.143 * PI };
    for (int i = 0; i < 3;i++) {
        simxSetJointTargetPosition(clientID, robotJoints[i], positionsJoints[i], (simxInt)simx_opmode_oneshot_wait);
        extApi_sleepMs(500);
    }
    extApi_sleepMs(2000);
}
void buttonNumber6(int* robotJoints, int clientID) {
    float positionsJoints[6] = { (simxFloat)-0.05,(simxFloat)-0.50,(simxFloat)-0.143 * PI };
    for (int i = 0; i < 3;i++) {
        simxSetJointTargetPosition(clientID, robotJoints[i], positionsJoints[i], (simxInt)simx_opmode_oneshot_wait);
        extApi_sleepMs(500);
    }
    extApi_sleepMs(2000);
}

void buttonNumber0(int *robotJoints,int clientID){
    float positionsJoints[6] = {(simxFloat) 0.01 * PI,(simxFloat)-0.165 * PI,(simxFloat) -0.180 * PI};
    for (int i = 0; i < 3;i++) {
        simxSetJointTargetPosition(clientID, robotJoints[i], positionsJoints[i], (simxInt)simx_opmode_oneshot_wait);
        extApi_sleepMs(500);
    }
    extApi_sleepMs(2000);
}
int main(int argc, char* argv[])
{

    /*
    FILE* arquivo = NULL;
    arquivo = fopen("arquivo.txt", "r");
    if (arquivo == NULL){
        printf("Erro na leitura de dados");
        exit(1);
    }
    */

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
    for(int k = 0;k < 6;k++){
        char jointName[70];
        sprintf(jointName, "/base_link_respondable[0]/joint_%d", k + 1);
        simxGetObjectHandle(clientID, jointName, &robotJoints[k], simx_opmode_oneshot_wait);
    }

    //Utilizado para simular a função da posição padrão do robo ou de recuo enquanto ela não esta pronta,depois sera apagado
    int handler = 0;
    simxChar handlerName[150] = "/base_link_respondable[0]/joint_3";
    simxGetObjectHandle(clientID, handlerName, &handler, (simxInt)simx_opmode_oneshot_wait);
    simxSetJointTargetPosition(clientID, handler, (simxFloat)-0.177 * PI, (simxInt)simx_opmode_oneshot_wait);
    extApi_sleepMs(7000);

    buttonNumber6(robotJoints, clientID);
    extApi_sleepMs(800);

    // Fechar a conexão
    simxFinish(clientID);

    return 0;
}

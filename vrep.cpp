//Definição da constante PI pois a movimentação dos itens é definida em radianos
#define PI 3.14159265359
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

extern "C" {
#include "extApi.h"
}

//Função que para o botão 0
void buttonNumber0(int *robotJoints,int clientID){
    float positionsJoints[6] = {(simxFloat) 0.01 * PI,(simxFloat)-0.166 * PI,(simxFloat)0};
    for (int i = 0; i < 2;i++) {
        simxSetJointTargetPosition(clientID, robotJoints[i], positionsJoints[i], (simxInt)simx_opmode_oneshot_wait);
        extApi_sleepMs(500);
    }
    extApi_sleepMs(2000);
}

//Função principal
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

    //Aguardar um breve período
    extApi_sleepMs(500);

    //Verificar a conexão com o simulador
    if (clientID == -1) {
        printf("Erro conectando ao Coppelia!\n");
        return 0;
    }
    else {
        printf("Conectado ao Coppelia!\n");
    }

    int robotJoints[6];
    for(int k = 0;k < 6;k++){
        char jointName[70];
        sprintf(jointName, "/base_link_respondable[0]/joint_%d", k + 1);
        simxGetObjectHandle(clientID, jointName, &robotJoints[k], simx_opmode_oneshot_wait);
    }

    //Esta parte depois sera excluida, quando a função da posição de recúo do robo estiver pronta
    //Aplicamos ela primeiro, inves de usar esse handler
    int handler = 0;
    simxChar handlerName[150] = "/base_link_respondable[0]/joint_3";
    simxGetObjectHandle(clientID, handlerName, &handler, (simxInt)simx_opmode_oneshot_wait);
    simxSetJointTargetPosition(clientID, handler, (simxFloat)-0.178 * PI, (simxInt)simx_opmode_oneshot_wait);
    extApi_sleepMs(7000);

    buttonNumber0(robotJoints, clientID);
    extApi_sleepMs(800);

    // Fechar a conexão
    simxFinish(clientID);

    return 0;
}

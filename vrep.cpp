//Defini��o da constante PI pois a movimenta��o dos itens � definida em radianos
#define PI 3.14159265359

//Importa��o das bibliotecas
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Transformar o codigo C++ para C
extern "C" {
#include "extApi.h"
}

//Fun��o principal
int main(int argc, char* argv[])
{

    //Futuramente iremos precisar ler um arquivo 

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

    //Aguardar um breve per�odo
    extApi_sleepMs(500);

    //Verificar a conex�o com o simulador
    if (clientID == -1) {
        printf("Erro conectando ao Coppelia!\n");
        return 0;
    }
    else {
        printf("Conectado ao Coppelia!\n");
    }

    // Variavel para o identificador do robo
    int robotHandle;
    //Nome do robo
    simxChar robotName[] = "base_link_respondable";

    //Fun��o onde ClientID � a conex�o ao copelia, robotName � o nome..
    //robotHandle: endere�o do identificador do robo
    simxGetObjectHandle(clientID, robotName, &robotHandle, simx_opmode_blocking);

    // Definir as coordenadas da posi��o desejada
    simxFloat newPosition[3] = { 0.1250f, 0.0530f, 0.9480f }; // X, Y, Z

    // Definir a posi��o do rob�
    simxSetObjectPosition(clientID, robotHandle, -1, newPosition, simx_opmode_oneshot);

    // Aguardar tempo suficiente para que a mudan�a de posi��o seja processada
    extApi_sleepMs(2000); // Ajuste o tempo conforme necess�rio para o seu caso

    // Configurar o manipulador da junta
    int handler = 0;
    simxChar handlerName[150] = "/base_link_respondable[0]/joint_3";
    simxGetObjectHandle(clientID, handlerName, &handler, (simxInt)simx_opmode_oneshot_wait);

    // Mover a junta para 0.3 * PI radianos 
    simxSetJointTargetPosition(clientID, handler, (simxFloat)-0.30 * PI, (simxInt)simx_opmode_oneshot_wait);

    // Aguardar tempo suficiente para que o movimento da junta seja conclu�do
    extApi_sleepMs(2000); // Ajuste o tempo conforme necess�rio para o seu caso

    // Fechar a conex�o
    simxFinish(clientID);

    return 0;
}

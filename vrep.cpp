//Definição da constante PI pois a movimentação dos itens é definida em radianos
#define PI 3.14159265359

//Importação das bibliotecas
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Transformar o codigo C++ para C
extern "C" {
#include "extApi.h"
}

//Função principal
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

    // Variavel para o identificador do robo
    int robotHandle;
    //Nome do robo
    simxChar robotName[] = "base_link_respondable";

    //Função onde ClientID é a conexão ao copelia, robotName é o nome..
    //robotHandle: endereço do identificador do robo
    simxGetObjectHandle(clientID, robotName, &robotHandle, simx_opmode_blocking);

    // Definir as coordenadas da posição desejada
    simxFloat newPosition[3] = { 0.1250f, 0.0530f, 0.9480f }; // X, Y, Z

    // Definir a posição do robô
    simxSetObjectPosition(clientID, robotHandle, -1, newPosition, simx_opmode_oneshot);

    // Aguardar tempo suficiente para que a mudança de posição seja processada
    extApi_sleepMs(2000); // Ajuste o tempo conforme necessário para o seu caso

    // Configurar o manipulador da junta
    int handler = 0;
    simxChar handlerName[150] = "/base_link_respondable[0]/joint_3";
    simxGetObjectHandle(clientID, handlerName, &handler, (simxInt)simx_opmode_oneshot_wait);

    // Mover a junta para 0.3 * PI radianos 
    simxSetJointTargetPosition(clientID, handler, (simxFloat)-0.30 * PI, (simxInt)simx_opmode_oneshot_wait);

    // Aguardar tempo suficiente para que o movimento da junta seja concluído
    extApi_sleepMs(2000); // Ajuste o tempo conforme necessário para o seu caso

    // Fechar a conexão
    simxFinish(clientID);

    return 0;
}

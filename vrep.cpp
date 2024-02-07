#define PI 3.14159265359

//Importação das bibliotecas
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Transformar o codigo C++ para C
extern "C" {
#include "extApi.h"
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

    //Vetor contendo as juntas dos robos
    int robotJoints[6];

    //Verificar a conexão com o simulador
    if (clientID == -1) {
        printf("Erro conectando ao Coppelia!\n");
        return 0;
    }
    else {
        printf("Conectado ao Coppelia!\n");
    }
    
     for(int k = 0;k < 6;k++){
         char jointName[50];
         sprintf(jointName, "base_link_responsable[0]/joint_%d", k + 1);
         simxGetObjectHandle(clientID, jointName, &robotJoints[k], simx_opmode_oneshot_wait);
     }

    extApi_sleepMs(2000);

    // Fechar a conexão
    simxFinish(clientID);

    return 0;
}

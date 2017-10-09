//
// Created by Carli on 28/09/2017.
//

#ifndef TRABALHO_I_RESTAURANTE_H
#define TRABALHO_I_RESTAURANTE_H
#include <queue>
#include <string>
#include "ChefeDeCozinha.h"

using namespace std;

class Restaurante{
private:
    int * mesa;
    queue<int> chefes;
    queue<string> * pedidos_espera;
    queue<int> mesa_espera;

    void atende_mesa_espera();

public:
    int getChefes();
    int getMesas_espera();

    Restaurante(int cf, int mesas); // construtor

    void setPedidos(int mesa, string pedido);
};

#endif //TRABALHO_I_RESTAURANTE_H
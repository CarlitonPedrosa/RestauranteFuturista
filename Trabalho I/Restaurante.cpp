//
// Created by Carli on 28/09/2017.
//

#include "Restaurante.h"

Restaurante::Restaurante(int cf, int mesas) {
    this->pedidos_espera[mesas];
    this->mesa[mesas+1];

    for(int i = 1; i <= cf; i++) {
        chefes.push(i); // seta 1 indicando os chefes disponivel
    }

    for (int j = 0; j <= mesas; j++) {
        mesa[j] = 0; // seta 0 indicando que a mesa não está sendo atendida por nennhum chefe
    }
}

void Restaurante::setPedidos(int mesa, string pedido) {
    if(this->mesa[mesa] != 0){ // verifico se a mesa já esta sendo atendida
        if(pedido == "fim" || pedido == "FIM") { // verificação é feita pelo chefe de cozinha
            chefes.push(this->mesa[mesa]); // chefe volta a ficar disponivel
            this->mesa[mesa]= 0; // mesa fica livre

            if(!mesa_espera.empty() & !chefes.empty()){ // já verifico se tem mesa em espera e chefes disponivel
                atende_mesa_espera();
            }
        }
    }else if(!chefes.empty()){ // se tiver chefe disponivel
        if(!mesa_espera.empty()){ // se tiver mesa na fila..
            atende_mesa_espera();
        } else{
            this->mesa[mesa] = chefes.front(); // se não a mesa é atendida pelo chefe disponivel

            chefes.pop();
        }
    }else{
        if(pedidos_espera[mesa].empty()){ // verifica se esta mesa já está em espera
            mesa_espera.push(mesa); // entra na fila de espera
        }
        pedidos_espera[mesa].push(pedido);
    }
}

void Restaurante::atende_mesa_espera() {
        this->mesa[mesa_espera.front()] = chefes.front();

        // manda pro chefe os pedidos

        chefes.pop();
        mesa_espera.pop();
}

int Restaurante::getChefes() {
    return chefes.size();
}

int Restaurante::getMesas_espera() {
    return mesa_espera.size();
}
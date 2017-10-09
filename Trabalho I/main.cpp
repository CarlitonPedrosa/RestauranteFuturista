#include <iostream>
#include <boost/algorithm/string.hpp>
#include <stdlib.h>
#include "Restaurante.h"

using namespace std;
using namespace boost;

int main() {

    string entrada, cf_st, mesas_st;

    int cf, mesas;

    bool fechar_programa = false;

    do{
        cout << "- Restaurante Futurista -" << endl;
        cout << "Digite o numero de Chefes de Cozinha e em seguida o numero de mesas - ou FIM para sair" << endl;

        cin >> entrada;

        getline(cin, mesas_st);

        if(entrada == "FIM" || entrada == "fim"){
            fechar_programa = true;
        }else {
            // converte string para int
            cf = atoi(entrada.c_str());
            mesas = atoi(mesas_st.c_str());

            Restaurante restaurante(cf, mesas); // crio um restaurante com um numero de chefes e mesas

            int mesa;

            string pedido;

            bool fechar_restaurante = false;

            do { // do/while só vai sair se todos os chefes estiverem desocupados

                cout << "Numero da mesa - Pedido" << endl;

                cin >> mesa; // mesa recebe o numero inserido

                getline(cin, pedido); // pedido recebe a frase junto ao primeiro espaço

                pedido.erase(0, 1); // elimina o espaço do começo da frase

                restaurante.setPedidos(mesa, pedido);

                if(restaurante.getChefes() == cf && !restaurante.getMesas_espera()) { // se todos os cf estiverem disponivel e sem
                    fechar_restaurante = true; // mesas de espera o restaurante pode ser fechado
                }

            }while(!fechar_restaurante);

        }
    }while(!fechar_programa);

    return 0;
}

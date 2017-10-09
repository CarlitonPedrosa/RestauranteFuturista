//
// Created by Carli on 12/09/2017.
//

#ifndef TRABALHO_I_CHEFEDECOZINHA_H
#define TRABALHO_I_CHEFEDECOZINHA_H

#include <string>
#include <zconf.h>
#include <iostream>

using namespace std;

class ChefeDeCozinha {
public:

    // construtor da classe
    ChefeDeCozinha(){
        pipe(fd);
        pid_t pid = fork();

        if(pid < 0) {
            cerr << "Erro";
        }else if(pid == 0) {
            // retorna o pid do processo
            pid = getpid();

            char buffer[256];

            close(fd[1]);

            while(read(fd[0], buffer, sizeof(buffer))) {
                cout << buffer << endl;
            }
        }
    }



    // construtor de copia
    ChefeDeCozinha(const ChefeDeCozinha &orig);

    // destrutor da classe, resposavel por matar o processo
    virtual ~ChefeDeCozinha(){
        kill(pid, SIGKILL);
    }

    void enviarPedido(string pedido) {
        close(fd[0]);
        write(fd[1], pedido.c_str(), pedido.size());
    }

private:
    // descritor, id que representa uma função
  int fd[2];
    // pid do processo
    pid_t pid;
};


#endif //TRABALHO_I_CHEFEDECOZINHA_H
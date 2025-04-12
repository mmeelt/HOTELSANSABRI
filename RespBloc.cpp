#include "RespBloc.h"
#include <iostream>
using namespace std;

RespBloc::RespBloc() : Utilisateur() {
    blocId = -1;
}

RespBloc::RespBloc(const char* nom, int age, int blocId)
    : Utilisateur(nom, "", age, "Responsable de bloc", "", ""), blocId(blocId) {}

void RespBloc::afficherInfos() {
    cout << "--- Responsable de Bloc ---" << endl;
    Utilisateur::afficherInfos();
    cout << "Bloc ID : " << blocId << endl;
}

int RespBloc::getBlocId() const {
    return blocId;
}

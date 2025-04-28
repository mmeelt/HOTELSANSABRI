#ifndef RESERVATION_H
#define RESERVATION_H

class Reservation {
private:
    int chambreNumero;
    int beneficiaireId;
    char date[20];

public:
    Reservation();
    Reservation(int chambre, int beneficiaire, const char* date);

    void afficherInfos();
};

#endif

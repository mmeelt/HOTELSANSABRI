#ifndef BLOC_H
#define BLOC_H

class Bloc {
private:
    int id;
    char nom[30];

public:
    Bloc();
    Bloc(int id, const char* nom);

    void afficherInfos();
    int getId() const;
};

#endif

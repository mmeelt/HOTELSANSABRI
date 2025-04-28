#ifndef FORMATION_H
#define FORMATION_H

#include <string>
#include "Personne.h"

class Formation {
private:
    std::string theme;
    Personne* formateur;

public:
    // Constructor
    Formation(const std::string& theme, Personne* formateur);

    // Getters
    std::string getTheme() const;
    Personne* getFormateur() const;

    // Setters
    void setTheme(const std::string& theme);
    void setFormateur(Personne* formateur);

    // Destructor
    ~Formation();
};

#endif // FORMATION_H
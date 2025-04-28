#ifndef ATELIER_H
#define ATELIER_H

#include <string>

class Atelier {
private:
    std::string sujet;
    std::string duree;
    int capacitee;

public:
    // Constructor
    Atelier(const std::string& sujet, const std::string& duree, int capacitee);

    // Getters
    std::string getSujet() const;
    std::string getDuree() const;
    int getCapacitee() const;

    // Setters
    void setSujet(const std::string& sujet);
    void setDuree(const std::string& duree);
    void setCapacitee(int capacitee);
};

#endif // ATELIER_H
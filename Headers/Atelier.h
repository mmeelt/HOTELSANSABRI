#ifndef ATELIER_H
#define ATELIER_H

#include "Evenement.h"
#include <memory> // For std::unique_ptr

class Atelier : public Evenement {
private:
    std::string sujet;
    std::string duree;
    int capacite;
    std::unique_ptr<TravailleurSocialEvenementiel> resp; // Use unique_ptr for ownership

public:
    // Constructeurs
    Atelier();
    Atelier(const std::string& date, const std::string& lieu, const std::string& description,
            std::unique_ptr<TravailleurSocialEvenementiel> resp, const std::string& sujet,
            const std::string& duree, int capacite);
    Atelier(const Atelier& other) = delete; // Delete copy constructor to prevent shallow copy
    Atelier(Atelier&& other) noexcept; // Move constructor

    // Destructeur
    ~Atelier();

    // Getters
    std::string getSujet() const;
    std::string getDuree() const;
    int getCapacite() const;
    const TravailleurSocialEvenementiel* getResp() const; // Provide access to resp
    unique_ptr<TravailleurSocialEvenementiel>& getResponsableNonConst() {
        return resp;
    }
    
    const unique_ptr<TravailleurSocialEvenementiel>& getResponsable() const {
        return resp;
    }
    // Setters
    void setSujet(const std::string& sujet);
    void setDuree(const std::string& duree);
    void setCapacite(int capacite);
    void setResp(std::unique_ptr<TravailleurSocialEvenementiel> resp); // Setter for resp

    // Méthodes
    void afficherInfo() const;

    void ajouterParticipant(unique_ptr<SansAbri> participant); // Ajouter un participant à la formation

    RespEvenementiel getResponsableRespEvenementiel() const; // Getter for resp
    // Surcharges
    friend std::ostream& operator<<(std::ostream& out, const Atelier& a);
    friend std::istream& operator>>(std::istream& in, Atelier& a);
    bool operator==(const Atelier& other) const;
    bool Atelier::operator!=(const Atelier& other) const {
        return !(*this == other);
    }
};

#endif

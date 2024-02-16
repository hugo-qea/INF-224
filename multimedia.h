#ifndef MULTIMEDIA_H
#define MULTIMEDIA_H
#include <string>
#include <iostream>

/**
 * @class Multimedia
 * @brief Classe de base pour les objets multimédia
 * 
 * Cette classe contient les informations de base pour tous les objets multimédia, comme le nom et le chemin.
 */
class Multimedia
{
protected:
    /** @brief Nom de l'objet multimédia */
    std::string name{};
    /** @brief Chemin de l'objet multimédia */
    std::string path{};
public:
    /**
     * @brief Constructeur prenant en paramètre le nom et le chemin de l'objet multimédia
     * @param [in] _name - Nom de l'objet multimédia
     * @param [in] _path - Chemin de l'objet multimédia
     */
    Multimedia(std::string _name, std::string _path);
    /**
     * @brief Constructeur par défaut
     */
    Multimedia();
    /**
     * @brief Modifieur pour le nom de l'objet multimédia
     * @param [in] _name - Nouveau nom de l'objet multimédia
     */
    void setName(std::string _name);
    /**
     * @brief Modifieur pour le chemin de l'objet multimédia
     * @param [in] _path - Nouveau chemin de l'objet multimédia
     */
    void setPath(std::string _path);
        /**
    * @brief Destructeur de la classe Multimedia
    */
    virtual ~Multimedia();

    /**
    * @brief Accesseur pour récupérer le nom de l'objet Multimedia
    * @return Le nom de l'objet
    */
    std::string getName() const;

    /**
    * @brief Accesseur pour récupérer le chemin de l'objet Multimedia
    * @return Le chemin de l'objet
    */
    std::string getPath() const;

    /**
    * @brief Méthode pour afficher les informations de l'objet Multimedia
    * @param [in] out Le flux de sortie où afficher les informations
    */
    virtual void display(std::ostream & out) const;

    /**
    * @brief Méthode purement virtuelle pour lancer la lecture de l'objet Multimedia
    */
    virtual void play() const = 0;


};

#endif // MULTIMEDIA_H

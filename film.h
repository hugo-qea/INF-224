#ifndef FILM_H
#define FILM_H

#include "video.h"

/**
 * @class Film
 * @brief Classe dérivée de la classe Video pour représenter un film.
 * 
 * Cette classe contient des informations supplémentaires spécifiques à un film, telles que les durées des chapitres.
 */
class Film : public Video {
private:
    /**
     * @brief Tableau de durées des chapitres.
     */
    int* chaptersDuration;
    /**
     * @brief Nombre de chapitres.
     */
    int nbChapters;

public:
    /**
     * @brief Constructeur prenant en paramètre le nom, le chemin, la durée et les durées des chapitres.
     * 
     * @param name Nom du film.
     * @param path Chemin d'accès au film.
     * @param duration Durée du film.
     * @param chaptersDuration Tableau de durées des chapitres.
     * @param nbChapters Nombre de chapitres.
     */
    Film(std::string name = "", std::string path = "", int duration = 0, int* chaptersDuration = nullptr, int nbChapters = 0);
    /**
     * @brief Destructeur.
     */
    ~Film();
    /**
     * @brief Modifieur pour passer un tableau de durées en argument.
     * 
     * @param chaptersDuration Tableau de durées des chapitres.
     * @param nbChapters Nombre de chapitres.
     */
    void setChaptersDuration(int* chaptersDuration, int nbChapters);
    /**
     * @brief Accesseur pour retourner le tableau de durées.
     * 
     * @return Pointeur vers le tableau de durées des chapitres.
     */
    int* getChaptersDuration() const;
    /**
     * @brief Accesseur pour retourner le nombre de chapitres.
     * 
     * @return Nombre de chapitres.
     */
    int getNbChapters() const;
    /**
     * @brief Méthode d'affichage affichant la durée des chapitres.
     * 
     * @param x Flux de sortie.
     */
    void display(std::ostream& x) const override;
};


#endif // FILM_H

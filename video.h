#ifndef VIDEO_H
#define VIDEO_H
#include "multimedia.h"

/*!
 * \class Video
 * \brief Classe qui représente une vidéo héritant de la classe Multimedia
 */
class Video : public Multimedia {
protected:
    int duration;
public:
    /*!
     * \brief Constructeur de la classe Video
     * \param _name : nom de la vidéo
     * \param _path : chemin de la vidéo
     * \param _duration : durée de la vidéo (en secondes)
     */
    Video(std::string _name = "", std::string _path = "", int _duration = 0){
        name = _name;
        path = _path;
        duration = _duration;
    }
    /*!
     * \brief Retourne la durée de la vidéo
     * \return durée de la vidéo (en secondes)
     */
    virtual int getDuration() const {
        return duration;
    }
    /*!
     * \brief Modifie la durée de la vidéo
     * \param _duration : nouvelle durée de la vidéo (en secondes)
     */
    virtual void setDuration(int _duration) {
        duration = _duration;
    }
    /*!
     * \brief Affiche les informations de la vidéo
     * \param x : flux de sortie
     */
    void display(std::ostream & x) const override {
		x << "Video { Path: " << path
		<< " | Name: " << name
		<< " | Duration: " << duration << "s }" << std::endl;
	}
    /*!
     * \brief Lance la lecture de la vidéo
     */
    void play() const override {
        system(("mpev " + getPath() + " &").data());
    }
	~Video(){
    std::cout<<" Video : " << path << " deleted" << std::endl;
	}


};


#endif // VIDEO_H

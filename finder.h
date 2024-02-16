#ifndef FINDER_H
#define FINDER_H
#include <string>
#include "multimedia.h"
#include "group.h"
#include "photo.h"
#include "video.h"
#include "film.h"
#include <map>
#include "tcpserver.h"
#include <iostream>
#include <sstream>

using MediaPtr = std::shared_ptr<Multimedia>;

using GroupPtr = std::shared_ptr<Group>;


/**
* @class Finder
* @brief Classe pour gérer les médias et les groupes de médias
*/
class Finder {
	private :
		/**
		* @brief Nom du Finder
		*/
		std::string name;
		
		/**
		* @brief Tableau contenant les pointeurs des médias
		*/
		std::map<std::string, MediaPtr> mediaTable = std::map<std::string, MediaPtr>();
		
		/**
		* @brief Tableau contenant les pointeurs des groupes
		*/
		std::map<std::string, GroupPtr> groupTable = std::map<std::string, GroupPtr>();
	public :
		/**
		* @brief Constructeur par défaut
		* @param _name Nom du Finder
		*/
		Finder(std::string _name = "");
		
		/**
		* @brief Destructeur
		*/
		~Finder();
		
		/**
		* @brief Ajoute un média à la table des médias
		* @param media Pointeur vers le média à ajouter
		*/
		void addMedia(MediaPtr media);
		
		/**
		* @brief Ajoute un groupe à la table des groupes
		* @param group Pointeur vers le groupe à ajouter
		*/
		void addGroup(GroupPtr group);
		    /**
     * @brief removeMedia : Remove a media from the mediaTable using its name
     * @param name : the name of the media to remove
     */
    void removeMedia(std::string name);

    /**
     * @brief removeGroup : Remove a group from the groupTable using its name
     * @param name : the name of the group to remove
     */
    void removeGroup(std::string name);

    /**
     * @brief printMedia : search for a media in the mediaTable using its name and display it on the given output stream
     * @param name : the name of the media to print
     * @param out : the output stream to display the media on
	 * @return true if the media was found, false otherwise
     */
	bool printMedia(std::string name, std::ostream& out) const;

    /**
     * @brief printGroup : search for a group in the groupTable using its name and display it on the given output stream
     * @param name : the name of the group to print
     * @param out : the output stream to display the group on
	 * @return true if the group was found, false otherwise
     */
    bool printGroup(std::string name, std::ostream& out) const;

    /**
     * @brief playMedia : play a media using its name
     * @param name : the name of the media to play
	 * @return true if the media was found, false otherwise
     */
    bool playMedia(std::string name) const;

    /**
     * @brief createPhoto : create a photo and add it to the mediaTable
     * @param name : the name of the photo
     * @param path : the path of the photo
     * @param latitude : the latitude of the photo
     * @param longitude : the longitude of the photo
	 * @return the created photo
     */
    std::shared_ptr<Photo>  createPhoto(std::string name = "", std::string path = "", double latitude = 0, double longitude = 0);

    /**
     * @brief createVideo : create a video and add it to the mediaTable
     * @param name : the name of the video
     * @param path : the path of the video
     * @param duration : the duration of the video
	 * @return the created video
     */
    std::shared_ptr<Video>  createVideo(std::string name = "", std::string path = "", int duration = 0);

    /**
     * @brief createFilm : create a film and add it to the mediaTable
     * @param name : the name of the film
     * @param path : the path of the film
     * @param duration : the duration of the film
     * @param chapterNumber : the number of chapters of the film
	 * @param chapterDurations : the durations of the chapters of the film
	 * @return the created film
     */
    std::shared_ptr<Film>  createFilm(std::string name = "", std::string path = "", int duration = 0, int chapterNumber = 0, int * chapterDurations = nullptr);

    /**
     * @brief createGroup : create a group and add it to the groupTable
     * @param name : the name of the group
     */
    void createGroup(std::string name);
	
	/**
	 * @brief removeMediaFromGroup supprime un media de groupe
	 * @param mediaName nom du media à supprimer
	 * @param groupName nom du groupe dans lequel supprimer le media
	*/
	void removeMediaFromGroup(std::string mediaName, std::string groupName);

	/**
	 * @brief addMediaToGroup ajoute un media à un groupe
	 * @param mediaName nom du media à ajouter
	 * @param groupName nom du groupe dans lequel ajouter le media
	*/
	void addMediaToGroup(std::string mediaName, std::string groupName);

	/**
	 * @brief processRequest traite une requête
	 * @param cnx connexion TCP
	 * @param request requête
	 * @param response réponse
	*/
	void processRequest(TCPConnection& cnx, const std::string& request, std::string& response);
};

#endif // FINDER_H
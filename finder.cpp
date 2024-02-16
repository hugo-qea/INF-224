#include "finder.h"

Finder::Finder(std::string _name){
	name = _name;
}
Finder::~Finder() {
	std::cout << "Finder deleted" << std::endl;
}

void Finder::addMedia(MediaPtr media) {
	mediaTable.operator[](media->getName()) = media;
}

void Finder::addGroup(GroupPtr group) {
	groupTable.operator[](group->getName()) = group;
}

bool Finder::playMedia(std::string name) const {
	auto it = mediaTable.find(name);
	if (it != mediaTable.end()) {
		it->second->play();
		return true;
	}
	else {
		std::cout << "Media not found in the MediaTable" << std::endl;
		return false;
	}
}

bool Finder::printMedia(std::string name, std::ostream& out) const {
	auto it = mediaTable.find(name);
	if (it != mediaTable.end()) {
		it->second->display(out);
		return true;
	}
	else {
		std::cout << "Media not found in the MediaTable" << std::endl;
		return false;
	}
}

bool Finder::printGroup(std::string name, std::ostream& out) const {
	auto it = groupTable.find(name);
	if (it != groupTable.end()) {
		it->second->display(out);
		return true;
	}
	else {
		std::cout << "Group not found in the GroupTable" << std::endl;
		return false;
	}
}

std::shared_ptr<Photo> Finder::createPhoto(std::string name, std::string path, double latitude, double longitude) {
	std::shared_ptr<Photo> photo = std::make_shared<Photo>(name, path, latitude, longitude);
	addMedia(photo);
	return photo;
}

std::shared_ptr<Video> Finder::createVideo(std::string name, std::string path, int duration) {
	std::shared_ptr<Video> video = std::make_shared<Video>(name, path, duration);
	addMedia(video);
	return video;
}

std::shared_ptr<Film>  Finder::createFilm(std::string name, std::string path, int duration, int chapterNumber, int * chapterDurations) {
	std::shared_ptr<Film> film = std::make_shared<Film>(name, path, duration, chapterDurations, chapterNumber);
	addMedia(film);
	return film;
}

void Finder::removeMedia(std::string name) {
	MediaPtr media = mediaTable.find(name)->second;
	for (auto& group : groupTable) {
		group.second->remove(media);
	}
	mediaTable.erase(name);

}

void Finder::removeGroup(std::string name) {
	groupTable.erase(name);
}

void Finder::processRequest(TCPConnection& cnx, const std::string& request, std::string& response) {
	
	std::cerr << "\nRequest: ' " << request << " '" << std::endl;

    // Extraction de la commande et de l'argument
    std::string command, argument;
    std::stringstream ss(request);
    ss >> command >> argument;

   bool searched, played;
   searched = false;
   played = false;
   std::stringstream answer_buffer;

   // Verrouillage des ressources
   //TCPLock lock(cnx);

    if (command == "search") {
        // Envoi des attributs de l'objet multimédia ou du groupe trouvé
         searched = printGroup(argument, answer_buffer);
		 if (!searched) {
			 searched = printMedia(argument, answer_buffer);
		 }
    } else if (command == "play") {
        // Lecture de l'objet multimédia trouvé
        played = playMedia(argument);
    } else {
        response = "Error : invalid command";
    }
	if (searched || played) {
		response = answer_buffer.str();
	}
	else {
		response = "Error : file not found";
	}
	
	std::cerr << "response: " << response << std::endl;

}


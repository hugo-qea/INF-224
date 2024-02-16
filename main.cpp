//
// main.cpp
// Created on 21/10/2018
//

#include "multimedia.h"
#include "photo.h"
#include "video.h"
#include <iostream>
#include "film.h"
#include "group.h"
#include <memory>
#include <chrono>
#include <thread>
#include <future>
#include "finder.h"
#include "tcpserver.h"
#include <sstream>

const int PORT = 3331;

int main() {

	
	/*
    // Creation of an object of the class Photo
    Photo p("nom", "chemin", 10.1, 20.2);
    p.display(std::cout);
    p.play(); // launch the function play which is implemented in the class Photo
  
    // Creation of an object of the class Video
    Video v("nom", "chemin", 180);
    v.display(std::cout);
    v.play(); // launch the function play which is implemented in the class Video

    Multimedia *tab[5];
    tab[0] = new Photo("photo1", "path/to/photo1", 42.5, 12.3);
    tab[1] = new Video("video1", "path/to/video1", 180);
    tab[2] = new Photo("photo2", "path/to/photo2", 45.2, 14.1);
    tab[3] = new Video("video2", "path/to/video2", 120);
    tab[4] = new Photo("photo3", "path/to/photo3", 48.6, 15.9);
    
    for (int i = 0; i < 5; i++) {
        tab[i]->display(std::cout);
        std::cout << std::endl;
    }
    
    std::cout << "Playing all elements of the array: " << std::endl;
    for (int i = 0; i < 5; i++) {
        tab[i]->play();
    }

    int chapters[] = {120, 180, 200};
    Film film("film1", "path/to/film1", 300, chapters, 3);
    film.display(std::cout);

    int * newChapters = new int[3];
    film.setChaptersDuration(newChapters, 3);
	delete[] newChapters;
    film.display(std::cout);

	int chapters[] = {120, 180, 200};
	// Création de quelques objets de différents types
    std::shared_ptr<Video> video1 (new Video("Video 1", "path/to/video1", 180));
	std::shared_ptr<Video> video2 (new Video("Video 2", "path/to/video2", 120));
	std::shared_ptr<Video> video3 (new Video("Video 3", "path/to/video3", 180));
    std::shared_ptr<Photo> photo1 (new Photo("Photo 1", "path/to/photo1", 42.5, 12.3));
	std::shared_ptr<Photo> photo2 (new Photo("Photo 2", "path/to/photo2", 45.2, 14.1));
	std::shared_ptr<Photo> photo3 (new Photo("Photo 3", "path/to/photo3", 48.6, 15.9));
    std::shared_ptr<Film> film1 (new Film("Film 1", "path/to/film1", 300, chapters, 3));
	std::shared_ptr<Photo> photo4 (photo3);

    // Création de groupes et ajout des objets
    Group * groupe1 (new Group("Group 1"));
    groupe1->push_back(video1);
	groupe1->push_back(video2);
    groupe1->push_back(photo1);
	groupe1->push_back(photo2);

    Group*	groupe2 (new Group("Group 2"));
    groupe2->push_back(video1);
	groupe2->push_back(video3);
    groupe2->push_back(film1);
	groupe2->push_back(photo2);
	groupe2->push_back(photo3);


    // On commence par afficher les groupes initiaux
	groupe1->display(std::cout);
	groupe2->display(std::cout);
	// Ensuite, on enlève les objets des groupes
	// On utilise un thread pour faire ça
	std::thread t1(removing, std::ref(*groupe1), video1, std::ref(*groupe2), film1);
	t1.join();
	printf("on a enlevé les objets des groupes \n");

	printf("Affichons les nouveaux groupes \n");


    // Afficher les groupes après suppression des objets
	groupe2->remove(photo3);
    groupe1->display(std::cout);
    groupe2->display(std::cout);

	groupe1->remove(photo1);
	//photo4.reset();

	// Afficher les groupes après suppression des objets
	groupe1->display(std::cout);
	groupe2->display(std::cout);

    // Vérifier que les objets ont été détruits
    // Ils ne devraient plus appartenir à aucun groupe et n'être pointés par aucun autre shared_ptr
    // Leurs destructeurs devraient afficher un message sur le terminal

	// Test de la classe finder
	// On crée un objet finder
	Finder finder;
	// On ajoute les groupes
	finder.addGroup(groupe1);
	finder.addGroup(groupe2);
	// On affiche les groupes
	finder.printGroup("Group 1", std::cout);
	finder.printGroup("Group 2", std::cout);
	// On affiche un objet
	finder.playMedia("Video 1");
	finder.playMedia("Photo 1");
	finder.playMedia("Audio 1");

	// Créer et ajouter des objets dans le finder
	std::shared_ptr<Video> video4 = finder.createVideo("Video 4", "path/to/video4", 180);
	std::shared_ptr<Photo> photo5 = finder.createPhoto("Photo 5", "path/to/photo5", 42.5, 12.3);
	std::shared_ptr<Film> film2 = finder.createFilm("Film 2", "path/to/film2", 300, chapters, 3);
	*/


	// Create the TCP server

	auto* server = new TCPServer([&] (std::string const& request, std::string& response) {
		std::cout << "Request: " << request << std::endl;
		response = "RECEIVED: " + request;

		return true;
	});

	// Start the server
	std::cout << "Starting the server... on port" << PORT << std::endl;

	int status = server->run(PORT);

	// In case of error, display the error message
	if (status < 0) {
		std::cerr << "Could not start the Server on port  " << PORT << std::endl;
	}

	// Create a finder
	Finder finder;
	// Create a group
	std::shared_ptr<Group> group = std::make_shared<Group>("Group 1");
	// Add medias to the group
	group->push_back(finder.createVideo("Video 1", "path/to/video1", 180));
	group->push_back(finder.createPhoto("Photo 1", "path/to/photo1", 42.5, 12.3));
	int chapters[] = {120, 180, 200};
	group->push_back(finder.createFilm("Film 1", "path/to/film1", 300, 3, chapters));
	// Add the group to the finder
	finder.addGroup(group);
	// Create a c





	return 0;
}



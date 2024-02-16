#include "film.h"
#include <iostream>


Film::Film(std::string _name, std::string _path, int _duration, int* _chaptersDuration, int _nbChapters) {
	if (_chaptersDuration != nullptr) {
		chaptersDuration = new int[_nbChapters];
		for (int i = 0; i < _nbChapters; ++i) {
			chaptersDuration[i] = _chaptersDuration[i];
		}
	}
	name = _name;
	path = _path;
	duration = _duration;
	nbChapters = _nbChapters;
	}


Film::~Film() {
    delete[] chaptersDuration;
    std::cout<<" Film : " << path << " deleted" << std::endl;
}

void Film::setChaptersDuration(int* _chaptersDuration, int _nbChapters) {
	delete[] chaptersDuration;
	chaptersDuration = new int[_nbChapters];
	for (int i = 0; i < _nbChapters; ++i) {
		chaptersDuration[i] = _chaptersDuration[i];
	}
	nbChapters = _nbChapters;
}

int* Film::getChaptersDuration() const {
    int * res = new int[nbChapters];
	for (int i = 0; i < nbChapters; ++i) {
		res[i] = chaptersDuration[i];
	}
	return res;
}

int Film::getNbChapters() const {
    return nbChapters;
}

void Film::display(std::ostream& x) const {
    Video::display(x);
    x << "Nombre de chapitres : " << nbChapters << std::endl;
    for (int i = 0; i < nbChapters; ++i) {
        x << "Chapitre " << i + 1 << " : " << chaptersDuration[i] << "s" << std::endl;
    }
}

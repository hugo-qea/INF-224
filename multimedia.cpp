#include "multimedia.h"

Multimedia::Multimedia(std::string _name, std::string _path){
    name = _name;
    path = _path;
}

void Multimedia::setName(std::string newname){
    name = newname;
}

void Multimedia::setPath(std::string newpath){
    path = newpath;
}

std::string Multimedia::getName() const {
    return name;
}

std::string Multimedia::getPath() const {
    return path;
}

void Multimedia::display(std::ostream & x) const{
    x
    <<"Name:" << name << std::endl;
	x
	<<"Path:" << path << std::endl;
}

Multimedia::~Multimedia() {
    std::cout<<" Media : " << path << " deleted" << std::endl;
}

Multimedia::Multimedia() {
	name = "";
	path = "";
}

#include "group.h"
#include <iostream>

Group::~Group() {
	for (auto& elem : *this) {
		elem.reset();
	}
	std::cout << "Group " << name << " deleted" << std::endl;
}

void Group::display(std::ostream& out) const {
    out << "Group: " << name << std::endl;
    for (auto& elem : *this) {
        elem->display(out);
    }
}
std::string Group::getName() const {
	return name;
}

void Group::setName(std::string _name) {
	name = _name;
}

Group::Group(std::string _name) {
	name = _name;
}






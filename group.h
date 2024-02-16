// groupe.h
#ifndef GROUP_H
#define GROUP_H

#include <string>
#include <list>
#include "multimedia.h"

using MediaPtr = std::shared_ptr<Multimedia>;

/**
 * @class Group
 * @brief Represents a group of Multimedia objects
 * 
 * This class inherits from the standard library container std::list<std::shared_ptr<Multimedia>> 
 * and allows to store and manage a group of Multimedia objects. It also has a name attribute 
 * and methods to access and modify it.
 */
class Group : public std::list<MediaPtr> {
private:
    std::string name;  ///< The name of the group

public:
    /**
     * @brief Constructs a Group object with a given name
     * @param _name The name of the group
     */
    Group(std::string _name = "");

    /**
     * @brief Destroys the Group object
     */
    ~Group();

    /**
     * @brief Returns the name of the group
     * @return The name of the group
     */
    std::string getName() const;
    
    /**
     * @brief Sets the name of the group
     * @param _name The new name of the group
     */
    void setName(std::string _name);

    /**
     * @brief Displays the information of all the Multimedia objects in the group
     * @param out The output stream to display the information
     */
    void display(std::ostream& out) const;
};



#endif // GROUP_H

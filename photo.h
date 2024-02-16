/**
 * @file photo.h
 * @brief Header file for the Photo class.
 * This class represents a photo, which is a subclass of Multimedia.
 * It contains the latitude and longitude attributes, as well as methods to access and modify them.
 * It also contains the display and play methods, which have the same signature as in the parent class.
 */

#ifndef PHOTO_H
#define PHOTO_H
#include "multimedia.h"

class Photo : public Multimedia {
private:
    double latitude; /**< Latitude of the photo */
    double longitude; /**< Longitude of the photo */

public:
    /**
     * @brief Constructor for the Photo class.
     * @param _name Name of the photo.
     * @param _path Path to the photo's file.
     * @param _latitude Latitude of the photo.
     * @param _longitude Longitude of the photo.
     */
    Photo(std::string _name = "", std::string _path = "", double _latitude = 0, double _longitude = 0){
        name = _name;
        path = _path;
        latitude = _latitude;
        longitude = _longitude;
    };

    /**
     * @brief Getter for the longitude attribute.
     * @return Longitude of the photo.
     */
    virtual double getLongitude() const {
        return longitude;
    }

    /**
     * @brief Getter for the latitude attribute.
     * @return Latitude of the photo.
     */
    virtual double getLatitude() const {
        return latitude;
    }

    /**
     * @brief Setter for the longitude attribute.
     * @param _longitude New longitude of the photo.
     */
    virtual void setLongitude(int _longitude) {
        longitude = _longitude;
    }
    /**
	 * @brief Set the latitude of the photo
	 * 
	 * @param _latitude The latitude to set
	 */
	virtual void setLatitude(double _latitude) {
		latitude = _latitude;
	}
	/**
	 * @brief Display the information of the photo
	 * 
	 * @param x The ostream to output the information
	 */
	void display(std::ostream & x) const override {
		x << "Photo { Path: " << path
		<< " | Name: " << name
		<< " | Longitude: " << longitude
		<< " | Latitude: " << latitude << " }" << std::endl;
	}
	/**
	 * @brief Play the photo with the system's default image viewer
	 * 
	 */
	void play() const override {
		system(("imagej " + getPath() + " &").data());
	}
	~Photo() {
    std::cout<<" Photo : " << path << " deleted" << std::endl;
	}



};

#endif // PHOTO_H


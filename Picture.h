/*!
 * \file
 * \brief  Class extending media objects. The name is self-explanatory
 * \author Benjamin LAZARD
 * \date   7 d�c. 2016
 *
 * This class is so simple, it does not even require .cpp file.
 */
/*!
 * \fn virtual void play() const override
 * calls Linux imagej reader to display the image.
 */

#ifndef PICTURE_H_
#define PICTURE_H_

#include <iostream>
#include <string>
#include <stdlib.h>
#include "Mediaobject.h"

//So as to make strings and console_out directly accessible.
using namespace std;

//extern string PICTURE_MEDIUM_TYPE;//!< Value defined in global_constants.cpp ( should be "picture")

class Picture : public Media_object {
private:
	float width;
	float height;

public:
	Picture(const string name, const string absolute_path= "", float width = 0, float height = 0) :
		Media_object(name, absolute_path), width(width), height(height) {}
	~Picture(){}//!<since there is no .cpp file, it needs to be implemented here.

	virtual float getWidth() const final{return width;}
	virtual void setWidth(float width) final {this->width = width;}
	virtual float getHeight() const final {return height;}
	virtual void setHeight(float height)final {this->height = height;}

	void printMediumData(ostream& stream) const override {
        stream << "Name: " << name << "    "//as we cannot use "\n" because of server communications
        << "Absolute path: " << absolute_path << "    "
        << "Width: " << width << "    "
        << "Height: " << height << "    "
        ;//<< endl;
	}

	/*!
	 * \brief Unix command that plays the medium depending on its type.
	 * calls Linux imagej reader to display the picture.
	 */
	virtual void play() const override{
		string system_arg = "imagej " + absolute_path + " &";
		system(system_arg.c_str());
	}

    virtual string getClass() const override{return "Picture";}

    virtual void writeToFile(ostream & file) const override {
        Media_object::writeToFile(file);
        file << width << "\n" << height << "\n";
    }

    virtual void readFromFile(ostream & file) const override{
        Media_object::readFromFile(file);
        string temp;
        getline(file, temp);
        width = stoi(temp);
        getline(file, temp);
        height = stoi(temp);
    }
};

#endif /* PICTURE_H_ */

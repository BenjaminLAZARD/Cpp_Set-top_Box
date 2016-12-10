/*!
 * \file
 * \brief  Class extending media objects. The name is self-explanatory
 * \author Benjamin LAZARD
 * \date   7 déc. 2016
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

extern string PICTURE_MEDIUM_TYPE;//!< Value defined in global_constants.cpp ( should be "picture")

class Picture : public Media_object {
private:
	float width;
	float height;

public:
	Picture(const string absolute_path= "", float width = 0, float height = 0) :
		Media_object(PICTURE_MEDIUM_TYPE, absolute_path), width(width), height(height) {}
	~Picture(){}//!<since there is no .cpp file, it needs to be implemented here.

	virtual float getWidth() const final{return width;}
	virtual void setWidth(const float width) final {this->width = width;}
	virtual float getHeight() const final {return height;}
	virtual void setHeight(const float height)final {this->height = height;}

	void printMediumData(ostream& stream) const override {
		stream << "Medium type: " << medium_type << "\n"
	    << "Absolute path: " << absolute_path << "\n"
	    << "Width: " << width << "\n"
	    << "Height: " << height << "\n"
	    << endl;
	}

	/*!
	 * \brief Unix command that plays the medium depending on its type.
	 * calls Linux imagej reader to display the picture.
	 */
	virtual void play() const override{
		string system_arg = "imagej " + absolute_path + " &";
		system(system_arg.c_str());
	}
};

#endif /* PICTURE_H_ */

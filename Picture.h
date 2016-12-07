/*!
 * \file   Picture.h
 * \brief  Class extending media objects. The name is self-explanatory
 * \author Benjamin LAZARD
 * \date   7 déc. 2016
 *
 * This class is so simple, it does not even require .cpp file.
 */

#ifndef PICTURE_H_
#define PICTURE_H_

#include <iostream>
#include <string>
#include <stdlib.h>
#include "Mediaobject.h"

//So as to make strings and console_out directly accessible.
using namespace std;

class Picture : public Media_object {
private:
	float width;
	float height;

public:
	Picture(const string medium_type = "", const string absolute_path= "", float width = 0, float height = 0) :
		Media_object(medium_type, absolute_path), width(width), height(height){}
	virtual ~Picture(){}//!<since there is no .cpp file, it needs to be implemented here.

	virtual float getWidth() const {return width;}
	virtual void setWidth(const float width) {this->width = width;}
	virtual float getHeight() const {return height;}
	virtual void setHeight(const float height) {this->height = height;}

	virtual void printMediumData(ostream& stream) const override {
		stream << "Medium type: " << medium_type << "\n"
			   << "Absolute path: " << absolute_path << "\n"
			   << "Width: " << width << "\n"
			   << "Height: " << height << "\n"
			   << endl;
	}

	virtual void play() const override{
		string system_arg = "imagej " + absolute_path + " &";
		system(system_arg.c_str());
	}
};

#endif /* PICTURE_H_ */

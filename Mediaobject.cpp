/*!
  \file   Mediaobject.cpp
  \brief  Abstract object the properties of which are shared by all media.
  \author Benjamin LAZARD
  \date   6 déc. 2016
 */
/*!
  \fn Media_object()
  \brief basic constructor which initializes empty properties.
 */
/*!
  \fn  Media_object(string medium_type, string absolute_path)
  \brief elaborated constructor which initializes basic properties.
  \param path : absolute path including name of the file and extension.
  \param type : type of medium, inferred from medium extension.
 */

#include "Mediaobject.h"
/*! using namespace std; //don't know if there is a redundancy with the namespace of the header file. */


//2 types of constructors
Media_object::Media_object() {
	medium_type = "";
	absolute_path = "";
}
Media_object::Media_object(const string medium_type, const string absolute_path) {
	this->medium_type = medium_type;
	this->absolute_path = absolute_path;
}

//destroyer
Media_object::~Media_object() {}

//getters and setters
string Media_object::getMediumType() const {return medium_type;}
string Media_object::getAbsolutePath() const {return absolute_path;}
void Media_object::setAbsolutePath(const string absolutePath) {this->absolute_path = absolutePath;}
void Media_object::setMediumType(const string mediumType) {this->medium_type = mediumType;}

//other functions
void Media_object::printMediumData(ostream& stream) const {
	stream << "Medium type: " << medium_type << "\n" << "Absolute path: " << absolute_path << "\n" << endl;
}

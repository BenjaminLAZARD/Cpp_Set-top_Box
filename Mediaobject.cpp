/*!
  \file
  \brief  Abstract object the properties of which are shared by all media.
  \author Benjamin LAZARD
  \date   6 d�c. 2016
 */
/*!
  \fn Media_object::Media_object()
  \brief basic constructor which initializes empty properties.
 */
/*!
  \fn  Media_object::Media_object(string medium_type, string absolute_path)
  \brief elaborated constructor which initializes basic properties.
  \param path : absolute path including name of the file and extension.
  \param type : type of medium, inferred from medium extension.
 */
/*!
 * \fn void Media_object::printMediumData(ostream& stream) const
 * \param stream The output where to print
 * \brief specifies all the existing properties of the object (name, and value).
 */

#include "Mediaobject.h"
/*! using namespace std; //don't know if there is a redundancy with the namespace of the header file. */


//2 types of constructors
Media_object::Media_object() {
	name = "";
	absolute_path = "";
}
Media_object::Media_object(const string name, const string absolute_path) {
	this->name = name;
	this->absolute_path = absolute_path;
}

//destroyer
Media_object::~Media_object() {}

//getters and setters
string Media_object::getName() const {return name;}
string Media_object::getAbsolutePath() const {return absolute_path;}
void Media_object::setAbsolutePath(const string absolutePath) {this->absolute_path = absolutePath;}
void Media_object::setName(const string name) {this->name = name;}

//other functions
void Media_object::printMediumData(ostream& stream) const {
    stream << "Name: " << name << "    " << "Absolute path: " << absolute_path << "    ";// << endl;//as we cannot use "\n" because of server communications
}

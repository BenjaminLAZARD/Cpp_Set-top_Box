/*!
 * \file   Mediaobject.h
 * \brief  Abstract object the properties of which are shared by all media.
 * \author Benjamin LAZARD
 * \date   6 d�c. 2016
 */
/*!
 * \fn virtual void printMediumData(ostream& stream) const
 * \brief Print basic properties of a medium, such as complete name and type.
 * \param stream : the output where to display the information.
 */
/*!
 * \fn virtual void play() const =0
 * \brief Unix command that plays the medium depending on its type.
 */

#ifndef MEDIAOBJECT_H_
#define MEDIAOBJECT_H_

#include <iostream>
#include <string>

//So as to make strings and console_out directly accessible.
using namespace std;

class Media_object {
protected://acessible to sub-classes
	string medium_type;
	string absolute_path;

public:
	Media_object();
	Media_object(const string medium_type, const string absolute_path);

	virtual ~Media_object();

	virtual string getMediumType() const;
	virtual string getAbsolutePath() const;
	virtual void setAbsolutePath(const string absolutePath); // not a const function since it modifies instance attributes
	virtual void setMediumType(const string mediumType);	// not a const function since it modifies instance attributes

	virtual void printMediumData(ostream& stream) const;

	virtual void play() const =0;
};

#endif /* MEDIAOBJECT_H_ */

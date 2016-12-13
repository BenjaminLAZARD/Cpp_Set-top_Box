/*!
 * \file
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
 * \class Media_object
 * \brief Print basic properties of a medium, such as complete name and type.
 */

#ifndef MEDIAOBJECT_H_
#define MEDIAOBJECT_H_

#include <iostream>
#include <string>

//So as to make strings and console_out directly accessible.
using namespace std;

class Media_object {
protected://acessible to sub-classes
	string name;
	string absolute_path;

public:
	Media_object();
	Media_object(const string name, const string absolute_path);

	virtual ~Media_object();

	virtual string getName() const final;
	virtual string getAbsolutePath() const final;
	virtual void setAbsolutePath(const string absolutePath) final; // not a const function since it modifies instance attributes
	virtual void setName(const string name) final;	// not a const function since it modifies instance attributes

	virtual void printMediumData(ostream& stream) const;

	/*!
	 * \brief Unix command that plays the medium depending on its type.
	 */
	virtual void play() const =0;
};

#endif /* MEDIAOBJECT_H_ */

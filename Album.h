/*!
 * \file
 * \brief  A class to allow the creation of albums grouping pictures or movies
 * \author Benjamin LAZARD
 * \date   13 déc. 2016
 *
 * Albums can group different media_objects by either subcategory (picture, or movies), or by attributes such as
 * time_period range.
 */

#ifndef ALBUM_H_
#define ALBUM_H_

//#include Mediaobject.h;
#include "Picture.h"
#include "Movie.h"

#include <list>

using namespace std;

class Album : public list<Media_object*>{
private:
	string albumName;
public:
	Album(string _albumName) : albumName(_albumName) {}
	virtual ~Album();

	virtual string getalbumName()const final{return albumName;}
	virtual void print(ostream& stream) final{
		int i = 0;
		for (list<Media_object*>::iterator it = this->begin(); it != this->end(); ++it){
			stream << "album " << albumName <<", item n° " << i << endl;
			(*it)->printMediumData(cout);
			i++;
		}
	}
};

#endif /* ALBUM_H_ */

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
#include <memory>

using namespace std;

using smartMediaPointer = shared_ptr<Media_object>;
//using smartMediaPointer = Media_object*;

class Album : public list<smartMediaPointer>{
private:
	string albumName;
public:
	Album(string _albumName) : albumName(_albumName) {}
	virtual ~Album();

	virtual string getalbumName()const final{return albumName;}
	virtual void print(ostream& stream) final{
		int i = 0;
		for (list<smartMediaPointer>::iterator it = this->begin(); it != this->end(); ++it){
            stream << "album " << albumName <<", item n° " << i ;//no endl since it is trouble for server communication
			(*it)->printMediumData(cout);
			i++;
		}
	}
};

#endif /* ALBUM_H_ */

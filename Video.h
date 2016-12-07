/*!
 * \file   Video.h
 * \brief  Class extending media objects. The name is self-explanatory
 * \author Benjamin LAZARD
 * \date   7 déc. 2016
 *
 * This class is so simple, it does not even require .cpp file.
 */

#ifndef VIDEO_H_
#define VIDEO_H_

#include <iostream>
#include <string>
#include <stdlib.h>
#include "Mediaobject.h"

//So as to make strings and console_out directly accessible.
using namespace std;

class Video : public Media_object {
private:
	float duration;

public:
	Video(const string medium_type = "", const string absolute_path = "", float duration = 0) :
		Media_object(medium_type, absolute_path), duration(duration){}
	virtual ~Video(){}//!<since there is no .cpp file, it needs to be implemented here.

	virtual float getDuration() const {return duration;}
	virtual void setDuration(const float duration) {this->duration = duration;}

	virtual void printMediumData(ostream& stream) const override {
		stream << "Medium type: " << medium_type << "\n"
			   << "Absolute path: " << absolute_path << "\n"
			   << "Duration: " << duration << "\n"
			   << endl;
	}
	virtual void play() const override{
			string system_arg = "mpv " + absolute_path + " &";
			system(system_arg.c_str());
		}
};



#endif /* VIDEO_H_ */

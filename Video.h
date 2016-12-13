/*!
 * \file
 * \brief  Class extending media objects. The name is self-explanatory
 * \author Benjamin LAZARD
 * \date   7 déc. 2016
 *
 * This class is so simple, it does not even require a .cpp file.
 */

#ifndef VIDEO_H_
#define VIDEO_H_

#include <iostream>
#include <string>
#include <stdlib.h>
#include "Mediaobject.h"

//So as to make strings and console_out directly accessible.
using namespace std;

//extern string VIDEO_MEDIUM_TYPE;//!< Value defined in global_constants.cpp ( should be "video")

class Video : public Media_object {
protected:
	float duration;

public:
	Video(const string name="", const string absolute_path = "", float duration = 0) :
		Media_object(name, absolute_path), duration(duration) {}
	~Video(){}//!<since there is no .cpp file, it needs to be implemented here.

	virtual float getDuration() const final {return duration;}
	virtual void setDuration(float duration) final {this->duration = duration;}

	void printMediumData(ostream& stream) const override {
		stream << "Name: " << name << "\n"
		<< "Absolute path: " << absolute_path << "\n"
		<< "Duration: " << duration << "\n"
		<< endl;
	}

	/*!
	 * \brief Unix command that plays the medium depending on its type.
	 * calls Linux mpv reader to play the video.
	 */
	virtual void play() const override{
			string system_arg = "mpv " + absolute_path + " &";
			system(system_arg.c_str());
		}
};



#endif /* VIDEO_H_ */

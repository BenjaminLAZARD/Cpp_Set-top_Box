/*!
 * \file   Main.cpp
 * \brief  Merely a test file.
 * \author Benjamin LAZARD
 * \date   6 déc. 2016
 */

#include "Video.h"
#include "Picture.h"

using namespace std;

void test_step1_2(){
	//medium has become an abstract class, and is no longer posible to instanciate
	//Media_object* medium = new Media_object("image", "C:/in/the/middle/of/nowhere/img.png");
	//medium->printMediumData(cout);

	Video* video = new Video();
	video->printMediumData(cout);
	delete video;
	video = nullptr;

	video = new Video("video", "C:/in/the/middle/of/nowhere/video.mp4", 32.5);
	video->setDuration(6);
	video->setAbsolutePath("and weirder");
	video->printMediumData(cout);

	Picture* picture = new Picture("image", "C:/in/the/middle/of/nowhere/image.png", 16, 9);
	picture->printMediumData(cout);
}

int main() {
	test_step1_2();
}


/*!
 * \file   Main.cpp
 * \brief  Merely a test file.
 * \author Benjamin LAZARD
 * \date   6 déc. 2016
 */

#include "Mediaobject.h"
using namespace std;

void test_step1_2(){
	Media_object* medium = new Media_object("image", "C:/in/the/middle/of/nowhere/img.png");
	medium->printMediumData(cout);

	medium->setMediumType("weirder");
	medium->setAbsolutePath("and weirder");
	medium->printMediumData(cout);
}

int main() {
	test_step1_2();
}


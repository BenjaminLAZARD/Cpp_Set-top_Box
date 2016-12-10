/*!
 * \file
 * \brief  Merely a test file.
 * \author Benjamin LAZARD
 * \date   6 déc. 2016
 */

#include "Video.h"
#include "Picture.h"
#include "Movie.h"

using namespace std;

void test_step1_2(){
	//medium has become an abstract class, and is no longer posible to instanciate
	//Media_object* medium = new Media_object("image", "C:/in/the/middle/of/nowhere/img.png");
	//medium->printMediumData(cout);

	Video* video = new Video();
	video->printMediumData(cout);
	delete video;
	video = nullptr;

	video = new Video("C:/in/the/middle/of/nowhere/video.mp4", 32.5);
	video->setDuration(6);
	video->setAbsolutePath("and weirder");
	video->printMediumData(cout);

	Picture* picture = new Picture("C:/in/the/middle/of/nowhere/image.png", 16, 9);
	picture->printMediumData(cout);

	delete video; delete picture; video = nullptr; picture = nullptr;
	//no need to delete n since it is in the heap, and therefore destroyed at the end of the function
}

void test_step3_4() {
	int n = 2;
	Media_object** playlist = new Media_object* [n]{
		new Video("here", 3),
		new Picture("there", 16, 9),
	};

	/*!
	 * __ In the following loop, we use polymorphism to print the proeprties of any medium ,
	 *    regardless of its type.
	 * __ C++ looping over arrays require the length of the array to be known
	 * __ The elements of the playlist are pointers towards object (to allow changes on the objects to be found while
	 *    picking an object from the array).
	 * __ Java allows the programmer to use transparently references towards objects as their name, hiding the pointers
	 *    mambo-jumbo. However, its implementation involves something similar to C++.
	 */

	for (int i = 0; i < n; ++i) {
		playlist[i]->printMediumData(cout);
	}

	delete[] playlist; playlist = nullptr;
}

void test_step5_6_7() {
	int n = 4;
	int markers[n] = {2, 5, 10, 15};
	Movie* movie = new Movie("path",777, markers, n);

	//Testing my arithmetics to measure markers length:
//	cout << "size of markers = " << sizeof(markers) << "; size of markers[0] = " << sizeof(*markers)
//		 << "; division result = " << sizeof(markers)/sizeof(*markers) << "\n"
//		 << "object calculation: " << movie->getNumberOfChapters()
//		 << "\n" << endl;
//	//strangely, the arithmetics with sizeof does not work inside the movie object. (size of markers become that of int = 4)


	//Testing inner functions access capability.
	cout << "INNER FUNCTIONS TEST" << "\n\n\n"
		 << "retrieving structured return : number of chapters = " << movie->getChaptersData().number_of_chapters
		 << " ||| chapter 0 marker = " << movie->getChaptersData().markers[0]
		 << "\n" <<endl;
	cout << "printMediumData"<<endl;
	movie->printMediumData(cout);


	//Let us change markers used for initialization, and see if it affects movie->markers
	cout << "ENCAPSULATION TESTS" << "\n\n\n"
	     << "encapsulation test 1 , the markers output should be unchanged" <<endl;
	markers[0] = 3;
	movie->printMarkers(cout);

	cout << "encapsulation test 2, the markers output should be unchanged" <<endl;
	int * markers2 = movie->getMarkers();
	*markers2 = 100100010;
	movie->printMarkers(cout);


	//Let us try different copies of movie, and check they are independant from the original.
	cout << "encapsulation test 3, the markers output should be unchanged" <<endl;
	markers[0] = 2;
	movie->setMarkers(markers, n);
	Movie* movie_le_retour = movie;
	markers[3] = 710010001;
	movie->setMarkers(markers, n);
	movie_le_retour->printMarkers(cout);

	cout << "encapsulation test 4, the markers output should be unchanged" <<endl;
	markers[3] = 15;
	movie->setMarkers(markers, n);
	Movie* movie_epilogue(movie);
	//movie_epilogue->printMarkers(cout);
	markers[3] = 100100010;
	movie->setMarkers(markers, n);
	movie_epilogue->printMarkers(cout);

	delete movie; movie = nullptr; delete markers2; markers2 = nullptr;
	//no need to delete markers since it is in the heap, and therefore destroyed at the end of the function
}

/*!
 * \brief test the different steps of the TP.
 * please un-comment the function corresponding to the steps you wish to try out, and leave the others commented.
 * @return console output mostly.
 */
int main() {
	//test_step1_2();
	//test_step3_4();
	test_step5_6_7();
}


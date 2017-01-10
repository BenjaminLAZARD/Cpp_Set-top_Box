/*!
 * \file
 * \brief  Merely a test file.
 * \author Benjamin LAZARD
 * \date   6 déc. 2016
 */

#include "Video.h"
#include "Picture.h"
#include "Movie.h"
#include "Album.h"

using namespace std;

void test_step1_2(){
	//medium has become an abstract class, and is no longer posible to instanciate
	//Media_object* medium = new Media_object("image", "C:/in/the/middle/of/nowhere/img.png");
	//medium->printMediumData(cout);

	Video* video = new Video();
	video->printMediumData(cout);
	delete video;
	video = nullptr;

	video = new Video("video1", "C:/in/the/middle/of/nowhere/video.mp4", 32.5);
	video->setDuration(6);
	video->setAbsolutePath("HDD");
	video->printMediumData(cout);

	Picture* picture = new Picture("picture1", "C:/in/the/middle/of/nowhere/image.png", 16, 9);
	picture->printMediumData(cout);

	delete video; delete picture; video = nullptr; picture = nullptr;
	//no need to delete n since it is in the heap, and therefore destroyed at the end of the function
}

void test_step3_4() {
	int n = 2;
	Media_object** playlist = new Media_object* [n]{
		new Video("something", "here", 3),
		new Picture("some other thing", "there", 16, 9),
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
	Movie* movie = new Movie("movie1", "path",777, markers, n);

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
	//const int * markers2 = movie->getMarkers();//cannot be modified
	movie->printMarkers(cout);


	//Let us try different copies of movie, and check they are independent from the original.
	cout << "encapsulation test 3, the markers output should be unchanged" <<endl;
	markers[0] = 2;
	movie->setMarkers(markers, n);
	Movie movie_le_retour = *movie;//notice that we work with movie objects here and not with movie* pointers.
	//movie_le_retour.printMarkers(cout); //this one is correctly printed (you can check)
	markers[2] = 71;
	movie->setMarkers(markers, n);
	//movie->printMarkers(cout);
	movie_le_retour.printMarkers(cout);

	//same thing as before, but trying to initialize the new object with constructor definition.
	cout << "encapsulation test 4, the markers output should be unchanged" <<endl;
	markers[2] = 10;
	movie->setMarkers(markers, n);
	Movie movie_epilogue(*movie);
	movie_epilogue.printMarkers(cout);
	markers[3] = 100100010;
	movie->setMarkers(markers, n);
	movie_epilogue.printMarkers(cout);

	delete movie; movie = nullptr;
	//delete[] markers2; markers2 = nullptr;
	//no need to delete markers or the other movies since it is in the heap, and therefore destroyed at the end of the function
}

//void test_step8(){
//	Video* video = new Video("video1", "C:/in/the/middle/of/nowhere/video.mp4", 32.5);
//	Picture* picture = new Picture("picture1", "C:/in/the/middle/of/nowhere/image.png", 16, 9);
//	int markers[4] = {2, 5, 10, 15};
//	Movie* movie = new Movie("movie1", "path",777, markers, 4);

//	Album* album = new Album("vacances");
//	album->push_back(video);
//	album->push_back(picture);
//	album->push_back(movie);
//	album->print(cout);

//	Album* album2 = new Album("travail");
//	album2->push_back(movie);
//	album2->print(cout);

//	delete album; album = nullptr;
//	album2->print(cout);

//	delete album2; album2 = nullptr;
//	delete video; delete picture; delete movie;
//	video = nullptr; picture=nullptr; movie=nullptr;
//};

void test_step9(){
    using smartMediaPointer = shared_ptr<Media_object>;
    //Video* video = new Video("video1", "C:/in/the/middle/of/nowhere/video.mp4", 32.5);
    int markers[4] = {2, 5, 10, 15};
    smartMediaPointer movie(new Movie("movie1", "path",777, markers, 4));

    Album* album = new Album("vacances");
    album->push_back(movie);
    album->print(cout);

    Album* album2 = new Album("travail");
    album2->push_back(movie);

    movie.reset();

    delete album; album = nullptr;
    album2->print(cout);
    delete album2; album2 = nullptr;
};

/*!
 * \brief test the different steps of the TP.
 * please un-comment the function corresponding to the steps you wish to try out, and leave the others commented.
 * @return console output mostly.
 */
int main() {
	//test_step1_2();
	//test_step3_4();
    //test_step5_6_7();
    //test_step8();
    test_step9();
}

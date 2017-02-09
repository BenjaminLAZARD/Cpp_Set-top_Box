/*! \file */
/*!
 * \fn Movie::Movie(const string absolute_path, float duration, int* markers)
 * \param markers an array of integers corresponding to the beginning of the different chapters.
 */

#include "Movie.h"

using namespace std;

Movie::Movie(const string name, const string absolute_path, float duration,
			 const int* markers, int number_of_chapters) : Video(name, absolute_path, duration){
	//this->name = name;//!< Value defined in global_constants.cpp ( should be "movie")

	//to avoid the compiler's warning, it is better to initialize markers and number_of_chapters directly in the .h file
	//at the private values.

	//setting up these values.
	this->setMarkers(markers, number_of_chapters);
}


void Movie::setMarkers(const int* markers, int number_of_chapters){
	this->number_of_chapters = number_of_chapters;//!< length of the array divided by the length of the first item.

	//!<deep copy of markers into the object to ensure encapsulation.
	if (this->markers != nullptr) {delete[] this->markers; this->markers = nullptr;}
	this->markers = new int[number_of_chapters]; //markers is a pointer, and number_of_chapters an array of integers
	for (int chapter = 0; chapter < number_of_chapters; ++chapter) {this->markers[chapter] = markers[chapter];}
}

const int* Movie::getMarkers() const {
	return markers;//!< since the function returns a const int*, there is no need for a copy of the returned object.
	/*
	int* markers_copy = new int[number_of_chapters];
	for (int chapter = 0; chapter < number_of_chapters; ++chapter) {markers_copy[chapter] = markers[chapter];}
	return markers_copy;
	*/
}

Chapters_data Movie::getChaptersData() const {
	return Chapters_data{this->getMarkers(), this->number_of_chapters};
}

void Movie::printMarkers(ostream& stream) const {
	for (int chapter = 0; chapter < number_of_chapters; ++chapter) {
        stream << "chapter n° " << chapter << ", index = " << markers[chapter] << "    "; //as we cannot insert "\n" in case of server communications
	}
    stream << "Total number of chapters = " << number_of_chapters << "    " ;//<< endl;
}

void Movie::printMediumData(ostream& stream) const {Video::printMediumData(stream); printMarkers(stream);}

/*!
 * copy constructor pour l'initialisation : Car othercar(original_car);
 * @param original
 * @return construct a new movie object, created as a deepcopy of the original one.
 */
Movie::Movie(const Movie& original) : Video(original){
	/*
	this->name = original.name;
	this->absolute_path = original.absolute_path;
	this->duration = original.duration;
	*/
	this->number_of_chapters = original.number_of_chapters;
	if(original.markers){
		this->markers = new int[number_of_chapters];
		for (int chapter = 0; chapter < number_of_chapters; ++chapter) {this->markers[chapter] = original.markers[chapter];}
	}
	else {this->markers = nullptr;}
}

/*!
 * operator= pour l'affectation : othercar = original_car;
 * @param original
 * @return the address of a new movie object, created as a deepcopy of the original one.
 */
Movie& Movie::operator=(const Movie& original){
	Video::operator=(original);//to paste original data which is OK (not pointed, but deeply copyied)
	this->number_of_chapters = original.number_of_chapters;
	if(this->markers && original.markers){
		this->markers = new int[number_of_chapters];
		for (int chapter = 0; chapter < number_of_chapters; ++chapter) {markers[chapter] = original.markers[chapter];}
	} else {
		delete this->markers;
		if (original.markers) {
			this->markers = new int[number_of_chapters];
			for (int chapter = 0; chapter < number_of_chapters; ++chapter) {markers[chapter] = original.markers[chapter];}
		}
		else {this->markers = nullptr;}
	}
	return * this;
}

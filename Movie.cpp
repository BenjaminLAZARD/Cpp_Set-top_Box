/*! \file */
/*!
 * \fn Movie::Movie(const string absolute_path, float duration, int* markers)
 * \param markers an array of integers corresponding to the beginning of the different chapters.
 */

#include "Movie.h"

using namespace std;

Movie::Movie(const string absolute_path, float duration, int* markers, int number_of_chapters) : Video(absolute_path, duration){
	this->medium_type = MOVIE_MEDIUM_TYPE;//!< Value defined in global_constants.cpp ( should be "movie")

	//initialisation of values to avoid warnings.
	this->markers = new int;
	this->number_of_chapters = 0;

	//setting up these values.
	this->setMarkers(markers, number_of_chapters);
}


void Movie::setMarkers(int* markers, int number_of_chapters){
	this->number_of_chapters = number_of_chapters;//!< length of the array divided by the length of the first item.

	//!<deep copy of markers into the object to ensure encapsulation.
	this->markers = new int[number_of_chapters]; //markers is a pointer, and number_of_chapters an array of integers
	for (int chapter = 0; chapter < number_of_chapters; ++chapter) {this->markers[chapter] = markers[chapter];}
}

int* Movie::getMarkers() const {
	int* markers_copy = new int[number_of_chapters];
	for (int chapter = 0; chapter < number_of_chapters; ++chapter) {markers_copy[chapter] = markers[chapter];}
	return markers_copy;
}

Chapters_data Movie::getChaptersData() const {
	return (Chapters_data){this->getMarkers(), this->number_of_chapters};
}

void Movie::printMarkers(ostream& stream) const {
	for (int chapter = 0; chapter < number_of_chapters; ++chapter) {
		stream << "chapter n° " << chapter << ", index = " << markers[chapter] << "\n";
	}
	stream << "Total number of chapters = " << number_of_chapters << "\n" << endl;
}

void Movie::printMediumData(ostream& stream) const {Video::printMediumData(stream); printMarkers(stream);}

/*!
 * copy constructor pour l'initialisation : Car othercar(original_car);
 * @param original
 * @return construct a new movie object, created as a deepcopy of the original one.
 */
Movie::Movie(const Movie& original) : Video(original){
	this->number_of_chapters = original.number_of_chapters; // "." and not "->" : why ?
	if(original.markers){
		this->markers = new int(number_of_chapters);
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
		//this->markers = new int(number_of_chapters);
		for (int chapter = 0; chapter < number_of_chapters; ++chapter) {*(markers + chapter) = *(original.markers + chapter);}
	} else {
		delete this->markers;
		if (original.markers) {
			//this->markers = new int(number_of_chapters);
			for (int chapter = 0; chapter < number_of_chapters; ++chapter) {markers[chapter] = original.markers[chapter];}
		}
		else {this->markers = nullptr;}
	}
	return * this;
}

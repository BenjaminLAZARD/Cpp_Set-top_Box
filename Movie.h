/*!
 * \file
 * \brief  A video with refined options
 * \author Benjamin LAZARD
 * \date   7 déc. 2016
 *
 * A movie is basically a video with chapters.
 */

#ifndef MOVIE_H_
#define MOVIE_H_

#include "Video.h"

extern string MOVIE_MEDIUM_TYPE;//!<used as global variable, defined in global_constants.cpp

struct Chapters_data {
	int* markers;
	int number_of_chapters;
};

class Movie : public Video {
	private:
		int* markers;
		int number_of_chapters;

	public:
		Movie():Video("", 0){ medium_type = MOVIE_MEDIUM_TYPE ; markers = new int; number_of_chapters = 0; }
		//Attention : possible ambiguity entre "movie" et video pour le "medium type".
		Movie(const string absolute_path, float duration, int* markers, int number_of_chapters);
		~Movie(){delete markers;}//!<We need to suppress the objects that are only pointed by this class, yet specific to it

		virtual int* getMarkers() const	final;
		virtual int getNumberOfChapters() const	final{return number_of_chapters;}
		virtual Chapters_data getChaptersData() const final;

		virtual void setMarkers(int* markers, int number_of_chapters) final;

		void printMediumData(ostream& stream) const override; //virtual property is inherited from grand-father
		virtual void printMarkers (ostream& stream) const final;

		//Let us redefine the copy of movie objects to guaranty full control of markers
		Movie(const Movie& original);
		Movie& operator=(const Movie& original);
};

#endif /* MOVIE_H_ */

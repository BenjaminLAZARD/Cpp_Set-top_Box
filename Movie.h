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

//extern string MOVIE_MEDIUM_TYPE;//!<used as global variable, defined in global_constants.cpp

// todo : suppress this structure, and the functions attached to it.
struct Chapters_data {
	const int* markers;
	int number_of_chapters;
};

class Movie : public Video {
	private:
		int* markers = nullptr;
		int number_of_chapters = 0;

	public:
		Movie():Video(){markers = nullptr; number_of_chapters = 0; }
		//Attention : possible ambiguity entre "movie" et video pour le "medium type".
		Movie(const string name, const string absolute_path="", float duration=0,
				const int* markers=nullptr, int number_of_chapters=0);
		~Movie(){delete[] markers;}//!<We need to suppress the objects that are only pointed by this class, yet specific to it

		virtual const int* getMarkers() const	final;
		virtual int getNumberOfChapters() const	final{return number_of_chapters;}
		virtual Chapters_data getChaptersData() const final;

		virtual void setMarkers(const int* markers, int number_of_chapters) final;

		void printMediumData(ostream& stream) const override; //virtual property is inherited from grand-father
		virtual void printMarkers (ostream& stream) const final;

		//Let us redefine the copy of movie objects to guaranty full control of markers
		Movie(const Movie& original);
		Movie& operator=(const Movie& original);
};

#endif /* MOVIE_H_ */

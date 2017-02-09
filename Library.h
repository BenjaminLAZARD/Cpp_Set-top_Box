/*!
 * \file
 * \brief  A library to enable the user to add media objects, search through it, and play them.
 * \author Benjamin LAZARD
 * \date   9 jan. 2016
 *
 * This library corresponds to the average browser such as itunes, windowsmediaplayer, or any smartphone integrated app.
 */

#ifndef LIBRARY_H
#define LIBRARY_H

//this object must know all the possible things it is supposed to be storing
#include "Mediaobject.h"
#include "Picture.h"
#include "Video.h"
#include "Movie.h"
#include "Album.h"

#include <iostream>
#include <string>
#include <stdlib.h>
#include <memory>
#include <map>

using namespace std;
using moptr = shared_ptr<Media_object>;
using aptr = shared_ptr<Album>;
using media_map = map<string, moptr>;
using album_map = map<string, aptr>;

class Library{
private:
    media_map mediaobjects_table;
    album_map albums_table;
public:
    Library(){}
    virtual ~Library(){}

    virtual shared_ptr<Picture> createPicture(const string name, const string absolute_path= "", float width = 0, float height = 0) final;
    virtual shared_ptr<Video> createVideo(const string name, const string absolute_path = "", float duration = 0) final;
    virtual shared_ptr<Movie> createMovie(const string name, const string absolute_path="", float duration=0,
                              const int* markers=nullptr, int number_of_chapters=0) final;
    virtual shared_ptr<Album> createAlbum(string _albumName) final;

    /**
     * The 2 functions below would be better off, if they were "const",
     * since they are not supposed to modify data, but it is not compatible
     * with the non-const argument returned by map::find()
     **/
    virtual void searchByName(const string name, ostream &stream) final;
    virtual void playMedium(const string _name, ostream &stream) final;
    virtual void deleteMedium(const string name, ostream &stream) final;
    virtual void deleteAlbum(const string name, ostream &stream) final;
};
#endif // LIBRARY_H

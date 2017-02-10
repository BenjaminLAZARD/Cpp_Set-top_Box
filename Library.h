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
#include "tcpserver.h"

#include <iostream>
#include <string>
#include <sstream>
#include <stdlib.h>
#include <memory>
#include <map>
#include <typeinfo> // to retrieve the name of the class of the objects stored in the library

using namespace std;
using namespace cppu;
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

    /**
     * @brief process any request made by an exterior client, codified in a specific way.
     * @param cnx
     * @param request
     * @param response
     * @return status of the treatment of the query
     *
     * 2 actions are possible:
     * --search for an element and display it
     * --play a media_object
     */
    virtual bool processRequest(TCPConnection& cnx, const string& request, string& response) final;

    virtual bool saveToFile(const string & fileName) const final;
    virtual bool readFromFile(const string & fileName) const final;
};
#endif // LIBRARY_H

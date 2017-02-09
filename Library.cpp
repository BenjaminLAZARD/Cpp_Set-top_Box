/*!
 * \file
 * \brief  A library to enable the user to add media objects, search through it, and play them.
 * \author Benjamin LAZARD
 * \date   9 jan. 2016
 *
 * This library corresponds to the average browser such as itunes, windowsmediaplayer, or any smartphone integrated app.
 */

#include "Library.h"

using namespace std;
using media_iterator = map<string, shared_ptr<Media_object>>::iterator;
using album_iterator = map<string,  shared_ptr<Album>>::iterator;

//Library::Library(){}
//Library::~Library(){}

shared_ptr<Picture> Library::createPicture(const string name, const string absolute_path, float width, float height){
    //Picture* temp = new Picture(name, absolute_path, width, height);
    shared_ptr<Picture> temp(new Picture(name, absolute_path, width, height));
    mediaobjects_table[name] = temp;
    return temp;
}

shared_ptr<Video> Library::createVideo(const string name, const string absolute_path, float duration){
    //Video* temp = new Video(name, absolute_path, duration);
    shared_ptr<Video> temp(new Video(name, absolute_path, duration));
    mediaobjects_table[name] = temp;
    return temp;
}

shared_ptr<Movie> Library::createMovie(const string name, const string absolute_path, float duration,
                          const int* markers, int number_of_chapters){
    //Movie* temp = new Movie(name, absolute_path, duration, markers, number_of_chapters);
    shared_ptr<Movie> temp(new Movie(name, absolute_path, duration, markers, number_of_chapters));
    mediaobjects_table[name] = temp;
    return temp;
}

shared_ptr<Album> Library::createAlbum(string albumName){
    //Album* temp = new Album(albumName);
    shared_ptr<Album> temp(new Album(albumName));
    albums_table[albumName] = temp;
    return temp;
}

void Library::searchByName(const string name, ostream &stream){
    media_iterator mi = mediaobjects_table.find(name);
    album_iterator ai = albums_table.find(name);

    bool media = true; bool album = true;
    if(mi == mediaobjects_table.end()){media = false;}
    if(ai == albums_table.end()){album = false;}

    if (media) { stream<<"one medium was found"<<endl; (mi->second)->printMediumData(stream);}    //print the appropriate media
    if (album) { stream<<"one album was found"<<endl; (ai->second)->print(stream);}   //print the appropriate media
    if(!media && !album){stream<<"this element could not be found"<<endl;}
}

void Library::playMedium(const string name, ostream &stream){
    media_iterator mi = mediaobjects_table.find(name);
    bool media = true;
    if(mi == mediaobjects_table.end()){media = false;}

    if (media) { stream<<"one medium was found"<<endl; (mi->second)->play();}
    else {stream<<"this element could not be found"<<endl;}
}

void Library::deleteMedium(const string name, ostream &stream){
    //iterate through albums to find this medium and delete it
    //
    //
    //
    //delete it from mediumobject table
    media_iterator mi = mediaobjects_table.find(name);
    if(mi == mediaobjects_table.end()){stream<<"medium was not found"<<endl;}
    else{
        mediaobjects_table.erase(mi);
        stream<<"this element was successfully deleted"<<endl;
    }
    //it should then be distroyed entirely because of smartpointers
}

void Library::deleteAlbum(const string name, ostream &stream){
    album_iterator ai = albums_table.find(name);
    if (ai == albums_table.end()) { stream<<"medium was not found"<<endl;}
    else {
        albums_table.erase(ai);
        stream<<"this element was successfully deleted"<<endl;
    }
    //it should then be distroyed entirely because of smartpointers
}

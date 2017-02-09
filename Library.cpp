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

    if (media) { stream<<"one medium was found    "   ;//<<endl;
        (mi->second)->printMediumData(stream);//print the appropriate media
    }
    if (album) { stream<<"one album was found    "   ;//<<endl;
        (ai->second)->print(stream); //print the appropriate media
    }
    if(!media && !album){stream<<"this element could not be found"<<endl;}
}

void Library::playMedium(const string name, ostream &stream){
    media_iterator mi = mediaobjects_table.find(name);
    bool media = true;
    if(mi == mediaobjects_table.end()){media = false;}

    if (media) {
        stream<<"one medium was found   " ;//<<endl;
        (mi->second)->play();}
    else {stream<<"this element could not be found"<<endl;}
}

void Library::deleteMedium(const string name, ostream &stream){
    //iterate through albums to find this medium and delete it
    //
    //
    //
    //delete it from mediumobject table
    media_iterator mi = mediaobjects_table.find(name);
    if(mi == mediaobjects_table.end()){stream<<"medium was not found " ;// <<endl;
    }
    else{
        mediaobjects_table.erase(mi);
        stream<<"this element was successfully deleted"<<endl;
    }
    //it should then be distroyed entirely because of smartpointers
}

void Library::deleteAlbum(const string name, ostream & stream){
    album_iterator ai = albums_table.find(name);
    if (ai == albums_table.end()) { stream<<"medium was not found"<<endl;}
    else {
        albums_table.erase(ai);
        stream<<"this element was successfully deleted"<<endl;
    }
    //it should then be distroyed entirely because of smartpointers
}

bool Library::processRequest(TCPConnection& cnx, const string& request, string& response){
    //print the request that has just been made
    cerr << "\nRequest: '" << request << "'" << endl;
    response= "";//let us fix the response


    //First let us analyse the query.
    //Suppose the request is either "SEARCH$<title>" or "PLAY$<title>" or "QUIT$ ". We just hav to parse that.
    istringstream stream(request); ostringstream pre_response; //get input and output as streams
    string order; string title; //store the data from the request
    getline(stream, order, '$'); getline(stream, title, '$');



    //Now let us process this data
    TCPLock lock(cnx);//lock while reading the library (in case of multiple client-threads)
    // if we modify data, we have to put a writing lock : // TCPLock lock(cnx, true);

    //if(title == "NULL"){title = "";} //eliminate mistake when title is forgotten
    if(order == "SEARCH"){
        searchByName(title, pre_response); //get the results of previously defined searchByName function

    } else if (order == "PLAY") {
        playMedium(title, pre_response);//get the results of previously defined searchByName function + plays music in the library

    } else if (order == "QUIT"){
        response = "OK, it was nice seing you";
        return false; //this will close the connection
    } else {
        response = "Sorry buddy, but there is a problem in your query!";
        return true;
    }


    //Eventually, let us return our response  // be wary of  \n and \r as server-client communication would be impacted
    if (response == "") {response =  pre_response.str();}//converts the stream obtained into a string
    cerr << "response: " << response << endl;

    return true;
}

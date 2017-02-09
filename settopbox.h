/*!
 * \file
 * \brief  The media server that will display the tree of media, and play them alltogether
 * \author Benjamin LAZARD
 * \date   7 fév. 2016
 *
 *This is a set-top box, and there is not much else to say
 */

#ifndef SETTOPBOX_H
#define SETTOPBOX_H

#include "settopbox.h"
#include <memory>
#include <string>
#include <iostream>
#include <sstream>
#include "tcpserver.h"
#include "Library.h"

using namespace std;
using namespace cppu;

class SetTopBox{
private:
    Library lib;
public:
    SetTopBox(): lib(new Library()) {}
    virtual ~SetSetTopBox();
    bool processRequest(TCPConnection& cnx, const string& request, string& response);

};

#endif // SETTOPBOX_H

//
// Created by Pedro Soares on 12/10/16.
//

#include "File.h"
#include <sys/stat.h>
#include <fstream>

Tigre::File::File(Tigre::String path) {
    this->path = path;
}

Tigre::File::~File() {

}

Tigre::String Tigre::File::getFileContent() {
    if(Tigre::File::Exists(this->path) && !Tigre::File::IsFolder(this->path)) {
        std::string getdata = "";

        int cont = 0;

        std::fstream data;

        data.open(this->path.getValue().c_str(), std::ios::in);

        Tigre::String output = "";

        while (!data.eof()) {
            getline(data, getdata);
            output += getdata;
        }
        return output;
    }
}

bool Tigre::File::Exists(Tigre::String path) {
    if (FILE *file = fopen(path.getValue().c_str(), "r")) {
        fclose(file);
        return true;
    }
    return false;
}

bool Tigre::File::IsFolder(Tigre::String path) {
    struct stat s;
    if( stat(path.getValue().c_str(),&s) == 0 ) {
        if( s.st_mode & S_IFDIR ) {
            return true;
        } else if( s.st_mode & S_IFREG ) {
            return false;
        }
    } else {
        throw new FileException("File or Directory don`t exists.");
    }
}
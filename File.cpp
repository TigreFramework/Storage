//
// Created by Pedro Soares on 12/10/16.
//

#include "File.h"
#include <sys/stat.h>


bool Tigre::File::Exists(Tigre::String path) {
    if (FILE *file = fopen(path..getValue().c_str(), "r")) {
        fclose(file);
        return true;
    }
    return false;
}

bool Tigre::File::IsFolder(Tigre::String path) {
    struct stat s;
    if( stat(path.c_str(),&s) == 0 ) {
        if( s.st_mode & S_IFDIR ) {
            return true;
        } else if( s.st_mode & S_IFREG ) {
            return false;
        }
    } else {
        throw new FileException("File or Directory don`t exists.");
    }
}
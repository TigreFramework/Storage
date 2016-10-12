//
// Created by Pedro Soares on 12/10/16.
//

#ifndef STORAGE_FILE_H
#define STORAGE_FILE_H

#include <string>

namespace Tigre {
    class FileException : public std::exception {
    public:
        /** Constructor (C strings).
         *  @param message C-style string error message.
         *                 The string contents are copied upon construction.
         *                 Hence, responsibility for deleting the \c char* lies
         *                 with the caller.
         */
        explicit FileException(const char* message):
                msg_(message)
        {
        }

        /** Constructor (C++ STL strings).
         *  @param message The error message.
         */
        explicit FileException(const std::string& message):
                msg_(message)
        {}

        /** Destructor.
         * Virtual to allow for subclassing.
         */
        virtual ~FileException() throw (){}

        /** Returns a pointer to the (constant) error description.
         *  @return A pointer to a \c const \c char*. The underlying memory
         *          is in posession of the \c Exception object. Callers \a must
         *          not attempt to free the memory.
         */
        virtual const char* what() const throw (){
            return msg_.c_str();
        }

    protected:
        /** Error message.
         */
        std::string msg_;

    };

    class File {
        public:
            static bool Exists(std::string path);
            static bool IsFolder(std::string path);

    };
};


#endif //STORAGE_FILE_H

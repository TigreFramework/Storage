#include <iostream>
#include "File.h"

using namespace std;

int main() {
    cout << "Hello, World!" << endl;
    cout << Tigre::File::Exists("/Users/pedrosoares/teste.txt") << "\n";
    cout << Tigre::File::IsFolder("/") << "\n";
    return 0;
}
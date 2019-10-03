#include "file.h"

/**
 *  这个部分是 mydiff
 *      compares two files named as parameters
 *
 *  /Users/zaumukcau/Downloads/testing_3307/file1.txt /Users/zaumukcau/Downloads/file6.txt
 */
int main(int argc, char *argv[]) {
    file compare_object1 = file(argv[1]);
    file compare_object2 = file(argv[2]);
    if (compare_object1.compare(compare_object2) == 1){
        cout << "They are the same!" << endl;
    } else {
        cout << "They are not the same!" << endl;
    }

    return 0;
}
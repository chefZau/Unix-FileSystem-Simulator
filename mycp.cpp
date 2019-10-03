//
// Created by 周牧秋 on 2019/10/2.
//
#include "file.h"
/**
 * mycp
 *      make a copy of a file from a source
 *      Parameter: destination named as parameters
 *      The dump method from above should work nicely for this on its own
 *
 *      /Users/zaumukcau/Downloads/testing_3307/file1.txt /Users/zaumukcau/Downloads/file1.txt
 * @param argc
 * @param argv
 * @return
 */
inline bool exists_test3 (const std::string& name);

inline bool exists_test3 (const std::string& name) {
    struct stat buffer;
    return (stat (name.c_str(), &buffer) == 0);
}

int main( int argc, char *argv[] ){
    file source_file = file(argv[1]);
    if (exists_test3(argv[2]) == -1){
        cout << " hhh  dsfadsa" << endl;
        std::ofstream file1(argv[2]);
        std::string data("data to write to file");
        file1 << data;
    }


    file dest_file = file(argv[2]);

    std::filebuf outfile;
    outfile.open(dest_file.get_name().c_str(), std::ios::out | std::ios::binary);
    std::fstream out_file(dest_file.get_name().c_str(), std::ios::out | std::ios::binary);
    source_file.dump(out_file);
    outfile.close();

    return 0;
}

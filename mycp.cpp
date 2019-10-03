//
// Created by 周牧秋 on 2019/10/2.
//
#include "file.h"
/**
 * mycp
 *      make a copy of a file from a source
 *      Parameter: destination named as parameters
 *      The dump method from above should work nicely for this on its own
 * @param argc
 * @param argv
 * @return
 */
int main( int argc, char *argv[] ){

    if ( argc < 3 ) {
        printf("Two argument expected.\n");
        exit(0);
    }

    file source_file = file(argv[1]);
    file dest_file = file(argv[2]);

    std::filebuf outfile;
    outfile.open(dest_file.get_name().c_str(), std::ios::out | std::ios::binary);
    std::fstream out_file(dest_file.get_name().c_str(), std::ios::out | std::ios::binary);
    source_file.dump(out_file);
    out_file.close();
    return 0;
}
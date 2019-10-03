//
// Created by 周牧秋 on 2019/10/2.
//
#include "file.h"
/**
 * mymv
 *      move and rename files around
 *      use the rename method of your class from above to do this.
 *      if EXDEV error or other error
 *          indicating that the source and destination are on different file
 *          systems, you should try to use the dump and remove methods to
 *          copy the file and then remove the original instead.
 *
 *      you only have to do this copy-delete alternative for regular files;
 *
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
    source_file.rename(argv[2]);
    int error_num = errno;

    if (error_num == EXDEV) {
        std::filebuf outfile;
        outfile.open(dest_file.get_name().c_str(), std::ios::out | std::ios::binary);
        std::fstream out_file(dest_file.get_name().c_str(), std::ios::out | std::ios::binary);
        source_file.dump(out_file);
        out_file.close();
        source_file.remove();
    }


    return 0;
}
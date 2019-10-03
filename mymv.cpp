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
int main(int argc, char *argv[]) {
//
//        char cwd[256];
//
//        if (chdir("/tmp") != 0)
//            perror("chdir() error()");
//        else {
//            if (getcwd(cwd, sizeof(cwd)) == NULL)
//                perror("getcwd() error");
//            else
//                printf("current working directory is: %s\n", cwd);
//        }

    /**
    * 这个部分是 mymv 从一个location mv到另外一个location
    * 两个argument
    *
    * /Users/zaumukcau/Downloads/testing_3307/file1.txt /Users/zaumukcau/Downloads/file6.txt
    */
    file source_file = file(argv[1]);
    source_file.rename(argv[2]);

    int error_num = errno;

    if (error_num == EXDEV) {
        std::filebuf outfile;
        outfile.open(argv[2], std::ios::out | std::ios::binary);
        std::fstream out_file(argv[2], std::ios::out | std::ios::binary);
        source_file.dump(out_file);
        out_file.close();
        source_file.remove();
    }


    return 0;
}
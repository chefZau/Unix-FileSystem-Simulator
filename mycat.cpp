//
// Created by 周牧秋 on 2019/10/2.
//
#include "file.h"

/**
 * mycat
 *      display the contents of all of the files given as parameters to the command to the terminal.
 *      need to support more than one file as the original command does.
 *
 *      Your dump function from above should help you do this as well.  This should work fine for text files
 *
 * @param argc
 * @param argv
 * @return
 */
int main(int argc, char *argv[]) {

    for (int i = 1 ; i < argc; ++i){
        file source_file = file(argv[i]);
        std::cout << std::ifstream(source_file.get_name()).rdbuf();
        cout << '\n';
    }

    return 0;
}

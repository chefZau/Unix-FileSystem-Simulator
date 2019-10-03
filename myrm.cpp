//
// Created by 周牧秋 on 2019/10/2.
//
#include "file.h"

/**
 * myrm
 *      removes the given files listed as parameters to this command.
 *      using the remove method you have implemented above. 
 *
 * @param argc
 * @param argv
 * @return
 */
int main( int argc, char *argv[] ){

    file trash_file = file(argv[1]);
    trash_file.remove();

    return 0;
}
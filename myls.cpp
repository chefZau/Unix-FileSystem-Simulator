#include "file.h"

/**
 *  这个部分是 myls
 *      Only For a directory
 *      list the contents of the directory
 *      also implement a "-l" option for this command
 */
int main(int argc, char *argv[]) {

    if (argc == 1){
        char current_directory[] = ".";
        file directory = file(current_directory);
        directory.expand();
        vector<file> child = directory.get_children();
        for (int i = 0; i < child.size()-1; i++) {
            cout << child[i].get_name() << endl;
        }
        return 0;
    }

    char option[] = "-l";
    if (strcmp(argv[1], option) == 0) {
        char current_directory[] = ".";
        file directory = file(current_directory);

        directory.expand();

        vector<file> child = directory.get_children();
        for (int i = 0; i < child.size(); i++) {
            child[i].ls_helper();
        }
        cout << '\n';
        return 0;
    }

    file directory = file(argv[1]);
    directory.expand();
    vector<file> child = directory.get_children();
    for (int i = 0; i < child.size(); i++) {
        child[i].ls_helper();
    }
    cout << '\n';

    return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <time.h>
#include <string.h>
#include <pwd.h>
#include <grp.h>
#include <errno.h>
#include <fcntl.h>
#include <dirent.h>
#include <iostream>
#include <fstream>
#include <vector>
#include <cstdio>
#include <algorithm>
#include <cstdlib>
#include <iterator>

#ifndef FILE_FILE_H
#define FILE_FILE_H
using namespace std;

string get_file_type(struct stat st);

char *permissions(char *file);

class file {

protected:
    string name, owner_name, group_name, type, permission;
    off_t size;
    uid_t owner_id;
    gid_t group_id;
    blksize_t block_size;
    string last_access_time;
    string last_modify_time;
    string last_status_change;
    int errno_num;
    vector<file> children;

public:
    file(char *filename);

    ~file(){}

    void dump(std::fstream &ofile);

    void rename(string new_name);

    void remove();

    bool compare(file compare_object);

    void expand();

    string get_name();

    string get_owner_name();

    string get_group_name();

    string get_type();

    string get_permission();

    off_t get_size();

    uid_t get_owner_id();

    gid_t get_group_id();

    blksize_t get_block_size();

    string get_last_access_time();

    string get_last_modify_time();

    string get_last_status_change();

    int get_errno_num();

private:
    string get_file_type(struct stat st);

    char *permissions(char *file);
};


#endif //FILE_FILE_H

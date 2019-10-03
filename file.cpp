#include "file.h"

file::file(char *filename) {
    struct stat st;
    struct passwd *my_info;
    struct group *grp;

    if (stat(filename, &st) != 0){
        perror("stat() error");
    }

    my_info = getpwuid(st.st_uid);
    grp = getgrgid(st.st_gid);

    this->name = (string) filename;
    this->owner_name = my_info->pw_name;
    this->group_name = grp->gr_name;
    this->type = get_file_type(st);
    this->size = st.st_size;
    this->owner_id = st.st_uid;
    this->group_id = st.st_gid;
    this->permission = permissions(filename);
    this->block_size = st.st_blksize;

    this->last_access_time = st.st_atime;
    this->last_modify_time = st.st_mtime;
    this->last_status_change = st.st_ctime;

    this->errno_num = 0;
}

int file::dump(std::fstream &out_file) {

    if (this->type != "regular file") {
        errno = ENOTSUP;
        perror("dump(..) error");
        return errno;
    }

    std::fstream in_file(this->name.c_str(), std::ios::in | std::ios::binary | std::ios::ate);
    size_t size = in_file.tellg();
    char *buffer = new char[size];
    in_file.seekg(0, std::ios::beg);
    in_file.read(buffer, size);
    out_file.write(buffer, size);
    in_file.close();

    return 0;
}

void file::rename(string new_name) {
    string old_name = this->name;
    int result = std::rename(old_name.c_str(), new_name.c_str());
    if (result == 0) {
        cout << "File successfully moved" << endl;
    } else {
        errno = ENOENT;
        cout << "Error renaming file" << " please include whole path." << endl;
//        return errno;
    }
}

void file::remove() {
    int file_descriptor;
    if ((file_descriptor = creat(this->name.c_str(), S_IWUSR)) < 0)
        perror("creat() error");
    else {
        close(file_descriptor);
        if (unlink(this->name.c_str()) != 0)
            perror("unlink() error");
        else {
            cout << "ok remove it already!" << endl;
        }
    }
}

bool file::compare(file compare_object) {
    std::ifstream lFile(this->name.c_str(), std::ios::in | std::ios::binary);
    std::ifstream rFile(compare_object.name.c_str(), std::ios::in | std::ios::binary);

    if (!lFile.is_open() || !rFile.is_open()) {
        return false;
    }

    blksize_t temp_block_size = this->block_size;
    char *lBuffer = new char[temp_block_size]();
    char *rBuffer = new char[temp_block_size]();
    do {
        lFile.read(lBuffer, temp_block_size);
        rFile.read(rBuffer, temp_block_size);

        if (memcmp(lBuffer, rBuffer, temp_block_size) != 0) {
            delete[] lBuffer;
            delete[] rBuffer;
            return false;
        }
    } while (lFile.good() || rFile.good());

    delete[] lBuffer;
    delete[] rBuffer;
    return true;
}

int file::expand() {

    if (this->type != "directory") {
        cout << "This is not a directory" << endl;
        errno = ENOENT;
        return errno;
    }

    DIR *dir;
    char path[1025];
    struct dirent *entry;

    const char *dirname = this->name.c_str();

    if ((dir = opendir(dirname)) == NULL) {
        perror("opendir() error");
    } else {
        while ((entry = readdir(dir)) != NULL) {
            if (entry->d_name[0] != '.') {
                strcpy(path, dirname);
                strcat(path, "/");
                strcat(path, entry->d_name);
                this->children.emplace_back(file(path));
            }
        }
        cout << "the number of files in this folder is: " << this->children.size() << endl;

        closedir(dir);
    }
    return 0;
}

string file::get_name() {
    return this->name;
}

string file::get_owner_name() {
    return this->owner_name;
}

string file::get_group_name() {
    return this->group_name;
}

string file::get_type() {
    return this->type;
}

string file::get_permission() {
    return this->permission;
}

off_t file::get_size() {
    return this->size;
}

uid_t file::get_owner_id() {
    return this->owner_id;
}

gid_t file::get_group_id() {
    return this->group_id;
}

blksize_t file::get_block_size() {
    return this->block_size;
}

time_t file::get_last_access_time() {
    return this->last_access_time;
}

time_t file::get_last_modify_time() {
    return this->last_modify_time;
}

time_t file::get_last_status_change() {
    return this->last_status_change;
}

int file::get_errno_num() {
    return this->errno_num;
}

string file::get_file_type(struct stat st) {
    string type;
    switch (st.st_mode & S_IFMT) {
        case S_IFBLK:
            type = "block device";
            break;
        case S_IFCHR:
            type = "character device";
            break;
        case S_IFDIR:
            type = "directory";
            break;
        case S_IFIFO:
            type = "FIFO/pipe";
            break;
        case S_IFLNK:
            type = "symlink";
            break;
        case S_IFREG:
            type = "regular file";
            break;
        case S_IFSOCK:
            type = "socket";
            break;
        default:
            type = "unknown?";
            break;
    }
    return type;
}

char *file::permissions(char *file) {
    struct stat st;
    char *modeval = (char *) malloc(sizeof(char) * 9 + 1);
    if (stat(file, &st) == 0) {
        mode_t perm = st.st_mode;
        modeval[0] = (perm & S_IRUSR) ? 'r' : '-';
        modeval[1] = (perm & S_IWUSR) ? 'w' : '-';
        modeval[2] = (perm & S_IXUSR) ? 'x' : '-';
        modeval[3] = (perm & S_IRGRP) ? 'r' : '-';
        modeval[4] = (perm & S_IWGRP) ? 'w' : '-';
        modeval[5] = (perm & S_IXGRP) ? 'x' : '-';
        modeval[6] = (perm & S_IROTH) ? 'r' : '-';
        modeval[7] = (perm & S_IWOTH) ? 'w' : '-';
        modeval[8] = (perm & S_IXOTH) ? 'x' : '-';
        modeval[9] = '\0';
        return modeval;
    }
    else {
        return strerror(errno);
    }
}


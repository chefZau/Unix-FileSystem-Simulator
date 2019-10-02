#include "file.h"

int main(int argc, char const *argv[]) {
    char filename1[] = "/Users/zaumukcau/Downloads/testing_3307/file1.txt";
    char filename2[] = "/Users/zaumukcau/Downloads/testing_3307/file2.txt";
    file p1 = file(filename1);
    file p2 = file(filename2);

    char filename3[] = "/Users/zaumukcau/Downloads/testing_3307";
    file p3 = file(filename3);
    // cout << "p3: " << p3.name << endl;
    // cout << "p3: " << p3.type << endl;

    p3.expand();

    // ofstream file(filename1);
    // std::filebuf outfile;
    // outfile.open(filename1, std::ios::out | std::ios::binary);
    // std::fstream ofile(filename1, std::ios::out | std::ios::binary);
    // p2.dump(ofile);
    // ofile.close();

    cout << "comparing file 1 with file 2, 1 is true and 0 is false: " << p1.compare(p2) << endl;

    cout << "name: " << p1.get_name() << endl;
    cout << "owner name: " << p1.get_owner_name() << endl;
    cout << "group name: " << p1.get_group_name() << endl;
    cout << "type: " << p1.get_type() << endl;
    cout << "size: " << p1.get_size() << endl;
    cout << "owner id: " << p1.get_owner_id() << endl;
    cout << "group id: " << p1.get_group_id() << endl;
    cout << "permmsion: " << p1.get_permission() << endl;
    cout << "block size: " << p1.get_block_size() << endl;
    cout << "last access time: " << p1.get_last_access_time() << endl;
    cout << "last modify time: " << p1.get_last_modify_time() << endl;
    cout << "last status change: " << p1.get_last_status_change() << endl;
    cout << "errno num: " << p1.get_errno_num() << endl;

    return 0;
}
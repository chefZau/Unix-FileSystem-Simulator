#include "file.h"

int main(int argc,  char *argv[]) {


    /**
     * 这个部分是 mycp 的 要声名两个参数
     * /Users/zaumukcau/Downloads/testing_3307/file1.txt /Users/zaumukcau/Downloads/file1.txt
     */
    //    file source_file = file(argv[1]);
    //    file dest_file = file(argv[2]);
    //    std::filebuf outfile;
    //    outfile.open(dest_file.get_name().c_str(), std::ios::out | std::ios::binary);
    //    std::fstream out_file(dest_file.get_name().c_str(), std::ios::out | std::ios::binary);
    //    source_file.dump(out_file);
    //    out_file.close();


    /**
     * 这个部分是 myrm
     */
    //    file trash_file = file(argv[2]);
    //    trash_file.remove();

    /**
     * 这个部分是 mymv 从一个location mv到另外一个location
     * 两个argument
     *
     * /Users/zaumukcau/Downloads/testing_3307/file1.txt /Users/zaumukcau/Downloads/file6.txt
     */
    //    file source_file = file(argv[1]);
    //    source_file.rename(argv[2]);
    //
    //    int error_num = errno;
    //
    //    if (error_num == EXDEV) {
    //        std::filebuf outfile;
    //        outfile.open(argv[2], std::ios::out | std::ios::binary);
    //        std::fstream out_file(argv[2], std::ios::out | std::ios::binary);
    //        source_file.dump(out_file);
    //        out_file.close();
    //        source_file.remove();
    //    }

    /**
     *  这个部分是 mydiff
     *      compares two files named as parameters
     *
     *  /Users/zaumukcau/Downloads/testing_3307/file1.txt /Users/zaumukcau/Downloads/file6.txt
     */
    //    file compare_object1 = file(argv[1]);
    //    file compare_object2 = file(argv[2]);
    //    if (compare_object1.compare(compare_object2) == 1){
    //        cout << "They are the same!" << endl;
    //    } else {
    //        cout << "They are not the same!" << endl;
    //    }

    /**
     *  这个部分是 mycat
     *      display the contents of all of the files given as parameters to the command to the terminal.
     *      need to support more than one file as the original command does.
     *
     *      use dump function
     */




    //    char filename1[] = "/Users/zaumukcau/Downloads/testing_3307/file1.txt";
    //    char filename2[] = "/Users/zaumukcau/Downloads/testing_3307/file2.txt";
    file p1 = file(argv[1]);
    file p2 = file(argv[2]);

    //    cout << "the path is: " << p1.file_path() << endl;

    char filename3[] = "/Users/zaumukcau/Downloads/testing_3307";
    file p3 = file(filename3);
    // cout << "p3: " << p3.name << end®l;
    // cout << "p3: " << p3.type << endl;

    p3.expand();

    //     std::filebuf outfile;
    //     outfile.open(filename1, std::ios::out | std::ios::binary);
    //     std::fstream ofile(filename1, std::ios::out | std::ios::binary);
    //
    //     p2.dump(ofile);
    //     ofile.close();

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

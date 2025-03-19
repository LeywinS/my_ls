#include "my_ls.h"

void list_directory(const char *path, options_t opts) {
    struct dirent **file_list;
    int file_count = scandir(path, &file_list, NULL, opts.t ? compare_time : compare_alpha);
    
    if (file_count < 0) {
        perror("scandir");
        return;
    }

    for (int i = 0; i < file_count; i++) {
        if (!opts.a && file_list[i]->d_name[0] == '.') continue;
        display_file_info(path, file_list[i], opts);
        free(file_list[i]);
    }
    free(file_list);
}

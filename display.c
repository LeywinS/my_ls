#include "my_ls.h"

void display_file_info(const char *path, struct dirent *entry, options_t opts) {
    if (opts.l) {
        struct stat file_stat;
        char full_path[1024];
        snprintf(full_path, sizeof(full_path), "%s/%s", path, entry->d_name);

        if (stat(full_path, &file_stat) == -1) {
            perror("stat");
            return;
        }

        printf("%c%c%c%c%c%c%c%c%c%c %ld %s %s %ld %s %s\n",
            (S_ISDIR(file_stat.st_mode)) ? 'd' : '-',
            (file_stat.st_mode & S_IRUSR) ? 'r' : '-',
            (file_stat.st_mode & S_IWUSR) ? 'w' : '-',
            (file_stat.st_mode & S_IXUSR) ? 'x' : '-',
            (file_stat.st_mode & S_IRGRP) ? 'r' : '-',
            (file_stat.st_mode & S_IWGRP) ? 'w' : '-',
            (file_stat.st_mode & S_IXGRP) ? 'x' : '-',
            (file_stat.st_mode & S_IROTH) ? 'r' : '-',
            (file_stat.st_mode & S_IWOTH) ? 'w' : '-',
            (file_stat.st_mode & S_IXOTH) ? 'x' : '-',
            file_stat.st_nlink,
            getpwuid(file_stat.st_uid)->pw_name,
            getgrgid(file_stat.st_gid)->gr_name,
            file_stat.st_size,
            ctime(&file_stat.st_mtime),
            entry->d_name);
    } else {
        printf("%s\n", entry->d_name);
    }
}

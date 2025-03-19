#include "my_ls.h"

int compare_time(const struct dirent **a, const struct dirent **b) {
    struct stat stat_a, stat_b;
    stat((*a)->d_name, &stat_a);
    stat((*b)->d_name, &stat_b);
    return (stat_b.st_mtime - stat_a.st_mtime);
}

int compare_alpha(const struct dirent **a, const struct dirent **b) {
    return strcmp((*a)->d_name, (*b)->d_name);
}

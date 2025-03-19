#ifndef MY_LS_H
#define MY_LS_H

#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/stat.h>
#include <unistd.h>
#include <pwd.h>
#include <grp.h>
#include <time.h>
#include <string.h>
#include <errno.h>

// Structure pour stocker les options
typedef struct {
    int l, R, r, d, t, a, A, L;
} options_t;

void parse_options(int argc, char *argv[], options_t *opts);
void list_directory(const char *path, options_t opts);
void display_file_info(const char *path, struct dirent *entry, options_t opts);
int compare_time(const struct dirent **a, const struct dirent **b);
int compare_alpha(const struct dirent **a, const struct dirent **b);

#endif

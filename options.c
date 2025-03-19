#include "my_ls.h"

void parse_options(int argc, char *argv[], options_t *opts) {
    int opt;
    while ((opt = getopt(argc, argv, "lRrdtaAL")) != -1) {
        switch (opt) {
            case 'l': opts->l = 1; break;
            case 'R': opts->R = 1; break;
            case 'r': opts->r = 1; break;
            case 'd': opts->d = 1; break;
            case 't': opts->t = 1; break;
            case 'a': opts->a = 1; break;
            case 'A': opts->A = 1; break;
            case 'L': opts->L = 1; break;
            default:
                fprintf(stderr, "Usage: my_ls [-lRrdtaAL] [file...]\n");
                exit(1);
        }
    }
}

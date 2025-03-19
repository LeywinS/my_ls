#include "my_ls.h"
#include <unistd.h>

int main(int argc, char *argv[]) {
    options_t opts = {0};
    parse_options(argc, argv, &opts);

    if (optind >= argc) {
        list_directory(".", opts);
    } else {
        for (int i = optind; i < argc; i++) {
            list_directory(argv[i], opts);
        }
    }
    return 0;
}

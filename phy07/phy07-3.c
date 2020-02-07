#include <stdio.h>

extern void normalize_path(char *path) {
    size_t it = 1;
    for (size_t i = 1; path[i - 1] != '\0'; ++i ){
        if (path[i] != '/' || path[i - 1] != '/') {
            path[it++] = path[i];
        }
    }
    it = 1;
    for (size_t i = 1; path[i - 1] != '\0'; ++i) {
        if (i > 1 && path[i - 2] == '.' && path[i - 1] == '.' && path[i] == '/') {
            for (; it > 0 && path[--it] != '/';);
            for (; it > 0 && path[--it] != '/';);
            ++it;
        } else if (i > 0 && path[i - 1] == '.' && path[i] == '/') {
            --it;
        } else {
            path[it++] = path[i];
        }
    }
    if (path[it - 2] == '/')
        path[it - 2] = '\0';
}
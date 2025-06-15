#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

int crtar(char *filename, char *path)
{

    struct stat path_stat;
    // check wheter is file or directory
    stat(path, &path_stat);
    printf("Creating archive: %s from %s, %s \n", filename, path, path_stat.st_mode & S_IFDIR ? "directory" : "file");
    return 0;
}
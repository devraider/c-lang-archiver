#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

char *get_path_type(char *path)
{
    struct stat path_stat;
    stat(path, &path_stat);
    return path_stat.st_mode & S_IFDIR ? "directory" : "file";
}

int crtar(char *filename, char *path)
{

    // check wheter is file or directory
    char *path_type = get_path_type(path);

    // TODO: To implement dir logic
    if (path_type == "directory")
    {

        printf("Brrr.. not implemented directory logic, yet!");
        return 1;
    }

    // read file
    printf("Creating archive: %s from %s (%s) \n", filename, path, path_type);
    return 0;
}
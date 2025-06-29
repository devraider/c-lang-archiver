#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <string.h>

char *get_path_permission(mode_t mode)
{
    static char perms[10];
    perms[0] = S_ISDIR(mode) ? 'd' : '-';
    perms[1] = (mode & S_IRUSR) ? 'r' : '-';
    perms[2] = (mode & S_IWUSR) ? 'w' : '-';
    perms[3] = (mode & S_IXUSR) ? 'x' : '-';
    perms[4] = (mode & S_IRGRP) ? 'r' : '-';
    perms[5] = (mode & S_IWGRP) ? 'w' : '-';
    perms[6] = (mode & S_IXGRP) ? 'x' : '-';
    perms[7] = (mode & S_IROTH) ? 'r' : '-';
    perms[8] = (mode & S_IWOTH) ? 'w' : '-';
    perms[9] = (mode & S_IXOTH) ? 'x' : '-';

    return perms;
}

int get_path_uid(struct stat path_stat)
{

    return path_stat.st_uid;
}

int get_path_guid(struct stat path_stat)
{
    return path_stat.st_gid;
}

// char *get_path_size(mode_t mode_t) {}
// char *get_path_modified_date(mode_t mode_t) {}
// char *get_path_checksum(mode_t mode_t) {}

char *get_path_type(struct stat path_stat)
{

    return path_stat.st_mode &
                   S_IFDIR
               ? "directory"
               : "file";
}

void file_archiever(char *path)
{
    FILE *file = fopen(path, "rb");
}

int crtar(char *filename, char *path)
{
    struct stat path_stat;
    stat(path, &path_stat);

    // check wheter is file or directory
    char *path_type = get_path_type(path_stat);
    char *path_permission = get_path_permission(path_stat.st_mode);
    int path_uid = get_path_uid(path_stat);
    int path_guid = get_path_guid(path_stat);

    // TODO: To implement dir logic
    if (strcmp(path_type, "directory") == 0)
    {

        printf("Brrr.. not implemented directory logic, yet!");
        return 1;
    }

    // read file
    printf("Creating archive: %s from %s (%s) \n", filename, path, path_type);
    printf(" Path permissions: %s \n", path_permission);
    printf(" Path User ID: %d \n", path_uid);
    printf(" Path Group ID: %d \n", path_guid);

    return 0;
}
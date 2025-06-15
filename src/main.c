#include "crtar.c"

int main(int argc, char *argv[])
{
    if (argc != 3)
    {
        fprintf(stderr, "Usage: %s <archive_name> <file_path>\n", argv[0]);
        return 1;
    }

    crtar(argv[1], argv[2]);
    return 0;
}
#include <dirent.h>
#include <errno.h>
#include <stdio.h>
#include <string.h>

int main( int argc, char *path[] ) 
{
    DIR *dir = 0;
    struct dirent *dirDes;

    if (argc == 2)
    {
        dir = opendir (path[1]);
        if (dir)
        {
            while ((dirDes = readdir(dir)) != NULL)
            {
                printf ("%s\n", dirDes->d_name);
                printf ("%d\n", dirDes->d_reclen);
            }

            closedir(dir);
        }
        else
        {
            printf ("Error during open dir!\n");
        }

    }
    else
    {
        printf ("invalid agrument!\n");
    }
    return 0;
}
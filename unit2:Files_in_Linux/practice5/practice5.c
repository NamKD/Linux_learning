#include <sys/types.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int file_exist (char *filename)
{
  struct stat   buffer;   
  return (stat (filename, &buffer) == 0);
}

int main (int argc, char *path[])
{
    struct stat st = {0};
    char tmp[1000] = {0};
    int index = 0;

    if (argc == 2)
    {
        strcpy (tmp, path[1]);
        strcat (tmp, "/libfoo.so");
        if (file_exist (tmp))
        {
            // create file foo.confg file
            system ("touch /etc/foo.conf");

            // copy libfoo.so into /usr/bin
            // reset tmp buffer and prepare console command
            strcpy (tmp, "");
            index = sprintf (tmp, "cp ");
            index += sprintf (tmp + index, path[1]);
            index += sprintf (tmp + index, "/libfoo.so");
            index += sprintf (tmp + index, " /usr/bin");
            // execute the copy
            // printf ("%s\n", tmp);
            system (tmp);
            
            // copy test into /bin
            // reset tmp buffer and prepare console command
            strcpy (tmp, "");
            index = 0;
            index = sprintf (tmp, "cp ");
            index += sprintf (tmp + index, path[1]);
            index += sprintf (tmp + index, "/test");
            index += sprintf (tmp + index, " /bin");
            // execute the copy
            // printf ("%s\n", tmp);
            system (tmp);
        }
        else
        {
            printf ("Error: The .so file is not available\n");
        }
    }
    else
    {
        printf ("Error: Missing argument!\n");
    }
}
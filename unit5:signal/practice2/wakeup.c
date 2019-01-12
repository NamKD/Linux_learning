#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h> 
#include <signal.h>

int main()
{
    int error = 0;
    int fd = 0;
    char buf [10000];
    int read_rel = 0;
    char cmd [10000];
    int index = 0;


    system("ps --no-header -o pid -C 'prac2' >> ./proceId.txt");

    fd = open("./proceId.txt",O_RDONLY);
    if ( fd > 0)
    {
        printf ("open and read proceId.\n");
        read_rel = read (fd, buf, 10000);
        if (read_rel > 0)
        {
            strcpy (cmd, "");
            index = sprintf (cmd, "kill ");
            index += sprintf (cmd + index, "-12");
            index += sprintf (cmd + index, "%s", buf);
            printf ("%s", cmd);
            system (cmd);
        }
        else
        {
            printf ("error!\n");
        }
        close(fd);
    }
    else
    {
        printf("Error during open proceId file!\n");
        error = 1;
    }



    return (error); 
}


#include <sys/types.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main ( int argc, char *path[] )
{
    char homeDir[1000] = {0};
    char cmdTerminal[1000] = {0};

    // printf ("%s\n", path[0]);
    // printf ("%s\n", path[1]);

    if (argc == 2)
    {
        // Copy path to homeDir
        strcpy (homeDir, path[1]);

        // create 'Test folder'
        strcat (homeDir, "Test_folder");
        mkdir (homeDir, 0764);

        // create 'efg' folder
        strcat (homeDir, "/efg");
        mkdir (homeDir, 0664);

        // create the 'Test1' folder
        // reset hoemDir
        strcpy (homeDir, path[1]);
        // make path for Test1 folder
        strcat (homeDir, "Test_folder/Test1");
        mkdir (homeDir, 0764);

        // create the abc folder
        strcat (homeDir, "/abc");
        mkdir (homeDir, 0444);

        // change permision for Test1
        // reset hoemDir
        strcpy (homeDir, path[1]);
        // make path for Test1 folder
        strcat (homeDir, "Test_folder/Test1");
        strcpy (cmdTerminal, "chmod 664 ");
        strcat (cmdTerminal, homeDir);
        // printf ("%s\n", cmdTerminal);
        system (cmdTerminal);

        // reset cmd buffer
        strcpy (cmdTerminal, "");

        // change permision for Test_folder
        // reset hoemDir
        strcpy (homeDir, path[1]);
        // make path for Test_folder
        strcat (homeDir, "Test_folder");
        strcpy (cmdTerminal, "chmod 664 ");
        strcat (cmdTerminal, homeDir);
        // printf ("%s\n", cmdTerminal);
        system (cmdTerminal);  

        return 0;
    }
    else
    {
        printf ("Error: Missing argument!\n");

        return 1;
    }
}

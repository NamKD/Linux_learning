#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <string.h>

int main ( int argc, char *path[] )
{
    char homeDir[1000] = {0};
    int mode = 0;

    // Copy path to homeDir
    strcpy (homeDir, path[1]);

    // create 'Test folder'
    strcat (homeDir, "Test_folder");
    mode = 0777;
    mkdir (homeDir,0777);

    // create 'Test1' folder
    // strcat (homeDir, "/Test1");
    // mkdir (homeDir, 664);

    return 0;
}

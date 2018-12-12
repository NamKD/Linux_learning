#include <stdio.h>
#include <string.h>

int main( int argc, char *argv[] ) 
{
    FILE *fp;
    char ch;

    fp=fopen(argv[1], "r");
    if (fp != NULL)
    {
        while((ch = fgetc(fp)) != EOF)
        {
            printf("%c", ch);
        }
    }
    else
    {
        printf ("Error during open the files!\n");
        return 1;
    }

    return 0;
}


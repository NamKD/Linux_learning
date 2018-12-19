#include <stdio.h>
#include <string.h>

int main (void)
{
    FILE *fp;
    char str1[100], str2[1000], ch;
    char file_buffer[] = {0};
    int fp_size = 0;

    printf("Enter process ID: \n");
    scanf("%s", str1);

    sprintf (str2, "/proc/%s/comm", str1);

    fp=fopen(str2, "r");
    if (fp != NULL)
    {
        fread(file_buffer, 1024*1024*4, 1, fp);
        if (strlen(file_buffer) > 0)
        {
            printf("The name of porcess is %s\n", file_buffer);
        }
    }
    else
    {
        perror("Error while opening the file.\n");
        return 1;
    }
    fclose(fp);

    return 0;
}
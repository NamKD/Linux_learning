#include <stdio.h>
#include <string.h>

int main (void)
{
    FILE *fp;
    char file_path[1000];
    char ch;

    printf("Print content of file in the Path\n");

    strcpy(file_path, "/home/namkd/NamKD_workspace/namkd_learning_Linux/namkd_learnLinux/unit1:overview_about_os/practice2/practice2_data.txt");

    fp=fopen(file_path, "r");
    if (fp == NULL)
    {
        perror("Error while opening the file.\n");
        return 1;
    }
    else
    {
        printf("the path is: %s \n", file_path);
    }
    
    while((ch = fgetc(fp)) != EOF)
    {
        printf("%c", ch);
    }
    
    fclose(fp);

    return 0;
}
#include <stdio.h>
#include <string.h> 
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>

/*function to get size of the file.*/
int findSize(const char *file_name)
{
    struct stat st; /*declare stat variable*/
     
    /*get the size using stat()*/
    if(stat(file_name,&st)==0)
        return (st.st_size);
    else
        return -1;
}

int main( int argc, char *path[] ) 
{
    int fileDes = 0;
    int size = 0;
    int numberOfByte = 0;
    char buffer[] = {0};

    size = findSize("/home/namkd/NamKD_workspace/Linux_learning/unit2:Files_in_Linux/practice1/data.txt");
    fileDes = open(path[1],O_RDONLY);
    if (fileDes)
    {
        numberOfByte = read(fileDes, buffer, size-200);
        if (numberOfByte)
        {
            printf ("%s", buffer);
        }
        else
        {
            printf ("ERROR");
        }
    }
    else
    {
        printf ("can not open file");
    }
    
    return 0;
}
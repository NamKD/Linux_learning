#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main (int argc, char *argument[])
{
    int ret_val = 0;
    int index = 0;
    char cmd_consl[1000] = {0};

    if (argc == 2)
    {
        if (strcmp(argument[1], "-l") == 0)
        {
            printf ("full property\n");
        }
        else if (strcmp(argument[1], "-a") == 0)
        {
            system ("ls -a");
        }
        else if (strcmp(argument[1], "-la") == 0)
        {
            printf ("full property\n");
            system ("ls -a");
        }
        else
        {
            printf ("Invalid argument!\n");
            ret_val = 2;
        }
    }
    else if (argc == 3)
    {
        if (strcmp(argument[2], "-l") == 0)
        {
            printf ("full property\n");
        }
        else if (strcmp(argument[2], "-a") == 0)
        {
            index = sprintf (cmd_consl,"ls ");
            index += sprintf (cmd_consl + index, argument[1]);
            index += sprintf (cmd_consl + index, " -a");

            system (cmd_consl);
        }
        else if (strcmp(argument[2], "-la") == 0)
        {
            index = sprintf (cmd_consl,"ls ");
            index += sprintf (cmd_consl + index, argument[1]);
            index += sprintf (cmd_consl + index, " -a");

            printf ("full property\n");
            system (cmd_consl);
        }
        else
        {
            printf ("Invalid argument!\n");
            ret_val = 2;
        }
    }
    else
    {
        printf ("only two argument for this command!\n");
        ret_val = 1;
    }

    return (ret_val);
}
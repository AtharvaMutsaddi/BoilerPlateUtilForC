#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXLEN 500
int exists(const char *fname)
{
    FILE *file;
    if ((file = fopen(fname, "r")))
    {
        fclose(file);
        return 1;
    }
    return 0;
}
void createoropen(const char *argv1,const char *argv2)
{
    char argv[50];
    strcat(argv, argv1);
    strcat(argv, argv2);

    if (!exists(argv))
    {
        FILE *ptr = fopen(argv, "w");
        if (ptr == NULL)
        {
            perror("Some error occurred: ");
            exit(1);
        }
        if (!strcmp(argv2,".c"))
        {
            char boiler[MAXLEN] = "#include<stdio.h>\n#include<stdlib.h>\nint main(){\n\n\treturn 0;\n}";
            fputs(boiler, ptr);
            fclose(ptr);
            char command[50] = "code ";
            strcat(command, argv);
            strcat(command, " .");
            system(command);
        }
        else if (!strcmp(argv2,".cpp"))
        {
            char boiler[MAXLEN] = "#include<bits/stdc++.h>\nusing namespace std;\nint main(){\n\n\treturn 0;\n}";
            fputs(boiler, ptr);
            fclose(ptr);
            char command[50] = "code ";
            strcat(command, argv);
            strcat(command, " .");
            system(command);
        }
        else
        {
            perror("The file name u have enetered is not supported by this Utility!");
        }
        
        
    }
    else
    {
        char command[50] = "code ";
        strcat(command, argv);
        strcat(command, " .");
        system(command);
    }
}
int main(int argc, char const *argv[])
{
    if (argc == 1)
    {
        perror("Please Enter name of prog!: ");
    }
    
    createoropen(argv[1], argv[2]);

    return 0;
}

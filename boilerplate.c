#include <stdio.h>
#include <stdlib.h>
#include<string.h>
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
void createoropen(const char * argv){
    if (!exists(argv))
    {
        FILE *ptr = fopen(argv, "w");
        if (ptr == NULL)
        {
            perror("Soime error occurred: ");
            exit(1);
        }
        char boiler[MAXLEN] = "#include<stdio.h>\n#include<stdlib.h>\nint main(){\n\n\treturn 0;\n}";
        fputs(boiler, ptr);
        fclose(ptr);
        char command[50]="code ";
        strcat(command, argv);
        strcat(command, " .");
        system(command);
    }
    else{
        char command[50]="code ";
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
    createoropen(argv[1]);
    
    return 0;
}

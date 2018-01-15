//Copyright (c) 2018 Calvin Ng
//This file is released under the MIT License.
//Please see LICENSE for the full text.

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(int argc, char** argv[])
{
    char* fileName;
    char* newName;
    char* buffer;
    char* command;
    char* dotLocation;
    long index;
    long n;
    size_t fileNameLength;
    if(argc == 4)
    {
        fileNameLength = strlen(argv[1]);

        if(fileNameLength == 0)
        {
            printf("Invalid filename. \n");
            exit(1);
        }
        else
        {
            fileName = malloc(sizeof(char) * (fileNameLength + 1));
            newName = malloc(sizeof(char) * (fileNameLength + 1));
            command = calloc(5 + fileNameLength + fileNameLength, sizeof(char));

            fileName = argv[1];
            index = strtol(argv[2], NULL, 10);
            n = strtol(argv[3], NULL, 10);

            if(n == -1)
            {
                dotLocation = strrchr(fileName, '.');
                n = (dotLocation - fileName) - index;
            }

            if(index < 0 || n < 0 || index + n > fileNameLength)
            {
                printf("Invalid Arguments.\n");
            }
            else
            {
                printf("%s ", fileName);

                memcpy(newName, fileName, index);

                memcpy(newName + index, fileName + index + n, fileNameLength - n);
                newName[fileNameLength - n] = '\0';

                strcat(command, "ren ");
                strcat(command, fileName);
                strcat(command, " ");
                strcat(command, newName);

                if(!system(command))
                {
                    printf("renamed to %s\n", newName);
                }
            }

            free(fileName);
            free(newName);
            free(command);
        }
    }
    else
    {
        printf("Trims n characters from a filename, starting after index\n");
        printf("If n is -1, all characters until (.) is deleted.\n");
        printf("Usage: trimmer [filename] [index] [n]\n");
    }
    return 0;
}

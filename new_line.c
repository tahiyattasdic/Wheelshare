#include <stdio.h>
#include <string.h>

int new_line(FILE *file){
    //Move the file pointer to the end of the file (so we don't overwrite)
    if (fseek(file, 0, SEEK_END) != 0) {
        fclose(file);
        return 1;
    }

    //Write a newline character to start the new content on a new line
    if (fprintf(file, "\n") < 0) {
        fclose(file);
        return 1;
    }
    return 0;
}
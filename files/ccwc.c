#include <stdio.h>
#include <string.h>

long int bytes(char[]);
long int count_lines(char[]);
long int count_words(char[]);
long int count_characters(char[]);


int main(int argc, char *argv[]) {
    if (argc == 1) {
        // Print the help text
        printf("Incorrect args");
        return -1;
    }
    if (argc == 2) {
        long int byte_count = bytes(argv[1]);
        if (byte_count == -1) {
            return -1;
        }
        long int line_count = count_lines(argv[1]);
        if (line_count == -1) {
            return -1;
        }
        long int word_count = count_words(argv[1]);
        if (word_count == -1) {
            return -1;
        }
        printf("%ld %ld %ld %s\n", line_count, word_count, byte_count, argv[1]);
    }
    if (argc == 3) {
        // Write extraction logic here
        if (strcmp(argv[1], "-c") == 0) {
            long int res = bytes(argv[2]);
            if (res != -1) {
                printf("%ld %s\n",res,argv[2]);
            }
        } else if (strcmp(argv[1], "-l") == 0) {
            long int res = count_lines(argv[2]);
            if (res != -1) {
                printf("%ld %s\n",res,argv[2]);
            }
        } else if (strcmp(argv[1], "-w") == 0) {
            long int res = count_words(argv[2]);
            if (res != -1) {
                printf("%ld %s\n",res,argv[2]);
            }
        } else if (strcmp(argv[1], "-m") == 0) {
            long int res = count_characters(argv[2]);
            if (res != -1) {
                printf("%ld %s\n",res,argv[2]);
            }
        }
    }
    return 0;
}

long int bytes(char file_name[]) {
    // Open the file in read mode
    FILE* fp = fopen(file_name, "r");
    // Verify if teh file exists
    if (fp == NULL) {
        printf("File Not Found!");
        return -1;
    }
    // Reach the EOF
    fseek(fp, 0L, SEEK_END);
    // Find the size of the file
    long int size_in_bytes = ftell(fp);
    fclose(fp);
    return size_in_bytes;
}

long int count_lines(char file_name[]) {
    // Open the file in read mode
    FILE* fp = fopen(file_name, "r");
    if (fp == NULL) {
        printf("File Not Found!");
        return -1;
    }
    int count = 0;
    char c;
    for (c = getc(fp); c != EOF; c = getc(fp))
        if (c == '\n') // Increment count if this character is newline
            count++;
    fclose(fp);
    return count;
}

long int count_characters(char file_name[]) {
    // Open the file in read mode
    FILE* fp = fopen(file_name, "r");
    if (fp == NULL) {
        printf("File Not Found!");
        return -1;
    }
    int count = 0;
    char c;
    for (c = getc(fp); c != EOF; c = getc(fp))
        if (c != ' ')
            count++;
    fclose(fp);
    return count;
}

long int count_words(char file_name[]) {
    FILE* fp = fopen(file_name, "r");
    if (fp == NULL) {
        printf("File Not Found!");
        return -1;
    }
    long int count = 0L;
    char ch;

    while ((ch = getc(fp)) != EOF) {
        // If the current character is whitespace
        if (ch == ' ' || ch == '\n' || ch == '\t' || ch == '\r') {
            count++;
            // Skip consecutive whitespace characters
            while ((ch = getc(fp)) == ' ' || ch == '\n' || ch == '\t' || ch == '\r');
        }
    }
    fclose(fp);
    return count;
} 
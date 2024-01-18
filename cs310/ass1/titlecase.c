#include <stdio.h>
#include <ctype.h>
#include <string.h>

void title_case(char *s) {
    int capitalize_next = 1;

    for (int i = 0; s[i] != '\0'; i++) {
        if (isspace(s[i])) {
            capitalize_next = 1;
        } else {
            if (capitalize_next) {
                s[i] = toupper(s[i]);
                capitalize_next = 0;
            } else {
                s[i] = tolower(s[i]);
            }
        }
    }
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Please provide a string as a command-line argument.\n");
    } else {
        char titlecased[1000];  // Adjust the size as needed
        strcpy(titlecased, "");

        for (int i = 1; i < argc; i++) {
            strcat(titlecased, argv[i]);
            if (i != argc - 1) {
                strcat(titlecased, " ");
            }
        }

        title_case(titlecased);
        printf("%s\n", titlecased);
    }

    return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("wgrep: searchterm [file ...]\n");
        exit(1);
    }

    char *word = argv[1];
    int word_len = strlen(word);
    for (int i = 2 - (argc == 2); i < argc; i++) {
        FILE *fp = argc == 2 ? stdin : fopen(argv[i], "r");
        if (fp == NULL) {
            printf ("wgrep: cannot open file\n");
            exit(1);
        }

        char *line = NULL;
        size_t size;
        ssize_t len;
        while ((len = getline(&line, &size, fp)) != -1) {
            for (int k = 0; k < len - word_len + 1; k++) {
                int j;
                for (j = 0; j < word_len && word[j] == line[k + j]; j++);

                if (j == word_len) {
                    printf("%s", line);
                    break;
                }
            }
        }
        fclose(fp);
    }
    return 0;
}

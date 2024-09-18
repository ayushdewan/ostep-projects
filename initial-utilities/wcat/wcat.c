#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    if (argc < 2) {
        return 0;
    }

    for (int i = 1; i < argc; i++) {
        FILE *fp = fopen(argv[i], "r");
        if (fp == NULL) {
            printf ("wcat: cannot open file\n");
            exit(1);
        }

        char buf[50];
        while (fgets(buf, 50, fp) != NULL) {
            printf("%s", buf);
        }
        fclose(fp);
    }
    return 0;
}

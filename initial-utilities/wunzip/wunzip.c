#include <stdio.h>
#include <stdlib.h>

struct packet {
    int len;
    char c;
};

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("wunzip: file1 [file2 ...]\n");
        exit(1);
    }

    for (int i = 1; i < argc; i++) {
        FILE *fp = fopen(argv[i], "r");
        if (fp == NULL) {
            printf ("wunzip: cannot open file\n");
            exit(1);
        }

        struct packet pkt;
        while (fread(&pkt, 5, 1, fp) > 0) {
            for (int j = 0; j < pkt.len; j++) {
                printf("%c", pkt.c);
            }
        }
    }
    return 0;
}

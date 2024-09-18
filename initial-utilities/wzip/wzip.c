#include <stdio.h>
#include <stdlib.h>

struct packet {
    int len;
    char c;
};

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("wzip: file1 [file2 ...]\n");
        exit(1);
    }

    int init_flag = 0;
    struct packet pkt;
    for (int i = 1; i < argc; i++) {
        FILE *fp = fopen(argv[i], "r");
        if (fp == NULL) {
            printf ("wzip: cannot open file\n");
            exit(1);
        }

        if (!init_flag) {
            pkt.c = fgetc(fp);
            pkt.len = 1;
            if (pkt.c == EOF) {
                continue;
            }
            init_flag = 1; 
        }

        char c;
        while ((c = fgetc(fp)) != EOF) {
            if (c == pkt.c) {
                pkt.len++;
            } else {
                fwrite(&pkt, 5, 1, stdout);
                pkt.len = 1;
            }
            pkt.c = c;
        }
    }
    fwrite(&pkt, 5, 1, stdout);
    return 0;
}

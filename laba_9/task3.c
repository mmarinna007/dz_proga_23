#include <stdio.h>
#include <string.h>
#include <getopt.h>
#include <ctype.h>
#include <stdlib.h>

#define MSG_NOT_FOUND_FILE "Could not open the file"
#define MSG_MISSING_ARG    "Missing console argv"
#define MSG_INCORRECT_NUM  "Wrong passed number"

typedef struct {
    char *str;
    int reserved;
} string_t;

int check_optarg(void)
{
    int i = 0;
    for (; optarg[i]; i++) {
        if (!isdigit(optarg[i])) {
            fprintf(stderr, "%s\n", MSG_INCORRECT_NUM);
            return 1;
        }
    }
    return 0;
}
int parse_arg(int argc, char **argv, int *n, int *p)
{
    int r;
    while ((r = getopt(argc, argv, "p:n:")) != -1) {
        switch (r) {
            case 'n':
                if (check_optarg()) {
                    return 1;
                }
                *n = atoi(optarg);
                break;

            case 'p':
                if (check_optarg()) {
                    return 1;
                }
                *p = atoi(optarg);
                break;
        }
    }
    return 0;
}
void reading(string_t *l, FILE *file)
{
    l->str[0] = 0;
    int len = 0;
    while (fscanf(file, "%10[^ \n]", l->str + len) == 1) {
        len += strlen(l->str + len);
        if (len < l->reserved) {
            break;
        }
        l->reserved *= 2;
        l->str = realloc(l->str, sizeof(char) * (l->reserved + 1));
    }
    fscanf(file, "%*c");
}

void task(FILE *f, int n, int p)
{
    string_t l = {.str = NULL, .reserved = 10};
    l.str = malloc(sizeof(char) * 11);
    
    int line = 0;
    while (!feof(f)) {
        int i = 0;
        reading(&l, f);

        while (l.str[i]) {
            printf("%d: ", (line % p) + 1);
            line++;
            int j = 0;
            while (l.str[i] && j < n) {
                printf("%c", l.str[i]);
                i++;
                j++;
            }
            printf("\n");
            if (line % p == 0) {
                printf("- Page %d -\n", line / p);
            }
        }
    }
    printf("- Page %d -\n", (line / p) + 1);
    free(l.str);
}
int main(int argc, char **argv) 
{
    int n = -1, p = -1;
    if (parse_arg(argc, argv, &n, &p)) {
        return 1;
    }
    if (n == -1 || p == -1) {
        fprintf(stderr, "%s\n", MSG_MISSING_ARG);
        return 2; 
    }

    FILE *file = fopen("file.txt", "r");
    if (file == NULL) {
        fprintf(stderr, "file.txt - %s\n", MSG_NOT_FOUND_FILE);
        return 1;
    }
    task(file, n, p);
    fclose(file);
    return 0;
}

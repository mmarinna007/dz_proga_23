#include <string.h>
#include <stdlib.h>
#include <stdio.h>

#define MSG_MISSING_ARG    "Missing console argv"
#define MSG_NOT_FOUND_FILE "Could not open the file"


typedef struct {
    char *str;
    int reserved;
} string_t;

void reading(string_t *l, FILE *file)
{
    l->str[0] = 0;
    int len = 0;
    while (fscanf(file, "%10[^\n]", l->str + len) == 1) {
        len += strlen(l->str + len);
        if (len < l->reserved) {
            break;
        }
        l->reserved *= 2;
        l->str = realloc(l->str, sizeof(char) * (l->reserved + 1));
    }
    fscanf(file, "%*c");
}
void task(FILE *f1, FILE *f2)
{
    string_t l = {.str = NULL, .reserved = 10};
    l.str = malloc(sizeof(char) * 11);

    while (!feof(f1) && !feof(f2)) {
        reading(&l, f1);
        if (l.str[0])
            printf("%s\n", l.str);

        reading(&l, f2);
        if (l.str[0])
            printf("%s\n", l.str);
    }

    while (!feof(f1)) {

        reading(&l, f1);
        if (l.str[0])
            printf("%s\n", l.str);
    }
    while (!feof(f2)) {
        reading(&l, f2);
        if (l.str[0])
            printf("%s\n", l.str);
    }
    free(l.str);
}

int main(int argc, char **argv)
{
    if (argc < 3) {
        fprintf(stderr, "%s\n", MSG_MISSING_ARG);
        return 1;
    }

    char *fname1 = argv[1];
    char *fname2 = argv[2];
    
    FILE *f1 = fopen(fname1, "r");
    if (f1 == NULL) {
        fprintf(stderr, "%s - %s\n", fname1, MSG_NOT_FOUND_FILE);
        return 3;
    }

    FILE *f2 = fopen(fname2, "r");
    if (f2 == NULL) {
        fclose(f1);
        fprintf(stderr, "%s - %s\n", fname2, MSG_NOT_FOUND_FILE);
        return 3;
    }

    task(f1, f2);

    fclose(f1);
    fclose(f2);
    return 0;
}

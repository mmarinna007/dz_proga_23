#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>

#define DEFAULT_NUM_LINES 5
#define MSG_MISSING_ARG    "Missing console argv"
#define MSG_INCORRECT_NUM  "Wrong passed number of lines lines"
#define MSG_NOT_FOUND_FILE "Could not open the file"
#define MSG_EMPTY_FILE "Empty file"

char* reading(FILE *file)
{
    char *str = malloc(sizeof(char) * 11);
    int n = 0;
    while (fscanf(file, "%10[^\n]", str + 10*n) == 1) {
        n++;
        str = realloc(str, sizeof(char) * (10*n + 11));
    }

    fscanf(file, "%*c");
    if (n == 0) {
        free(str);
        return NULL;
    }

    n--;
    str = realloc(str, sizeof(char) * (10*n + strlen(str + 10 * n) + 1));     
    return str;
}
int fill(FILE *f, char **strs, int count)
{
    char *ptr = NULL;
    int i = 0;
    while (i < count) {
        ptr = reading(f);
        if (ptr == NULL) {
            if (!feof(f)) {
                continue;
            }
            return 0;
        }
        strs[i] = ptr;
        i++;
    }

    i = 0;
    while (!feof(f)) {
        ptr = reading(f);
        if (ptr == NULL) {
            if (!feof(f)) {
                continue;
            }
            break;
        }
        free(strs[i]);
        strs[i] = ptr;
        i = (i + 1) % count;
    }
    return i;
}
int parse_arg(char **argv, int *n, int *ind_fname)
{
    if (argv[1] == NULL) {
        return 1;
    }
    *ind_fname = 1;

    if (argv[2] != NULL) {
        for (int i = 0; argv[2][i]; i++) {
            if (!isdigit(argv[2][i])) {
                return 2;
            }
        }
        *n = atoi(argv[2]);
    } else {
        *n = DEFAULT_NUM_LINES; // 
    }
    return 0;
}

int main(int argc, char **argv)
{
    int num = 0;
    int index_fname = 0; 
    
    char *msg[] = {NULL, MSG_MISSING_ARG, MSG_INCORRECT_NUM};
    int err = parse_arg(argv, &num, &index_fname);
    if (err) {
        fprintf(stderr, "%s\n", msg[err]);
        return err;
    }

    char *fname = argv[index_fname];
    FILE *file = fopen(fname, "r");
    if (file == NULL) {
        fprintf(stderr, "%s\n", MSG_NOT_FOUND_FILE);
        return 3;
    }

    char **a = calloc(sizeof(char*), num);
    int first = fill(file, a, num);
    fclose(file);

    if (a[first] == NULL) {
        printf("%s\n", MSG_EMPTY_FILE);
    } else {
        for (int i = 0; i < num; i++) {
            if (a[(first + i) % num] != NULL) {
                printf("%s\n", a[(first + i) % num]);
                free(a[(first + i) % num]);
            }
        }
    }
    free(a);

    return 0;
}

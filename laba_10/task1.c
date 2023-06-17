#include <stdio.h>
#include <string.h>
#include <getopt.h>
#include <stdlib.h>


#define MSG_MISSING_ARG    "Missing console argv"
#define MSG_NOT_FOUND_FILE "Could not open the file"


typedef struct Node node_t;
struct Node {
    node_t *left;
    node_t *right;
    char   *str;
    int     repeats;
};


node_t* new_node(char *l)
{
    node_t *n = malloc(sizeof(node_t));
    n->left = NULL;
    n->right = NULL;
    n->str = l;
    n->repeats = 1;
    return n;
}
node_t* insert(node_t *r, char *l)
{
    if (r == NULL) {
        return new_node(l);
    }
    node_t *p = r;
    for (;;) {
        int res = strcmp(p->str, l);
        if (res == 0) {
            p->repeats++;
            free(l);
            return r;
        }
        if (res < 0) {
            if (p->left == NULL) {
                p->left = new_node(l);
                return r;
            }
            p = p->left;
        } else {
            if (p->right == NULL) {
                p->right = new_node(l);
                return r;
            }
            p = p->right;
        }
    }
}
void clear(node_t *n)
{
    if (n) {
        clear(n->left);
        clear(n->right);
        free(n->str);
        free(n);
    }
}
int parse_arg(int argc, char **argv, int *o)
{
    int r;
    while ((r = getopt(argc, argv, "o:")) != -1) {
        switch (r) {
            case 'o':
                if (strcmp(optarg, "DESC") == 0) {
                    *o = 1;
                } 
                else if (strcmp(optarg, "ASC") == 0) {
                    *o = 2;
                } else {
                    fprintf(stderr, "Incorrect option\n");
                    return 1;
                }
                break;
        }
    }
    return 0;
}
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
void inorder(node_t *n)
{
    if (n) {
        inorder(n->left);
        printf("%s %d\n", n->str, n->repeats);
        inorder(n->right);
    }
}
void rinorder(node_t *n)
{
    if (n) {
        inorder(n->right);
        printf("%s %d\n", n->str, n->repeats);
        inorder(n->left);
    }
}
void task(FILE *f, int o)
{
    node_t *n = NULL;
    while (!feof(f)) {
        char *line = reading(f);
        if (line) {
            n = insert(n, line);
        }
    }

    if (o == 1) {
        inorder(n);
    } else {
        rinorder(n);
    }
    
    clear(n);
}

int main(int argc, char **argv)
{
    if (argc < 2) {
        fprintf(stderr, "%s\n", MSG_MISSING_ARG);
        return 1;
    }


    char *fname = argv[1];
    FILE *f = fopen(fname, "r");
    if (f == NULL) {
        fprintf(stderr, "%s - %s\n", fname, MSG_NOT_FOUND_FILE);
        return 3;
    }

    int o = 1;
    if (parse_arg(argc, argv, &o)) {
        fclose(f);
        return 1;
    }

    task(f, o);

    fclose(f);

    return 0;
}

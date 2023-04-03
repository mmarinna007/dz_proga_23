#include <stdio.h>
#include <stdlib.h>

#define FIRST ("1) Insert elements in the first list\n")
#define SECOND ("2) Delete an element from the first list\n")
#define THIRD ("3) Display elements of the first list\n")
#define FOURTH ("4) Add an element to the first list\n")
#define FIFTH ("5) Insert elements in the second list\n")
#define SIXTH ("6) Delete an element from the second list\n")
#define SEVENTH ("7) Display elements of the second list\n")
#define EIGHTH ("8) Add an element to the second list\n")
#define NINGTH ("9) Exit\n")
#define ADD ("Insert an element you would like to add\n")
#define DELETE ("Insert an element you would like to delete\n")
#define NOELEMENTS ("There are no elements in the list")
#define ELEMENTS ("Here are the elements\n")

typedef struct Node Node;
struct Node {
    int num;
    struct Node* next;
};
typedef struct Set Set;
struct Set {
    Node* first;
};
Node* func(int integer) {
     Node* element = malloc(sizeof(Node));
     element->num = integer;
     element->next = NULL;
     return element;
}

void append (struct Set* list, int sym) {
     Node* first = func(sym);
     first->next = list->first;
     list->first = first;
}
void add(struct Set *list) {
    printf(ADD);
    printf(">");
    int first_num;
    scanf("%i", &first_num);
    append(list, first_num);
            
}

void insert(struct Set *list) {
    int sym;
    if (list->first == NULL) {
        while (scanf("%i", &sym) != 0){
           append(list, sym);
        }
        scanf("%*s"); /* Убираем буквы из входного потока ввода */
    }
}
void del(struct Set *list) {
    int vol;
    Node *iterator = list->first;
    printf(DELETE);
    printf(">");
    scanf("%i", &vol);
    if (iterator == NULL) {
        printf(NOELEMENTS);
    }
    else if (iterator->num == vol) {
        Node *tmp = iterator;
        list->first = list->first->next;
        free(tmp);
    }
    else {
        while (iterator->next != NULL && iterator->next->num != vol) {
            iterator = iterator->next;
        }
        Node *tmp = iterator->next;
        iterator->next = iterator->next->next;
        free(tmp);
    }
}
void display(const struct Set *list) {
    printf(ELEMENTS);
    Node* iterator = list->first;
    while (iterator != NULL) {
        printf("%i\n", iterator->num); 
        iterator = iterator->next;
        
    }   
}
int main() {
    struct Set list1;
    list1.first = NULL;
    struct Set list2;
    list2.first = NULL;
    for (;;) {
        printf(FIRST);
        printf(SECOND);
        printf(THIRD);
        printf(FOURTH);
        printf(FIFTH);
        printf(SIXTH);
        printf(SEVENTH);
        printf(EIGHTH);
        printf(NINGTH);
        printf(">");
        int a, b; 
        scanf("%i", &a);
        if (a == 9) {
            break;
        }
        struct Set *list = a > 4 ? &list2: &list1;
        a = a%4;
        switch (a) {
            case 1: insert(list);
                    break;
            case 2: del(list);
                    break;
            case 3: display(list);
                    break;
            case 0: add(list);
                    break;       
        }
    }
}
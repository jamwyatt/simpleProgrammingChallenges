#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>

typedef struct _stack {
        int element;
        struct _stack *next;
        } Stack;

void push(Stack **head,int value) {
    Stack *entry = (Stack *)malloc(sizeof(Stack));
    entry->element = value;
    printf("adding: %d\n",value);
    entry->next = *head;
    *head = entry;
    }


int pop(Stack **head) {
        Stack *entry = *head;
        if(entry) {
            *head = entry->next;
            int value = entry->element;
            free(entry);
            return value;
            }
        return -1;
        }


int main(int argc, char *argv[]) {

    Stack *mystack = NULL;

    printf("\n----------------------------\n\n");
    for(int i=0;i<10;i++)
        push(&mystack, i);
    printf("\n----------------------------\n\n");
    int x;
    while((x = pop(&mystack)) >= 0)
        printf("Element: %d\n",x);
    printf("\n----------------------------\n\n");
    }

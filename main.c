#include <stdio.h>
#include <string.h>


#define MAX_SIZE 10

// Stack data structure
typedef struct {
    char items[MAX_SIZE];
    int top;
} Stack;

// Initialize stack
void initialize(Stack *stack) {
    stack->top = -1;
}

// Check if stack is empty
int isEmpty(Stack *stack) {
    return stack->top == -1;
}

// Check if stack is full
int isFull(Stack *stack) {
    return stack->top == MAX_SIZE - 1;
}

// Push item to stack
void push(Stack *stack, char item) {
    if (isFull(stack)) {
        printf("Stack is full. Cannot push item.\n");
        return;
    }
    stack->items[++stack->top] = item;
}

// Pop item from stack
char pop(Stack *stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty. Cannot pop item.\n");
        return '\0';
    }
    return stack->items[stack->top--];
}

// Recursive permutation function using stacks
void permuteRecursive(char *str, int start, int end) {
    static Stack stack;
    static char output[MAX_SIZE];
    static int used[MAX_SIZE] = {0};

    if (start >= end) {
        printf("%s\n", output);
        return;
    }

    for (int i = 0; i < end; i++) {
        if (!used[i]) {
            // Push character to stack
            push(&stack, str[i]);
            used[i] = 1;
            output[start] = str[i];

            // Recurse on remaining characters
            permuteRecursive(str, start + 1, end);

            // Pop character from stack
            pop(&stack);
            used[i] = 0;
        }
    }
}

// Permutation function wrapper
void permute(char *str) {
    int size = strlen(str);
    permuteRecursive(str, 0, size);
}

int main() {
    char str[] = "CAT";
    permute(str);

    printf("\n");

    char str2[] = "MATT";
    permute(str2);

    return 0;
}
#include <stdio.h>
#include <stdbool.h>

#define MAX_SIZE 100

typedef struct
{
    char items[MAX_SIZE];
    int top;
} Stack;

void initialize(Stack *s)
{
    s->top = -1;
}

void push(Stack *s, char c)
{
    if (s->top == MAX_SIZE - 1)
    {
        printf("Stack penuh\n");
        return;
    }
    s->items[++(s->top)] = c;
}

char pop(Stack *s)
{
    if (s->top == -1)
    {
        printf("Stack kosong\n");
        return '\0';
    }
    return s->items[(s->top)--];
}

bool isBalanced(char *expression)
{
    Stack s;
    initialize(&s);
    int i = 0;
    while (expression[i] != '\0')
    {
        if (expression[i] == '(' || expression[i] == '[' || expression[i] == '{')
        {
            push(&s, expression[i]);
        }
        else if (expression[i] == ')' || expression[i] == ']' || expression[i] == '}')
        {
            if (s.top == -1)
            {
                return false;
            }
            else
            {
                char popped = pop(&s);
                if ((popped == '(' && expression[i] != ')') ||
                    (popped == '[' && expression[i] != ']') ||
                    (popped == '{' && expression[i] != '}'))
                {
                    return false;
                }
            }
        }
        i++;
    }
    return s.top == -1;
}

int main()
{
    char expression[MAX_SIZE];
    printf("Masukkan set tanda kurung: ");
    scanf("%s", expression);

    if (isBalanced(expression))
    {
        printf("YES\n");
    }
    else
    {
        printf("NO\n");
    }

    return 0;
}
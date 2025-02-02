#include <stdio.h>
#include "boolean.h"
#include "stack.h"

int main()
{
    int N, i;
    char ch;
    Stack s;
    CreateEmpty(&s);
    // Stack declaration here...

    scanf("%d", &N);

    for (i = 0; i < N; i++)
    {
        scanf(" %c", &ch);
        if (ch == '(' || ch == '[' || ch == '{') {
            Push(&s, ch);
        } else if (ch == ')' || ch == ']' || ch == '}') {
            if (IsEmpty(s)) {
                printf("Invalid\n");
                return 0;
            }
            infotype top;
            Pop(&s, &top);
            if ((ch == ')' && top != '(') || (ch == ']' && top != '[') || (ch == '}' && top != '{')) {
                printf("Invalid\n");
                return 0;
            }
        }
    }

    if (IsEmpty(s)) {
        printf("Valid\n");
    } else {
        printf("Invalid\n");
    }

    return 0;
}
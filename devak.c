#include <stdio.h>

int calculator(int a, int b, char x)
{
    int result;
    switch (x)
    {
    case '+':
        result = a + b;
        break;
    case '-':
        result = a - b;
        break;
    case '*':
        result = a * b;
        break;
    case '/':
        result = a / b;
        break;
    default:
        break;
    }
    return result;
}

int main()
{
    int a, b;
    char operator;
    int i = 1;
    float output;
    while (i != 0)
    {
        printf("Enter the First Operand");
        scanf("%d", &a);
        printf("Enter the Second Operand");
        scanf("%d", &b);
        printf("Enter the Operator");

        scanf(" %c", &operator);
        output = calculator(a, b, operator);
        printf("%f", output);
        printf("If you want the calculator to continue, Enter 1, else 0");
        scanf("%d", &i);
    }
    return 0;
}
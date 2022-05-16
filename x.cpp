#include <iostream>
using namespace std;

void display(void (*p)(int num))
{
    for (int i = 1; i <= 5; i++)
    {
        p(i);
    }
}
void print_numbers(int num)
{
    cout << num;
}
int main()
{
    // void (*p)(int); // void function pointer declaration
    printf("The values are :");
    display(print_numbers);
    return 0;
}

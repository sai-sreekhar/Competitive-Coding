#include <bits/stdc++.h>

using namespace std;
#define MAX_SIZE 10
int arr[MAX_SIZE];

int leftTop = -1;
int rightTop = -1;

void pushS1(int val)
{
    if (leftTop + 1 == rightTop)
    {
        cout << "Stack1 Overflow" << endl;
        return;
    }

    leftTop++;
    arr[leftTop] = val;
    return;
}

void pushS2(int val)
{
    if (leftTop + 1 == rightTop)
    {
        cout << "Stack2 Overflow" << endl;
        return;
    }

    if (rightTop == -1)
    {
        rightTop = MAX_SIZE - 1;
        arr[rightTop] = val;
        return;
    }

    rightTop--;
    arr[rightTop] = val;
    return;
}

void popS1()
{
    if (leftTop == -1)
    {
        cout << "Stack1 Underflow" << endl;
        return;
    }

    leftTop--;
    return;
}

void popS2()
{
    if (rightTop == -1)
    {
        cout << "Stack2 Underflow" << endl;
        return;
    }

    if (rightTop == MAX_SIZE - 1)
    {
        rightTop = -1;
        return;
    }

    rightTop++;
    return;
}

void display()
{
    if(leftTop == -1)
    {
        cout << "Stack 1: Empty" << endl;
        return;
    }
    
    cout << "Stack 1: ";
    for (int i = 0; i <= leftTop; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    if(rightTop == -1)
    {
        cout << "Stack 2: Empty" << endl;
        return;
    }

    cout << "Stack 2: ";
    for (int i = rightTop; i < MAX_SIZE; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main()
{
    pushS1(100);
    pushS1(90);
    pushS1(80);
    pushS1(70);
    pushS1(60);
    pushS1(50);
    pushS1(40);
    // pushS2(10);
    // popS2();
    // pushS2(20);
    // popS2();
    // popS2();
    display();

    return 0;
}
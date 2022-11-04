// FILE: wk6_stacks.cpp
// Homework assignment to implement showBottomtoTop and compareStacks
// in both linked list an static array into driver file

#include <cctype>     // Provides isdigit
#include <cstdlib>    // Provides EXIT_SUCCESS
#include <cstring>    // Provides strchr
#include <iostream>   // Provides cout, cin, peek, ignore
#include <stack>      // Provides the stack template class
#include "bag4.h"
#include "node2.h"
using namespace main_savitch_6A;
using namespace std;


void showBottomToTop(stack<double>, int);
// Precondition: The stack has values inside the stack
// PostCondition: Displays from bottom to top of stack values
bool compareStacks(stack<double>, stack<double>, int);
void intro();


int main()
{
intro();
int opt;
cin >> opt;

if(opt == 1)
{
    stack<double> input1, input2;
    double submit=1, answer;
    while(submit != 2)
    {
        cout << "Would you like to add a number?\n| 1 - YES | 2 - NO |\n";
        cin >> submit;
        if(submit == 2)
            break;
        cout << "\nWhat number would you like to add?\n";
        cin >> answer;
        cout << endl << endl;
        input1.push(answer);
    }
    showBottomToTop(input1, opt);
submit = 1;
    cout << "\n\n\nNow add numbers to the second stack or else.\n";
    while(submit != 2)
    {
        cout << "\nWould you like to add a number?\n| 1 - YES | 2 - NO |\n";
        cin >> submit;
        cout << endl << endl;
        if(submit == 2)
            break;
        cin >> answer;
        cout << endl << endl;
        input2.push(answer);
    }
    if(compareStacks(input1, input2, opt))
        cout << "\nThe stacks Match!\n";
    else
        cout << "\nThe stacks don't match.\n";
}

if(opt == 2)
{
    stack<double> input1, input2;
    double submit=1, answer;
    while(submit != 2)
    {
        cout << "Would you like to add a number?\n| 1 - YES | 2 - NO |\n";
        cin >> submit;
        if(submit != 2)
        {
        cout << "\nWhat number would you like to add?\n";
        cin >> answer;
        cout << endl;
        input1.push(answer);
        }
    }
        showBottomToTop(input1, opt);
submit = 1;
    cout << "\n\n\nNow add numbers to the second stack or else.\n";
    while(submit != 2)
    {
        cout << "\nWould you like to add a number?\n| 1 - YES | 2 - NO |\n";
        cin >> submit;
        cout << endl << endl;
        if(submit == 2)
            break;
        cin >> answer;
        cout << endl;
        input2.push(answer);
    }
    if(compareStacks(input1, input2, opt))
        cout << "\nThe stacks Match!\n";
    else
        cout << "\nThe stacks don't match.\n";
}
}

bool compareStacks(stack<double> num1, stack<double> num2, int cnt)
{
    if(cnt == 1 && num1.size() == num2.size()) //&& num1.empty() = false && num2.empty() = false && num2.size() == num1.size)
    {
        double arr1[num1.size()];
        double arr2[num2.size()];
        int arrSize = num2.size();

    for(int i = 0; i < arrSize; i++)
    {
        arr1[i] = num1.top();
        num1.pop();
        arr2[i] = num2.top();
        num2.pop();
    }

    //Sorting algorithm
    int temp;
    for(int i = 0; i < arrSize; i++)
    {
        for(int j = 0; j < arrSize; j++)
        {
            if(arr1[j] > arr1[i])
            {
                temp = arr1[i];
                arr1[i] = arr1[j];
                arr1[j] = temp;
            }
            if(arr2[j] > arr2[i])
            {
                temp = arr2[i];
                arr2[i] = arr2[j];
                arr2[j] = temp;
            }

        }
    }
    int match = 0;

    for(int i = 0; i < arrSize; i++)
        if(arr2[i] == arr1[i])
            match++;


    if(match == arrSize)
        return true;
    }


    if(cnt == 2 && num1.size() == num2.size())
    {
        int arrSize = num2.size();
        bag<double> link1, link2;
        double arr1[arrSize];
        double arr2[arrSize];

        for(int i = 0; i < arrSize; i++)
        {
            link1.insert1(num1.top());
            arr1[i] = num1.top();
            num1.pop();

            link2.insert1(num2.top());
            arr2[i] = num2.top();
            num2.pop();
        }

    //Sorting algorithm
    int temp;
    for(int i = 0; i < arrSize; i++)
    {
        for(int j = 0; j < arrSize; j++)
        {
            if(arr1[j] > arr1[i])
            {
                temp = arr1[i];
                arr1[i] = arr1[j];
                arr1[j] = temp;
            }
            if(arr2[j] > arr2[i])
            {
                temp = arr2[i];
                arr2[i] = arr2[j];
                arr2[j] = temp;
            }

        }
    }
    int match = 0;

    for(int i = 0; i < arrSize; i++)
        if(arr2[i] == arr1[i])
            match++;


    if(match == arrSize)
        return true;
    }

    return false;
}

void intro()
{
    cout << "' 1 ' for static array implementation of stack\n";
    cout << "' 2 ' for linked list implementation of stack\n";

}

void showBottomToTop(stack<double> numbers, int opt)
{
if(opt == 1)
{
    double rev[numbers.size()];
    int cnt =numbers.size();

    for(int i = numbers.size(); i > 0; i--)
    {
        rev[i] = numbers.top();
        numbers.pop();
        cout << rev[i] << ", ";
    }

    cout << endl << endl;
}

if(opt == 2)
{
    bag<double> backward;

    for(int i = numbers.size(); i > 0; i--)
    {
        double newData;
        newData = numbers.top();
        backward.insert1(newData);
        numbers.pop();
    }
    cout << endl << "Numbers backwards:\n";
    backward.print();


}
}

/*Given an array with all distinct elements,
find the largest three elements. Expected time complexity is O(n)
and extra space is O(1).*/
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int first = INT_MIN, second = INT_MIN, third = INT_MIN; // initialize all with -INFINITY
    int arr[] = {10, 4, 3, 50, 23};
    for (auto x : arr)
    {
        if (x > first)
        {
            third = second; 
            second = first;
            first = x;
        }
        else if (x > second && x != first)
        {
            third = second;
            second = x;
        }
        else if (x > third && x != second)
        {
            third = x;
        }
    }
    cout << first << " " << second << " " << third;
    return 0;
}
// Met2: sort in nlogn and print last 3 elements
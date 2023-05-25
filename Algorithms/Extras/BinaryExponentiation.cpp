#include <iostream>
using namespace std;
// #define m 1e9 + 7
long long m = 1000000007;
int BinaryIterative(int a, int b)
{
    int res = 1;
    while (b > 0)
    {
        if (b & 1)
            res = res * a;
        a = a * a;
        b >>= 1;
    }
    return res;
}
long long BinaryIterativeWithModulo(long int a, long int b)
{
    long long int res = 1;
    while (b > 0)
    {
        if (b & 1)
            res = (res * a) % m;
        a = (a * a) % m;
        b >>= 1;
    }
    return res;
}
long long binpowRecursive(long long a, long long b)
{
    if (b == 0)
        return 1;
    long long res = binpowRecursive(a, b / 2);
    if (b % 2)
        return (res * (res * a) % m) % m;
    else
        return (res * res) % m;
}
int main()
{
    cout << BinaryIterative(0, 4);
    //cout << binpowRecursive(2, 2);
    return 0;
}

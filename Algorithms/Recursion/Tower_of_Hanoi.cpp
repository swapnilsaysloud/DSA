#include<iostream>
using namespace std;

void towerOfHanoi(int n, char A, char C, char B)
{
    if (n == 1)
    {
        cout << "Move disk 1 from rod " << A <<
                            " to rod " << C <<endl;
        return;
    }
    towerOfHanoi(n - 1, A, B, C);
    cout << "Move disk " << n << " from rod " << A <<
                                " to rod " << C << endl;
    towerOfHanoi(n - 1, B, C, A);
}
void solve()
{ int n=3 ;
      towerOfHanoi(n, 'A', 'C', 'B');
}
int main()
{
 solve();
}
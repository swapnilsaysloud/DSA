#include <bits/stdc++.h>
using namespace std;
string help(int i, int j)
{
    string s = "";
    if (j == 7)
        s += 'h';
    if (j == 6)
        s += 'g';
    if (j == 5)
        s += 'f';
    if (j == 4)
        s += 'e';
    if (j == 3)
        s += 'd';
    if (j == 2)
        s += 'c';
    if (j == 1)
        s += 'b';
    if (j == 0)
        s += 'a';
    if (i == 7)
        s += '1';
    if (i == 6)
        s += '2';
    if (i == 5)
        s += '3';
    if (i == 4)
        s += '4';
    if (i == 3)
        s += '5';
    if (i == 2)
        s += '6';
    if (i == 1)
        s += '7';
    if (i == 0)
        s += '8';

    return s;
}
/* 
Better solution but not memory efficient
int main(){
	vector<string>s(8);
	for(int i=0;i<8;i++)cin >> s[i];
	for(int i=0;i<8;i++)for(int j=0;j<8;j++){
		if(s[i][j]=='*'){
			cout << "abcdefgh"[j] << 8-i << endl;
			return 0;
		}
	}
} */
// TC-O(n2)
// SC-O(1)
int main()
{
    int row = 0;
    for (int i = 0; i < 8; i++)
    {
        string s;
        cin >> s;
        int column = 0;
        for (int j = 0; j < 8; j++) // row
        {
            if (s[j] == '*')
            {
              cout<<help(row,column);
                return 0;
            }
            else
                column++;
        }
        row++;
    }
    return 0;
}

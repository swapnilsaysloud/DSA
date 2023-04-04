#include<bits/stdc++.h>
using namespace std;
// METHOD 1 - RECURSIVE: GIVES TLE 
/*int FirstScore(vector<int>a,int i,int j)
{
if(i>j) return 0;
if(i==j) return a[i];
int curScore = max(a[i] + min(FirstScore(a,i+1,j-1),FirstScore(a,i+2,j)),a[j] + min(FirstScore(a,i+1,j-1),FirstScore(a,i,j-2)));
return curScore;
}
int TotalScore(vector<int>a)
{
    int sum =0;
    for(int x: a) sum += x;
    return sum;
}
*/
int main(){
    vector<int>nums{1,5,233,7};
//int Totalscore = TotalScore(nums);
//int Firstscore = FirstScore(nums,0,nums.size()-1);
//if(Firstscore>=Totalscore-Firstscore) cout<<"true";
//else cout<<false;
return 0;
}
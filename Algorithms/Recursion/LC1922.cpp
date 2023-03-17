 #include<bits/stdc++.h>
 using namespace std;
 int mod = 1e9 +7;
 // this function calculates x^n in logn time
long long pow(int x,long long n)
{
    if(x==1 || n==0) return 1;
    long long y = pow(x,n/2);
    if(n%2==0) return (y*y)%mod;
    else return y*y*x;
}
// SOLUTIONS STARTS HERE
 long long powerMod(int a, long long b, int mod) {
        if(b == 0)
            return 1;
        long long x = powerMod(a, b/2, mod); 
        if(b % 2 == 0)
            return (x * x) % mod; // a^b/2 * a^b/2 = a^b but only when b is even
        else
            return (((a * x) % mod) * x) % mod; // say b=5, a^b = a^b/2*a^b/2*a bcoz 5/2=2
    }
    
    int countGoodNumbers(long long n) {
        int mod = 1e9+7;
        return (powerMod(5, (n + 1) / 2, mod) * powerMod(4, n / 2, mod)) % mod;
    }
     int main(){
  
 return 0;
 }
 
    #include<bits/stdc++.h>
    using namespace std;
    string invert(string s){
        for(int i=0;i<s.length();i++){
            if(s[i]=='1')s[i]='0';
            else
            s[i]='1';
        }
        return s;
    }
    string reverse(string s){
        int i=0,j=s.length()-1;
        while(i<=j){
            swap(s[i],s[j]);
            i++;
            j--;
        }
        return s;
    }
    int i=0;
    string findValue(int n,string s){
        if(n==1){
            return s+"0";
        }
        string temp1=findValue(n-1,s);
        string temp2=invert(temp1);
        string temp3=reverse(temp2);
        string temp4= temp1+"1"+temp3;
        cout<<i<<" "<<temp4<<endl;
        i++;
        return temp4;
    }
    char findKthBit(int n, int k) {
        string res=findValue(n,"");
        return res[k-1];
        
    }
        int main(){
    cout<<findKthBit(6,5);
    return 0;
    }
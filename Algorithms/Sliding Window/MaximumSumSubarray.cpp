int maxSubArraySum(int arr[], int n, int k) {
    int max_sum = 0;
    int window_sum = 0;
    
    // Initialize the first window sum
    for (int i = 0; i < k; i++) {
        window_sum += arr[i];
    }
    
    // Slide the window and update the max sum
    for (int i = k; i < n; i++) {
        window_sum += arr[i] - arr[i-k];
        max_sum = max(max_sum, window_sum);
    }
    
    return max_sum;
}
#include<bits/stdc++.h>
using namespace std;
int main(){

return 0;
}
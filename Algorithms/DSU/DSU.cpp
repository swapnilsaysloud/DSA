#include <bits/stdc++.h>
using namespace std;
const int N = 1e9 + 10;
int parent[N];
int size[N];  // Stores the number of members of that parent
/* Amortized time complexity*/
/* O (alpha(n)): Value increases very slowly */
void make(int v)
{
    parent[v] = v;
    size[v] = 1;
}
int find(int v)
{
    if (v == parent[v])
        return v;
    // return find(parent[v]); // or use while loops
     return parent[v] = find(parent[v]); // Implementing path compression
}
void Union(int a, int b) // Join roots aka parents of both nodes
{
    a = find(a);
    b = find(b);
    // b: chhota a: bada
    if (a != b)
    {
        // Union by size
        if (size[b] > size[a])
            swap(a, b);
        parent[b] = a;
        size[a] += size[b];
    }
}
/* Problem:
1. We're always adding a as parent of b, this might cause the tree to be very large if we are adding one big tree on other
 *Chhote tree ko bade mein jodo*
 Merge on the basis of size or rank (Depth).
*/
int main()
{

    return 0;
}
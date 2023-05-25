#include <bits/stdc++.h>
using namespace std;
void dfs(vector<vector<int>> &image, int sr, int sc, int oldcolor, int newcolor)
{
    int row = image.size();
    int col = image[0].size();
    if (sr < 0 || sc < 0 || sr >= row || sc >= col || image[sr][sc] != oldcolor)
        return;
    image[sr][sc] = newcolor;
    dfs(image, sr + 1, sc, oldcolor, newcolor);
    dfs(image, sr - 1, sc, oldcolor, newcolor);
    dfs(image, sr, sc + 1, oldcolor, newcolor);
    dfs(image, sr, sc - 1, oldcolor, newcolor);
}
void dfs(vector<vector<int>> &image, int sr, int sc, int oldcolor,int newcolor,vector<vector<bool>> &visited)
{
int row = image.size();
int col = image[0].size();
if(sr<0 || sc<0 || sr>=row || sc>=col || image[sr][sc] != oldcolor || visited[sr][sc]==true) return;
visited[sr][sc]= true;
image[sr][sc]=newcolor;
dfs(image,sr+1,sc,oldcolor,newcolor,visited);
dfs(image,sr-1,sc,oldcolor,newcolor,visited);
dfs(image,sr,sc+1,oldcolor,newcolor,visited);
dfs(image,sr,sc-1,oldcolor,newcolor,visited);
}
    void fill(vector<vector<int>>& image, int sr, int sc, int color, int cur) {
        // If sr is less than 0 or greater equals to the length of image...
        // Or, If sc is less than 0 or greater equals to the length of image[0]...
        if(sr < 0 || sr >= image.size() || sc < 0 || sc >= image[0].size()) return;
        // If image[sr][sc] is not equal to previous color...
        if(cur != image[sr][sc]) return;
        // Update the image[sr][sc] as a color...
        image[sr][sc] = color;
        // Make four recursive calls to the function with (sr-1, sc), (sr+1, sc), (sr, sc-1) and (sr, sc+1)...
        fill(image, sr-1, sc, color, cur);
        fill(image, sr+1, sc, color, cur);
        fill(image, sr, sc-1, color, cur);
        fill(image, sr, sc+1, color, cur);
    }
vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc, int color)
{
    dfs(image, sr, sc, image[sr][sc], color);
    return image;
}
int main()
{

    return 0;
}
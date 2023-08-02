#include<bits/stdc++.h>
void helper(vector<vector<int>>&image,int x,int y ,int newColor,int check){
    
    if(x>=image.size()||x<0 || y<0 ||y>=image[0].size())return;
    if(image[x][y]!=check)return;

        image[x][y]=newColor;
        helper(image,x-1,y,newColor,check);
        helper(image,x+1,y,newColor,check);
        helper(image,x,y-1,newColor,check);
        helper(image,x,y+1,newColor,check);

}
vector<vector<int>> floodFill(vector<vector<int>> &image, int x, int y, int newColor)
{
    int check=image[x][y];
    if(check==newColor)return image;
    helper(image,x,y,newColor,check);
    return image;
}

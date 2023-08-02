void rotateMatrix(vector<vector<int>> &mat, int n, int m)
{

    int i,j,left,right,top,bottom,k,shift;
     left=0;top=0;right=m-1;bottom=n-1;

     while(top<bottom && left<right)
     {
         shift=mat[top][left];
         for(i=left+1;i<=right;i++)
         {
             k= mat[top][i];
             mat[top][i]=shift;
             shift=k;
         }
         top++;
         for(i=top;i<=bottom;i++)
         {
                k=mat[i][right];
                mat[i][right]=shift;
                shift=k;
         }
         right--;
         for(i=right;i>=left;i--)
         {
             k=mat[bottom][i];
             mat[bottom][i]=shift;
             shift=k;
         }
         bottom--;
         for(i=bottom;i>=top;i--)
         {
             k=mat[i][left];
             mat[i][left]=shift;
             shift=k;
         }
         left++;
         mat[top-1][left-1]=shift;

     }

}

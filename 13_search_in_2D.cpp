bool searchMatrix(vector<vector<int>>& mat, int target) {
  
  //every row of matrix is sorted so we can apply binary search for every row of matrix 
  //if target element present in any row matrix then return true otherwise return false
    int m=mat.size();
    int n=mat[0].size();
        for(int i=0;i<m;i++)
        {
            int start=0;
            int end=n-1;
            while(start<=end)
            {
                int mid=start+(end-start)/2;
                
                if(mat[i][mid]==target)return true;
                else if(mat[i][mid]>target)end=mid-1;
                else start=mid+1;   
            }
        }
        return false;
}

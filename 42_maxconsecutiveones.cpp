int longestSubSeg(vector<int> &arr , int n, int k){
  
   //using sliding window algo ,here window will store maximum k zero 
  
    int start=0;
    int maxconsecutiveones=0;
    int zero=0;
    for(int end=0;end<n;end++)
    {
        if(arr[end]==0)zero++;

        while(zero>k)
        {
            if(arr[start]==0)zero--;
            start++;
        }

        maxconsecutiveones=max(maxconsecutiveones,end-start+1);
    }
    return maxconsecutiveones;
}

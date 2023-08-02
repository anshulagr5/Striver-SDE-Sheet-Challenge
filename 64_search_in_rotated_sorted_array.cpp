int search(int* arr, int n, int k) {

    int low=0;
    int high=n-1;
    int mid;
    while(low<=high)
    {
        mid=low+(high-low)/2;
        if(arr[mid]==k)return mid;
        if(arr[mid]>k) // 4 5 6 8 2 3 -> (1)-> 4 5 6 + (2)-> 2 3 
        {
            if(arr[low]>arr[high]) //check if it is rotated or not
            {
                if(arr[mid]>=arr[low]) // if mid lies on (1) 
                {
                    if(arr[low]<=k)high=mid-1; //check if key lies between (low to mid) ,if(not)-> low=mid+1 ,if(yes)-> high=mid-1
                    else low=mid+1; 
                }
                else high=mid-1; //if mid lies on (2)
            }
            else high=mid-1; // if array is not rotated
        }
        else{
             if(arr[low]>arr[high])  //check if it is rotated or not
             {
                if(arr[mid]>=arr[low]) // check mid lies on (1) or (2)
                    low=mid+1;
                else{
                    if(arr[high]<k)high=mid-1;//check if key lies between (mid to high) ,if(not)-> high=mid-1 ,if(yes)-> low=mid+1
                    else low=mid+1;
                }
             }
            else low=mid+1; // if array is not rotated
          }
    }
    return -1;
}

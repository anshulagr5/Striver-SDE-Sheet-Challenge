int removeDuplicates(vector<int> &arr, int n) {
  
	for(int i=1;i<n;i++)
	{
         if(arr[i]==arr[i-1])
	{
	   arr.erase(arr.begin()+i);
	   n--;
	   i--;
	 }
	}
	return arr.size();
}

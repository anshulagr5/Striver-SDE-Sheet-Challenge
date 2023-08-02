 #include<bits/stdc++.h>
 using namespace std;

vector<int> subsetSums(vector<int> num, int n) {
  if(num.size()==0)return {0};
	if(num.size()==1)return {0,num[0]};
	int n=num.size();
	vector<int>temp=subsetSum((num.begin(),num.end()-1));
	
	int j=0;
	vector<int>ans=temp;
	int check;
	for(int i=0;i<n-1;i++)
	{
		check=num[n-1]+temp[i];
		while(temp[j]<=check)j++;
		ans.insert(ans.begin()+j,check);
		j++;
	}
	return ans;
 }

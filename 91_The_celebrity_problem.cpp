#include <bits/stdc++.h> 

/*
	This is signature of helper function 'knows'.
	You should not implement it, or speculate about its implementation.

	bool knows(int A, int B); 
	Function 'knows(A, B)' will returns "true" if the person having
	id 'A' know the person having id 'B' in the party, "false" otherwise.
*/

int findCelebrity(int n) {
	int left=0;
	int right=n-1;
	while(left<right)
	{
		if(knows(left,right))left++;
	    else right--;
	}

	for(int i=0;i<n;i++){
		if(i!=left && knows(left,i))return -1;
		if(i!=left && !knows(i,left))return -1;
	}
    return left;
}

#include <bits/stdc++.h> 
using namespace std;

struct meeting {
   int s;
   int e;
   int pos;
};


bool static compare(struct meeting &a , struct meeting &b)
{
     if(a.end!=b.end) return a.e < b.e;
     return a.pos<b.pos;
}

vector<int> maximumMeetings(vector<int> &start, vector<int> &end) {
   vector<int>ans;
   int n=start.size();
   
    vector<struct meeting>meetings(n);
    for (int i = 0; i < n; i++) {
         meetings[i].s = start[i];
          meetings[i].e = end[i];
          meetings[i].pos = i + 1;
      }

   sort(meetings.begin(),meetings.end(),compare);
   int limit=meetings[0].e;
   ans.push_back(meetings[0].pos);

   for(int i=1;i<n;i++)
   {
       if(limit<meetings[i].s){
           limit=meetings[i].e;
           ans.push_back(meetings[i].pos);
       }
   }
   return ans;
}

#include <bits/stdc++.h> 
/***************************************************************************

	Class for graph node is as follows:

	class graphNode
	{
		public:
    		int data;
    	vector<graphNode *> neighbours;
    	graphNode()
    	{
        	data = 0;
        	neighbours = vector<graphNode *>();
    	}

    	graphNode(int val)
    	{
        	data = val;
        	neighbours = vector<graphNode *>();
    	}

    	graphNode(int val, vector<graphNode *> neighbours)
    	{
        	data = val;
        	this->neighbours = neighbours;
    	}
	};

******************************************************************************/
void solve(graphNode *node,unordered_map<graphNode*,graphNode*>&mp)
{
	if(!node)
	return;
	mp[node]=new graphNode(node->data);
	for(auto nbr:node->neighbours)
	{
		if(mp[nbr]==NULL)
		solve(nbr,mp);
		mp[node]->neighbours.push_back(mp[nbr]);
	}
}

graphNode *cloneGraph(graphNode *node)
{
    // Write your code here.
	    unordered_map<graphNode*,graphNode*> mp;
	solve(node,mp);
	return mp[node];
}

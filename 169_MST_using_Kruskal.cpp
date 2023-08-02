#include <bits/stdc++.h> 
using namespace std;
class DisjointSet{
	vector<int>parent,size;
	public:
	 DisjointSet(int n)
	 {
         size.resize(n+1,1);
		 parent.resize(n+1);
		 for(int i=0;i<=n;i++)parent[i]=i;
	 }

	 int findUparent(int u){
		 if(u==parent[u])return u;
		 return parent[u]=findUparent(parent[u]);
	 }

	 void uniont(int u,int v)
	 {
		 int x=findUparent(u);
		 int y=findUparent(v);
         if(x==y)return;
		 if(size[x]<size[y])
		 {
             parent[x]=y;
			 size[y]+=size[x];
		 }
		 else
		 {
             parent[y]=x;
			 size[x]+=size[y];
		 }
		 
	 }
};
int kruskalMST(int n, int m, vector<vector<int>> &graph) {
	vector<pair<int,pair<int,int>>>adj(m);
	for(auto it:graph){
		adj.push_back({it[2],{it[0],it[1]}});
	}
	sort(adj.begin(),adj.end());
    DisjointSet ds(n);
	int mincost=0;
	for(auto i:adj){
		int u=i.second.first;
		int v=i.second.second;
		int w=i.first;

		if(ds.findUparent(u)!=ds.findUparent(v)){
             mincost+=w;
			 ds.uniont(u,v);
		}
	}
	return mincost;
}

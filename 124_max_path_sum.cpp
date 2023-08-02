/************************************************************

    Following is the TreeNode class structure

    template <typename T>
    class TreeNode {
       public:
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this->data = data;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/
int helper(TreeNode<int>*root,int&ans)
{
    if(root==NULL)return 0;
    int l=helper(root->left,ans);
    int r=helper(root->right,ans);
    int temp=0;
    if(l>0)temp+=l;
    if(r>0)temp+=r;
    temp+=root->data;
    ans=max(temp,ans);
    return (l<=0 &&r<=0)?root->data:root->data + max(l,r);
}
int maxPathSum(TreeNode<int> *root)
{
    int ans=-1e5;
    helper(root,ans);
    return ans;
}

/*
Following is the class structure of the Node class:

class Node
{
public:
    int data;
    Node *left, *right;
    Node()
    {
        this->data = 0;
        left = NULL;
    }
    Node(int data)
    {
        this->data = data; 
        this->left = NULL;
        this->right = NULL;
    }
    Node(int data, Node* left, Node* right)
    {
        this->data = data;
        this->left = left;
        this->right = right;
    }
};
*/

bool isParentSum(Node *root){
    if(root==NULL)return true;
    if(root->left==NULL && root->right==NULL)return true;
    int lv=0;
    int rv=0;
    if(root->left!=NULL)lv+=root->left->data;
    if(root->right!=NULL)rv+=root->right->data;
    if(lv+rv!=root->data)return false;

    bool l=isParentSum(root->left);
    bool r=isParentSum(root->right);
    if(!l || !r) return false;
    return true;
}

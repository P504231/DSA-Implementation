class Solution {
    int count=0,ans=-1;
  public:
    // Return the Kth smallest element in the given BST
    int KthSmallestElement(Node *root, int K) {
       inorder(root,K);
       return ans;
    }
    void inorder(Node*root,int k)
    {
        if(root==NULL)
         return;
        inorder(root->left,k);
        if(++count==k)
        {
            ans=root->data;
            return;
        }
        inorder(root->right,k);
    }
};

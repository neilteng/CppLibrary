#include<iostream>
using namespace std;
// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// preorder
void prerder(TreeNode* root) 
{ 
	TreeNode *current, *pre; 

	if (root == NULL) 
		return; 

	current = root; 
	while (current != NULL) { 

		if (current->left == NULL) { 
			printf("%d ->", current->val); 
			current = current->right; 
		} 
		else { 

			/* Find the inorder predecessor of current */
			pre = current->left; 
			while (pre->right != NULL && pre->right != current) 
				pre = pre->right; 

			/* Make current as the right child of its inorder 
			predecessor */
			if (pre->right == NULL) { 
                printf("%d ->", current->val); 
				pre->right = current; 
				current = current->left; 
			} 

			/* Revert the changes made in the 'if' part to restore 
			the original tree i.e., fix the right child 
			of predecessor */
			else { 
				pre->right = NULL; 
				current = current->right; 
			} /* End of if condition pre->right == NULL */
		} /* End of if condition current->left == NULL*/
	} /* End of while */
} 

// inorder
void inorder(TreeNode* root) 
{ 
	TreeNode *current, *pre; 

	if (root == NULL) 
		return; 

	current = root; 
	while (current != NULL) { 

		if (current->left == NULL) { 
			printf("%d ->", current->val); 
			current = current->right; 
		} 
		else { 

			/* Find the inorder predecessor of current */
			pre = current->left; 
			while (pre->right != NULL && pre->right != current) 
				pre = pre->right; 

			/* Make current as the right child of its inorder 
			predecessor */
			if (pre->right == NULL) { 
				pre->right = current; 
				current = current->left; 
			} 

			/* Revert the changes made in the 'if' part to restore 
			the original tree i.e., fix the right child 
			of predecessor */
			else { 
				pre->right = NULL; 
				printf("%d ->", current->val); 
				current = current->right; 
			} /* End of if condition pre->right == NULL */
		} /* End of if condition current->left == NULL*/
	} /* End of while */
} 

// reverse inorder
TreeNode* find_inorder_successor(TreeNode* root){
        TreeNode* succ = root->right;
        while(succ->left!=nullptr and succ->left!=root){
            succ=succ->left;
        }
        return succ;
    }

TreeNode* post_order(TreeNode* root) {
    TreeNode* cur=root;
    while (cur!=nullptr){
        if (cur->right == nullptr) {
            cout<<cur->val<<"->";
            cur = cur->left;
        }
        else{
            TreeNode* succ=find_inorder_successor(cur);
            if (succ->left==nullptr){
                succ->left=cur;
                cur=cur->right;
            }
            else{
                succ->left=nullptr;
                cout<<cur->val<<"->";
                cur=cur->left;
            }
        }
    }
    return root;
}


/* Driver program to test above functions*/
int main() 
{ 
  
    /* Constructed binary tree is 
            1 
          /   \ 
        2      3 
      /  \ 
    4     5 
  */
    TreeNode* root = new TreeNode(1); 
    root->left = new TreeNode(2); 
    root->right =new TreeNode(3); 
    root->left->left =new TreeNode(4); 
    root->left->right =new TreeNode(5); 
  
    preorder(root); 
    cout<<'\n';
    inorder(root); 
    cout<<'\n';
    post_order(root);

    return 0; 
}


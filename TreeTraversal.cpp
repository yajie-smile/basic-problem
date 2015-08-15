#include<iostream>
#include<stack>
#include<queue>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
void preOrder(TreeNode* root) {
    if(root == NULL) return;
    cout<<root->val<<" ";
    if(root->left != NULL) preOrder(root->left);
    if(root->right != NULL) preOrder(root->right);
}
void preOrder(TreeNode* root) {
    if(NULL == root) return;
    
    stack<TreeNode*> stk;
    TreeNode* node = root;
    
    stk.push(node);
    
    while(!stk.empty()) {
        node = stk.top();
        stk.pop();
        cout<<node->val<<" ";
        
        if(node->right != NULL) stk.push(node->right);
        if(node->left != NULL) stk.push(node->left);
    }
}
void inOrder(TreeNode* root) {
    if(root == NULL) return;
    if(root->left != NULL) inOrder(root->left);
    cout<<root->val<<" ";
    if(root->right != NULL) inOrder(root->right);
}
void inOrder(TreeNode* root) {
    if(NULL == root) return;
    
    stack<TreeNode*> stk;
    TreeNode* node = root;
    
    while(node != NULL || !stk.empty()) {
        while(node != NULL) {
            stk.push(node);
            node = node->left;
        }
        
        node = stk.top();
        stk.pop();
        cout<<node->val<<" ";
        
        node = node->right;
    }
}
void postOrder(TreeNode* root) {
    if(root == NULL) return;
    if(root->left != NULL) postOrder(root->left);
    if(root->right != NULL) postOrder(root->right);
    cout<<root->val<<" ";
}
void postOrder(TreeNode* root) {
    if(NULL == root) return;
    
    stack<TreeNode*> stk;
    TreeNode* node = root, *pre;
    
    stk.push(node);
    
    while(!stk.empty()) {
        while(node != NULL) {
            if(node != root)
                stk.push(node);
            node = node->left;
        }
        
        pre = NULL;
        while(!stk.empty()) {
            node = stk.top();
            stk.pop();
            if(node->right == pre) {
                cout<<node->val<<" ";
                pre = node;
            }
            else {
                stk.push(node);
                node = node->right;
                break;
            }
        }
    }
}

void dfs(TreeNode* root) {
    if(NULL == root) return;
    
    stack<TreeNode*> stk;
    TreeNode* node = root;
    
    stk.push(node);
    
    while(!stk.empty()) {
        node = stk.top();
        stk.pop();
        cout<<node->val<<" ";
        
        if(node->right != NULL) stk.push(node->right);
        if(node->left != NULL)  stk.push(node->left);
    }
    
}

void bfs(TreeNode* root) {
    if(NULL == root) return;
    
    queue<TreeNode*> que;
    TreeNode* node = root;
    
    que.push(node);
    
    while(!que.empty()) {
        node = que.front();
        que.pop();
        cout<<node->val<<" ";
        
        if(node->left != NULL)  que.push(node->left);
        if(node->right != NULL) que.push(node->right);
    }
}

int main() {
    TreeNode root = TreeNode(1), node11 = TreeNode(2), node12 = TreeNode(3), node21 = TreeNode(4), node22 = TreeNode(5), node23 = TreeNode(6);
    root.left = &node11, root.right = &node12;
    node11.left = &node21, node11.right = &node22;
    node12.left = &node23;
    
    //    preOrder(&root);
    //    inOrder(&root);
    //    postOrder(&root);
    //    dfs(&root);
    bfs(&root);
    cout<<endl;
    
    return 0;
}
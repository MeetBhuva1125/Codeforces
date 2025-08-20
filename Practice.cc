#include<bits/stdc++.h>
using namespace std;

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode() : val(0), left(nullptr), right(nullptr){};
    TreeNode(int x) : val(x), left(nullptr), right(nullptr){};
};

struct ListNode{
    int val;
    ListNode* next;

    ListNode() : val(0), next(nullptr){};
    ListNode(int x) : val(x), next(nullptr){};
};

TreeNode* BuildBinaryTree(){
    TreeNode* root = new TreeNode(50);

    root -> left = new TreeNode(40);
    root -> right = new TreeNode(60);
    root -> left -> left = new TreeNode(30);
    root -> left -> right = new TreeNode(20);

    return root;
}

void Preorder(TreeNode* root){
    if(root==NULL)return;

    cout << root->val << " ";
    Preorder(root->left);
    Preorder(root->right);
}

void Inorder(TreeNode* root){
    if(root==NULL)return;

    Inorder(root->left);
    cout << root->val << " ";
    Inorder(root->right);
}

void Postorder(TreeNode* root){
    if(root==NULL)return;

    Postorder(root->left);
    Postorder(root->right);
    cout << root->val << " ";
}

void LevelOrder(TreeNode *root){
    if (root == NULL) {
        cout << "\n0"; // Height of an empty tree is 0
        return;
    }
    //{Node,height}
    queue<pair<TreeNode*, int>> q;
    int max_height = 0; // To store the maximum level reached

    // Push the root node with its level (level 1 for the root)
    q.push({root, 1});
    while (!q.empty()) {
        TreeNode* node = q.front().first;
        int current_level = q.front().second;
        q.pop();

        // Print the node's value
        cout << node->val << " ";

        // Update max_height with the current_level.
        // Since we process nodes level by level, the last node processed
        // will have its level recorded, which will correspond to the tree's height.
        max_height = current_level;

        // Add left child to the queue with incremented level
        if (node->left) {
            q.push({node->left, current_level + 1});
        }
        // Add right child to the queue with incremented level
        if (node->right) {
            q.push({node->right, current_level + 1});
        }
    }
    // Print the calculated height
    cout << "\n" << max_height;
}

void StringStreamInput(){
        cin.ignore();
        string line;
        getline(cin, line);
        stringstream ss(line);
        
        int num;
        int n=0;
        while (ss >> num) {
            cout << num << " ";
            n++;
        }
        cout <<"\n" << n ;
}


TreeNode* build(TreeNode *root, int data){
    if(root==NULL){
        return new TreeNode(data);
    }

    if(data<=root->val){
        root->left=build(root->left,data);
    }
    else{
        root->right=build(root->right,data);
    }

    return root;
}

void BST(){
    string line;
    getline(cin,line);
    stringstream ss(line);
    vector<int> numbers;

    int num;
    while(ss >> num){
        numbers.push_back(num);
    }
    
    TreeNode* root;
    for(int i=0; i<numbers.size(); i++){
        root = build(root,numbers[i]);
    }
}

int main(){
    TreeNode* root = BuildBinaryTree();
    LevelOrder(root);
}
// Please Online Edit Code here: https://repl.it/repls/GlitteringEcstaticMegahertz
// Please Online Back Up here: https://www.programiz.com/cpp-programming/online-compiler/
// Please Online Debug here: https://wandbox.org/
// $ clang++ prog.cc -Wall -Wextra -I/opt/wandbox/boost-1.73.0/clang-head/include -std=gnu++2a 
#include <iostream> 
#include <iostream>
#include <vector>
#include <queue> 
#include<climits>  
#include <algorithm>
using namespace std;
struct TreeNode {
  string val;
  TreeNode *left;
  TreeNode *right;
  inline TreeNode():val(0), left(NULL), right(NULL) {}
  inline TreeNode(string x) : val(x), left(NULL), right(NULL) {}
  inline TreeNode(string x, TreeNode *left, TreeNode *right):val(x), left(left), right(right) {}
};
TreeNode* incompleteTreeCreate(vector<string> vec_str, vector<string>::size_type root_node_index){
    if (root_node_index > vec_str.size() -1 || vec_str[root_node_index] == "#" || vec_str[root_node_index] == "NULL") {
        return NULL;
    }
    TreeNode *root = new TreeNode(vec_str[root_node_index]);
    
    vector<string>::size_type left_node_index = 2*root_node_index + 1;
    vector<string>::size_type right_node_index = 2*(root_node_index + 1);
    if (left_node_index > vec_str.size() -1 || vec_str[left_node_index] == "#" || vec_str[left_node_index] == "NULL") {
        root -> left = NULL;
    }else{
        root -> left = incompleteTreeCreate(vec_str, left_node_index);
    }
    if (right_node_index > vec_str.size() -1 || vec_str[right_node_index] == "#" || vec_str[right_node_index] == "NULL") {
        root -> right =NULL;
    }else{
        root -> right = incompleteTreeCreate(vec_str, right_node_index);
    }
    return root;
}
bool inputNodeTrue(vector<string> vec_str) {
    bool node_true;
    vector<size_t> node_input_error_index;
    for(vector<string>::size_type i = 0; i < vec_str.size(); ++i) {
        if(vec_str[i] == "#" || vec_str[i] == "NULL") {
        
        }else if(isdigit(vec_str[i][0]) ) {
            string int_str = vec_str[i];
            for(int j = int_str.length()-1; j > 0; --j){
                if(!isdigit(int_str[j])) {
                    node_input_error_index.push_back(i);
                }
            }
        } else {
            node_input_error_index.push_back(i); 
        }// if-else..
    } // for...
    if(!node_input_error_index.empty()) {
        cout << "     " << "YOU INPUTTING  ";
        for(size_t i = 0; i < node_input_error_index.size(); ++i) {
            cout << node_input_error_index[i] << ' ' << "th " << vec_str[node_input_error_index[i]] << ' ';
            node_true = false;
        } // for .
        cout << " " << "ERROR" << endl;
    } else {
        cout << "  " << "Congratulations ! INPUTTING YES." << endl;
        node_true = true;
    } //if-else ..
    return node_true;
} // bool inputNodeTrue();
// Your Code here: function below, recursion
void mirroTree(TreeNode *root)  
{  
    if(NULL == root) return;  
    if(NULL == root->left && NULL == root->right)  return;   
    TreeNode *temp = root->left;  
    root->left = root->right;  
    root->right = temp;   
    if(root->left)   mirroTree(root->left);  
    if(root->right)   mirroTree(root->right);  
}  
/*
// Your Code here: function below, no-recursion
void mirroTreeN(TreeNode *root) {  
    if(NULL == root) return;  
    if(NULL == root) return;  
    queue<TreeNode*> q;  q.push(root);
    TreeNode *node;
    while(!q.empty())  {  
        node = q.front();  q.pop();  
        if(NULL != node->left || NULL != node->right)  {  
            TreeNode *temp = node->left;  
            node->left = node->right;  
            node->right = temp;  
        }  
        if(NULL != node->left)   q.push(node->left);  
        if(NULL != node->right)   q.push(node->right);  
    }  
}  
*/
//...
void preOrderTraverse(TreeNode *root){
    if(root){
        cout<<root->val<<" ";                
        preOrderTraverse(root->left);           
        preOrderTraverse(root->right);           
    }
    return;
}
int main() {
  //...
  string str_in;
  vector<string> vec_str_in_node;
  cout << "Please input Tree nodes' values by level, values must be int,"<< endl;
  cout << "'#' or 'NULL' represents nullptr, '\\n' means to end input." << endl;
  while(cin >> str_in) {
      vec_str_in_node.push_back(str_in);
  }
  cout << "     " << "YOU INPUT TREE NODE BELOW" << endl;
  for(vector<string>::size_type i = 0; i < vec_str_in_node.size(); ++i) {
      cout << vec_str_in_node[i] << ' ';
  }
  cout << endl;
  TreeNode *T;
  bool againYes = inputNodeTrue(vec_str_in_node);
  if(againYes) {
      T = incompleteTreeCreate(vec_str_in_node, 0);
      // Your Code here.
      cout << "          " << "The pre order is  " << endl;
      preOrderTraverse(T);
      cout << endl;
      mirroTree(T);
      cout << "          " << "The pre order is  " << endl;
      preOrderTraverse(T);
      //..
  }
  return 0;
}

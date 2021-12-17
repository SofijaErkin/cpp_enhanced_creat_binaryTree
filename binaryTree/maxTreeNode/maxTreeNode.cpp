// Please Online Edit Code here: https://repl.it/repls/GlitteringEcstaticMegahertz
// Please Online Back Up here: https://www.programiz.com/cpp-programming/online-compiler/
// Please Online Debug here: https://wandbox.org/
// $ clang++ prog.cc -Wall -Wextra -I/opt/wandbox/boost-1.73.0/clang-head/include -std=gnu++2a 
#include <iostream>
#include <iostream>
#include <vector> // vector<sting> ; vector<int>;
#include <string> // stoi(); sting val;
#include <cctype> // isdigit();
#include <climits> // INT_MIN;
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
        cout << "    " << "Congratulations ! INPUTTING YES." << endl;
        node_true = true;
    } //if-else ..
    return node_true;
} // bool inputNodeTrue();

// Your Code here: function below, recursion
int findMax(TreeNode* root) {  
    // Base case  
    if (root == NULL)  
        return INT_MIN;  
    // Return maximum of 3 values:  
    // 1) Root's data 2) Max in Left Subtree  
    // 3) Max in right subtree  
    int max_t = stoi(root->val);  
    int max_l = findMax(root->left);  
    int max_r = findMax(root->right);  
    if (max_l > max_t)  
    max_t = max_l;  
    if (max_r > max_t) 
        max_t = max_r;  
    return max_t;  
}  
// Your Code here: function below, no-recursion
/*
#include <climits> // INT_MIN
#include <string> // stoi()
#include <queue> // queue<TreeNode*>
#include <algorithm> // max()
int findMaxN(TreeNode* root){ //NRCRS  
    // Base case  
    if (root == NULL)  return INT_MIN;  
    // Return maximum of 3 values:  
    // 1) Root's data 2) Max in Left Subtree  
    // 3) Max in right subtree  
    int max_t = stoi(root->val);  
    queue<TreeNode*> q; q.push(root);
    TreeNode *node; 
    int node_val;
    while(!q.empty()) {
      for(size_t i = q.size();i > 0; --i) {
        node = q.front(); q.pop();
        node_val = stoi(node->val);
        max_t = max(max_t, node_val);
        if(node->left != NULL) q.push(node->left);
        if(node->right != NULL) q.push(node->right);
      }
    }  
    return max_t;  
}  
*/
int main(){ 
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
        cout << "          " << "The pre order is  " << endl;
        // Your Code here.
        // preOrderTraverse(T);
        cout << "       " << "Maximum element is " << findMax(T) << endl;
        //.
    }
    return 0;
}

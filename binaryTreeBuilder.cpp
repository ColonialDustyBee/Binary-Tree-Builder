#include <iostream>
#include <fstream>
#include <string>
#include <stack>

struct TreeNode {
    TreeNode* left = nullptr;
    TreeNode* right = nullptr;
    int data = 0;
};

// Simulates the call stack
TreeNode* findPositionOfNode(TreeNode* parent, int a) {
    std::stack<TreeNode*> stackOfBT;
    stackOfBT.push(parent);
    while (!stackOfBT.empty()) {
        TreeNode* temp = stackOfBT.top(); // Fetches top of stack to be used for comparison
        if (temp->data == a) {
            return temp;
        }
        stackOfBT.pop(); // Popped if it isn't the node we are looking for
        if (temp->left != nullptr) {  // Left Subtree pushed onto stack
            stackOfBT.push(temp->left);
        }
        if (temp->right != nullptr) { // Right Subtree pushed onto stack
            stackOfBT.push(temp->right);
        }
    }
}

void addNodesToTree(std::string& edgeCase, TreeNode* parent, TreeNode*& child, int a, int b) {
    TreeNode* temp = findPositionOfNode(parent, a);
    if (edgeCase == "L") {
        child = new TreeNode;
        child->left = nullptr;
        child->right = nullptr;
        child->data = b;
        temp->left = child;

    }
    else if (edgeCase == "R") {
        child = new TreeNode;
        child->left = nullptr;
        child->right = nullptr;
        child->data = b;
        temp->right = child;
    }
}
// TRAVERSALS //
void preOrderTraversal(TreeNode*& root) { // Recursive
    if (root == nullptr) {
        return;
    }
    std::cout << root->data << " ";
    preOrderTraversal(root->left); // All prefixes from the left.
    preOrderTraversal(root->right); // All prefixes from the right.
}
void inOrderTraversal(TreeNode*& root){
    if (root == nullptr){
        return;
    }
    inOrderTraversal(root->left);
    std::cout << root->data << " ";
    inOrderTraversal(root->right);
}
void postOrderTraversal(TreeNode*& root){
    if (root == nullptr){
        return;
    }
    postOrderTraversal(root->left);
    postOrderTraversal(root->right);
    std::cout << root->data << " ";
}

int main() {
    int a, b = 0;
    char menuInput;
    bool first = false;
    TreeNode* root = new TreeNode;
    TreeNode* child;
    std::fstream fileIO;
    std::string input;
    std::cout << "Please input the corresponding text file that contains the binary tree you wish to build: " << std::endl;
    getline(std::cin, input);
    fileIO.open(input);
    if(fileIO.is_open()){
        while (!fileIO.eof()) {
            if (!first) { // Basically initializes the parent and child node in the first line.
                getline(fileIO, input, ',');
                a = stoi(input);
                getline(fileIO, input, ' ');
                b = stoi(input);
                getline(fileIO, input);
                root->left = nullptr;
                root->right = nullptr;
                root->data = a;
                addNodesToTree(input, root, child, a, b);
                first = true;
            }
            getline(fileIO, input, ',');
            a = stoi(input);
            getline(fileIO, input, ' ');
            b = stoi(input);
            getline(fileIO, input);
            addNodesToTree(input, root, child, a, b);
        }
        fileIO.close();
    }
    else{
        std::cout << "Unable to open file." << std::endl;
        return 1;    
    }
    std::cout << "Choose one of the following traversals to conduct:\n1 for preorder\n2 for inorder\n3 for postorder" << std::endl;
    std::cin >> menuInput;
        switch(menuInput){
            default:
                std::cout << "Incorrect input";
                break;
            case '1':
                preOrderTraversal(root);
                break;
            case '2':
                inOrderTraversal(root);
                break;
            case '3':
                postOrderTraversal(root);
                break;
        }
    return 0;
}

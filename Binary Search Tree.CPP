#include <iostream>
using namespace std;

class Node{
public:
    int data;     //node data
    Node *left;   //pointer to the left node
    Node * right; //pointer to the right node

    Node(int data, Node* left = nullptr, Node* right = nullptr) { //Node constructor
        this->data = data;
        this->left = left;
        this->right = right;
    }
}

void preOrder(Node *x){
    /*
     *@brief Pre Order traversal : root => left => right
     *@param reference to a node which we have to start the traversal
     *return void print the BST according to the Pre Order
     *
     
    */

    if(x != nullptr){

        cout << x -> data;
        preOrder(x -> left);
        preOrder(x -> right);
    }
}

void inOrder(Node *x){
    /*
     *@brief In Order traversal : left => root => right
     *@param reference to a node which we have to start the traversal
     *return void print the BST according to the In Order
     *
     * complexity O(n)
     
    */
   
    if(x != nullptr){

        inOrder(x -> left);
        cout << x -> data;
        inOrder(x -> right);
    }
}

void postOrder(Node *x){
    /*
     *@brief Post Order traversal : left => right => root
     *@param reference to a node which we have to start the traversal
     *return void print the BST according to the Post Order
     *
     
    */
   
    if(x != nullptr){

        postOrder(x -> left);
        postOrder(x -> right);
        cout << x -> data;

    }
}

Node* BST_search(Node *root, int key){
    /*
     * @brief serching for a node
     * @param root refernce to the root of the BST  
     * @param key refernce to the data we have to search
     * @return Node which contain the key value
    */

    if(root -> data == key){  //Here root is a pointer. we are returning a pointer. Therefore return type must be Node*. If we use Node as the return type a copy of root will be returned. Not the actual one
        return root;
    }

    else if(root -> data > key){
        return BST_search(root -> left, key);
    }

    else{
        return BST_search(root -> right, key);
    }

}

void BST_insert(Node *root, int key){
    Node *x =root;
    Node *y;

    while(x != nullptr){
    
        y = x;

        if(x -> data > key){
            x = x -> left;

        }
        else{
            x = x -> right;
        }
    }

    Node *z= new Node(key);

    if(y -> data > key){
        y -> left = z;
    }

    else if(y -> data < key){
        y -> right = z;
    }

    else{
        root = z;
    }
}


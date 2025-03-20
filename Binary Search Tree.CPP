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

//..............................................................................................................//
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

//..............................................................................................................//
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

//...............................................................................................................//
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
//...............................................................................................................//
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

    else if(root -> data > key){ //Here instead of root->data we can use (*root).data. It is also correct

        return BST_search(root -> left, key);
    }

    else{
        return BST_search(root -> right, key);
    }

}
//...............................................................................................................//
Node* BST_insert(Node *root, int key){
    /*
    * @brief insert a node to the BST
    * @param root refer to the root of the BST
    * @param key refer to the data that should be inserted
    * @return a pointer to the root of the BST
    * 
    */

    if(root == nullptr){
        return new Node(key);
    }
    Node *x =root;
    Node *y;

    while(x != nullptr){ //finding the parent node for the  new node
        y = x;

        if(x -> data > key){
            x = x -> left;

        }
        else{
            x = x -> right;
        }
    }

    Node *z= new Node(key); //create a new node using the key value

    if(y -> data > key){   //insert as the left child of the parent y
        y -> left = z;
    }

    else {                 //insert as the right child of the parent y
        y -> right = z;
    }

    return root;
}

//..............................................................................................................//
Node* findMax(Node *x){
    /*
    * @brief finding the maximum node in the left subtree
    * @param x refer to a pointer which point towards a node which is the root of the left subtree
    * @ return a pointer to the maximum node
    */
    if(x == nullptr){ //if x is a NULL node
        return nullptr;
    }

    while(x -> right != nullptr){ //otherwise trvaerse to the rightmost node which is the maximum
        x = x -> right;
    }
    return x;  //return the maximum
}

//...............................................................................................................//
Node* BST_delete(Node *root, int key){
    /*
    * @breif delete a node
    * @param root refer to the root of the BST
    * @param the data in the deleted node
    * @return the pointer to the root of the modified BST
    */

    if(root == nullptr){ //if the Tree is empty
        cout << "Tree is empty";
        return nullptr;
    }
    Node *x = root;
    Node *y;

    //taking the node to be deleted as x and its parent as y
    while(x -> data != key){
        if (root == nullptr) return root;

        y=x;

        if(x -> data > key){
            x = x ->left;
        }
        else{
            x = x -> right;
        }

    }
    //if the key node isn't found
    if(x == nullptr){
        cout << "Key not found";
        return root;
    }
    
    //if the x is a leaf node
    else if(x -> left == nullptr && x -> right == nullptr ){
    
        if (y == nullptr) return nullptr;       //if x is the root node
        if(y -> left == x) y -> left = nullptr; //replace the x with nullptr
        else y -> right = nullptr;              //replace the x with nullptr
        delete x;                               //delete x
        
    }
    //if the x has only a left child
    else if(x -> left != nullptr && x -> right == nullptr ){
        if (y == nullptr) x = x -> left;            //if x is the root node replace x with its left child
        if(y -> left == x) y -> left = x -> left;   //replace the x with its left child
        else y -> right = x -> left;                //replace the x with its left child
        delete x;

    }
    //if the x has only a right child
    else if(x -> left == nullptr && x -> right != nullptr ){
        if (y == nullptr) x = x -> right;           //if x is the root node replace x with its right child
        if(y -> left == x) y -> left = x -> right;  //replace the x with its right child
        else y -> right = x -> right;               //replace the x with its right child
        delete x;

    }
    //if x has both left and right childs
    else{
        Node *max = findMax(x->left);    //find the maximum node in the left subtree of the x  
        x -> data = max -> data;         //replace data of the x with data of the maximum  
        x -> left = BST_delete(x -> left, max -> data);  //delete the maximum node
        

    }
    return root; //return the root of the modified tree
}


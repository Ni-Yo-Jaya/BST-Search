#include <iostream>
using namespace std;

class Node{

    int data;     //node data
    Node *left;   //pointer to the left node
    Node * right; //pointer to the right node

}

void preOrder(Node x){
    /*
     *@brief Pre Order traversal : root => left => right
     *@param reference to a node which we have to start the traversal
     *return void print the BST according to the Pre Order
     *
     
    */

    if(x != Null){

        cout << x.data;
        preOrder(x.left);
        preOrder(x.right);
    }
}

void inOrder(Node x){
    /*
     *@brief In Order traversal : left => root => right
     *@param reference to a node which we have to start the traversal
     *return void print the BST according to the In Order
     *
     * complexity O(n)
     
    */
   
    if(x != Null){

        inOrder(x.left);
        cout << x.data;
        inOrder(x.right);
    }
}

void postOrder(Node x){
    /*
     *@brief Post Order traversal : left => right => root
     *@param reference to a node which we have to start the traversal
     *return void print the BST according to the Post Order
     *
     
    */
   
    if(x != Null){

        postOrder(x.left);
        postOrder(x.right);
        cout << x.data;
        
    }
}


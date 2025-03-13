
#include <iostream>;
using namespace std;

//Creating a node
class Node{
public:
    int data; //data consist in a node
    Node *left; //pointer to its left node
    Node *right; //pointer to its right node

    Node(int data){
        data=data;
        left=nullptr;
        right=nullptr;
    }

}
//in order traversal
void BTS_inorder_traversal(Node x){
    if(x!=NULL){
        BTS_inorder_traversal(x.left);
        cout<<x.data;
        BTS_inorder_traversal(x.right);

    }

}
//pre order traversal
void BTS_preorder_traversal(Node x){
    if(x!=NULL){
        
        cout<<x.data;
        BTS_inorder_traversal(x.left);
        BTS_inorder_traversal(x.right);

    }

}

//post order traversal
void BTS_preorder_traversal(Node x){
    if(x!=NULL){
        
        BTS_inorder_traversal(x.left);
        BTS_inorder_traversal(x.right);
        cout<<x.data;

    }

}
//BTS search algorithm
void BTS_search(Node root,int key){
    // if the tree only consist the root and it is equal to the key we are searching
    if(root.left==nullptr && root.right==nullptr && root.data==key){
        return root;
    }
    // if the  searched value is less than the root data, traverse in the left sub tree
    else if(root.data>key){
        BTS_search(root.left,key);
    }

    // if the searched value is higher than the root data, traverse in the right sub tree
    else{
        BTS_search(root.right,key);
    }
    
}
//BTS insert algorithm
void BTS_insert(Node root,int key){
    Node y=NULL;
    Node x=root;

    while(x!= NULL){
        y=x
        if(key<x.data){
            x=x.left;

        }
        else{
            x=x.right;
        }

    }
    Node to_insert = y;
    if(y==NULL){
        root = to_insert;
    }
    else if(y.data<key){
        y.left=to_insert;
    }
    else{
        y.right=to_insert;
    }
}



int main(){
        struct node *root = NULL;
      
        int operation;
        int operand;
        cin >> operation;
      
        while (operation != -1) {
          switch(operation) {
            case 1: // insert
              cin >> operand;
              root = BTS_insert(root, operand);
              cin >> operation;
              break;
            case 2: // delete
              cin >> operand;
              root = BTS_delete(root, operand);
              cin >> operation;
              break;
            default:
              cout << "Invalid Operator!\n";
              return 0;
          }
        }
        
        BTS_inorder_traversal(root);
      }



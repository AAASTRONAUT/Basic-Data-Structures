//
//  main.cpp
//  BST
//
//  Created by Shivansh Jain on 23/02/23.
//

#include <iostream>
#include "queueBST.h"
#include "stackBST.h"
using namespace std;

class BST{
public:
    node * root;
    BST(){
        root = NULL;
    }
    void create(int A[] , int nodes);
    void insert(int x);
    node * Rinsert(node * root , int x);
    void inorder(node * root);
    int height(node * root);
    node * inpre(node * root);
    node * insucc(node * root);
    node * Delete(node * root , int x);
    node * preToTree(int pre[] , int nodes);
};

void BST::create(int A[] , int nodes){
    root = new node;
    root->data = A[0];
    root->left = root->right = NULL;
    for(int i = 1 ; i<nodes ; i++){
        node * iter = root;
        node * trail = NULL;
        node * temp = new node;
        temp->data = A[i];
        temp->left = temp->right = NULL;
        
        while(iter != NULL){
            trail = iter;
            if(iter->data > A[i]){
                iter = iter->left;
            }
            else{
                iter = iter->right;
            }
        }
        if(trail->data < A[i]){
            trail->right = temp;
        }
        else{
            trail->left = temp;
        }
    }
}

void BST::insert(int x){
    if(root != NULL){
        node * iter = root;
        node * trail = NULL;
        
        node * temp = new node;
        temp->data = x;
        temp->left = temp->right = NULL;
        
        while(iter != NULL){
            trail = iter;
            if(iter->data > x){
                iter = iter->left;
            }
            else{
                iter = iter->right;
            }
        }
        if(trail->data < x){
            trail->right = temp;
        }
        else{
            trail->left = temp;
        }
    }
    else{
        root->data = x;
        root->left = root->right = NULL;
    }
}

node * BST::Rinsert(node * root , int x){
    if(root!= NULL){
        if(root->data < x){
            root->right = Rinsert(root->right , x);
        }
        else{
            root->left = Rinsert(root->left , x);
        }
    }
    else{
        root = new node;
        root->data = x;
        root->left = root->right = NULL;
    }
    return root;
}

void BST::inorder(node * root){
    if(root!=NULL){
        inorder(root->left);
        cout<<root->data<<"\t";
        inorder(root->right);
    }
}

node * BST::insucc(node * root){
    if(root!= NULL){
        root = root->right;
        while(root->left != NULL){
            root = root->left;
        }
        return root;
    }
    else return NULL;
}

node * BST::inpre(node * root){
    if(root!= NULL){
        root = root->left;
        while(root->right != NULL){
            root = root->right;
        }
        return root;
    }
    else return NULL;
}

int BST::height(node * root){
    int x , y;
    if(root != NULL){
        x = height(root->left);
        y = height(root->right);
        if(x > y) return ++x;
        else return ++y;
    }
    else return 0;
}

node * BST::Delete(node * root , int x){
    if(root!= NULL){
        if(x > root->data){
            root->right = Delete(root->right , x);
        }
        else if(x < root->data){
            root->left = Delete(root->left ,  x);
        }
        else{
            if(root->left == NULL && root->right == NULL){
                delete root;
                root = NULL;
            }
            else{
                if(height(root->left) > height(root->right)){
                    node * newroot = inpre(root);
                    root->data = newroot->data;
                    root->left =  Delete(root->left , newroot->data);
                }
                else{
                    node * newroot = insucc(root);
                    root->data = newroot->data;
                    root->right = Delete(root->right , newroot->data);
                }
            }
        }
        return root;
    }
    else return NULL;
}

node * BST::preToTree(int pre[] , int nodes){
    stack store(nodes);
    node * gen = new node;
    gen->data = pre[0];
    gen->left = gen->right = NULL;
    node * iter = gen;
    int i = 1;
    while(i<nodes){

        if(pre[i] < iter->data){
            node * temp = new node;
            temp->data = pre[i++];
            temp->left = temp->right = NULL;

            store.push(iter);
            iter->left = temp;
            iter = iter->left;
        }
        else{
            if(!store.isEmpty()){
                node * temp = new node;
                temp->left = temp->right = NULL;
                if(iter->data < pre[i] && pre[i] < store.topele()->data){
                    temp->data = pre[i++];
                    iter->right = temp;
                    iter = iter->right;
                }
                else{
                    iter = store.pop();
                }
            }
            else{
                node * temp = new node;
                temp->data = pre[i++];
                temp->left = temp->right = NULL;
                iter->right = temp;
                iter = iter->right;
            }
        }
    }
    return gen;
}

int main() {
    int size;
    cout<<"Enter number of nodes of the tree: ";
    cin>>size;
    cout<<"Enter node values of the BST: \n";
    int A[size];
    for(int i=0 ; i<size ; i++){
        cin>>A[i];
    }
    
    BST bintree;
    bintree.create(A , size);
    bintree.inorder(bintree.root);
    cout<<endl;
    int x;
    cout<<"Enter element to be inserted in the tree: ";
    cin>>x;
    bintree.insert(x);
    cout<<"BST after insertion: \n";
    bintree.inorder(bintree.root);
    cout<<endl;
    
    cout<<"Enter element to be inserted recursively in the tree: ";
    cin>>x;
    bintree.Rinsert(bintree.root , x);
    cout<<"BST after recursive insertion: \n";
    bintree.inorder(bintree.root);
    cout<<endl;
    
    cout<<"Enter element ot be deleated: ";
    cin>>x;
    bintree.Delete(bintree.root, x);
    bintree.inorder(bintree.root);
    cout<<endl;
    
    int s;
    cout<<"Enter size of the preorder array: ";
    cin>>s;
    int pre[size];
    for(int i = 0 ; i<size ; i++){
        cin>>pre[i];
    }
    
    BST newtree;
    newtree.root = newtree.preToTree(pre, 7);
    newtree.inorder(newtree.root);
    return 0;
}

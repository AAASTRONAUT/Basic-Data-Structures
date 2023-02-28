//
//  main.cpp
//  Tree
//
//  Created by Shivansh Jain on 21/02/23.
//

#include <iostream>
#include "queue.h"
#include "stack.h"

class tree{
public:
    node * root;
    tree(){
        root = NULL;
    }
    void create(int nodes);
    
    void preorder(node * root);
    void inorder(node * root);
    void postorder(node * root);
    void levelorder(node * root);
    int count(node * root);
    int height(node * root);
    void itrPreorder(node * root , int nodes);
    void itrInorder(node * root , int nodes);
    void itrPostorder(node * root , int nodes);
};

void tree::create(int nodes){
    root = new node;
    queue  q(nodes);
    cout<<"Enter the value of root: ";
    cin>>root->data;
    root->left = root->right = NULL;
    q.enqueue(root);
    while(!q.isFull()){//isFull function tells whether i can insert or can i dequeue more elements from the queue or not
        node * last = q.dequeue();
        
        int x;
        cout<<"Enter left element of "<<last->data<<" :";
        cin>>x;
        if(x == -1){}
        else{
            node * Newleft = new node;
            Newleft->data = x;
            Newleft->right = Newleft->left = 0;
            last->left = Newleft;
            q.enqueue(Newleft);
        }
        if(q.isEmpty()){ //isEmpty function tells whether i can insert more elements or not in a tree
            cout<<"Enter right element of "<<last->data<<" :";
            cin>>x;
            if(x == -1){}
            else{
                node * Newright = new node;
                Newright->data = x;
                Newright->right = Newright->left = 0;
                last->right = Newright;
                q.enqueue(Newright);
            }
        }
    }
    cout<<"Tree full!!\n";
}

void tree::preorder(node * root){
    if(root!=NULL){
        cout<<root->data<<"\t";
        preorder(root->left);
        preorder(root->right);
    }
}

void tree::inorder(node * root){
    if(root!=NULL){
        inorder(root->left);
        cout<<root->data<<"\t";
        inorder(root->right);
    }
}

void tree::postorder(node * root){
    if(root!=NULL){
        postorder(root->left);
        postorder(root->right);
        cout<<root->data<<"\t";
    }
}

void tree::levelorder(node * root){
    if(root!= NULL){
        queue record(100);
        record.enqueue(root);
        cout<<root->data<<"\t";
        while(!record.isFull()){
            node * temp = record.dequeue();
            if(temp->left){
                cout<<temp->left->data<<"\t";
                record.enqueue(temp->left);
            }
            if(temp->right){
                cout<<temp->right->data<<"\t";
                record.enqueue(temp->right);
            }
        }
    }
}

int tree::count(node * root){
    int x , y;
    if(root!= NULL){
        x = count(root->left);
        y = count(root->right);
        return x + y + 1;
    }
    else return 0;
}

int tree::height(node * root){
    int x , y;
    if(root!= NULL){
        x = height(root->left);
        y = height(root->right);
        if(x > y) return ++x;
        else return ++y;
    }
    else return 0;
}

void tree::itrPreorder(node *root , int nodes){
    stack record(nodes);
    while(root!= NULL || !record.isEmpty()){
        if(root != 0){
            cout<<root->data<<"\t";
            record.push(root);
            root = root->left;
        }
        else{
            root = record.pop();
            root = root->right;
        }
    }
}

void tree::itrInorder(node *root , int nodes){
    stack record(nodes);
    while(root!= NULL || !record.isEmpty()){
        if(root != 0){
            record.push(root);
            root = root->left;
        }
        else{
            root = record.pop();
            cout<<root->data<<"\t";
            root = root->right;
        }
    }
}

void tree::itrPostorder(node * root , int nodes){
    stack record(nodes);
    long int temp;
    while(root!= NULL || !record.isEmpty()){
        if(root != 0){
            record.push(root);
            root = root->left;
        }
        else{
            temp = (long int)record.pop();
            if(temp>0){
                record.push((node *)-temp);
                root = (node *)temp;
                root = root->right;
            }
            else{
                root = (node *)-temp;
                cout<<root->data<<"\t";
                root = NULL;
            }
        }
    }
}

int main() {
    tree binTree;
    binTree.create(7);
    cout<<"preorder traversal: ";
    binTree.preorder(binTree.root);
    cout<<endl;
    cout<<"Inorder traversal: ";
    binTree.inorder(binTree.root);
    cout<<endl;
    cout<<"postorder traversal: ";
    binTree.postorder(binTree.root);
    cout<<endl;
    cout<<"levelorder traversal: ";
    binTree.levelorder(binTree.root);
    cout<<endl;
    cout<<"count: ";
    cout<<binTree.count(binTree.root);
    cout<<endl;
    cout<<"height: ";
    cout<<binTree.height(binTree.root);
    cout<<endl;
    cout<<"iterative Preorder: ";
    binTree.itrPreorder(binTree.root , 7);
    cout<<endl;
    cout<<"iterative Inorder: ";
    binTree.itrInorder(binTree.root , 7);
    cout<<endl;
    cout<<"iterative Postorder: ";
    binTree.itrPostorder(binTree.root , 7);
    cout<<endl;
    return 0;
}

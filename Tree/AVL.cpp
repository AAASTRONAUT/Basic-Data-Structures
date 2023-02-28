//
//  main.cpp
//  AVL
//
//  Created by Shivansh Jain on 25/02/23.
//

#include <iostream>

class node{
public:
    int data;
    node * left;
    node * right;
    int height;
};

class AVL{
public:
    node * root;
    AVL(){
        root = NULL;
    }
    node * Rinsert(node * root , int x);
    int balance(node * root);
    int Height(node * root);
    node * llrotation(node * root);
    node * lrrotation(node * root);
    node * rrrotation(node * root);
    node * rlrotation(node * root);
    node * Delete(node * root , int x);
    node * inpre(node * root);
    node * insucc(node * root);
};

int AVL::balance(node * root){
    return Height(root->left) - Height(root->right);
}

node * AVL::llrotation(node * root){
    node * temp = root->left;
    node * temp2 = temp->right;
    temp->right = root;
    root->left = temp2;
    temp->height = Height(temp);
    root->height = Height(root);
    return temp;
}

node * AVL::rrrotation(node * root){
    node * temp = root->right;
    node * temp2 = temp->left;
    temp->left = root;
    root->right = temp2;
    temp->height = Height(temp);
    root->height = Height(root);
    return temp;
}

node * AVL::lrrotation(node * root){
    node * temp = root->left->right;
    node * temp2 = root->left;
    node * temp3 = temp->left;
    node * temp4 = temp->right;
    root->left = temp4;
    temp->right = root;
    temp->left = temp2;
    temp2->right = temp3;
    temp->height = Height(temp);
    temp2->height = Height(temp2);
    root->height = Height(root);

    return temp;
}

node * AVL::rlrotation(node * root){
    node * temp = root->right->left;
    node * temp2 = root->right;
    node * temp3 = temp->right;
    node * temp4 = temp->left;
    root->right = temp4;
    temp->left = root;
    temp->right = temp2;
    temp2->left = temp3;
    
    temp->height = Height(temp);
    temp2->height = Height(temp2);
    root->height = Height(root);

    return temp;
}

int AVL::Height(node * root){
    int x , y;
    if (root != NULL){
        x = Height(root->left);
        y = Height(root->right);
        if(x>y) return ++x;
        else return ++y;
    }
    else return 0;
}

node * AVL::Rinsert(node * root , int x){
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
        root->height = 1;
        root->left = root->right = NULL;
    }
    
    root->height = Height(root);
    if(balance(root) == 2 && balance(root->left) == 1){
        root = llrotation(root);
    }
    else if(balance(root) == 2 && balance(root->left) == -1){
        root = lrrotation(root);
    }
    else if(balance(root) == -2 && balance(root->right) == -1){
        root = rrrotation(root);
    }
    else if(balance(root) == -2 && balance(root->right) == 1){
        root = rlrotation(root);
    }
    return root;
}

node * AVL::insucc(node * root){
    if(root!= NULL){
        root = root->right;
        while(root->left != NULL){
            root = root->left;
        }
        return root;
    }
    else return NULL;
}

node * AVL::inpre(node * root){
    if(root!= NULL){
        root = root->left;
        while(root->right != NULL){
            root = root->right;
        }
        return root;
    }
    else return NULL;
}

node * AVL::Delete(node * root , int x){
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
                if(Height(root->left) > Height(root->right)){
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
        if(root != NULL){
            root->height = Height(root);
            if(balance(root) == 2 && (balance(root->left) == 1 || balance(root->left) == 0)){
                root = llrotation(root);
            }
            else if(balance(root) == 2 && balance(root->left) == -1){
                root = lrrotation(root);
            }
            else if(balance(root) == -2 && (balance(root->right) == -1 || balance(root->right) == 0)){
                root = llrotation(root);
            }
            else if(balance(root) == -2 && balance(root->right) == 1){
                root = rlrotation(root);
            }
            return root;
        }
        else return NULL;
    }
    else return NULL;
}

int main() {
    AVL tree;
    tree.root = tree.Rinsert(tree.root,10);
    tree.root = tree.Rinsert(tree.root,20);
    tree.root = tree.Rinsert(tree.root,30);
    tree.root = tree.Rinsert(tree.root,25);
    tree.root = tree.Rinsert(tree.root,28);
    tree.root = tree.Rinsert(tree.root,27);
    tree.root = tree.Rinsert(tree.root,5);
    tree.root = tree.Delete(tree.root, 28);
    tree.root = tree.Delete(tree.root, 30);
    tree.root = tree.Delete(tree.root, 27);
    return 0;
}

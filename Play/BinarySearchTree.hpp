//
//  BinarySearchTree.hpp
//  Play
//
//  Created by Suri on 5/9/18.
//  Copyright © 2018 Suri. All rights reserved.
//

#ifndef BinarySearchTree_hpp
#define BinarySearchTree_hpp

#include <stdio.h>
#include <vector>
#include <list>
#include <iostream>
#include <math.h>

namespace BinarySearch {
    
    using namespace std;
    
    class Solution {
        
    public:
        struct node {
            node* left = nullptr;
            node* right = nullptr;
            
            int value;
            node(int v) {
                this->value = v;
            }
           
        };
        
        node* newNode(int value) {
            node* n = new node(value);
           
            return n;
        }
        
    private:
        
    public:
        void insert(node*& n, int value) {
            
            if(n== nullptr) {
                n = newNode(value);
                return;
            }
            
            if (value < n->value) {
                insert(n->left, value);
            } else if(value > n->value) {
                insert(n->right, value);
            }
            
        }
        
        void preorder(node* root) {
            if (root == nullptr) return;
            
            cout << root->value << " ";
            preorder(root->left);
            preorder(root->right);
        }
        
        void inorder(node* root) {
            if (root == nullptr) {
                return;
            }
            
            if(root->left != nullptr) {
                inorder(root->left);
            }
            
            cout << root->value << " ";
            
            if (root->right != nullptr) {
                inorder(root->right);
            }
            
        }
        
        void postorder(node* root) {
            if(root == nullptr) return;
            
            if(root->left != nullptr) {
                postorder(root->left);
            }
            if(root->right != nullptr){
                postorder(root->right);
            }
            
            cout << root->value << " ";
        }
        
        int height(node* root) {
            if(root == nullptr) return 0;
            //cout << root->value << " ";
            return 1 + max(height(root->left), height(root->right));
        }
        
        
    };
};

#endif /* BinarySearchTree_hpp */

//
//  main.cpp
//  Play
//
//  Created by Suri on 4/16/18.
//  Copyright © 2018 Suri. All rights reserved.
//

#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>
#include <string>
#include <set>
//#include "3Sum.hpp"
//#include "3SumNonRecursive.hpp"
//#include "3SumInternetSolution.hpp"
#include "3SumClosest.hpp"
#include "Random.hpp"
#include "FacebookInterviewQuestions.hpp"
#include "Graphs.hpp"
//#include "GraphSuri.hpp"
#include "GraphTreeQuestion.hpp"
#include "GraphVaildTree.hpp"
#include "GraphDepthFirstSearch.cpp"
#include "Inputs.h"
#include "BinarySearchTree.cpp"

void print(vector<int>a) {
    cout << "{";
    for (int i = 0; i < a.size(); i++) {
        cout << a[i];
        if(i != a.size() -1) {
            cout << ",";
        }
    }
    cout << "}";
}

void print(vector<vector<int>>a) {
    
    for(int i  = 0; i < a.size(); i++) {
        vector<int>sub = a.at(i);
        print(sub);
    }
    
}

void print(int a) {
    cout << "{"<< a << "}";
}
template <typename T>
void print(vector<T> a) {
    
    cout << "\n";    
    for(int i = 0; i < a.size(); i++) {        
        cout << "{ parents:" << a[i].parents << " vertex:" << a[i].vertex <<" distance:" << a[i].distance << ", predecessor:";
        print(a[i].predecessor);
        cout << " }\n";
    }
}


void GraphCreate(int vertices) {
    
    //GraphSuri g(adjList);
    
    //print(g.DSF(vertices));
    //print(g.BSF(vertices));
    //print(g.BSF(5, edges));
    //print(g.DSF(5, edges));
}

void binarySearchTree() {
    BinarySearch::Solution BST;
    BinarySearch::Solution::node* root = new BinarySearch::Solution::node(10);
    
    BST.insert(root, 20);
    BST.insert(root, 1);
    /*BST.insert(root, 100);
    BST.insert(root, 21);
    BST.insert(root, 129);*/
    
    
    cout << "inorder:";
    BST.inorder(root);
    cout << "\n";
    
    cout << "preorder:";
    BST.preorder(root);
    cout << "\n";
    
    cout << "postorder:";
    BST.postorder(root);
    cout << "\n";
    
    cout << "height:" << BST.height(root);
    
}


int main(int argc, const char * argv[]) {
    int graphStartIndex = 4;
    if (argc > 1) {
        graphStartIndex = atoi(argv[1]);
    }
    
    binarySearchTree();
    return 0;
}

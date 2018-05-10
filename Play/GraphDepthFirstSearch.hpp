//
//  GraphDepthFirstSearch.hpp
//  Play
//
//  Created by Suri on 5/1/18.
//  Copyright © 2018 Suri. All rights reserved.
//

#ifndef GraphDepthFirstSearch_hpp
#define GraphDepthFirstSearch_hpp

#include <stdio.h>
#include <vector>
#include <iostream>

using namespace std;

class GraphDFS {
private:
    struct node {
        int distance = 0;
        int predecessor = -1;
        int vertex = -1;
    };
    
    void swap(vector<int>& e) {
        int temp = e[0];
        e[0] = e[1];
        e[1] = temp;
    }
    
    void DFSRecursive(int s, vector<node> &parents, vector<vector<int>> &adjList) {
        
        cout << s << " ";
        
        for(const int v : adjList[s]) {
            if (parents[v].vertex == -1) {
                node n;
                n.distance = parents[v].distance + 1;
                n.predecessor = s;
                n.vertex = v;
                
                parents[v] = n;
                
                DFSRecursive(v, parents, adjList);
            }
        }
    }
    
    vector<vector<int>> createAdjcencyList(int s, vector<vector<int>>& edges) {
        vector<vector<int>> adjList(s);
        
        for(vector<int> e : edges) {
            if (e[0] > e[1]) {
                swap(e);
            }
            adjList[e[0]].push_back(e[1]);
        }
        
        return adjList;
    }
    
public:
    
    vector<node> DFS(int s, vector<vector<int>>& edges) {
        vector<node> parents(s);
        vector<vector<int>> adjList = createAdjcencyList(s, edges);
        
        for(int i = 0; i < s; i++) {
            
            if(parents[i].vertex == - 1) {
                node n;
                n.vertex = s;
                parents.push_back(n);
                
                DFSRecursive(i, parents, adjList);
            }
           
        }
        
        
        
        return parents;
    }
    
};

#endif /* GraphDepthFirstSearch_hpp */

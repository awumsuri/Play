//
//  GraphTreeQuestion.hpp
//  Play
//
//  Created by Suri on 4/30/18.
//  Copyright © 2018 Suri. All rights reserved.
//

#ifndef GraphTreeQuestion_hpp
#define GraphTreeQuestion_hpp

#include <stdio.h>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

namespace GraphTree {
    
    class Solution {
    private:
        struct node {
            int vertex = -1;
            int parent = -1;
            bool visited = false;
        };
        
        void swap(vector<int> &edge) {
            int temp = edge[0];
            edge[0] = edge[1];
            edge[1] = temp;
        }
        
        vector<vector<int>> createAdjcencyList(int vertices, vector<vector<int>>& edges) {
            vector<vector<int>> adjList(vertices);
            
            for(vector<int> edge : edges) {
                if(edge[0] > edge[1]) {
                    swap(edge);
                }
                
                adjList[edge[0]].push_back(edge[1]);
            }
            
            return adjList;
        };
        
        void DFS(vector<vector<int>> &adj, vector<node>& parents, node parent, bool &foundCycle) {
            
            cout << parent.vertex << " ";
            
            for(int i = 0; i < adj[parent.vertex].size(); i++) {
                int neighbor = adj[parent.vertex][i];
                
                node &n = parents[neighbor];
                
                if(n.visited != true) {
                    n.visited = true;
                    n.vertex  = neighbor;
                    n.parent = parent.vertex;
                    
                    DFS(adj, parents, n, foundCycle);
                    
                } else if(parent.parent != -1 && parent.visited && parent.vertex != n.parent ) {
                    cout << "n.parent:" << n.parent << " parent:" << parent.parent;
                    foundCycle = true;
                    break;
                }
                else {
                    cout << "test";
                }
            }
            
            
        }
        
    public:
        bool validTree(int s, vector<vector<int>>& edges) {
            vector<node> parents(s);
            vector<vector<int>> adjList = createAdjcencyList(s, edges);
            bool foundCycle = false;
            
            for(int i = 0; i < s; i++) {
                
                node &n = parents[i];
                
                if(!foundCycle && n.visited != true) {
                    n.vertex = i;
                    n.visited = true;
                    
                    DFS(adjList, parents, n, foundCycle);
                }
            }
            
            
            return !foundCycle;
            
        }
        
    };
}

#endif /* GraphTreeQuestion_hpp */

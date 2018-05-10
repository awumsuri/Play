//
//  GraphVaildTree.hpp
//  Play
//
//  Created by Suri on 5/1/18.
//  Copyright © 2018 Suri. All rights reserved.
//

#ifndef GraphVaildTree_hpp
#define GraphVaildTree_hpp

#include <stdio.h>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

class GraphValidTree {
private:
    
    void swap(vector<int> &e) {
        int temp = e[0];
        e[0] = e[1];
        e[1] = temp;
    }
    
    struct node {
        int distance = 0;
        vector<int> predecessor;
        int vertex = -1;
        int parents = 0;
    };
    
    vector<vector<int>> createAdjcencyList(int s, vector<vector<int>> edges) {
        vector<vector<int>> adjList(s);
        
        for(vector<int> e : edges) {
            if (e[0] > e[1]) {
                swap(e);
            }
            adjList[e[0]].push_back(e[1]);
        }
        
        return adjList;
    }
    
    void DFSRecursive(int s, vector<bool> &visited, vector<vector<int>>& adjList, vector<node>& nodes) {
        
        visited[s] = true;
        cout << s << " ";
        
        for(int i = 0; i < adjList[s].size(); i++) {
            int next = adjList[s][i];
            node &n = nodes[next];
            n.parents++;
            n.predecessor.push_back(s);
            
            if(!visited[next]) {
                n.distance++;
                n.vertex = next;
                n.predecessor.push_back(s);
                
                DFSRecursive(next, visited, adjList, nodes);
            }
        }
    }
    
    vector<node> DFS(int s, vector<vector<int>> edges) {
        vector<vector<int>> adjList = createAdjcencyList(s, edges);
        vector<bool>visited(s, false);
        vector<node>nodes(s);
        vector<int>vn(s, 0);
        
        for(int i = 0; i < s; i++) {
            if(!visited[i]) {
                node &n = nodes[i];
                n.vertex = i;
                
                DFSRecursive(i, visited, adjList, nodes);
            }
        }
        
        return nodes;
    }
    
public:
    vector<node> validTree(int s, vector<vector<int>>& edges) {
        
        if(edges.empty()) {
            if(s == 1) {
              // return true;
            }
            //return false;
        }
        
        vector<node> nodes = DFS(s, edges);
        
        for(int i = 0; i < nodes.size(); i++) {
            node n = nodes[i];
            if (i != 0 && n.parents != 1) {
                //return false;
            }
        }
        
        return nodes;
    }
    
};

#endif /* GraphVaildTree_hpp */

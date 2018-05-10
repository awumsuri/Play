//
//  GraphSuri.hpp
//  Play
//
//  Created by Suri on 4/29/18.
//  Copyright © 2018 Suri. All rights reserved.
//

#ifndef GraphSuri_hpp
#define GraphSuri_hpp

#include <stdio.h>
#include <queue>
#include <iostream>
#include <stack>
#include <list>

using namespace std;

class GraphSuri {
public:
    struct node {
        int distance = -1;
        int predecessor = -1;
        int vertex = -1;
    };
private:
    vector<vector<int>> adj;
    
    void DSFInterator(int s, vector<bool>& visited, vector<node>& result, vector<vector<int>>& adjList) {
        
        cout << s << " ";
        visited[s] = true;
        stack<int> stack;
        stack.push(s);
        
        for(int i = 0; i < adjList[s].size(); i++) {
            int nv = adjList[s][i];
            
            if(visited[nv] != true) {
                result[nv].distance = result[s].distance + 1;
                result[nv].predecessor = s;
                DSFInterator(nv, visited, result, adjList);
            }
        }
        
        
    }
    
    vector<vector<int>> createGraph(int s, vector<vector<int>> edges) {
        
        vector<vector<int>>adjList(s);
        
        for(vector<int> e : edges) {
            adjList[e[0]].push_back(e[1]);
        }
        
        return adjList;
    }

public:
    
    GraphSuri(vector<vector<int>> adjList) {
        adj = adjList;
    }
    
    //Recursive Depth First Search
    vector<node> DSF(int s, vector<vector<int>> &edges) {
        
        vector<vector<int>> adjList = createGraph(s, edges);
        
        vector<node> result(adjList.size());
        vector<bool> visited(adjList.size(), false);
        result[0].distance = 0;
        
        DSFInterator(0, visited, result, adjList);
        
        return result;
        
    }
    
    //Recursive Depth First Search
    vector<node> DSF(int s) {
        
        vector<node> result(adj.size());
        vector<bool> visited(adj.size(), false);
        result[s].distance = 0;
        
        DSFInterator(s, visited, result, adj);
        
        return result;
        
    }
    
    //Breath First Search with edges
    vector<node> BSF(int s, vector<vector<int>> &edges) {
        
        vector<vector<int>> adjList = createGraph(s, edges);
        
        return BSF(adjList);
    }
    
    vector<node> BSF(vector<vector<int>> adjList) {
        
        vector<node> result;
        queue<int> queue;
        vector<bool> visited(adjList.size(), false);
        int s = 0;
        
        for(int i = 0; i < adjList.size(); i++) {
            node n;
            result.push_back(n);
        }
        
        result[s].distance = 0;
        visited[s] = true;
        queue.push(s);
        
        while(!queue.empty()) {
            s = queue.front();
            cout << s << " ";
            queue.pop();
            
            for(int i = 0; i < adjList[s].size(); i++) {
                
                if (!adjList[s].empty() && i < adjList[s].size()) {
                    int nearestNeighbor = adjList[s][i];
                    
                    if(visited[nearestNeighbor] != true) {
                        queue.push(nearestNeighbor);
                        visited[nearestNeighbor] = true;
                        result[nearestNeighbor].distance = result[s].distance + 1;
                        result[nearestNeighbor].predecessor  = s;
                    }
                }
                
                
            }
            
        }
        
        return result;
        
    }
    
    vector<node> BSF(int s) {
        
        vector<node> result(adj.size());
        queue<int> queue;
        vector<bool> visited(adj.size(), false);
        
        for(int i = 0; i < result.size(); i++) {
            node n;
            result[i] = n;
        }
        
        result[s].distance = 0;
        visited[s] = true;
        queue.push(s);
        
        while(!queue.empty()) {
            s = queue.front();
            cout << s << " ";
            queue.pop();
            
            for(int i = 0; i < adj[s].size(); i++) {
                
                int nearestNeighbor = adj[s][i];
                
                if(visited[nearestNeighbor] != true) {
                    queue.push(nearestNeighbor);
                    visited[nearestNeighbor] = true;
                    result[nearestNeighbor].distance = result[s].distance + 1;
                    result[nearestNeighbor].predecessor  = s;
                }
                
            }
            
        }
        
        return result;
        
    }
};

#endif /* GraphSuri_hpp */

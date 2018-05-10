//
//  BreathSearchFirst.hpp
//  Play
//
//  Created by Suri on 4/28/18.
//  Copyright © 2018 Suri. All rights reserved.
//

#ifndef BreathSearchFirst_hpp
#define BreathSearchFirst_hpp

#include <stdio.h>
#include <list>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

class Graph {
    
private:
    int V; //No. of vertices
    
    //Adjecency list
    list<int> *adj;
    
public:
    Graph(int v) {
        V = v;
        adj = new list<int>[v];
    }
    
    void addEdge(int v, int w) {
        auto t = adj[v];
        adj[v].push_back(w);
    }
    
    void BreatheSearchFirst(int s) {
        
        vector<bool> visited(V, false);
        queue<int> queue;
        visited[s] = true;
        queue.push(s);
        list<int>::iterator i;
        
        while(!queue.empty()) {
            s = queue.front();
            cout << s << " ";
            queue.pop();
            
            for(i = adj[s].begin(); i != adj[s].end(); i++) {
                if(visited[*i] != true) {
                    visited[*i] = true;
                    queue.push(*i);
                }
            }
            
        }
        
    }
    
};
#endif /* BreathSearchFirst_hpp */

//
//  FacebookInterviewQuestions.hpp
//  Play
//
//  Created by Suri on 4/24/18.
//  Copyright © 2018 Suri. All rights reserved.
//

#ifndef FacebookInterviewQuestions_hpp
#define FacebookInterviewQuestions_hpp

#include <vector>
#include <unordered_map>
#include <string>
#include <iostream>

using namespace std;

class Facebook {
private:
    struct pair {
        int x;
        int y;
        int value;
    };
    unordered_map<int, pair> map;
    vector<string> orderStrings(string s, string t) {
        
        if(s.size() > t.size()) {
            return {s, t};
        }
        
        return {t, s};
    }
    
    bool checkOneEdit(string s, string t) {
        
        int diffCount = 0;
       
        for(int i = 0; i < s.size(); i++) {
            
            if(s[i] != t[i]) {
                diffCount++;
                if (diffCount > 1) {
                  return false;
                }
            }           
            
        }
        
        return true;
    }
    
    
public:
    bool OneEditAway(string s, string t) {
        
        if (abs((int)s.size() - (int)t.size()) > 1) {
            return false;
        }
        
        if(s.size() == t.size()) {
            return checkOneEdit(s, t);
        }
        
        //Add Padding
        vector<string> order = orderStrings(s, t);
        string larger = order[0];
        string smaller = order[1];
        string paddingS;
        paddingS.reserve(larger.size());
        
        int k = 0;
        
        for(int i = 0; i < larger.size(); i++) {
            
            if(larger[i] == smaller[k]) {
                paddingS.insert(i, 1,smaller[k]);
                k++;
            } else {
                paddingS.insert(i, 1, ' ');
                
            }
        
        }
        
        return checkOneEdit(paddingS, order[0]);
        
    }
    
    vector<vector<int>> spirial(int s) {
        vector<vector<int>> result(s,vector<int>(s));
        
        int sCount = s*s;
        int indexX = 0;
        int indexY = s - 1;
        int count = 1;
        
        while(count <= sCount) {
            for(int i = indexX; i <= indexY; i++ ) {
                pair p;
                p.x = indexX;
                p.y = i;
                p.value = count;
                map[count] = p;
                count++;
            }
            
            indexX++;
            
            for(int j = indexX; j <= indexY; j++) {
                pair p;
                p.x = j;
                p.y = indexY;
                p.value = count;
                map[count] = p;
                count++;
            }
            
            indexY--;
            
            for (int k = indexY; k >= indexX - 1; k--) {
                pair p;
                p.x = indexY + 1;
                p.y = k;
                p.value = count;
                map[count] = p;
                count++;
            }
            
            for(int l = indexY; l >= indexX; l-- ) {
                pair p;
                
                p.x = l;
                p.y = indexX - 1;
                p.value = count;
                map[count] = p;
                count++;
            }            
            
        }        
        
        for(int n = 1; n <= sCount; n++) {
            pair p = map[n];
            result[p.x][p.y] = p.value;
        }
        
        return result;
    }
    
};

#endif /* FacebookInterviewQuestions_hpp */

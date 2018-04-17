//
//  3SumNonRecursive.hpp
//  Play
//
//  Created by Suri on 4/17/18.
//  Copyright © 2018 Suri. All rights reserved.
//

#ifndef _SumNonRecursive_hpp
#define _SumNonRecursive_hpp

#include <stdio.h>
#include <stdio.h>
#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>
#include <string>
#include <set>

using namespace std;

class Solution {
private:
    unordered_map<int, int> map;
    set<vector<int>> memMap;
    set<vector<int>> results;
    
    void populateMap(vector<int>& nums) {
        for(int i = 0; i < nums.size(); i++) {
            map[nums[i]] = i;
        }
    }
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        populateMap(nums);     
        
        for (int i = 0; i < nums.size(); i++) {
            int n1 = nums[i];
            
            for(int j = 0; j < nums.size(); j++) {
                if (i == j) continue;
                int n2 = nums[j];
                int complement = -(n1 + n2);
                
                if(memMap.find({n1,n2}) != memMap.end()) {
                    continue;
                }
                
                if (map.find(complement) != map.end() && map.at(complement) != j && map.at(complement) != i) {
                    vector<int>r = {nums[map.at(complement)], n1, n2};
                    sort(r.begin(), r.end(), less_equal<>());                    
                    results.insert(r);
                }
            }            
            
        }
        
        return {results.begin(), results.end()};
    }
    
};

#endif /* _SumNonRecursive_hpp */

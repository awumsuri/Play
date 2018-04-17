//
//  3Sum.hpp
//  Play
//
//  Created by Suri on 4/17/18.
//  Copyright © 2018 Suri. All rights reserved.
//

#ifndef _Sum_hpp
#define _Sum_hpp

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
    unordered_map<int, bool> memMap;
    set<vector<int>> results;
    
    void populateMap(vector<int>& nums) {
        for(int i = 0; i < nums.size(); i++) {
            map[nums[i]] = i;
        }
    }
    
public:   
    set<vector<int>> twoSum(vector<int>& nums, int target, int currentIndex) {
        
        set<vector<int>>r;
        
        for(int i = currentIndex + 1; i < nums.size(); i++) {          
            
            int n = nums[i];
            int complement = target - n;
            
            if(map.find(complement) != map.end() &&
               map.at(complement) != i && map.at(complement) != currentIndex) {
                r.insert({nums[map.at(complement)], nums[i]});
            }
            
        }
        
        memMap[target] = true;
        return r;
        
    }
    
    vector<vector<int>> threeSum(vector<int>& nums) {
        
        populateMap(nums);
        
        for(int i = 0; i < nums.size(); i++) {
            int pivot = nums[i];
            
            if (memMap.find(-pivot) != memMap.end()) {
                continue;
            }
            
            set<vector<int>> result = twoSum(nums, -pivot, i);
            
            if (!result.empty()) {
                for(vector<int> subR : result) {
                    vector<int> r = {subR.at(0), subR.at(1), pivot};
                    sort(r.begin(), r.end(), less_equal<int>());
                    results.insert(r);
                }
            }
            
        }
        
        return {results.begin(), results.end()};
    }
};

#endif /* _Sum_hpp */

//
//  3SumClosest.hpp
//  Play
//
//  Created by Suri on 4/18/18.
//  Copyright © 2018 Suri. All rights reserved.
//

#ifndef _SumClosest_hpp
#define _SumClosest_hpp

#include <stdio.h>
#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
    
private:
    
    int getDistanceToTarget(int sum, int target) {
        return abs(sum - target);
    }
    unordered_map<int, int> map;
    
public:
    int threeSumClosest(vector<int>& nums, int target) {
        
        int smallestSumDistance = INT_MAX;
        
        for (int i = 0; i < nums.size() - 2; i++) {
            for(int j = i + 1; j < nums.size() - 1; j++) {
                for(int k = j + 1; k < nums.size(); k++) {
                    int sum = nums[i] + nums[j] + nums[k];
                    
                    if (sum == target) {
                        return sum;
                    }
                    
                    
                    int distanceFromTarget = getDistanceToTarget(sum, target);
                    
                    
                    smallestSumDistance = min(distanceFromTarget, smallestSumDistance);
                    
                    if(map.find(smallestSumDistance) == map.end()) {
                        map[smallestSumDistance] = sum;
                    }
                    
                }
            }
        }
        
        return map[smallestSumDistance];
    }
};

#endif /* _SumClosest_hpp */

//
//  3SumInternetSolution.hpp
//  Play
//
//  Created by Suri on 4/17/18.
//  Copyright © 2018 Suri. All rights reserved.
//

#ifndef _SumInternetSolution_hpp
#define _SumInternetSolution_hpp

#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
private:
    vector<vector<int>> results;
public:
     vector<vector<int>> threeSum(vector<int>& nums) {
         if(nums.size()<3)
             return results;
         sort(nums.begin(), nums.end(), less<int>());
         for (int i = 0; i < nums.size() - 2; i++) {
             if (i == 0 || nums[i] > nums[i - 1]) {
                 
                 int j = i + 1;
                 int k = (int)nums.size() -1;
                 
                 while(j < k) {
                     if (nums[i] + nums[j] + nums[k] == 0) {
                         results.push_back({nums[i], nums[j], nums[k]});
                         j++;
                         k--;
                         
                         while(j<k && nums[j] == nums[j -1]) {
                             j++;
                         }
                         
                         while(j<k && nums[k] == nums[k+1]) {
                             k--;
                         }
                     } else if (nums[i] + nums[j] + nums[k] < 0) {
                         j++;
                     } else {
                         k--;
                     }
                 }
                 
             }
         }
         
         return results;
         
     }
};
#endif /* _SumInternetSolution_hpp */

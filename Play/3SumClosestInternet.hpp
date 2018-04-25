//
//  3SumClosestInternet.hpp
//  Play
//
//  Created by Suri on 4/22/18.
//  Copyright © 2018 Suri. All rights reserved.
//

#ifndef _SumClosestInternet_hpp
#define _SumClosestInternet_hpp

#include <stdio.h>
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
    
public:
    int threeSumClosest(vector<int>& nums, int target) {
        std::sort(nums.begin(),nums.end());//使用STL的sort对nums进行排序
        int min=nums.at(0)+nums.at(1)+nums.at(2); //初始化closest value
        for(int i=0;i<nums.size()-2;i++){
            int L=i+1,R=nums.size()-1;//左游标 右端点游标
            while(L<R){
                int temp=nums.at(i)+nums.at(L)+nums.at(R);
                if(abs(temp-target)<=abs(min-target))//当前更近
                    min=temp;
                if(temp<target){ //小于目标值
                    L++;
                }else if(temp>target){ //大于目标值
                    R--;
                }else{ //等于目标值
                    return target;
                }
                while(L<(R-1)&&nums.at(L)==nums.at(L+1)){ //处理相同的左游标数
                    L++;
                }
                while((L+1)<R&&nums.at(R)==nums.at(R-1)){ //处理相同的右游标数
                    R--;
                }
            }
            while(i<(nums.size()-2)&&nums.at(i)==nums.at(i+1)){ //处理相同的数
                i++;
            }
        }
        return min;
        
    }
};

#endif /* _SumClosestInternet_hpp */

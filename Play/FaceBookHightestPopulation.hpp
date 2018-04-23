//
//  FaceBookHightestPopulation.hpp
//  Play
//
//  Created by Suri on 4/21/18.
//  Copyright © 2018 Suri. All rights reserved.
//

#ifndef FaceBookHightestPopulation_hpp
#define FaceBookHightestPopulation_hpp

#include <stdio.h>
#include <list>
#include <string>
#include <algorithm>
#include <unordered_map>

using namespace std;

class Solution {
    /* Give a list with people and birthdays how would you find the year with higest population *. */
private:
    struct person{
        string name;
        int birthyear;
        int deathdate;
    };
    
    int parseBirthYear(int date) {
        return date;
    }
   
public:
    long findHightestYear(list<person> persons, int start, int end){
        unordered_map<int, int> countMap;
        int maxYearCount = 0;
        int maxYear;
        
        for(person const& p : persons) {
            if (countMap.find(p.birthyear) == countMap.end()) {
                countMap[p.birthyear] = {1, };
            } else {
                countMap[p.birthyear] += 1;
            }
        }
        
        //find max year
        for (int i = start; i < end; i++) {
            if (countMap.find(i) != countMap.end()) {
                
                int currentYearCount = countMap.at(i);
               
                //if (maxYearCount > currentYearCount && i > countMap[currentYearCount].deathdate) {
                    maxYear = i;
               // }
                
            }
        }
        
        return countMap[maxYear];
    }
};

#endif /* FaceBookHightestPopulation_hpp */

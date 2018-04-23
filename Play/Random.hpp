//
//  Random.hpp
//  Play
//
//  Created by Suri on 4/22/18.
//  Copyright © 2018 Suri. All rights reserved.
//

#ifndef Random_hpp
#define Random_hpp

#include <stdio.h>
#include <string>

using namespace std;

namespace suri {
    
    class Solution {
        
    public:
        string reverseString(string s) {
            
            unsigned int k = (unsigned int)s.size() -1;
            for(int i = 0; i < s.size()/2; i++) {
                char temp = s[i];
                s[i] = s[k];
                s[k] = temp;
                k--;
            }
            
            return s;
            
        }
    };
}
#endif /* Random_hpp */

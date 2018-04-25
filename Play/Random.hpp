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
#include <iostream>

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
        
        char* reverseString(char* a, int length) {
            
            int k = length - 1;
            
            for (int i = 0; i < length/2; i++) {
                char temp = a[i];
                a[i] = a[k];
                a[k] = a[temp];
                k--;
            }
           
            return a;
        }
        
        char*  reverse_string( char *s )
        {
            char *p = s;
            
            while ( *p ) ++p;
            
            if ( p != s )
            {
                for ( char *q = s; q < --p; ++q )
                {
                    char c = *q;
                    *q = *p;
                    *p = c;
                }
            }
            
            return s;
        };
    };
    
    
    
    
}
#endif /* Random_hpp */

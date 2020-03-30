/**
 * AUTHORS: <george kouzi and dolev saadia>
 * 
 * Date: 2020-02
*/

#include "PhoneticFinder.hpp"

string phonetic :: find(string a,string b){
        
        if(b==""&&a==""){
		throw std::out_of_range{"The word and the txt is empty please try again"};
        }
        
        string word = "";
        string wordtolower = "";
        string realWord="";
        for (auto y : b){
                y = tolower(y);
            realWord=realWord+y; 
 
}
        for (auto x : a)
        {
            if (x == ' ')
            {
                
                if (check(wordtolower,realWord)==1)
                {
                    return word ;
                }
                else
                {
                    wordtolower="";
                    word="";
                }
            }
            else
            {
                word=word+x;
                x = tolower(x);
                wordtolower=wordtolower+x;
            }
        }
        if (check(wordtolower,realWord)==1)
        {
           return word;
        }
        else if(b==""|| b==" "){
		throw std::out_of_range{"The word is empty please try again"};
        }
        else
        {
		throw std::out_of_range{"The word "+b+" does not appear in the text"};
       }

    
}

int phonetic:: check(string s,string t) {
    int arr [26] = {12, 1, 3, 5 , 13, 1, 2 , 14, 7, 2 , 3, 15, 16 , 17, 6, 1 , 3, 18, 4 , 5, 6, 0, 0, 11, 7, 4  };
    if (s.length() == t.length()) {
        for (int i = 0; i < s.length(); i++) {
            const char c = s.at(i);
            const char p = t.at(i);
            if (arr[c - 'a'] != arr[p - 'a']) {
                return 0;
            }
        }
        return 1;
    }
    return 0;
}

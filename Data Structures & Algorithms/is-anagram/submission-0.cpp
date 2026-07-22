class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length() != t.length()){
            return false ;
        }
        // create an array of all the alphabets and initialize all indexes with 0
        int frequency[26] = {0};


        // increment the index if char found in a
        // decrement the index if char found in t
        for( int i =0 ; i < s.length() ; i++){
            frequency[s[i] - 'a']++;
            frequency[t[i] - 'a']--;
        }


        // check if any value in frequency is more than 0 

        for ( int count  : frequency){
            if (count != 0){
                return false ;
            }
        }

        return true ; 
        
    }
};

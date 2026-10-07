class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length() != t.length()){
            return false ;
        }
        vector<int> alphabets(26 , 0);

        for ( char c : s){
            alphabets[c - 'a'] +=1 ;
        }
        for(char c : t){
            alphabets[c -'a'] -= 1;
        }

        for ( int num : alphabets){
            if(num != 0){
                return false ;
            }
        }
        return true ;
        
    }
};

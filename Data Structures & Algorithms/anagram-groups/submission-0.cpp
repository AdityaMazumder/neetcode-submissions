class Solution {
public:
    string getHash (string& s){
        string hash ;

        vector<int> freq(26 , 0);

        for( char ch : s){
            freq[ch -'a']++ ;
        }

        for ( int i = 0 ; i < 26 ; i++){
            hash.append(to_string(freq[i]));
            hash.append("$");
        }
        return hash ;
    }

    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        // actual output res = {   {}     ,    {}     ,   {}   }
        vector<vector<string>> res ;



        // map will store the hash value of the key -- key -- string  --- hash value -- int 
        unordered_map<string , int > mp;


        

        for ( int i = 0 ; i <strs.size() ; i++){
            // generate key
            string key = getHash(strs[i]);

            if(mp.find(key) == mp.end()){
                mp[key] = res.size();
                res.push_back({});
            }
            res[mp[key]].push_back(strs[i]);
        }
        return res ;
        
    }
};

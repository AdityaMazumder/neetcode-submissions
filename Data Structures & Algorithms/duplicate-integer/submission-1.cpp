class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        // create a hashset
        unordered_set<int> seen ; 

        // iterate through the array 
        for ( int i = 0 ; i < nums.size() ; i++){
            // check if the element is present in hashset
            if ( seen.find(nums[i]) != seen.end()){
                return true ;
            }
            // if not found then add the element to the hash set
            seen.insert(nums[i]);
        }
        return false ; 
        
    }
};
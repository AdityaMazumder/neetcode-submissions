class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {

        int p = 0 ;
        int q = numbers.size() -1 ;

        while( p < q){
            int sum = numbers[p] + numbers[q];
            if(sum == target){
                return {p+1 , q+1};
            }
            else if (sum < target){
                p++;
            }
            else{
                q-- ;
            }
        }

        return {} ;
        
    }
};

class Solution {
public:
    int maxArea(vector<int>& heights) {
        int left = 0 ;
        int right = heights.size() -1 ;


        int res  = 0 ;

        // area = length x breadth -- length = min(heights[left] , heights[right]) ---- breadth = right - left

        while(left < right){
            int length = min(heights[left] , heights[right]);
            int breadth = right - left ;
            int area = length*breadth ;
            
            res = max(res , area);

            if(heights[left] < heights[right]){
                left ++ ;
            }
            else{
                right-- ;
            }



        }

        return res ;
        
    }
};

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        // make sure that the decimal can be printed each time.
        cout << fixed << setprecision(1);
        
        // deal with cases that either of vectors is empty
        if(nums1.empty()||nums2.empty()){
            if(nums1.empty()) // make nums1 non-empty vector
                swap(nums1, nums2);
            if(nums1.size()%2 != 0) // cases that nums1 has an odd number of data.
                return nums1[nums1.size()/2];
            return (double) (nums1[nums1.size()/2] + nums1[nums1.size()/2-1])/2;  // otherwise, cases that nums1 has an even number of data.
        }
        
        // deal with cases that either of vectors contains only one datum.
        if(nums1.size()==1 || nums2.size()==1){
            if(nums1.size()==1 && nums2.size()==1) // cases that each vector contains only one datum.
                return (double) (nums1[0] + nums2[0])/2;
            if(nums1.size()==1) //otherwise, make nums1 contains more than 1 datum, and nums2 contains only one.
                swap(nums1, nums2);
            if(nums1.size()%2 != 0){ // case that nums1 has an odd number of data.
                if(nums2[0] < nums1[nums1.size()/2]) 
                    return (double) (max(nums1[nums1.size()/2],nums2[0]) + max(nums1[nums1.size()/2-1],nums2[0])) / 2;
                return (double) (min(nums1[nums1.size()/2+1],nums2[0]) + min(nums1[nums1.size()/2],nums2[0])) / 2; 
            }else{   // otherwise, case that nums1 has an even number of data.
                if(nums2[0] < nums1[nums1.size()/2]) 
                    return (double) max(nums1[nums1.size()/2-1], nums2[0] );
                return (double) min(nums1[nums1.size()/2] , nums2[0]);
            }
        }
        
        if(nums1.size() > nums2.size()) // make nums2 contain no less data than nums1 does.
            swap(nums1, nums2); 
            
        // The following concept is:
        // the median is located around the half of sorted numbers in nums1 + nums2. Therefore,
        // 1. set condition: n left data in nums1 + m right data in nums2 = floor of (the length of nums1 + nums2)/2
        //                    any data after the nth data in nums1 and the mth data in nums2 is bigger than data 1~n in nums1 and data 1~m in nums2.
        // 2. after finding n & m, determine the median
        //     Case 1: number of total data is odd-> return min(nums1[n+1], nums2[m+1])
        //     Case 2: number of total data is even-> return (max(nums1[n], nums2[m]) + min(nums1[n+1], nums2[m+1])) / 2
        pair<int, int> left; // to store nums1[n] & nums2[m]
        pair<int, int> right; // to store nums1[n+1] & nums2[m+!]
        int half = (int) (nums1.size() + nums2.size())/2;
        // check the conditions from the half of nums1
        // the left part of nums1 has L1 data, and the left part of nums2 has (half-L1) data.
        int L1 = (int) nums1.size()/2; 
        int high = (int) nums1.size();
        int low = 0;
        while(1){
            if(L1 > 0 && nums1[L1-1] > nums2[half-L1]){
                if(L1-1 == 0){  
                    // In case like (1) nums1 = [3,4] & nums2 = [1,2]; (2) nums1 = [4,5] & nums2 = [1,2,3,6]
                    if(nums2.size() == half || nums1[0] < nums2[half-L1+1]){ 
                        left.first = numeric_limits<int>::min(); 
                        right.first = nums1[L1-1]; 
                        L1 = 0;
                        left.second = nums2[half-L1-1]; // Thus, max(left.first, left.second) = nums2[half-L1-1];
                        right.second = numeric_limits<int>::max(); // Thus, min(right.first, right.second) = nums1[L1-1];
                        break;
                    }else{ 
                    // In case like (1) nums1 = [5,6] & nums2 = [1,2,3,4];
                        left.first = numeric_limits<int>::min();
                        right.first = numeric_limits<int>::max();
                        L1 = 0;
                        left.second = nums2[half-L1-1];
                        right.second = nums2[half-L1];
                        break;
                    }
                }
                // otherwise, increase L1 (general cases)
                high = L1;
                L1 = (low+high)/2;
            }else if(L1 < nums1.size() && nums1[L1] < nums2[half-L1-1]){
                if(L1 == (int) nums1.size()-1){
                    // In case like (1) nums1 = [1,2] & nums2 = [3,4]; (2) nums1 = [2,3] & nums2 = [1,4,5,6]
                    if(nums1.size() == half || nums1[L1] > nums2[half-L1-2]){
                        left.first = nums1[L1];
                        right.first = numeric_limits<int>::max();
                        L1 = (int) nums1.size();
                        left.second = numeric_limits<int>::min();
                        right.second = nums2[half-L1];
                        break;
                    }else{
                        // In case like (1) nums1 = [1,2] & nums2 = [3,4,5,6];
                        left.first = numeric_limits<int>::min();
                        right.first = numeric_limits<int>::max();
                        L1 = (int) nums1.size();
                        left.second = nums2[half-L1-1];
                        right.second = nums2[half-L1];
                        break;
                    }
                }
                // otherwise, decrease L1 (general cases)
                low = L1;
                L1 = (low+high)/2;
            }else{
                left.first = nums1[L1-1]; // left.first = the nth data in nums1; left.second = the mth data in nums2; 
                right.first = nums1[L1];  // right.first = the (n+1)th data in nums1; right.second = the (m+1)th data in nums2; 
                left.second = nums2[half-L1-1]; 
                right.second = nums2[half-L1];
                break;
            }
        }
        if((nums1.size() + nums2.size())%2 == 1)
            return min(right.first, right.second);
        return (double) (min(right.first,right.second) + max(left.first,left.second)) / 2;
    }
};

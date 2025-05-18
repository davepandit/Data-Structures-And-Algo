// peak ele definition 
// arr[i - 1] < arr[i] > arr[i + 1]

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        // we need to return the index of the peak ele 
        // peak ele => arr[i - 1] < arr[i] > arr[i + 1]
        int n = nums.size();
        if(n == 1 || nums[0] > nums[1]){
            return 0;
        }
        if(nums[n - 1] > nums[n - 2]){
            return n - 1;
        }

        int low = 1, high = n - 2;
        while(low <= high){
            int mid = (low + high) / 2;
            if(nums[mid] > nums[mid - 1] && nums[mid] > nums[mid + 1]){
                return mid;
            }
            // other than this the mid can exist in the increasing part or in the decreasing part
            // if mid is in the increasing part
            else if(nums[mid] >= nums[mid - 1]){
                // eliminate the left search space 
                low = mid + 1;
            }
            // if the mid is in the decreasing search space 
            else if(nums[mid] >= nums[mid + 1]){
                // eliminate the right search space
                high = mid - 1;
            }
            else{
                // this is a very interesting case 
                // agar ye case na likhe then the below case will fail 
                // [1, 2, 1, 2, 1]
                high = mid - 1;
            }
        }

        return -1;
    }
};
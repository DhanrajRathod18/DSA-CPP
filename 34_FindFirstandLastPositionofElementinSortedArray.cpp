class Solution {

    // Find the FIRST occurrence of target
    int firstOccurrence(vector<int>& nums, int n, int target) {

        int low = 0;
        int high = n - 1;

        // Stores the answer whenever we find target
        int first = -1;

        while (low <= high) {

            int mid = (low + high) / 2;

            if (nums[mid] == target) {

                // Target found, store this index
                first = mid;

                // Search on the LEFT for an earlier occurrence
                high = mid - 1;
            }
            else if (nums[mid] < target) {

                // Target is on the RIGHT
                low = mid + 1;
            }
            else {

                // Target is on the LEFT
                high = mid - 1;
            }
        }

        return first;
    }


    // Find the LAST occurrence of target
    int lastOccurrence(vector<int>& nums, int n, int target) {

        int low = 0;
        int high = n - 1;

        // Stores the answer whenever we find target
        int last = -1;

        while (low <= high) {

            int mid = (low + high) / 2;

            if (nums[mid] == target) {

                // Target found, store this index
                last = mid;

                // Search on the RIGHT for a later occurrence
                low = mid + 1;
            }
            else if (nums[mid] < target) {

                // Target is on the RIGHT
                low = mid + 1;
            }
            else {

                // Target is on the LEFT
                high = mid - 1;
            }
        }

        return last;
    }


public:

    // Returns [first occurrence, last occurrence]
    vector<int> searchRange(vector<int>& nums, int target) {

        int n = nums.size();

        // Find first occurrence
        int first = firstOccurrence(nums, n, target);

        // Target doesn't exist
        if (first == -1) {
            return {-1, -1};
        }

        // Find last occurrence
        int last = lastOccurrence(nums, n, target);

        return {first, last};
    }
};
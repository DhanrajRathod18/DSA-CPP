class Solution {
public:

    // Function to calculate how many days are required
    // when the ship has a given capacity 'cap'
    int FindDays(vector<int>& weights, int cap) {

        // Start with Day 1
        int day = 1;

        // 'load' = total weight loaded on the ship
        // for the CURRENT day
        int load = 0;

        // Process every package one by one
        for (int i = 0; i < weights.size(); i++) {

            // Check if the current package can fit
            // in the current day's ship
            if (load + weights[i] > cap) {

                // Current package does NOT fit.
                // So we need a new day.
                day++;

                // Start the new day with the current package.
                //
                // IMPORTANT:
                // Previous 'load' belonged to the previous day,
                // so we don't add it.
                //
                // Example:
                // cap = 10
                // current load = 5
                // current package = 7
                //
                // 5 + 7 = 12 > 10
                // So 7 cannot fit in the old day.
                //
                // New day:
                // load = 7
                load = weights[i];
            }
            else {

                // Current package fits in the same day,
                // so add its weight to the current load.
                load = load + weights[i];
            }
        }

        // Return the total number of days required
        return day;
    }


    // Function to find the minimum ship capacity
    // needed to ship all packages within 'days' days
    int shipWithinDays(vector<int>& weights, int days) {

        // Minimum possible capacity:
        // The ship must at least be able to carry
        // the heaviest single package.
        int low = *max_element(weights.begin(), weights.end());

        // Maximum possible capacity:
        // If the ship carries everything in one day,
        // its capacity must equal the total weight.
        int high = accumulate(weights.begin(), weights.end(), 0);

        // Binary search for the minimum valid capacity
        while (low <= high) {

            // Find the middle capacity
            int mid = low + (high - low) / 2;

            // Check how many days are needed
            // if the ship capacity is 'mid'
            int daysRequired = FindDays(weights, mid);

            // If we can finish within the given number of days,
            // then this capacity works.
            //
            // But maybe an even smaller capacity can also work,
            // so search on the left side.
            if (daysRequired <= days) {

                high = mid - 1;
            }
            else {

                // We need more days than allowed.
                // This means capacity is too small.
                // So search on the right side.
                low = mid + 1;
            }
        }

        // 'low' is the smallest capacity
        // that can ship all packages within 'days' days.
        return low;
    }
};
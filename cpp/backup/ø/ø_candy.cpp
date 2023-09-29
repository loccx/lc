class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        // initialize vector of the same length as ratings which stores the candy for each student
        vector<int> val(n, 1);

        // if your rating is higher than the previous student, you get 1 extra candy compared to the previous student
        for (int k = 1; k < ratings.size(); k++) {
            if (ratings[k] > ratings[k-1]) val[k] = val[k-1] + 1;
        }

        for (int k = ratings.size() - 2; k >= 0; k--) {
            if ((ratings[k] > ratings[k+1]) && (val[k] <= val[k+1])) {
                val[k] = val[k+1] + 1;
            }
        }

        auto ans = reduce(val.begin(), val.end());
        return ans;
    }
};

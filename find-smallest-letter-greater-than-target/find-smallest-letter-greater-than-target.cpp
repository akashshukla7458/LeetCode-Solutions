class Solution {
public:
    char nextGreatestLetter(vector<char>& arr, char key) {
         int s = 0, e = arr.size() - 1;
    char ans = arr[0];
    while (s <= e) {
        int m = s + (e - s) / 2;
        if (arr[m] <= key) {
            s = m + 1;
        } else {
            ans = arr[m];
            e = m - 1;
        }
    }
    return ans <= key ? arr[0] : ans;
    }
};
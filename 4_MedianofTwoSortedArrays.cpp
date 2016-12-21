class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size();
        int n = nums2.size();
        int total = m + n;
        if (total % 2){
            return findK(nums1, 0, m, nums2, 0, n, total / 2 + 1);
        }else{
            return (findK(nums1, 0, m, nums2, 0, n, total / 2) + findK(nums1, 0, m, nums2, 0, n, total / 2 + 1)) / 2;
        }
    }
private:
    double findK(vector<int>& num1, int s1, int m, vector<int>& num2 ,int s2, int n, int k){
        if (m > n){
            return findK(num2, s2, n, num1, s1, m, k);
        }
        if (m == 0){
            return num2[s2 + k - 1];
        }
        if (k == 1){
            return (min(num1[s1], num2[s2]));
        }
        int p1 = min(k / 2, m);
        int p2 = k - p1;
        if (num1[s1 + p1 - 1] < num2[s2 + p2 - 1]){
            return findK(num1, s1 + p1, m - p1, num2, s2, n, k - p1);
        }else if (num1[s1 + p1 - 1] > num2[s2 + p2 - 1]){
            return findK(num1, s1, m, num2, s2 + p2, n - p2, k - p2);
        }else{
            return num1[s1 + p1 - 1];
        }
    }
};

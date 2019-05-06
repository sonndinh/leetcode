#include <vector>
#include <iostream>

using namespace std;
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int s1 = nums1.size();
        int s2 = nums2.size();
        if (nums2.size() == 0) {
            return 0.5*(nums1[s1/2] + nums1[(s1-1)/2]);
        }
        if (nums1.size() == 0) {
            return 0.5*(nums2[s2/2] + nums2[(s2-1)/2]);
        }
        
        int k = (s1 + s2)/2 + 1;
        // Find the last element of the first array in range [lo, hi].
        int lo = max(0, k - s2);
        int hi = min(k, s1);
        while (lo < hi) {
            int x = lo + (hi - lo)/2;
            int a1 = x-1 < 0 ? numeric_limits<int>::min() : nums1[x-1];
            int a2 = x >= nums1.size() ? numeric_limits<int>::max() : nums1[x];
            int b1 = k-x-1 < 0 ? numeric_limits<int>::min() : nums2[k-x-1];
            int b2 = k-x >= nums2.size() ? numeric_limits<int>::max() : nums2[k-x];
            
            if (a1 > b2) {
                hi = x - 1;
            } else if (a2 < b1) {
                lo = x + 1;
            } else {
                int med = max(a1, b1);
                if ((s1+s2)%2 == 1) return med;
                int med_1;
                if (med == a1) {
                    if (x-1 <= 0)
                        med_1 = b1;
                    else
                        med_1 = max(b1, nums1[x-2]);
                } else if (med == b1) {
                    if (k-x-1 <= 0)
                        med_1 = a1;
                    else
                        med_1 = max(a1, nums2[k-x-2]);
                }
                return 0.5*(med+med_1);
            }
        }
		int a = lo <= 0 ? numeric_limits<int>::min() : nums1[lo-1];
		int b = k-lo <= 0 ? numeric_limits<int>::min() : nums2[k-lo-1];
		int med = max(a, b);
        if ((s1+s2)%2 == 1) return med;
		
        int med_1;
        if (lo <= 0) {
            med_1 = nums2[k-lo-2];
        } else if (k-lo <= 0) {
            med_1 = nums1[lo-2];
        } else {
            if (med == a) {
                if (lo-1 <= 0)
                    med_1 = b;
                else 
                    med_1 = max(b, nums1[lo-2]);
            } else if (med == b) {
                if (k-lo-1 <= 0)
                    med_1 = a;
                else 
                    med_1 = max(a, nums2[k-lo-2]);
            }
        }
        return 0.5*(med+med_1);
    }
};

int main() {
	vector<int> A{1, 5, 7, 10};
	vector<int> B{3, 6, 9};
	//	vector<int> A{1, 3};
	//	vector<int> B{2};
	Solution sol;

	cout << "Median: " << sol.findMedianSortedArrays(A, B) << endl;
	
	return 0;
}

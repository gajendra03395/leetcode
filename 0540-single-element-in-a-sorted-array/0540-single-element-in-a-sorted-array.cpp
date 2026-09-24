class Solution {
public:
    int singleNonDuplicate(vector<int>& a) {
        int n = a.size();
        
        
        if (n == 1) return a[0];
        if (a[0] != a[1]) return a[0];
        if (a[n - 1] != a[n - 2]) return a[n - 1];

        
        int st = 1, end = n - 2;

        while (st <= end) {
            int mid = st + (end - st) / 2;
            
            
            if (a[mid - 1] != a[mid] && a[mid] != a[mid + 1]) {
                return a[mid];
            }

            if (mid % 2 == 0) {
                
                if (a[mid] == a[mid + 1]) {
                    st = mid + 1; 
                } else {
                    end = mid - 1; 
                }
            } else {
                
                if (a[mid] == a[mid - 1]) {
                    st = mid + 1; 
                } else {
                    end = mid - 1; 
                }
            }
        }
        return -1;
    }
};

class Solution {
public:
    int search(vector<int>& a, int tar) {
        int st = 0 , end = a.size() - 1 ;
        while(st<=end)
        {
            int mid = st + (end-st)/2;
            if(a[mid]==tar)
            {
                return mid;
            }
            if(a[st]<=a[mid])
            {
                if(a[st]<=tar && tar<=a[mid])
                {
                    end = mid - 1 ;
                }
                else
                {
                    st = mid + 1 ;
                }
            }
            else
            {
                if(a[mid]<=tar && tar<=a[end])
                {
                    st = mid + 1 ;
                }
                else
                {
                    end = mid - 1 ;
                }
            }
        }
        return -1;
    }
};
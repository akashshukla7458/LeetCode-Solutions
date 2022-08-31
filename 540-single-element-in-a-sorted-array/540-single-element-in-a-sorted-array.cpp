class Solution
{
    public:
        int singleNonDuplicate(vector<int> &nums)
        {
            int low = 0;
            int high = nums.size() - 2;
           
            while (low <= high)
            {
                 int mid = (low + high) / 2;
                if (mid % 2 == 0)
                {
                   	//check  if we r in ryt half
                    if (nums[mid] != nums[mid + 1])
                    {
                       	//shrink ryt
                        high = mid - 1;
                    }
                    else

                        low = mid + 1;
                }
                else
                {

                    if (nums[mid] == nums[mid + 1])
                    {
                       	// shrink ryt
                        high = mid - 1;
                    }
                    else low = mid + 1;
                }
            }
            return nums[low];
        }
};
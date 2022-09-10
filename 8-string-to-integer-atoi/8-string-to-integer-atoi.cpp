class Solution
{
    public:
        int myAtoi(string s)
        {
            int value {};
            stringstream ss
            {
                s
            };

            ss >> value;

            return value;
        }
};
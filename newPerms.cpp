#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> recursePerm(vector<int>& nums, int n, vector<vector<int>>& newVect)//first perm, elements, return our result as newVect
{
    if(n == 1)//if we have 1 element permutations, add it to our newVect
    {
        newVect.push_back(nums);
    }
    else
    {
        recursePerm(nums, n - 1, newVect);
        for(int i = 0; i < n - 1; i++)
        {
            if(n % 2 != 0)
            {
                swap(nums[0], nums[n - 1]);
            }
            else
            {
                swap(nums[i],  nums[n - 1]);
            }
            recursePerm(nums, n - 1, newVect);
        }
    }
    return newVect;
}

    vector<vector<int>> permute(vector<int>& nums) 
    {
        vector<vector<int>> newVect;
        return recursePerm(nums, nums.size(), newVect);//nums.size is our # of elements
    }
};
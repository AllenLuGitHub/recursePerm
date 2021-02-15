#include <iostream>
#include <vector>

using namespace std;

int factorial(int n)
{
	if (n > 1)
	{
		return n * factorial(n - 1);
	}
	else
	{
		return 1;
	}
}

vector<int> swapFunction(vector<int> nums, int index)
{
	//cout << index << endl;
    
    if (nums.size() - 1 == index)//last postiiton swap with first position
	{
		swap(nums[index], nums[0]);
	}

	else
	{
		swap(nums[index], nums[index + 1]);
	}
	return nums;
}


vector<vector<int>> recursePerm(vector<int> nums, int n, int index, vector<vector<int>> newVect) //
{
	
	if (n > 0)//as long as we have permutations to go through..2 perms
	{
		newVect.push_back(nums);//pushback all nums at once, 0,1 -> 1,0
		nums = swapFunction(nums, index); //swap values 0,1
		return recursePerm(nums, n - 1, (index + 1) % nums.size(), newVect);//1,0..1permleft..2%2 = 0
	}
	return newVect;
}

int main()
{
	vector<int> newNums{ 1,2,3 };
	vector<vector<int>> newVect;//establish 2d vector

	newVect = recursePerm(newNums, factorial(newNums.size()), 0, newVect);
	for(int i = 0; i < newVect.size(); i++)
	{
		for(int j = 0; i < newVect[i].size(); j++)
		{
			cout << newVect[i][j];
		}
		cout << endl;
	}
	return 0;
}
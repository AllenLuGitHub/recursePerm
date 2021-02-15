#include <iostream>

using namespace std;


void permute(int a[], int l, int r)
    {
        if (l == r)
        {
            for(int i = 0;i <= r ;i ++)
            {
                cout << a[i];
            }
        cout << "\n";
        }
    
        else
        {
            for (int i = l; i <= r; i++)
            {
                swap(a[l], a[i]);
                permute(a, l+1, r);
                swap(a[l], a[i]);
            }
        }
    }

    // Driver Code
    int main()
    {
        int n = [1,2,3];
    //cin >> n;
        int arr[n];

    //input the array
        permute(arr,0,n-1);
        return 0;
    }
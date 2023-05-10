#include <iostream>
using namespace std;

int binary_search(int **arr, int n, int row)
{

    int l = 0;
    int r = n - 1;
    int mid;

    while (l <= r)
    {
        mid = (l + r) / 2;
        if (arr[row][mid] == 1)
        {
            if (arr[row][mid + 1] == 0)
                return mid + 1;
            else
                l = mid + 1;
        }
        else
            r = mid - 1;
    }
    return r < 0 ? 0 : n;
}

int count_ones(int **arr, int n)
{
    int c = 0;
    for (int i = 0; i < n; i++)
        c += binary_search(arr, n, i);
    return c;
}

int main()
{
    int n, **arr;
    cin >> n;
    arr = new int *[n];
    for (int i = 0; i < n; i++)
    {
        arr[i] = new int[n];
        for (int j = 0; j < n; j++)
            cin >> arr[i][j];
    }
    cout << "Ones : " << count_ones(arr, n);
    return 0;
}

/*

4
1 1 0 0
1 0 0 0
1 1 1 0
1 1 1 1
*/
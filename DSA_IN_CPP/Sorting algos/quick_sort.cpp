#include <bits/stdc++.h>
#define ll long long
using namespace std;

// Analysis criteria:- its an divide and conqueror approach
// 1)Time complexity --> worst case --> O(n2)(already sorted array)  best case -->O(nlogn)(when equal division).
//-->inplace sorting algorithms(always happens in constant space doesnt depend upon n)--> yes its
// 2)stability --> no its a stable algo
// 3)adaptive algo --->already sorted array takes less time --> not adapive algo
// 4)recursive or not --> yes

void printvec(vector<int> &v)
{
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }
    cout << "" << endl;
}

int partition(vector<int> &v, int low, int high)// time complexity--> proportional to n
{
    int pivot = v[low];
    int i = low + 1;
    int j = high;
    do
    {
        while (v[i] <= pivot)
        {
            i++;
        }
        while (v[j] > pivot)
        {
            j--;
        }
        if (i < j)
        {
            swap(v[i], v[j]);
        }
    } while (i < j);
    swap(v[low],v[j]);
    return j;
}

void quick_sort(vector<int> &v, int low, int high)
{
    if (low < high)
    {
        int partionIndex = partition(v, low, high);
        quick_sort(v, low, partionIndex-1); // sort left subarray
        quick_sort(v, partionIndex + 1, high); // sort right subarray
    }
}

int main()
{
    ll n;
    cout << "ENTER THE NUMBER OF ELEMENTS YOU WANT" << endl;
    cin >> n;
    vector<int> v(n);
    cout << "ENTER THE ELEMENTS YOU WANT:-" << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    cout << "array before buuble sort is :" << endl;
    printvec(v);
    quick_sort(v, 0, n - 1);
    cout << "array after buuble sort is :" << endl;
    printvec(v);
    return 0;
}
#include <bits/stdc++.h>
#define ll long long
using namespace std;

// Analysis criteria:- sorting in minimum number of swaps(0->n-1 swaps)
// 1)Time complexity --> worst case --> O(n2)  best case -->O(n2).
//-->inplace sorting algorithms(always happens in constant space doesnt depend upon n)
// 2)stability --> no its a stable algo
// what is stable algo ?
// ex->6a 1 2 6b
// after sorting ->1 2 6a 6b (its a stable sorting algo as a is coming befor b as in preivous array order )
// 3)adaptive algo --->already sorted array takes less time --> not adapive algo

void printvec(vector<int> &v)
{
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }
    cout << "" << endl;
}

void selection_sort(vector<int> &v)
{
    int n = v.size();
    for (int i = 0; i < n - 1; i++)
    {
        int index_of_min = i;
        for (int j = i + 1; j < n; j++)
        {
            if (v[index_of_min] > v[j])
            {
                index_of_min = j;
            }
        }
        swap(v[index_of_min], v[i]);
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
    selection_sort(v);
    cout << "array after buuble sort is :" << endl;
    printvec(v);
    return 0;
}
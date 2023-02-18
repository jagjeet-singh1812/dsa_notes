#include <bits/stdc++.h>
#define ll long long
using namespace std;

// analysis criteria:-
// 1)Time complexity --> O(n2)
// 2)space complexity -->O(1) so inplace algo
//-->inplace sorting algorithms(always happens in constant space doesnt depend upon n)
// 3)stability --> yes its a stable algo
// what is stable algo ?
// ex->6a 1 2 6b
// after sorting ->1 2 6a 6b (its a stable sorting algo as a is coming befor b as in preivous array order )
// 4)internal or external sorting algo
// --> all data is loaded in memory-internal sorting algo
// --> all data is not loaded in memory-external sorting algo
// 5)adaptive algo --->already sorted array takes less time --> not by default adapive algo but it can be made adaptive
// 6)recursive or not -> not recursive

void printvec(vector<int> &v)
{
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }
    cout << "" << endl;
}

void bubble_sort(vector<int> &v)
{
    bool is_sorted;
    for (int i = 0; i < v.size() - 1; i++) // n-1 passes
    {
        is_sorted = true;                          // for adaptiveness
        for (int j = 0; j < v.size() - i - 1; j++) // for comparision in each pass
        {
            if (v[j] > v[j + 1])
            {
                int temp = v[j];
                v[j] = v[j + 1];
                v[j + 1] = temp;
                is_sorted = false;
            }
        }
        cout << "Array after " << i + 1 << " pass:" << endl;
        printvec(v);
        if (is_sorted)
        {
            return;
        }
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
    bubble_sort(v);
    cout << "array after buuble sort is :" << endl;
    printvec(v);
    return 0;
}
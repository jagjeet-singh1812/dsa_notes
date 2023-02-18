#include <bits/stdc++.h>
#define ll long long
using namespace std;

// analysis criteria:-
// 1)Time complexity --> worst case --> O(n2)  best case -->O(n)
// 2)space complexity
//-->inplace sorting algorithms(always happens in constant space doesnt depend upon n)
// 3)stability --> yes its a stable algo
// what is stable algo ?
// ex->6a 1 2 6b
// after sorting ->1 2 6a 6b (its a stable sorting algo as a is coming befor b as in preivous array order )
// 4)adaptive algo --->already sorted array takes less time --> yes adapive algo

void printvec(vector<int> &v)
{

    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }
    cout << "" << endl;
}

void insertion_sort(vector<int> &v)
{
    int key, j;
    int n = v.size();
    for (int i = 1; i <= n - 1; i++)
    {
        key = v[i];
        j = i - 1;
        while (key < v[j] && j >= 0)
        {
            v[j + 1] = v[j];
            j--;
        }
        v[j + 1] = key;
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
    insertion_sort(v);
    cout << "array after buuble sort is :" << endl;
    printvec(v);
    return 0;
}
/*Problem Statement : 

  given an array find if any subset meets the target sum

 Solution strategy : 

    Meet in the middle
*/
#include <bits/stdc++.h>
using namespace std;

void search(int index, const vector<int>& a, int n, vector<int>& sum, int currentSum) {
    if (index == n) {
        sum.push_back(currentSum);
        return;
    }

    // Don't include a[index]
    search(index + 1, a, n, sum, currentSum);

    // Include a[index]
    search(index + 1, a, n, sum, currentSum + a[index]);
}

void solve(int arr[], int length, int target) {
    vector<int> v1(arr, arr + length / 2);
    vector<int> v2(arr + length / 2, arr + length);

    vector<int> sum1, sum2;

    search(0, v1, v1.size(), sum1, 0);
    search(0, v2, v2.size(), sum2, 0);

    // Use set for faster lookup
    unordered_set<int> sumSet(sum2.begin(), sum2.end());

    for (int s1 : sum1) {
        if (sumSet.count(target - s1)) {
            cout << "Subset with target sum found: " << s1 << " + " << (target - s1) << " = " << target << endl;
            return;
        }
    }

    cout << "No subset with the given target sum found.\n";
}

int main() {
    int arr[4] = {2, 4, 5, 9};
    int target = 15;
    solve(arr, 4, target);
    return 0;
}

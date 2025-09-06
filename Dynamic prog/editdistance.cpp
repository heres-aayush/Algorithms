/*Problem Statement : 

find the no. of operations needed to convert string x to string y 

operations are : 
1. add
2. remove
3. modify 

 Solution strategy : 

 creating a 2d array and checking whether add, remove required or modify the letters

*/#include <bits/stdc++.h>
using namespace std;

int main () {
    string x = "Love";
    string y = "Movie";

    int arr[x.length() + 1][y.length() + 1];

    // Initialize base cases
    for (int i = 0; i <= x.length(); i++)
        arr[i][0] = i;

    for (int j = 0; j <= y.length(); j++)
        arr[0][j] = j;

    // Fill the DP array
    for (int i = 1; i <= x.length(); i++) {
        for (int j = 1; j <= y.length(); j++) {
            int cost;
            if (x[i - 1] == y[j - 1])
                cost = 0;
            else
                cost = 1;

            arr[i][j] = min(arr[i - 1][j] + 1, // remove
                        min(arr[i][j - 1] + 1, // insert
                            arr[i - 1][j - 1] + cost)); // replace
        }
    }

    cout << arr[x.length()][y.length()];
    return 0;
}
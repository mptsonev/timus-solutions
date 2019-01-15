#include <iostream>
#include <cmath>
using namespace std;

void nextPermutation(int arr[], int n)
{
    int br = n - 1;
    while (arr[br] == 1) {
        arr[br] = 0;
        br--;
    }
    arr[br] = 1;
}

int calcSum(int masiv[], int weights[], int n)
{
    int sum = 0;

    for (int i = 0; i < n; i++) {
        sum += masiv[i] * weights[i];
    }
    return sum;
}

int main()
{
    int n;
    cin >> n;
    int weights[n];
    int masiv[n], masiv2[n];
    for (int i = 0; i < n; i++) {
        cin >> weights[i];
        masiv[i] = 0;
        masiv2[i] = 1;
    }
    int ans, allSum = calcSum(masiv2, weights, n);
    int sum = 0;
    int br = 0;
    ans = allSum;
    for (int i = 0; i < pow(2, n); i++) {
        nextPermutation(masiv, n);
        sum = calcSum(masiv, weights, n);
        if (abs(allSum - 2 * sum) < ans)
            ans = abs(allSum - 2 * sum);
        for (int j = 0; j < n; j++) {
            br++;
        }
    }
    cout << ans;

    return 0;
}
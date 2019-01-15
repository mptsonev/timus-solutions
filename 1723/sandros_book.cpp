#include <iostream>
#include <string.h>
using namespace std;
int main()
{
    int wordsCount[26], maxCount = 0, maxIndex = 0;
    string input;
    cin >> input;
    for (int i = 0; i < 26; i++)
        wordsCount[i] = 0;
    for (int i = 0; i < input.length(); i++) {
        wordsCount[input[i] - 'a']++;
        if (maxCount < wordsCount[input[i] - 'a']) {
            maxCount = wordsCount[input[i] - 'a'];
            maxIndex = i;
        }
    }
    cout << input[maxIndex];

    return 0;
}

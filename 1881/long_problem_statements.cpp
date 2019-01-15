#include <iostream>
#include <string.h>
//#include<fstream>
using namespace std;
int main()
{
    int lines = 1, symbols = 0, pages = 1;
    string words;
    int h, w, n;
    cin >> h >> w >> n;
    for (int i = 0; i < n; i++) {
        cin >> words;
        symbols += words.length() + 1;
        if (symbols == w || symbols - 1 == w) {
            lines++;
            symbols = 0;
        }
        else if (symbols > w) {
            lines++;
            symbols = words.length() + 1;
            if (symbols == w || symbols - 1 == w) {
                lines++;
                symbols = 0;
            }
            if (lines > h) {
                pages++;
                lines = lines - h;
            }
        }
        if (lines > h) {
            pages++;
            lines = lines - h;
        }
    }

    if (lines == 1 && symbols == 0)
        cout << pages - 1;
    else
        cout << endl
             << pages;
    return 0;
}

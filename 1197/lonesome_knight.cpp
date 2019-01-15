#include <iostream>
#include <cstring>
using namespace std;

int calc (string s)
{
    int ans=0;
    if (s[1]-46<=8 && (char)(s[0]+1)<='h') ans++;
    if (s[1]-46<=8 && (char)(s[0]-1)>='a') ans++;
    if (s[1]-50>=1 && (char)(s[0]+1)<='h') ans++;
    if (s[1]-50>=1 && (char)(s[0]-1)>='a') ans++;
    if (s[1]-47<=8 && (char)(s[0]+2)<='h') ans++;
    if (s[1]-47<=8 && (char)(s[0]-2)>='a') ans++;
    if (s[1]-49>=1 && (char)(s[0]+2)<='h') ans++;
    if (s[1]-49>=1 && (char)(s[0]-2)>='a') ans++;
    return ans;


}

int main()
{
    int n;
    cin>>n;
    string pos;

    for (int i=0; i<n; i++)
    {
       cin>>pos;
       cout<<calc(pos)<<endl;
    }




}

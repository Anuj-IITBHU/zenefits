#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int fact(int n)
{
    if(n==0)
        return 1;
    return(n*fact(n-1));
}

int find_rank(vector<char> l, string s)
{
    int r=1;
    int n=l.size();
    for(int i=0;i<n;i++)
    {
        sort(l.begin(), l.end());
        int c=0;
        for(int j=0;;j++)
        {
            if(s[i]==l[j])
            {
                l[j]= (char)124;
                break;
            }
            c++;
        }
        r=r+c*fact(n-1-i);
    }
    return r;
}

int main() {
	int n;
	cin >> n;
	vector<char> l;
	for(int i=0;i<n;i++)
	{
	    char temp;
	    cin >> temp;
	    l.push_back(temp);
	}
	string s;
	cin >> s;
	cout << (find_rank(l, s));
	return 0;
}

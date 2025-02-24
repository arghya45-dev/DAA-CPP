#include <iostream>
#include <string>
using namespace std;

void naiveStringMatch(string text, string pattern)
{
    int n = text.size(), m = pattern.size();

    for (int i = 0; i <= n - m; i++)
    {
        int j;
        for (j = 0; j < m; j++)
            if (text[i + j] != pattern[j])
                break;
        if (j == m)
            cout << "Pattern found at index " << i << endl;
    }
}

int main()
{
    string text = "ABABABAB";
    string pattern = "ABAB";
    naiveStringMatch(text, pattern);
    return 0;
}

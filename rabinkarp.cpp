#include <iostream>
#include <string>
using namespace std;

#define d 256

void rabinKarp(string text, string pattern, int q)
{
    int n = text.size();
    int m = pattern.size();
    int h = 1; // The value of h will be pow(d, m-1) % q
    int p = 0; // Hash value for pattern
    int t = 0; // Hash value for text
    int i, j;

    // Calculate h = pow(d, m-1) % q
    for (i = 0; i < m - 1; i++)
        h = (h * d) % q;

    // Calculate initial hash values for pattern and text
    for (i = 0; i < m; i++)
    {
        p = (d * p + pattern[i]) % q;
        t = (d * t + text[i]) % q;
    }

    for (i = 0; i <= n - m; i++)
    {
        if (p == t)
        {
            for (j = 0; j < m; j++)
                if (text[i + j] != pattern[j])
                    break;

            if (j == m)
                cout << "Pattern found at index " << i << endl;
        }

        if (i < n - m)
        {
            t = (d * (t - text[i] * h) + text[i + m]) % q;
            if (t < 0)
                t += q;
        }
    }
}

int main()
{
    string text = "GEEKS FOR GEEKS";
    string pattern = "GEEK";
    int q = 101; // A prime number
    rabinKarp(text, pattern, q);
    return 0;
}

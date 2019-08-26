// version 1

In the following function KR all the multiplications by 2 are implemented by shifts. Furthermore, the computation of the modulus function is avoided by using the implicit modular arithmetic given by the hardware that forgets carries in integer operations. So, q is chosen as the maximum value for an integer.

#define REHASH(a, b, h) ((((h) - (a)*d) << 1) + (b))

void KR(char *x, int m, char *y, int n) {
   int d, hx, hy, i, j;

   /* Preprocessing */
   /* computes d = 2^(m-1) with
      the left-shift operator */
   for (d = i = 1; i < m; ++i)
      d = (d<<1);

   for (hy = hx = i = 0; i < m; ++i) {
      hx = ((hx<<1) + x[i]);
      hy = ((hy<<1) + y[i]);
   }

   /* Searching */
   j = 0;
   while (j <= n-m) {
      if (hx == hy && memcmp(x, y + j, m) == 0)
         OUTPUT(j);
      hy = REHASH(y[j], y[j + m], hy);
      ++j;
   }

}

//version 2 

# include <iostream>
#define q 3355439
#define d 256

int rksearch(char *p, char *a)
{ int M = strlen(p), N = strlen(a);
int i, j, dM = 1, h1 = 0, h2 = 0;
for (j = 1; j < M; j++)
    dM = (d*dM) % q;
for (j = 0; j < M; j++)
    h1 = (h1*d + p[j]) % q;
for (i = 0; i < M; i++)
    h2 = (h2*d + a[i]) % q;
for (i = M; i < N; i++)
{
if (h1 == h2) return i-M;
h2 = (h2 + d*q - a[i-M]*dM) % q;
h2 = (h2*d + a[i]) % q;
}
return N;
}

//version3
/* Following program is a C++ implementation of Rabin Karp
Algorithm given in the CLRS book */
#include <iostream>
#include<string>
using namespace std; 

// d is the number of characters in the input alphabet 
#define d 256 
// A prime number 
# define divider 101

/*
pat -> pattern 
    txt -> text 
*/
class Rolling_Hash_Pattern_Mathing {
public:
    int search(char pat[], char txt[]) 
{
    int LenPat = strlen(pat); 
    int LenTxt = strlen(txt); 
    int start_ptTxt, j; 
    int targetHash = 0; // hash value for pattern 
    int curHash = 0; // hash value for txt 
    int multiplier = 1; 

    // The value of multiplier would be "pow(d, LenPat-1)%q" 
    for (start_ptTxt = 0; start_ptTxt < LenPat - 1; start_ptTxt++) 
        multiplier = (multiplier * d) % divider; 

    // Calculate the hash value of pattern and first 
    // window of text 
    for (start_ptTxt = 0; start_ptTxt < LenPat; start_ptTxt++) 
    { 
        targetHash = (d * targetHash + pat[start_ptTxt]) % divider; 
        curHash = (d * curHash + txt[start_ptTxt]) % divider; 
    } 

    // Slide the pattern over text one by one 
    for (start_ptTxt = 0; start_ptTxt <= LenTxt - LenPat; start_ptTxt++) 
    { 

        // Check the hash values of current window of text 
        // and pattern. If the hash values match then only 
        // check for characters on by one 
        if ( targetHash == curHash ) 
        { 
            /* Check for characters one by one */
            for (j = 0; j < LenPat; j++) 
            { 
                if (txt[start_ptTxt+j] != pat[j]) 
                    break; 
            } 

            // if targetHash == curHash and pat[0...LenPat-1] = txt[start_ptTxt, start_ptTxt+1, ...start_ptTxt+LenPat-1] 
            if (j == LenPat) 
                cout<<"Pattern found at index "<< start_ptTxt<<endl; 
                return start_ptTxt;
        } 

        // Calculate hash value for next window of text: Remove 
        // leading digit, add trailing digit 
        if ( start_ptTxt < LenTxt-LenPat ) 
        { 
            curHash = (d*(curHash - txt[start_ptTxt]*multiplier) + txt[start_ptTxt+LenPat])%divider; 

            // We might get negative value of curHash, converting it 
            // to positive 
            if (curHash < 0) 
            curHash = (curHash + divider); 
        } 
    }
    // if not found, return -1;
    return -1;
}
};



/* Driver code */
int main() 
{
    char txt[] = "cdabcdab";
    char pat[] = "abcd";
    Rolling_Hash_Pattern_Mathing(pat, txt); 
    return 0; 
} 

// This is code is contributed by rathbhupendra 



#include<iostream>
#include<bits/stdc++.h>
 
using namespace std;

int minimumRecolors(string blocks, int k) {
    int countB = 0;
    int maxCountB = 0;

    for (int i = 0; i < blocks.length(); ++i) {
      if (blocks[i] == 'B')
        ++countB;
      if (i >= k && blocks[i - k] == 'B')
        --countB;
      maxCountB = max(maxCountB, countB);
    }

    return k - maxCountB; 
}

int main() {
    string blocks = "WBBWWBBWBW";
    int k = 7;

    cout<<minimumRecolors(blocks, k);

    return 0;
}
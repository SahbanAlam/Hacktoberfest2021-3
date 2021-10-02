/*
    given a an array with size N and N elements where all the elements repeat twice except two elements which dont repeat

    for examle: 
    N = 6
    array : [2, 5, 8, 5, 2, 7]  except 8 and 7 all elements are repeating

    Output :
    print those two elements which dont repeat

    for the above array output should be : 8, 7

    Complexity : O(n) [Bit Magic, XOR]

*/

#include <bits/stdc++.h>
using namespace std;

int main() {

    // array size
    int N;
    std::cin >> N;
    // create a vector / array of size N
    vector<int> V(N);
    // take inputs for the array
    for (int i = 0; i < N; i++)
        cin >> V[i];
    // initialize x with 0 initially : (x ^ 0) = x
    // take xor of all elements in the vector / array with x
    // the two elements which didn't repeat in the vector / array will be stored in x
    // for example if elements a & b appear in the vector only once then after taking xor of all elements
    // x will have a ^ b that is - >  x = a ^ b
    int x = 0;
    for (int i = 0; i < N; i++)
        x ^= V[i];
    // so now we have x = a ^ b
    // since x is not zero we can easily get the rightmost set bit of x
    int temp = x, i = 1;
    while (x) {
        if (x & i)
            break;
        i <<= 1;
    }
    // we check for what elements in the vector the x is having a set bit ( rightmost set bit of x) and then take xor with temp ( where temp = x )
    for (int j = 0; j < N; j++) {
        if (V[j] & i)
            temp ^= V[j];
    }
    // temp is having either a or b stored in it ( lets say temp = a)
    // we already know that x = a ^ b
    // therefore x = (x ^ temp) => a ^ b ^ a => b ( since any val ^ val = 0 and any val ^ 0 = val)
    x ^= temp;
    cout << x << " " << temp;

    return 0;
}

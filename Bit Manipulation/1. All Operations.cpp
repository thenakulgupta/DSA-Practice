/*
    Probleam: All Operations.

    Test cases:
    Input:
    7 2 0

    Output:
    peek: 1
    1
    7
    3
    3
    4
*/

#include <iostream>
using namespace std;

int getBit(int n, int place) {
    return (n & (1 << place));
}

int setBit(int n, int place) {
    return (n | (1 << place));
}

int clearBit(int n, int place) {
    return (n & ~(1 << place));
}

int updateBit(int n, int place, int ch) {
    return ch == 1 ? setBit(n, place)
        : clearBit(n, place);
}

int clearLastBits(int n, int place) {
    return (n & ((~0) << place));
}

int main() {
    int n, place, ch;
    cin >> n >> place >> ch;
    cout << (getBit(n, place) > 0 ? 1 : 0) << endl;
    cout << setBit(n, place) << endl;
    cout << clearBit(n, place) << endl;
    cout << updateBit(n, place, ch) << endl;
    cout << clearLastBits(n, place) << endl;
    return 0;
}
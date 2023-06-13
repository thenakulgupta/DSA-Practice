/*
    Probleam: Valid Anagram.

    Test cases:
    Input:
    4 4
    race
    care

    Output:
    1



    Input:
    5 4
    tulip
    care

    Output:
    0

*/


#include <iostream>
#include <map>

using namespace std;

bool checkIsAnagram(map<char, int> hm, map<char, int> hm1) {
    for (auto m : hm) {
        if (hm1[m.first] != 0) {
            if (hm1[m.first] == 1) {
                hm1.erase(m.first);
            }
            else {
                hm1[m.first] -= 1;
            }
        }
        else {
            return false;
        }
    }
    return hm1.empty();
}

int main() {
    string n, n1;
    cin >> n >> n1;
    map<char, int> hm;
    map<char, int> hm1;
    for (int i = 0;i < n.length();i++) {
        hm[n[i]] = hm[n[i]] + 1;
    }
    for (int i = 0;i < n1.length();i++) {
        hm1[n[i]] = hm1[n[i]] + 1;
    }
    cout << checkIsAnagram(hm, hm1);
    return 0;
}
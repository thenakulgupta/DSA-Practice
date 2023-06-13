/*
    Probleam: Basic of HashMaps.
*/

#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;
int main() {
    unordered_map<string, int> hm;
    hm["India"] = 50;
    hm["Usa"] = 10;
    hm["China"] = 20;

    for (auto key : hm) {
        cout << key.first << ":" << key.second << endl;
    }

    cout << hm["India"] << endl;
    cout << hm["Indonesia"] << endl;

    cout << (hm.find("India") != hm.end() ? "Key Found" : "Key Not Found") << endl;
    cout << (hm.find("Russia") != hm.end() ? "Key Found" : "Key Not Found") << endl;

    hm.erase(hm.find("India"));
    cout << (hm.find("India") != hm.end() ? "Key Found" : "Key Not Found") << endl;

    cout << hm.size() << endl;
    cout << hm.empty() << endl;
    return 0;
}
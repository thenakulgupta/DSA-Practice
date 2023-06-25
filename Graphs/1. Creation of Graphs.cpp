/*
    Probleam: Creation of Graphs.
*/

#include <iostream>
#include <list>

using namespace std;

class Edge {
public:
    int src;
    int dest;
    int weight;
    Edge(int src1, int dest1, int weight1) {
        src = src1;
        dest = dest1;
        weight = weight1;
    }
};

int main() {
    /*           (5)
            0 -------- 1
                      / \
                 (1) /   \ (3)
                    /     \
                   2 ----- 3
                   |  (1)
               (2) |
                   |
                   4

    */
    list<Edge> edges[5];
    edges[0].push_back({ 0,1,5 });
    edges[1].push_back({ 1,2,1 });
    edges[1].push_back({ 1,3,3 });
    edges[2].push_back({ 2,1,1 });
    edges[2].push_back({ 2,3,1 });
    edges[2].push_back({ 2,4,2 });
    edges[3].push_back({ 3,1,3 });
    edges[3].push_back({ 3,2,1 });
    edges[4].push_back({ 4,2,2 });

    // Finding Neighbours of "2"
    for (auto i : edges[2]) {
        cout << "Src: " << (i.src) << endl << "Dest: " << i.dest << endl << "Weight: " << i.weight << endl << endl;
    }
    return 0;
}
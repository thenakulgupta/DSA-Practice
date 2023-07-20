/*
    Probleam: Find Minimum Depth of a Binary Tree.
*/

#include <iostream>
#include <queue>

using namespace std;

class Node {
public:
    int data;
    int depth;
    Node* left;
    Node* right;

    Node(int d) {
        data = d;
    }
};

int findMinDepth(Node* n) {
    // Initialising the minDepth to MAX to get the minimum of all the edges
    int minDepth = INT_MAX;
    // Current Depth
    int cDepth = 1;
    queue<Node*> q;
    // Assigned the current Depth to the node
    n->depth = cDepth;
    // Pushing the node into the queue.
    q.push(n);
    while (!q.empty()) {
        // Getting the top node from queue.
        Node* curr = q.front();
        q.pop();

        // Checking if a node is a leaf node or not
        if (curr->right != NULL || curr->left != NULL) {
            // Current Node is not a leaf node
            cDepth += 1;
            if (curr->right != NULL) {
                curr->right->depth = cDepth;
                q.push(curr->right);
            }
            if (curr->left != NULL) {
                curr->left->depth = cDepth;
                q.push(curr->left);
            }
        }
        else {
            // Leaf Node
            // Assinging the minimum Depth from minDepth and current Node depth.
            minDepth = min(minDepth, curr->depth);
        }
    }
    return minDepth;
}

int main() {
    /*
            1
           / \
          8   2
         / \  /
        6  5 9
    */
    Node* n = new Node(1);
    n->left = new Node(8);
    n->left->left = new Node(6);
    n->left->right = new Node(5);
    n->right = new Node(2);
    n->right->left = new Node(9);

    cout << findMinDepth(n);
    return 0;
}
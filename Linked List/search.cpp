#include <bits/stdc++.h>
using namespace std;

class Node {
    public:
    int data;
    Node* next;

    Node(int data1) {
        data = data1;
        next = nullptr;
    }
};

// Function to search for a value in the linked list
int checkifPresent(Node* head, int desiredElement) {
    Node* temp = head;

    //Traverse the linked list
    while(temp != nullptr) {
        if (temp->data == desiredElement)
            return 1;

        temp = temp->next;
    }

    return 0;
}

int main() {
    // Create a linked list: 1 -> 2 -> 3
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);

    int val = 5;  // Element to be checked for presence in the linked list

    // Call the checkifPresent function and print the result
    cout << checkifPresent(head, val) << '\n';

    return 0;  // Return 0 to indicate successful execution
}


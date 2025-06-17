#include<bits/stdc++.h>
#include<iostream>
// This code is a simple implementation of a singly linked list node in C++.
using namespace std;
class Node {
    public: //access modifier
    int data; //the data value
    Node* next; //the pointer to the next value
    //constructor
    Node (int data1, Node* next1) {
        data = data1; //Initialize data with the provided value
        next=next1;  //Initialize next with the provided value
    }
    Node (int data1) {
        data=data1; //Initialize data with the provided value
        next = nullptr; //Initialize next to nullptr
    }

};
int main() {
    vector<int> arr = {2,5,8,7};
    Node* y = new Node(arr[0]);
    cout<<y<<'\n';
    cout<<y->data<<'\n';
}
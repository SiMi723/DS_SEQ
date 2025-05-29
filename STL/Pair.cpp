#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main() {
    
    //name, age, weight

    // pair<string, int>p;
    // p = make_pair("Alice", 25);
    // p.first = "Alice";
    // p.second = 25;
    
    // pair<string, pair<int, int> >p;
    // p.first = "Alice";
    // p.second.first = 25;
    // p.second.second = 55;

    pair< pair<string, int> , int>p;
    p = make_pair(make_pair("Alice", 25), 55);
     
    // pair<string, pair<int, int>> p;
    // p = make_pair("Alice", make_pair(25, 55));

    cout << p.first.first << " " << p.first.second << " " << p.second << endl;
}
#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main() {
    list<int> l;
    l.push_back(20);
    l.push_back(30);
    l.push_back(40);
    l.push_front(70);
    l.push_front(15);

    cout<<l.front()<<" "<<l.back()<<endl;

}
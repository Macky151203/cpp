#include<iostream>
using namespace std;
struct datanode{
    string name;
    int weight;
    datanode *link;
};
struct headnode{
    int count;
    datanode *first;
};
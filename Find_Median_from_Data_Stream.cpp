#include <iostream>
#include <queue>
using namespace std;
 
priority_queue<int>leftHeap;  
priority_queue<int, vector<int>, greater<int>> rightHeap;
 
void insertNumber(int value){
    leftHeap.push(value);
    rightHeap.push(leftHeap.top());
    leftHeap.pop();
 
    if (rightHeap.size() > leftHeap.size()){
        leftHeap.push(rightHeap.top());
        rightHeap.pop();
    }
}
double findMedian(){
    if (leftHeap.size() == rightHeap.size())
        return (leftHeap.top()+ rightHeap.top()) / 2.0;
    return leftHeap.top();
}
int main(){
    int count;
    cout<<"Enter the number of numbers you want to put:";
    cin >>count;
    cout <<"Enter "<< count<<" values:\n";
    for(int i=0; i<count; i++){
        int x;
        cin>>x;
        insertNumber(x);
        cout << "Median so far: "<<findMedian()<<endl;
    }
    cout<<"Median of all numbers: "<< findMedian()<<endl;
    return 0;
}

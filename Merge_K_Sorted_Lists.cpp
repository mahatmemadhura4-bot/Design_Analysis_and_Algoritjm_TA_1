#include <iostream>
#include <vector>
using namespace std;
struct Node{
    int data;
    Node* next;
    Node(int x) : data(x), next(nullptr) {}
};
 
Node* mergeTwo(Node* a, Node* b){
    Node dummy(0);
    Node* tail = &dummy;
    while(a && b) {
        if(a->data <= b->data){
            tail->next = a;
            a = a->next;
        }
        else{
            tail->next = b;
            b = b->next;
        }
        tail = tail->next;
    }
    tail->next=(a ? a : b);
    return dummy.next;
}
 
Node* mergeAll(vector<Node*>& lists){
    if (lists.empty()) return nullptr;
    while (lists.size() > 1){
        vector<Node*> temp;
        for (size_t i = 0; i < lists.size(); i += 2){
            Node* first = lists[i];
            Node* second = (i+1 < lists.size()) ? lists[i + 1] : nullptr;
            temp.push_back(mergeTwo(first, second));
        }
        lists = move(temp);
    }
    return lists[0];
}
Node* buildList(const vector<int>& arr){
    Node dummy(0);
    Node* curr = &dummy;
    for (int val : arr) {
        curr->next = new Node(val);
        curr = curr->next;
    }
    return dummy.next;
}
void printList(Node* head){
    while (head) {
        cout<<head->data;
        if (head->next) cout << " -> ";
        head = head->next;
    }
    cout << "\n";
}
int main(){
    int k;
    cout << "Enter how many lists: ";
    cin >> k;
    vector<Node*> lists;
    for (int i = 0; i < k; i++){
        int n;
        cout << "Enter size of list " << i + 1 << ": ";
        cin >>n;
 
        vector<int> arr(n);
        cout << "Enter " << n << " sorted elements: ";
        for (int j= 0; j< n; j++) {
            cin >> arr[j];
        }
        lists.push_back(buildList(arr));
    }
    Node* result = mergeAll(lists);
    cout<<"Merged list: ";
    printList(result);
    return 0;
}


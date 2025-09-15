#include <iostream>
#include <vector>
using namespace std;
int maxProfit(vector<int>& prices){
    if(prices.empty())
    return 0;
    int buy= prices[0];
    int profit= 0;
    for(int i= 1; i < prices.size(); i++){
        if (prices[i] < buy){
            buy= prices[i];
        }
        else if(prices[i] - buy > profit){
            profit =prices[i]-buy;
        }
    }
    return profit;
}
int main(){
    int n;
    cout <<"Enter number of days: ";
    cin >>n;
    vector<int>prices(n);
    cout << "Enter stock prices: ";
    for (int i = 0; i < n; i++){
        cin>>prices[i];
    }
    int result =maxProfit(prices);
    cout<<"Maximum Profit: "<<result<< endl;
    return 0;
}

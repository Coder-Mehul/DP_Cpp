#include<bits/stdc++.h>
using namespace std;

int helper(vector <int > arr , int n , int i){
    if(i==n-1){
        return 0;
    }
    if(i>=n-1){
        return INT_MAX;
    }
    int steps=INT_MAX;
    int max_jump=arr[i];
    for(int jump=1;jump<=max_jump;i<jump++){
        int next=i+jump;
        int sbprm=helper(arr , n , next);
        if(sbprm!=INT_MAX){
            steps=min(steps, sbprm+1);
        }
    }
    return steps;


}

int main(){
    vector< int > arr  = {3,4,2,1,2,3,7,1,1,3};
    int n=arr.size();

    cout<<helper(arr , n ,0);
}
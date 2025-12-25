#include <iostream>
#include <vector>
#include <algorithm>
using std:: cout;
using std:: cin;
using std:: vector;
using std:: sort;
using std:: endl;

void solve(){
    int n;
    if (!(cin >> n)) return;
    vector<int> votes;
    votes.reserve(n);

    int tempID;
    for(int i = 0; i < n; i++){
        cin >> tempID;
        votes.push_back(tempID);
    }
    sort(votes.begin(), votes.end());
    
    int winnerID = votes[0];
    int maxVote = 0;
    int currentVote = 1;

    for(int i = 1; i < n; i++){
        if(votes[i] == votes[i-1]){
            currentVote++;
        } else{
            if(currentVote >= maxVote){
                maxVote = currentVote;
                winnerID = votes[i-1];
            }
            currentVote = 1;
        }
    }
    cout << winnerID << " " << maxVote <<endl;
}


int main() {
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
}
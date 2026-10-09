#include <bits/stdc++.h>
using namespace std;

int pos[46],goal[46];
long long moves=0;
long long towerCost(const int state[],int k,int dest) {
    if (k==0) return 0;
    if (state[k]==dest) return towerCost(state,k-1,dest);
    int other=6-state[k]-dest;
    return towerCost(state,k-1,other)+(1LL<<(k-1)); // 收小盘、移大盘、再搬整塔。
}
void moveDisk(int k,int dest) {
    cout << "move " << k << " from " << char('A'+pos[k]-1) << " to " << char('A'+dest-1) << '\n';
    pos[k]=dest; ++moves;
}
void gather(int k,int dest) {
    if (k==0) return;
    if (pos[k]==dest) { gather(k-1,dest); return; }
    int other=6-pos[k]-dest;
    gather(k-1,other); moveDisk(k,dest); gather(k-1,dest); // 每次大盘移动前清空上方。
}
void transform(int k) {
    if (k==0) return;
    if (pos[k]==goal[k]) { transform(k-1); return; }
    int source=pos[k],dest=goal[k],other=6-source-dest;
    long long direct=towerCost(pos,k-1,other)+1+towerCost(goal,k-1,other);
    long long via=towerCost(pos,k-1,dest)+(1LL<<(k-1))+1+towerCost(goal,k-1,source);
    if (direct<=via) {
        gather(k-1,other); moveDisk(k,dest); transform(k-1);
    } else {
        gather(k-1,dest); moveDisk(k,other);
        gather(k-1,source); moveDisk(k,dest); transform(k-1);
    }
}

int main() {
    int n; cin >> n;
    for (int peg=1;peg<=3;++peg) { int count; cin >> count; while(count--){int disk;cin>>disk;pos[disk]=peg;} }
    for (int peg=1;peg<=3;++peg) { int count; cin >> count; while(count--){int disk;cin>>disk;goal[disk]=peg;} }
    transform(n);
    cout << moves << '\n';
}

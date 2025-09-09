#include<bits/stdc++.h>
using namespace std;

const int N = 2*1e5;

class query {
public:
    int id, l, r, res, time;
//    int block;
};
vector<query> qv;
vector<pair<int, int> > updateQueries;

int distinct = 0; // distinct elements in current window
int cnt[N+5]; // stores the frequency


void add(int val) {
    cnt[val]++;
    if(cnt[val]==1) distinct++;
    if(cnt[val]==2) distinct--;
    // we are finding unique values in a range
    // if we find duplicate, the kind will no longer be distinct
    // not same distinct as in DQUERY
}
void rem(int val) {
    cnt[val]--;
    if(cnt[val]==0) distinct--;
    if(cnt[val]==1) distinct++;
}

void update(vector<int>& v, int i, int x, int y) {

    int idx = updateQueries[i].first;
    int val = updateQueries[i].second;

    int old = v[idx];
    v[idx] = val;
    updateQueries[i].second = old;

    if(idx>=x && idx<=y) {
        rem(old);
        add(val);
    }
}

int main() {

    ios_base::sync_with_stdio(0); cin.tie(NULL);

    int n, num_q; cin>>n>>num_q;
    vector<int> v(n);
    for(int i=0; i<n; i++) cin>>v[i];

    int sz = pow(n, 2.0/3.0)+1;

    for(int i=0; i<num_q; i++) {

        int c; cin>>c;
        if(c==1) {
            int idx, val; cin>>idx>>val;
            updateQueries.push_back(make_pair(idx, val));
        } else if(c==2) {
            query q;
            cin>>q.l; cin>>q.r;

            q.id = i; q.time = updateQueries.size();
//            q.block = (q.l)/sz;
            qv.push_back(q);

        }
    }

    // sort queries
    sort(qv.begin(), qv.end(), [&](query a, query b){

        if((a.l/sz)==(b.l)/sz){
            if((a.r/sz)==(b.r/sz)) return a.time<b.time;
            return (a.r/sz)<(b.r/sz);
         }
         return (a.l/sz)<(b.l/sz);

    });

    int x = 0, y = 0; // maintain current window, [x, y)
    int current_time = 0;
    for(int i=0; i<qv.size(); i++) {

        // update time
        int time = qv[i].time;

        while(current_time<time) {
            update(v, current_time, x, y);
            current_time++;
        }
        while(current_time>time) {
            current_time--;
            update(v, current_time, x, y);
        }

        // add y
        while(y<=qv[i].r) {
            add(v[y]);
            y++;
        }
        // removing y
        while(y>(qv[i].r+1)) {
            y--;
            rem(v[y]);
        }
        // removing x
        while(x<qv[i].l) {
            rem(v[x]);
            x++;
        }
        // add x
        while(x>qv[i].l) {
            x--;
            add(v[x]);
        }

        qv[i].res = distinct;

    }

    sort(qv.begin(), qv.end(), [&](query a, query b){
            return a.id<b.id;
    });

    for(int i=0; i<qv.size(); i++) {
        cout<<qv[i].res<<'\n';
    }

    return 0;
}

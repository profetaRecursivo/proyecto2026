vector<pair<int,int>> compressed;
int curL = segs[0].first;
int curR = segs[0].second;

for(int i = 1; i < segs.size(); i++) {
    if(segs[i].first <= curR) {
        // hay solapamiento
        curR = max(curR, segs[i].second);
    } else {
        // no se solapan, guardamos el actual
        compressed.push_back({curL, curR});
        curL = segs[i].first;
        curR = segs[i].second;
    }
}
// guardar el ult
compressed.push_back({curL, curR});
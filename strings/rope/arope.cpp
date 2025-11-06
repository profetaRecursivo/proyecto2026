// The Alphabetic Rope is now available in the market. The Alphabetic Rope consists of alphabetic characters in each stripe which looks like string. You are given an Alphabetic Rope consisting of lowercase alphabetic characters only. You have to perform some operations on the rope and answers some queries on it and Time is increases by 1. Initial time is 0 and queries are of 4 types:
// 1 X Y: Cut the rope segment from X to Y and join at the front of rope.
// 2 X Y: Cut the rope segment from X to Y and join at the back of rope.
// 3 Y: Print on a new line the character at the Yth position of current rope.
// 4 X Y: Print on a new line the character on Yth position of rope configuration at Xth time.
char buff[tam];
#include <ext/rope>
using namespace __gnu_cxx;

void solve(){
    scanf("%s", buff);
    int q, t;
    scanf("%d", &q);
    vector<rope<char>> arr(1);
    arr[0] = rope<char>(buff);
    int x, y;
    while(q--){
        scanf("%d", &t);
        arr.push_back(arr.back());
        if(t == 1){
            scanf("%d %d", &x, &y);
            auto temp = arr.back().substr(x, y - x + 1);
            arr.back().erase(x, y - x + 1);
            arr[sz(arr)-1] = temp.append(arr.back());
        }else if(t == 2){
            scanf("%d %d", &x, &y);
            auto temp = arr.back().substr(x, y - x + 1);
            arr.back().erase(x, y - x + 1);
            arr[sz(arr)-1] = arr.back().append(temp);
        }else if(t == 3){
            scanf("%d", &y);
            printf("%c\n", arr.back()[y]);
        }else{
            scanf("%d %d", &x, &y);
            printf("%c\n", arr[x][y]);
        }
    }
}
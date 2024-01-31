#include <vector>
#include <iostream>
using namespace std;

    int firstDayBeenInAllRooms(std::vector<int>& nextVisit) {
        const int MOD = 1e9 + 7;
        int day = 0, room = 0;
        int daylength = nextVisit.size();
        std::vector<int> count(daylength, 0);
        while(true){
            count[room]++;
            if(count[room] % 2 == 1 && room != daylength){ //jishu
                room = nextVisit[room];
                day++;
            }
            else if(room == daylength){
                return (day + 1) % MOD;
            }
            else{
                room = (room + 1) % daylength;
                day++;
            }

        }
    }


int main() {
    std::vector<int> nextVisit = {0,0,2};
    int result = firstDayBeenInAllRooms(nextVisit);
    cout<< result;
    return 0;
}

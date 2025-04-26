#include<iostream>
#include<vector>
#include<map>
#include<queue>

using namespace std;

class Vehicle
{
    public:
    string number;
    string type;
    Vehicle(string num,string t)
    {
        number=num;
        type=t;
    }
};
class ParkingSlot
{
    int slotId;
    string type;
    bool isOccupied;
    ParkingSlot(int id,string t)
    {
        slotId=id;
        type=t;
        isOccupied=false;
    }
};

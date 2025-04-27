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
    public:
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
class ParkingLot
{
    private:
    queue<Vehicle>carQueue,bikeQueue,truckQueue;
    public:
    vector<ParkingSlot>slots;
    map<string,int>VehicleToslot;
    void addslot(ParkingSlot);
    void parkVehicle(Vehicle);
    void removeVehicle(string);
};
void ParkingLot::addslot(ParkingSlot slot)
{
     slots.push_back(slot);
}
void ParkingLot::parkVehicle(Vehicle v)
{
    bool parked=false;
    for(auto &slot:slots)
    {
        if(!slot.isOccupied && slot.type==v.type)
        {
            slot.isOccupied=true;
            VehicleToslot[v.number]=slot.slotId;
            cout<<"Vehicle "<<v.number<<"is parked at "<<slot.slotId<<endl;
            parked=true ;
            break;
        }
    }
    if(!parked)
    {
        if(v.type=="car")carQueue.push(v);
        else if(v.type=="bike")bikeQueue.push(v);
        else if(v.type=="truck")truckQueue.push(v);
        cout<<"No slot available for "<<v.number<<".Added to queue."<<endl;
        if(!(v.type=="car")||!(v.type=="bike")||!(v.type=="truck"))
        cout<<"invalid vehicle"<<endl;

    }
}
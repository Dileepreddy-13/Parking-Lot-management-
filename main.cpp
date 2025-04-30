#include<iostream>
#include<vector>
#include<map>
#include<queue>
#include<algorithm>
#include<cctype>

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
    void assignVehicle(string);
    void displayStatus();
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
            cout<<"Vehicle "<<v.number<<" is parked at "<<slot.slotId<<endl;
            parked=true ;
            break;
        }
    }
    if(!parked)
    {
        if(!(v.type=="car"||v.type=="bike"||v.type=="truck"))
        cout<<"invalid vehicle type."<<endl;
        else if(v.type=="car")carQueue.push(v);
        else if(v.type=="bike")bikeQueue.push(v);
        else if(v.type=="truck")truckQueue.push(v);
        else cout<<"No slot available for "<<v.number<<".Added to queue."<<endl;

    }
}
void ParkingLot::removeVehicle(string vehicleNumber)
{
    if(VehicleToslot.find(vehicleNumber)!=VehicleToslot.end())
    {
        int slotId=VehicleToslot[vehicleNumber];
        string slotType;
        for(auto &slot:slots)
        {
            if(slot.slotId==slotId)
            {
                slot.isOccupied=false;
                slotType=slot.type;
                cout<<"Vehicle "<<vehicleNumber<<"is removed from "<<slotId<<endl;
                VehicleToslot.erase(vehicleNumber);
                break; 
            }
        }
        assignVehicle(slotType);
    }
    else
    {
        cout<<"Vehicle not found."<<endl;
    }
}
void ParkingLot::assignVehicle(string type)
{
    if(type=="car" && !carQueue.empty())
    {
        Vehicle v=carQueue.front();
        carQueue.pop();
        parkVehicle(v);
    }
    else if(type=="bike" && !bikeQueue.empty())
    {
        Vehicle v=bikeQueue.front();
        bikeQueue.pop();
        parkVehicle(v);
    }
    else if(type=="truck" && !truckQueue.empty())
    {
        Vehicle v=truckQueue.front();
        truckQueue.pop();
        parkVehicle(v);
    }
}
void ParkingLot::displayStatus()
{
    cout<<"Parking Lot Status"<<endl;
    for(auto &slot:slots)
    {
        cout<<"Slot "<<slot.slotId<<"("<<slot.type<<") : ";
        if(slot.isOccupied)
        {
            for(auto &pair:VehicleToslot)
            {
                if(pair.second==slot.slotId)
                {
                    cout<<"Occupied by "<<pair.first<<endl;
                    break;
                }
            }
        }
        else
        {
            cout<<"Available"<<endl;
        }
    }
    cout<<"------------------"<<endl;
    cout<<"Queues"<<endl;
    cout<<"Car Queue : "<<carQueue.size()<<endl;
    cout<<"Bike Queue : "<<bikeQueue.size()<<endl;
    cout<<"Truck Queue : "<<truckQueue.size()<<endl;
}

int main()
{
    ParkingLot lot;
    for(int i=1;i<=5;i++)
    {
        lot.addslot(ParkingSlot(i,"car"));
    }
    for(int i=6;i<=10;i++)
    {
        lot.addslot(ParkingSlot(i,"bike"));
    }
    for(int i=11;i<=15;i++)
    {
        lot.addslot(ParkingSlot(i,"truck"));
    }
    int choice;
    while(1)
    {
        cout<<"Parking Lot Menu"<<endl;
        cout<<"1.Park Vehicle"<<endl;
        cout<<"2.Remove Vehicle"<<endl;
        cout<<"3.Display Status"<<endl;
        cout<<"4.Exit"<<endl;
        cout<<"------------------"<<endl;
        cout<<"Enter Your Choice"<<endl;
        cin>>choice;
        cout<<"------------------"<<endl;
        switch(choice)
        {
            case 1:
            {
                string number,type;
                cout<<"Enter Vehicle Number :"<<endl;
                cin>>number;
                transform(number.begin(),number.end(),number.begin(), ::toupper);
                cout<<"Enter Vehicle Type :"<<endl;
                cin>>type;
                transform(type.begin(),type.end(),type.begin(), ::tolower);
                lot.parkVehicle(Vehicle(number,type));
                break;
            }
            case 2:
            {
                string number;
                cout<<"Enter Vehicle Number :"<<endl;
                cin>>number;
                transform(number.begin(),number.end(),number.begin(), ::toupper);
                lot.removeVehicle(number);
                break;
            }
            case 3:
            {
                lot.displayStatus();
                break;
            }
            case 4:
            {
                cout<<"Exiting program."<<endl;
                exit(0);
            }
            default:
            {
                cout<<"Invalid choice. Try again"<<endl;
            }
        }
        cout<<"------------------"<<endl;
    }
    return 0;
}
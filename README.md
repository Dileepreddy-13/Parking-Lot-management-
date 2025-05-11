# Parking-Lot-management-
The Parking Lot Management System is a software application designed to streamline and automate the process of managing vehicle parking .

The Vehicle(string num, string t) constructor is responsible for initializing a vehicle object with a unique vehicle number and a type, such as "car", "bike", or "truck". This identification helps the parking system correctly allocate slots and manage vehicles. Similarly, the ParkingSlot(int id, string t) constructor is used to create parking slot objects, each with a specific slot ID and vehicle type. These slots are initially marked as unoccupied and are later filled based on incoming vehicle types.

The function addslot(ParkingSlot slot) allows new slots to be added to the parking lots internal list by inserting them into a vector. This setup function is typically used during the initialization phase to create a predefined number of slots for each vehicle type. 

When a new vehicle arrives, the parkVehicle(Vehicle v) function tries to find a suitable and available slot that matches the vehicle's type. If such a slot is found, the vehicle is parked there, the slot is marked as occupied, and a mapping between the vehicle number and the slot ID is stored. If no matching slot is available, the vehicle is placed into a waiting queue corresponding to its type, ensuring it will be parked once a slot becomes free.

To handle vehicle departures, the removeVehicle(string vehicleNumber) function checks whether the vehicle is currently parked. If it is found, the corresponding slot is freed up, the mapping is removed, and the function attempts to assign a vehicle from the queue (if any) to the newly vacated slot. This assignment is managed by the assignVehicle(string type) function, which checks the appropriate queue based on the slot type and parks the next waiting vehicle if possible.

Finally, the displayStatus() function provides a snapshot of the current parking lot state. It lists every parking slot along with whether it is occupied or available, and if occupied, it shows which vehicle is parked there. Additionally it displays the number of vehicles waiting in each queue, offering a clear overview of the systems load and efficiency.

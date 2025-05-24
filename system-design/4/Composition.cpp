#include <iostream>
#include <string>
#include <vector>

class Room {
public:
    std::string name;
    Room(std::string n) : name(n) {}
    void describe() { std::cout << "This is a " << name << ".\n"; }
};

class House {
public:
    std::string address;
    std::vector<Room> rooms; // Composition: House owns Rooms
    House(std::string addr) : address(addr) {}
    void addRoom(std::string roomName) {
        rooms.push_back(Room(roomName));
    }
    void describeHouse() {
        std::cout << "House at " << address << " has:\n";
        for (auto& room : rooms) {
            room.describe();
        }
    }
    // When House is destroyed, its Rooms are automatically destroyed
};

int main() {
    House house("123 Main St");
    house.addRoom("Living Room");
    house.addRoom("Kitchen");
    house.describeHouse(); // Output: House at 123 Main St has:
                          // This is a Living Room.
                          // This is a Kitchen.

    // When house goes out of scope, its rooms are destroyed
    return 0;
}
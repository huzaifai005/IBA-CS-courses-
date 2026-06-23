
#include "../header/Dungeon.hpp"
#include "../header/Player.hpp"
#include "../header/Room.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>

int main() {
    srand(static_cast<unsigned int>(time(0))); 
    
    Player player("Adventurer", 100, 20);

    
    Dungeon dungeon(&player);

    
    std::cout << "WELCOME TO THE DUNGEON\n";
    std::cout << "IT DOES NOT MATTER HOW YOU GOT HERE OR WHO BROUGHT YOU, THE ONLY THING THAT MATTERS IS, CAN YOU ESCAPE THE DUNGEON, MWAHAHAHAHAHAH!!!\n\n";

    std::cout << "You wake up feeling as if you've been out for days. A sharp pain in your back, realizing you are unable to move.\n";
    std::cout << "You look around you. The room is dark and gloomy, with strange, ominous sounds echoing through the walls. You realize you need to find a way out of this place.\n";
    std::cout << "You put all your energy into it, and after a few moments of struggle, you manage to stand up.\n";
    std::cout << "You see an open door at the far end of the room, leading into the unknown.\n\n";
    std::cout << "It's time to explore... and escape.\n";

    
    std::cout << "\nPress Enter to begin your journey...";
    std::cin.get(); 

    
    Room* room1 = new Room(
        "A dimly lit room with a faint glow coming from a weapon on the ground.",
        "Find the weapon to increase your attack power.",
        "Weapon collected!",
        false, 
        false, 
        true  
    );

    Room* room2 = new Room(
        "A narrow hallway sending chills down your spine.",
        "Defeat the Goblin to proceed.",
        "Goblin defeated!",
        true, 
        false,
        false 
    );

    Room* room3 = new Room(
        "A treasure room filled with glittering gold and jewels.",
        "Collect the treasure to gain its benefits.",
        "Treasure collected!",
        false, 
        true,  
        false 
    );

    Room* room4 = new Room(
        "A mysterious room with an old man standing in the corner.",
        "Solve the old man's riddle to gain a treasure.",
        "Riddle solved and treasure collected!",
        false, 
        true,  
        false, 
        true   
    );

    Room* room5 = new Room(
        "A room that brings you ever so closer to the exit.",
        "Take the sword to increase your attack power.",
        "Weapon collected!",
        false, 
        false, 
        true  
    );

    Room* room6 = new Room(
        "A room filled with ancient artifacts and a glowing chest.",
        "Open the chest to collect the treasure.",
        "Treasure collected!",
        false, 
        true,  
        false 
    );

    Room* room7 = new Room(
        "A large, ominous chamber with enemies guarding the exit.",
        "Defeat the enemies to escape the dungeon.",
        "Enemies defeated! You can now escape!",
        true,  
        false, 
        false, 
        false, 
        true,  
        true   
    );

    
    dungeon.addRoom(room1);
    dungeon.addRoom(room2);
    dungeon.addRoom(room3);
    dungeon.addRoom(room4);
    dungeon.addRoom(room5);
    dungeon.addRoom(room6);
    dungeon.addRoom(room7);

    
    dungeon.playGame();

    
    delete room1;
    delete room2;
    delete room3;
    delete room4;
    delete room5;
    delete room6;
    delete room7;

    return 0;   
}
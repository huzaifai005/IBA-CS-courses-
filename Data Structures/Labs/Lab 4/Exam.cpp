#include <iostream>
#include <set>

class ExamRoom {
private:
    std::set<int> occupiedSeats;
    int totalSeats;              

public:
    ExamRoom(int N) : totalSeats(N) {}


    int seat() {
        if (occupiedSeats.empty()) {
            occupiedSeats.insert(0);
            return 0;
        }
        int maxDistance = *occupiedSeats.begin(); 
        int bestSeat = 0;                         
        auto previous = occupiedSeats.begin();
        for (auto current = std::next(occupiedSeats.begin()); current != occupiedSeats.end(); ++current) {
            int gap = (*current - *previous) / 2; 
            if (gap > maxDistance) {
                maxDistance = gap;
                bestSeat = *previous + gap;      
            }
            previous = current;
        }
        int endGap = totalSeats - 1 - *previous;
        if (endGap > maxDistance) {
            bestSeat = totalSeats - 1;
        }
        occupiedSeats.insert(bestSeat);
        return bestSeat;
    }

    void leave(int seatNumber) {
        occupiedSeats.erase(seatNumber);
    }
};

int main() {
    ExamRoom examRoom(10);

    std::cout << "First student enters the room and sits at seat: " << examRoom.seat() << "\n";  
    std::cout << "Second student enters the room and sits at seat: " << examRoom.seat() << "\n"; 
    std::cout << "Third student enters the room and sits at seat: " << examRoom.seat() << "\n";  
    std::cout << "Fourth student enters the room and sits at seat: " << examRoom.seat() << "\n";  
    examRoom.leave(4); 
    std::cout << "Student leaves seat 4.\n";
    std::cout << "Fifth student enters the room and sits at seat: " << examRoom.seat() << "\n";  

    return 0;
}
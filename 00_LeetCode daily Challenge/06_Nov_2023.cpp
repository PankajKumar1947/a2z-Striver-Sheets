//1845. Seat Reservation management

#include<bits/stdc++.h>
using namespace std;

//Brut Force Solution:
class SeatManager {   
private:
    vector<int> seat;
public:
    SeatManager(int n) {
        seat.resize(n+1,0);
    }
    
    int reserve(){
        for(int i=1;i<=seat.size();i++){
            if(seat[i]==0){
                seat[i]=1;
                return i;
            }
        }
        return -1;
    }
    
    void unreserve(int seatNumber) {
        if(seatNumber>=1 && seatNumber<=seat.size())
            seat[seatNumber]=0;
    }
};

//optimal solution:
class SeatManager {
private:
    priority_queue<int, vector<int>, greater<int>> available_seats;

public:
    SeatManager(int n) {
        for (int i = 1; i <= n; i++) {
            available_seats.push(i);
        }
    }

    int reserve() {
        if (!available_seats.empty()) {
            int reserved_seat = available_seats.top();
            available_seats.pop();
            return reserved_seat;
        } else {
            return -1; // No available seats.
        }
    }

    void unreserve(int seatNumber) {
        available_seats.push(seatNumber);
    }
};



/**
 * Your SeatManager object will be instantiated and called as such:
 * SeatManager* obj = new SeatManager(n);
 * int param_1 = obj->reserve();
 * obj->unreserve(seatNumber);
 */
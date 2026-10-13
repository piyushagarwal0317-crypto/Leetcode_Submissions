class BusBooking {
public:

    unordered_map<string, int> book; // seats mapped with cost
    int cost = 0;

    BusBooking(int n) {
        
    }
    
    void toggle(string seat) {
        if(book.count(seat)){
            cost -= book[seat];
            book.erase(seat);
            return;
        }

        string mid = "";
        if(seat[0] == 'A'){
            mid = 'B'; // reversing to check if the adjacent seats are already booked
        }
        else if(seat[0] == 'D'){
            mid = 'C';
        }

        mid += seat.substr(1); // add the row number after the seat no

        book[seat] = book.contains(mid) ? 3 : 1;
        cost += book[seat];
    }
    
    int getTotalTime() {
        return cost;
    }
    
    int getMinTime() {
        return book.size();
    }
};

/**
 * Your BusBooking object will be instantiated and called as such:
 * BusBooking* obj = new BusBooking(n);
 * obj->toggle(seat);
 * int param_2 = obj->getTotalTime();
 * int param_3 = obj->getMinTime();
 */
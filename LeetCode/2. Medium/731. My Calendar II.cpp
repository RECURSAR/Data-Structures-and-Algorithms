#include<iostream>
#include<bits/stdc++.h>
 
using namespace std;

class MyCalendarTwo {
public:
    vector<pair<int, int>> singleBookings; // Stores intervals where one event is booked
    vector<pair<int, int>> doubleBookings; // Stores intervals where two events are booked

    MyCalendarTwo() {}
    
    bool book(int start, int end) {
        // Check if the new event would cause a triple booking
        for (auto& [s, e] : doubleBookings) {
            if (max(start, s) < min(end, e)) { // There's an overlap with double-booked interval
                return false;
            }
        }
        
        // Check for overlaps with single-booked intervals and add the overlapping part to doubleBookings
        for (auto& [s, e] : singleBookings) {
            if (max(start, s) < min(end, e)) { // There's an overlap
                doubleBookings.push_back({max(start, s), min(end, e)});
            }
        }
        
        // Add the current event to single bookings
        singleBookings.push_back({start, end});
        
        return true;
    }
};

int main() {
    MyCalendar cal;
    
    cout << cal.book(10, 20); // returns true, no overlap
    cout << cal.book(50, 60); // returns true, no overlap
    cout << cal.book(10, 40); // returns true, overlaps with [10, 20]
    cout << cal.book(5, 15);  // returns false, would cause triple booking with [10, 20] and [10, 40]
    cout << cal.book(5, 10);  // returns true, overlaps with [10, 20] but no triple booking


    return 0;
}
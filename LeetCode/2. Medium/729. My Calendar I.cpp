#include<iostream>
#include<bits/stdc++.h>
 
using namespace std;

class MyCalendar {
public:
    map<int, int> calendar;  // Stores intervals as [start, end)
    
    MyCalendar() {
        
    }
    
    bool book(int start, int end) {
        auto next = calendar.lower_bound(start); // Find the first event whose start >= 'start'
        
        // Check if there's an overlap with the next event
        if (next != calendar.end() && next->first < end) {
            return false; // Overlap with the next event
        }
        
        // Check if there's an overlap with the previous event
        if (next != calendar.begin() && prev(next)->second > start) {
            return false; // Overlap with the previous event
        }
        
        // No overlap, insert the event
        calendar[start] = end;
        return true;
    }
};

int main() {
    MyCalendar cal;
    
    cout << cal.book(10, 20); // returns true
    cout << cal.book(15, 25); // returns false (overlaps with [10, 20])
    cout << cal.book(20, 30); // returns true (no overlap)

    return 0;
}
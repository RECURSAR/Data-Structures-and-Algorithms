#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class NumberContainers {
public:
    void change(int index, int number)
    {
        const auto it = indexToNumber.find(index);
        if (it != indexToNumber.cend())
        {
            const int originalNumber = it->second;
            auto &indices = numberToIndices[originalNumber];
            indices.erase(index);
            if (indices.empty())
                numberToIndices.erase(originalNumber);
        }
        indexToNumber[index] = number;
        numberToIndices[number].insert(index);
    }

    int find(int number)
    {
        const auto it = numberToIndices.find(number);
        if (it == numberToIndices.cend())
            return -1;
        const auto &indices = it->second;
        return *indices.begin();
    }

private:
    unordered_map<int, int> indexToNumber;
    unordered_map<int, set<int>> numberToIndices;
};

int main() {
    NumberContainers *obj = new NumberContainers();

    obj->change(1, 10);
    obj->change(2, 10);
    obj->change(1, 20);
    cout << obj->find(10) << endl; 
    cout << obj->find(20) << endl;
     
    delete obj;
    return 0;
}
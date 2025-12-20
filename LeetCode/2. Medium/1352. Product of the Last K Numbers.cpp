#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class ProductOfNumbers {
public:
    ProductOfNumbers() : prefix{1} {}

    void add(int num) {
    if (num == 0)
        prefix = {1};
    else
        prefix.push_back(prefix.back() * num);
    }

    int getProduct(int k) {
        return k >= prefix.size() ? 0 : prefix.back() / prefix[prefix.size() - k - 1];
    }

private:
    vector<int> prefix;
};

int main() {
    ProductOfNumbers *obj = new ProductOfNumbers();

    obj->add(3);
    obj->add(0);
    obj->add(2);
    obj->add(5);
    obj->add(4);
    cout << obj->getProduct(2) << endl; // Output: 20
    cout << obj->getProduct(3) << endl; // Output: 40
    cout << obj->getProduct(4) << endl; // Output: 0
    obj->add(8);
    cout << obj->getProduct(2) << endl; // Output: 32
    delete obj;

    return 0;
}
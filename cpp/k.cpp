#include<bits/stdc++.h>
using namespace std;

enum Size {
    S, M, L
};

struct Package {
    Package() {};

    long long id;
    Size size;
    bool frozen_food;
};
 
class LockerSystem {
private:
    const long long MAX_CAPACITY = 3;

    unordered_map<Size,unordered_set<long long>> lockers;
    queue<Package> locker_queue;
    
    unordered_map<Size,unordered_set<long long>> frozen_lockers;
    queue<Package> frozen_locker_queue;

public:
    LockerSystem() {}

    bool add_package(Package package) {
        if (package.frozen_food) {
            if (frozen_lockers[package.size].size() < MAX_CAPACITY) {
                frozen_lockers[package.size].insert(package.id);
                return true;
            }
            else {
                frozen_locker_queue.push(package);
                return false;
            }
        }
        else {
            if (lockers.size() < MAX_CAPACITY) {
                lockers[package.size].insert(package.id);
                return true;
            }
            else {
                locker_queue.push(package);
                return false;
            }
        }
    }

    bool retrieve_package(Package package) {
        if (package.frozen_food) {
            if (frozen_lockers.size() > ) {
                frozen_lockers[package.size].insert(package.id);
                return true;
            }
            else {
                frozen_locker_queue.push(package);
                return false;
            }
        }
        else {
            if (lockers.size() < MAX_CAPACITY) {
                lockers[package.size].insert(package.id);
                return true;
            }
            else {
                locker_queue.push(package);
                return false;
            }
        }
    }
};
 
int main(){
    LockerSystem locker_system;
    l.output_max();
}

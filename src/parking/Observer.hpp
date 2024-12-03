#ifndef OBSERVER_H
#define OBSERVER_H

#include <algorithm>
#include <string>
#include <vector>

using namespace std;

class Observer {
   public:
    virtual void update(const string& message) = 0;
    virtual ~Observer() {}
};

#endif

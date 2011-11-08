#ifndef USEMAPHORE_H
#define USEMAPHORE_H

#ifndef UCPP_COMPILER

class uSemaphore {
public:
    uSemaphore(unsigned int count = 1);
    void P();
    bool tryP();
    void V(unsigned int times = 1);
    int counter() const;
    bool empty() const;
};

#endif // UCPP_COMPILER

#include "uSemaphore.h"

#endif // USEMAPHORE_H

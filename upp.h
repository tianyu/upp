#ifndef UCPP_H
#define UCPP_H

#ifndef UCPP_COMPILER

#include <istream>
#include <ostream>

#define _Coroutine class
#define _Event class
#define _Task class
#define _Monitor class
#define _Cormonitor class
#define _Enable
#define _CatchResume catch
#define _Resume throw
#define _At ; throw
#define _Throw throw
#define _Mutex
#define _Nomutex
#define _When if
#define _Accept while
#define or

#define COROUTINE \
protected: \
    void resume(); \
    void suspend(); \
public: \
    void *stackPointer() const; \
    unsigned int stackSize() const; \
    void *stackStorage() const; \
    ptrdiff_t stackFree() const; \
    ptrdiff_t stackUsed() const; \
    void verify(); \
    \
    const char *setName(const char *name); \
    const char *getName() const; \
    uBaseCoroutine &starter() const; \
    uBaseCoroutine &resumer() const; \
    \
    static int asyncpoll(); \
    \
    enum CancellationState { CancelEnabled, CancelDisabled }; \
    void cancel(); \
    bool cancelled(); \
    bool cancelInProgress(); \
    \
    _Event Failure; \
    _Event UnhandledException; \
private:

#define TASK \
    COROUTINE \
public: \
    static void yield(unsigned int times = 1);\
    uBaseCoroutine &getCoroutine() const;\
    int getActivePriority(); \
    int getBasePriority(); \
private:

#else

#define COROUTINE
#define TASK

#endif // UCPP_COMPILER

#include "uC++.h"

#endif // UCPP_H

#ifndef RVL_SDK_OS_MUTEX_H
#define RVL_SDK_OS_MUTEX_H
// Trimmed from doldecomp/ogws include/revolution/OS/OSMutex.h (CC0-1.0), see docs/SDK.md.
#include "types.h"
#include "revolution/OS/OSThread.h"
#ifdef __cplusplus
extern "C" {
#endif

struct OSMutex {
    OSThreadQueue queue; // at 0x0
    OSThread* thread;    // at 0x8
    s32 lock;            // at 0xC
    OSMutex* next;       // at 0x10
    OSMutex* prev;       // at 0x14
};

typedef struct OSCond {
    OSThreadQueue queue; // at 0x0
} OSCond;

void OSInitMutex(OSMutex* mutex);
void OSLockMutex(OSMutex* mutex);
void OSUnlockMutex(OSMutex* mutex);
void __OSUnlockAllMutex(OSThread* thread);
BOOL OSTryLockMutex(OSMutex* mutex);
void OSInitCond(OSCond* cond);
void OSWaitCond(OSCond* cond, OSMutex* mutex);
void OSSignalCond(OSCond* cond);

#ifdef __cplusplus
}
#endif
#endif

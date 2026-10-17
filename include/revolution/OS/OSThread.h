#ifndef RVL_SDK_OS_THREAD_H
#define RVL_SDK_OS_THREAD_H
// Trimmed from doldecomp/ogws include/revolution/OS/OSThread.h (CC0-1.0), see docs/SDK.md.
#include "types.h"
#ifdef __cplusplus
extern "C" {
#endif

typedef struct OSThread OSThread;

typedef struct OSThreadQueue {
    OSThread* head; // at 0x0
    OSThread* tail; // at 0x4
} OSThreadQueue;

void OSInitThreadQueue(OSThreadQueue* queue);
void OSSleepThread(OSThreadQueue* queue);
void OSWakeupThread(OSThreadQueue* queue);

#ifdef __cplusplus
}
#endif
#endif

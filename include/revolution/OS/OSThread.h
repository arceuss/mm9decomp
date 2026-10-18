#ifndef RVL_SDK_OS_THREAD_H
#define RVL_SDK_OS_THREAD_H
// Trimmed from doldecomp/ogws include/revolution/OS/OSThread.h (CC0-1.0), see docs/SDK.md.
#include "types.h"
#ifdef __cplusplus
extern "C" {
#endif

typedef struct OSThread OSThread;
typedef struct OSMutex OSMutex;

typedef struct OSThreadQueue {
    OSThread* head; // at 0x0
    OSThread* tail; // at 0x4
} OSThreadQueue;

typedef struct OSThreadLink {
    OSThread* next; // at 0x0
    OSThread* prev; // at 0x4
} OSThreadLink;

typedef struct OSMutexQueue {
    OSMutex* head; // at 0x0
    OSMutex* tail; // at 0x4
} OSMutexQueue;

// OSContext is kept opaque until a source TU needs its fields.
struct OSThread {
    u8 context[0x2C8];        // at 0x0
    u16 state;                // at 0x2C8
    u16 flags;                // at 0x2CA
    s32 suspend;              // at 0x2CC
    s32 priority;             // at 0x2D0
    s32 base;                 // at 0x2D4
    u32 val;                  // at 0x2D8
    OSThreadQueue* queue;     // at 0x2DC
    OSThreadLink link;        // at 0x2E0
    OSThreadQueue joinQueue;  // at 0x2E8
    OSMutex* mutex;           // at 0x2F0
    OSMutexQueue mutexQueue;  // at 0x2F4
};

void OSInitThreadQueue(OSThreadQueue* queue);
void OSSleepThread(OSThreadQueue* queue);
void OSWakeupThread(OSThreadQueue* queue);
OSThread* OSGetCurrentThread(void);
s32 OSDisableScheduler(void);
s32 OSEnableScheduler(void);
s32 __OSGetEffectivePriority(OSThread* thread);
void __OSPromoteThread(OSThread* thread, s32 prio);

#ifdef __cplusplus
}
#endif
#endif

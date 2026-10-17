#ifndef RVL_SDK_OS_INTERRUPT_H
#define RVL_SDK_OS_INTERRUPT_H
// Trimmed from doldecomp/ogws include/revolution/OS/OSInterrupt.h (CC0-1.0), see docs/SDK.md.
#include "types.h"
#ifdef __cplusplus
extern "C" {
#endif

BOOL OSDisableInterrupts(void);
BOOL OSEnableInterrupts(void);
BOOL OSRestoreInterrupts(BOOL status);

#ifdef __cplusplus
}
#endif
#endif

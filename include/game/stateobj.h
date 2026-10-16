#ifndef GAME_STATEOBJ_H
#define GAME_STATEOBJ_H

#include "types.h"

// Object handled by the per-type update/draw pairs: update dispatches through a
// per-file state table indexed by `state`, draw calls fn_800C7608 when bit 0 of
// `flags14` is set. Not yet proven to be the same type as Obj in obj.h (that one
// stores a byte at 0x14).
typedef struct StateObj {
    /* 0x00 */ u8 pad00[0x11];
    /* 0x11 */ u8 state;
    /* 0x12 */ u8 pad12[0x14 - 0x12];
    /* 0x14 */ u32 flags14;
} StateObj;

typedef void (*StateObjFunc)(StateObj* obj);

void fn_800C7608(StateObj* obj);

#endif

#ifndef GAME_OBJ_H
#define GAME_OBJ_H

#include "types.h"

// Pooled game object. Allocated by fn_800E8C44 from the pool at lbl_804EE738 and
// initialised by fn_80042DA0(obj, type). Only offsets with matched accesses are
// listed; field names are offsets until their meaning is pinned down.
// 0x34 and 0xCC are type-specific: fn_80063FA0 stores an s32/u8 there, while
// fn_80043794 treats 0x34 as an object pointer and fn_80043938/fn_80046344 use 0xCC
// as a word. Those files use local layouts until the per-type variants are known.
typedef struct Obj {
    /* 0x00 */ u8 pad00[0xA];
    /* 0x0A */ u8 flagsA; // bit 0 is cleared before fn_80042CF8(obj, 4)
    /* 0x0B */ u8 pad0B[0x14 - 0xB];
    /* 0x14 */ u8 unk14;
    /* 0x15 */ u8 pad15[0x34 - 0x15];
    /* 0x34 */ s32 unk34;
    /* 0x38 */ u8 pad38[0x60 - 0x38];
    /* 0x60 */ s32 unk60; // copied as a pair into the arg of fn_80040AD0, likely a position
    /* 0x64 */ s32 unk64;
    /* 0x68 */ u8 pad68[0xC8 - 0x68];
    /* 0xC8 */ s32 unkC8;
    /* 0xCC */ u8 unkCC;
} Obj;

extern void* lbl_804EE738; // object pool handed to fn_800E8C44

Obj* fn_800E8C44(void* pool);
void fn_800E9244(Obj* obj);
void fn_80042DA0(Obj* obj, s32 type);
void fn_80042CF8(Obj* obj, s32 arg);

#endif

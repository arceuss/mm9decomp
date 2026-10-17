#include "types.h"

typedef struct Unk8009DE58 {
    /* 0x000 */ u32 unk0;
    /* 0x004 */ u8 pad4[0x8 - 0x4];
    /* 0x008 */ const char* unk8;
    /* 0x00C */ u32* unkC;
    /* 0x010 */ u8* unk10;
    /* 0x014 */ u8 pad14[0xFC - 0x14];
    /* 0x0FC */ s32 unkFC;
    /* 0x100 */ s32 unk100;
} Unk8009DE58;

typedef struct Unk80316D78 {
    /* 0x0000 */ u8 pad0[0x3004];
    /* 0x3004 */ u8* unk3004;
} Unk80316D78;

typedef struct Unk80301280 {
    /* 0x00 */ u8 pad0[0x40];
    /* 0x40 */ u32* unk40;
} Unk80301280;

extern u8 lbl_8031BF70[];
extern Unk80316D78 lbl_80316D78;
extern Unk80301280 lbl_80301280;

void fn_800AA554(const char* name, u16 idx, void* arc);
void fn_800AA9A4(void);
void fn_8009FB64(void);
void fn_800E7960(void* w, void (*cb)(void));
void fn_8000BF80(void* a, void* b, void* c, void* d, u8* e);
void fn_8009EDEC(void* hdr, u8* data, void* dst);
void fn_8009F0A0(s16 i, Unk8009DE58* s);

#define ARC (lbl_80316D78.unk3004 + 0xCD5000)

static inline void Reset(void) {
    *(s32*)(lbl_8031BF70 + 0x4AEB8) = 0x7FFFFFFF;
    *(s32*)(lbl_8031BF70 + 0x4AEBC) = 0x7FFFFFFF;
    *(s32*)(lbl_8031BF70 + 0x4AEC0) = 0;
    *(s32*)(lbl_8031BF70 + 0x4AEC4) = 0;
    *(s32*)(lbl_8031BF70 + 0x4AEC8) = 0x400000;
    *(s32*)(lbl_8031BF70 + 0x4AECC) = 0x380000;
    lbl_8031BF70[0x28E] = 0;
    lbl_8031BF70[0x28F] = 0;
    *(s32*)(lbl_8031BF70 + 0x4CED4) = 0x100;
    *(s32*)(lbl_8031BF70 + 0x4CED8) = 0;
    lbl_8031BF70[0x4CED0] = 0;
    lbl_8031BF70[0x4CED1] = 0;
    lbl_8031BF70[0x4CED2] = 0;
    lbl_8031BF70[0x4CED3] = 0;
}

void fn_8009DE58(Unk8009DE58* s, s32* pos) {
    u32* hdr;
    u32* t;
    s32 i;
    u8* w;
    u8* a;

    *(Unk8009DE58**)(lbl_8031BF70 + 0x288) = s;
    fn_800AA554(s->unk8, 0xFFFF, ARC);
    fn_800AA9A4();
    a = ARC;
    hdr = (u32*)((*(u32*)(a + 4) >> 1) + (u32)a);
    s->unkC = hdr;
    a = ARC;
    t = (u32*)((*(u32*)(a + 0x1C) >> 1) + (u32)a);
    if (s->unk10 == 0) {
        s->unk10 = (u8*)t + *t;
    }
    w = lbl_8031BF70;
    *(u16*)(w + 0x28C) = s->unk0 | 0x80;
    *(s32*)(w + 0x280) = pos[0];
    *(s32*)(w + 0x284) = pos[1];
    *lbl_80301280.unk40 &= ~0xF00;
    fn_800E7960(w, fn_8009FB64);
    *(u8**)(w + 8) = w;
    *(u16*)(w + 0x4AEAE) = 0;
    *(u16*)(w + 0x890) = 0xFF0F;
    *(u16*)(w + 0x892) = 0xFF0F;
    *(u16*)(w + 0x894) = 0xFF0F;
    *(u16*)(w + 0x896) = 0xFF0F;
    *(s32*)(w + 0x4AEB0) = s->unkFC;
    *(s32*)(w + 0x4AEB4) = s->unk100;
    fn_8000BF80(w + 0x270, hdr[1] + (u8*)hdr, hdr[0] + (u8*)hdr, hdr[2] + (u8*)hdr, s->unk10);
    a = ARC;
    fn_8009EDEC((void*)((*(u32*)(a + 4) >> 1) + (u32)a), s->unk10, w + 0x8A4);
    for (i = 0; i < 4; i++) {
        fn_8009F0A0(i, s);
    }
    Reset();
}

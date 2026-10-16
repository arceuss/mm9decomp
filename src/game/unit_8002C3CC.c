#include "types.h"

typedef struct Unk8002C3CC {
    /* 0x000 */ u8 pad0[0x26C];
    /* 0x26C */ u8 mode;
    /* 0x26D */ u8 drawn;
    /* 0x26E */ u8 pad26E;
    /* 0x26F */ u8 unk26F;
    /* 0x270 */ u8 unk270;
    /* 0x271 */ s8 scroll;
    /* 0x272 */ u8 voice;
    /* 0x273 */ s8 unk273;
    /* 0x274 */ u8 pad274[0x283 - 0x274];
    /* 0x283 */ u8 voiceStep;
    /* 0x284 */ u8 voiceIdx;
} Unk8002C3CC;

typedef struct Unk80316D78 {
    /* 0x0000 */ u8 pad0[0x3004];
    /* 0x3004 */ u8* unk3004;
} Unk80316D78;

typedef struct Unk8037C3D8 {
    /* 0x0 */ u8 unk0;
    /* 0x1 */ u8 pad1[0x5 - 0x1];
    /* 0x5 */ u8 unk5;
    /* 0x6 */ u8 pad6[0x50 - 0x6];
} Unk8037C3D8;

typedef struct Unk80301420 {
    /* 0x000 */ u8 pad0[0x48];
    /* 0x048 */ u8 unk48[0x380 - 0x48];
} Unk80301420;

extern Unk80301420 lbl_80301420;
extern u8 lbl_8043CD08[];
extern void (*lbl_804EC8C8[2])(Unk8002C3CC* obj);
extern Unk80316D78 lbl_80316D78;
extern u8 lbl_80263E7C[0x34];
extern u8 lbl_80263EE4[0x34];
extern u8 lbl_804EE6D0;
extern Unk8037C3D8 lbl_8037C3D8;
extern void* lbl_804EE948;

void fn_800E6A78(void* arg0);
void fn_8009C04C(s32 arg0, void* arg1, s32 arg2);
void fn_800A78AC(void);
void fn_8002C69C(Unk8002C3CC* obj);
void fn_8002C89C(Unk8002C3CC* obj);
void fn_8002C954(Unk8002C3CC* obj);
void fn_8000ECB8(s32 arg0, void* gfx, u8 tile, s8 x, s8 y);
void fn_800A7084(s32 arg0, u8 id, s32 arg2, s32 arg3, s32 arg4);
void fn_800A6D90(void);
void fn_800E8D30(void* arg0, s32 arg1);
void fn_800E8FC4(void* arg0, void* arg1);
void fn_800E69E8(void* arg0);

#define GFX (lbl_80316D78.unk3004 + 0xC28FF8)

static inline void* Font(void) {
    u8* p = lbl_80316D78.unk3004 + 0xC29000;

    return (*(u32*)(p + 8) >> 1) + p;
}

void fn_8002C3CC(Unk8002C3CC* obj) {
    u8 i;

    fn_800E6A78(lbl_80301420.unk48);
    fn_8009C04C(0, lbl_8043CD08, 0x20);
    fn_800A78AC();
    if (obj->mode != 3) {
        lbl_804EC8C8[obj->mode](obj);
    }
    if (obj->mode == 3) {
        if (obj->voiceStep == 0) {
            fn_8002C69C(obj);
            fn_8002C89C(obj);
        }
        fn_8002C954(obj);
    }
    if (obj->drawn == 0) {
        obj->drawn = 1;
        for (i = 0; i < 9; i++) {
            for (lbl_804EE6D0 = 0; lbl_804EE6D0 < 0x15; lbl_804EE6D0++) {
                fn_8000ECB8(0x38, Font(), 0xB, lbl_804EE6D0 + 2, i * 2 + 8);
            }
            fn_8000ECB8(0x38, Font(), lbl_80263E7C[i + obj->scroll], 2, i * 2 + 8);
        }
        if (obj->scroll == 0) {
            obj->unk26F = 0;
        } else {
            obj->unk26F = 1;
        }
        if (obj->scroll == 0x29) {
            obj->unk270 = 0;
        } else {
            obj->unk270 = 1;
        }
    }
    if (obj->voice == 1 && obj->unk273 == 0) {
        switch (obj->voiceStep) {
        case 0:
            fn_800A7084(1, lbl_80263EE4[obj->voiceIdx], 0x18, 0, 0);
            obj->voiceStep++;
            break;
        case 1:
            fn_800A6D90();
            if (lbl_8037C3D8.unk0 == 0 && lbl_8037C3D8.unk5 == 0) {
                obj->voiceStep++;
            }
            break;
        case 2:
            obj->voiceStep = 0;
            obj->voice = 0;
            break;
        }
    }
    fn_800E8D30(lbl_804EE948, 0x100);
    fn_800E8FC4(lbl_804EE948, lbl_80301420.unk48);
    fn_800E69E8(lbl_80301420.unk48);
}

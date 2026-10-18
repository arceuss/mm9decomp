#include "types.h"

typedef struct Unk80301280 {
    /* 0x00 */ u32 unk0;
    /* 0x04 */ u8 pad4[0x40 - 0x4];
    /* 0x40 */ u32* unk40;
} Unk80301280;

typedef struct Unk8038B2F8Sub {
    /* 0x0000 */ u8 pad0[0x2500];
    /* 0x2500 */ u8 unk2500;
} Unk8038B2F8Sub;

typedef struct Unk8038B2F8 {
    /* 0x0000 */ u8 pad0[0x184];
    /* 0x0184 */ Unk8038B2F8Sub* unk184;
    /* 0x0188 */ u8 pad188[0x26BC - 0x188];
    /* 0x26BC */ s16 unk26BC;
} Unk8038B2F8;

typedef struct Unk8043CD28 {
    /* 0x000 */ u8 pad0[0x2E4];
    /* 0x2E4 */ u8 unk2E4;
    /* 0x2E5 */ u8 pad2E5[0x2E8 - 0x2E5];
} Unk8043CD28;

extern Unk80301280 lbl_80301280;
extern Unk8038B2F8 lbl_8038B2F8;
extern u8 lbl_80313E98[];
extern void* lbl_804EE984;
extern u8 lbl_803051D8[];
extern u32 lbl_804EE98C;
extern void* lbl_804EE990;
extern u8 lbl_80313118[];
extern u8 lbl_80312C58[];
extern u8 lbl_80312598[];
extern u8 lbl_80311C18[];
extern u8 lbl_803117F8[];
extern u8 lbl_8030FCF8[];
extern u8 lbl_8030E8B8[];
extern u8 lbl_8030C2B8[];
extern u8 lbl_8030A7B8[];
extern u8 lbl_80308CB8[];
extern u8 lbl_803140C0[];
extern Unk8043CD28 lbl_8043CD28;

void fn_800E6878(void);
void fn_8008334C(void* a);
void fn_800E695C(void* a);
void fn_800A7860(void);
void fn_800A78CC(void);
void fn_800E8CDC(void);
void fn_800AB70C(void* pool, void* buf, s32 n);
void fn_800BB9AC(void* pool, void* buf, s32 n);
void fn_800AB5A0(void* pool, void* buf, s32 n);
void fn_800C2D34(void* pool, void* buf, s32 n);
void fn_800241F8(void* pool, void* buf, s32 n);
void fn_8000EF50(void* pool, void* buf, s32 n);
void fn_80042DEC(void* pool, void* buf, s32 n);
void fn_800728B4(void* pool, void* buf, s32 n);
void fn_800408F8(void* pool, void* buf, s32 n);
void fn_800CA26C(void* pool, void* buf, s32 n);
void fn_8009C130(void* pool, void* buf, s32 n);
void fn_800AB904(void);
void* fn_800B709C(s32 a, void* b, s32 c, s32 d, s32 e);
void fn_8007D93C(void* a, void* b, void* c);
void fn_800A6888(void);
void fn_800C664C(void* a);
void fn_800C7CDC(void);
void fn_800E9FA0(u32 a, s32 b);
void fn_8008C07C(void* obj, s32 next);

void fn_80089A00(u8* obj) {
    u32 id = *(u32*)(obj + 0x2154);
    void* p;

    lbl_80301280.unk0 = ((lbl_80301280.unk0 | 0x40000000) & ~0x3F000000) | 0x18000000;
    fn_800E6878();
    lbl_8038B2F8.unk26BC = 0;
    lbl_8038B2F8.unk184->unk2500 = 0;
    *lbl_80301280.unk40 &= ~0xF00;
    lbl_804EE984 = lbl_80313E98;
    fn_8008334C(obj + 0x2244);
    lbl_803051D8[2] &= ~8;
    fn_800E695C(obj + 0xBC4);
    fn_800A7860();
    fn_800A78CC();
    fn_800E8CDC();
    lbl_804EE98C = *(u32*)(obj + 0x2278);
    lbl_804EE990 = obj + 0x2278;
    fn_800AB70C(obj + 0x10, lbl_80313E98, 1);
    fn_800BB9AC(obj + 0x3C, lbl_80313118, 0x10);
    fn_800AB5A0(obj + 0x68, lbl_80312C58, 8);
    fn_800C2D34(obj + 0x94, lbl_80312598, 8);
    fn_800241F8(obj + 0xC0, lbl_80311C18, 0x10);
    fn_8000EF50(obj + 0xEC, lbl_803117F8, 4);
    fn_80042DEC(obj + 0x118, lbl_8030FCF8, 0x20);
    fn_800728B4(obj + 0x144, lbl_8030E8B8, 0x18);
    fn_800408F8(obj + 0x170, lbl_8030C2B8, 0x40);
    fn_800CA26C(obj + 0x19C, lbl_8030A7B8, 0x20);
    fn_8009C130(obj + 0x1C8, lbl_80308CB8, 0x20);
    if (*(s8*)(obj + 0x21E1) != 2) {
        obj[0x21E1] = (lbl_803051D8[3] >> 5) & 1;
    }
    fn_800AB904();
    p = fn_800B709C(0, obj + 0x21E0, 0, 0, 0);
    lbl_804EE984 = p;
    *(void**)(lbl_803140C0 + 0x2290) = p;
    fn_8007D93C(obj + 0x221C, obj + 0xBC4, p);
    fn_800A6888();
    fn_800C664C(obj + 0x215C);
    fn_800C7CDC();
    fn_800E9FA0(id, 0);
    lbl_8043CD28.unk2E4 = 0;
    fn_8008C07C(obj, 0x900);
}

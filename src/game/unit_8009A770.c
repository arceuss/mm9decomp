#include "types.h"

typedef struct Unk8009A770Frame {
    /* 0x00 */ u8 layer;
    /* 0x01 */ u8 pad1;
    /* 0x02 */ u8 kind;
    /* 0x03 */ u8 pad3[0xB - 0x3];
    /* 0x0B */ u8 more;
    /* 0x0C */ u8 padC[0x18 - 0xC];
} Unk8009A770Frame;

typedef struct Unk8009A770 {
    /* 0x00 */ Unk8009A770Frame* frame;
    /* 0x04 */ u8 pad4[0x18 - 0x4];
    /* 0x18 */ u32 flags;
    /* 0x1C */ u8 pad1C[0x20 - 0x1C];
    /* 0x20 */ u8 invuln;
    /* 0x21 */ u8 pad21;
    /* 0x22 */ u8 unk22;
    /* 0x23 */ u8 hitHi : 4;
    /* 0x23 */ u8 hitType : 4;
    /* 0x24 */ u8 pad24[0x2E - 0x24];
    /* 0x2E */ s16 hp;
    /* 0x30 */ u8 pad30[0x3B - 0x30];
    /* 0x3B */ u8 dmgFlags;
} Unk8009A770;

typedef struct Unk80316398 {
    /* 0x000 */ u8 unk0;
    /* 0x001 */ u8 pad1[0x938 - 0x1];
} Unk80316398;

extern Unk80316398 lbl_80316398;

static inline Unk8009A770Frame* FindBody(Unk8009A770* obj) {
    Unk8009A770Frame* f = obj->frame;

    if (f == NULL) {
        return NULL;
    }
    for (;;) {
        if (f->layer == 1) {
            break;
        }
        if (f->more != 0) {
            f++;
        } else {
            f = NULL;
            break;
        }
    }
    return f;
}

u8 fn_8009A770(Unk8009A770* obj, u8 dmg, u8 type) {
    u8 flags = obj->dmgFlags;
    Unk8009A770Frame* body;

    if (lbl_80316398.unk0 & 0x80) {
        return 0;
    }
    body = FindBody(obj);
    if (body == NULL) {
        return 0;
    }
    if (obj->invuln != 0) {
        return 0;
    }
    if (flags & 0x40) {
        dmg = (dmg * 2) / 3;
    }
    if (flags & 2) {
        return dmg;
    }
    obj->hp -= dmg;
    obj->flags |= 0x10000001;
    obj->unk22 = 0;
    obj->hitHi = 0;
    obj->hitType = type;
    if (obj->hp <= 0) {
        obj->flags |= 0x200;
        obj->hp = 0;
    }
    if (body->kind == 1) {
        obj->invuln = 0x5A;
        if (flags & 0x10) {
            obj->invuln = 0x6A;
        }
    } else if (body->kind == 2) {
        obj->invuln = 0x14;
        if (flags & 0x10) {
            obj->invuln = 0x24;
        }
    }
    return dmg;
}

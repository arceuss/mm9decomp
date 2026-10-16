#include "types.h"

typedef struct Unk80027394Kv {
    /* 0x0 */ char* key;
    /* 0x4 */ char* value;
} Unk80027394Kv;

typedef struct Unk80027394Str {
    /* 0x0 */ u32 len;
    /* 0x4 */ char text[1];
} Unk80027394Str;

typedef u64 Unk80027394Id;

typedef struct Unk80027394Title {
    /* 0x00 */ Unk80027394Id id;
    /* 0x08 */ Unk80027394Kv* name;
    /* 0x0C */ u8 padC[0x10 - 0xC];
    /* 0x10 */ Unk80027394Str* desc;
    /* 0x14 */ s32 hasDesc;
    /* 0x18 */ Unk80027394Kv* kv;
    /* 0x1C */ u32 kvCount;
} Unk80027394Title;

typedef struct Unk80027394Block {
    /* 0x00 */ u8 pad0[0x8];
    /* 0x08 */ Unk80027394Kv* name;
    /* 0x0C */ u8 padC[0x10 - 0xC];
    /* 0x10 */ Unk80027394Str* desc;
    /* 0x14 */ s32 hasDesc;
    /* 0x18 */ Unk80027394Kv* kv;
    /* 0x1C */ u32 kvCount;
    /* 0x20 */ u8 pad20[0x30 - 0x20];
} Unk80027394Block;

typedef struct Unk80027394List {
    /* 0x00 */ u8 pad0[0x8];
    /* 0x08 */ Unk80027394Id* ids;
    /* 0x0C */ char** extraKeys;
} Unk80027394List;

typedef struct Unk80301320State {
    /* 0x00 */ u8 pad0[0x4];
    /* 0x04 */ Unk80027394List* list;
    /* 0x08 */ u8 pad8[0xC - 0x8];
    /* 0x0C */ u32 count;
    /* 0x10 */ u8 pad10[0x14 - 0x10];
    /* 0x14 */ u8 unk14;
    /* 0x15 */ u8 unk15;
    /* 0x16 */ u8 pad16;
    /* 0x17 */ u8 mode;
    /* 0x18 */ void* entries;
} Unk80301320State;

typedef struct Unk80301320 {
    /* 0x00 */ u8 pad0[0x5C];
    /* 0x5C */ Unk80301320State* state;
} Unk80301320;

extern Unk80301320 lbl_80301320;
extern char* lbl_80263B30[14];

s32 fn_8017530C(const char* a, const char* b);

char* fn_80027394(u32 key) {
    Unk80301320State* st = lbl_80301320.state;
    Unk80027394Kv* kv = NULL;
    u8 kvCount;
    char* name;
    s32 i;

    if (st->mode == 0) {
        u32 idx;
        u32 j;
        Unk80027394Title* t;
        Unk80027394Title* all;

        all = st->entries;
        t = all;

        for (j = 0; j < st->count; j++, t++) {
            idx = st->unk14;
            if (t->id == st->list->ids[idx]) {
                if (key == 7) {
                    if (all[idx].hasDesc != 0) {
                        return all[j].desc->text;
                    }
                    return NULL;
                }
                if (key == 8) {
                    return all[j].name->value;
                }
                kv = all[j].kv;
                kvCount = all[j].kvCount;
                break;
            }
        }
    } else {
        Unk80027394Block* b = st->entries;

        if (st->count == 0 || st->unk15 >= st->count) {
            return NULL;
        }
        if (key == 7) {
            if (b[st->unk15].hasDesc != 0) {
                return b[st->unk15].desc->text;
            }
            return NULL;
        }
        if (key == 8) {
            return b[st->unk15].name->value;
        }
        kv = b[st->unk15].kv;
        kvCount = b[st->unk15].kvCount;
    }
    if (kv == NULL) {
        return NULL;
    }
    if (key <= 0xD) {
        name = lbl_80263B30[(u8)key];
    } else {
        name = st->list->extraKeys[key - 0xE];
    }
    if (name == NULL) {
        return NULL;
    }
    for (i = 0; i < kvCount; i++) {
        if (fn_8017530C(kv[i].key, name) == 0) {
            return kv[i].value;
        }
    }
    return NULL;
}

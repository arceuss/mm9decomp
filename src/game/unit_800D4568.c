#include "types.h"

void fn_8019A230(void* self);
void dtor_8018223C(void* p);

// compiler-generated deleting destructor shape: run the base dtor, free if asked
void* fn_800D4568(void* self, s32 flags) {
    if (self != NULL) {
        fn_8019A230(self);
        if (flags > 0) {
            dtor_8018223C(self);
        }
    }
    return self;
}

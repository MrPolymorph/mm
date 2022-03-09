#ifndef Z_OBJ_TOKEI_TURRET_H
#define Z_OBJ_TOKEI_TURRET_H

#include "global.h"

struct ObjTokeiTurret;

typedef struct ObjTokeiTurret {
    /* 0x000 */ DynaPolyActor dyna;
    /* 0x15C */ UNK_TYPE1 unk_15C[0x4];
} ObjTokeiTurret; // size = 0x160

extern const ActorInit Obj_Tokei_Turret_InitVars;

#endif // Z_OBJ_TOKEI_TURRET_H

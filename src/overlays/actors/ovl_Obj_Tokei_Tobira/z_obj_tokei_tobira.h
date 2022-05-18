#ifndef Z_OBJ_TOKEI_TOBIRA_H
#define Z_OBJ_TOKEI_TOBIRA_H

#include "global.h"

struct ObjTokeiTobira;

typedef void (*ObjTokeiTobiraActionFunc)(struct ObjTokeiTobira*, GlobalContext*);

typedef struct ObjTokeiTobira {
    /* 0x0000 */ DynaPolyActor dyna;
    /* 0x015C */ ObjTokeiTobiraActionFunc actionFunc;
    /* 0x0160 */ char unk_160[0x10];
} ObjTokeiTobira; // size = 0x170

extern const ActorInit Obj_Tokei_Tobira_InitVars;

#define PARAMS(thisx) ((thisx)->params & 3)

#endif // Z_OBJ_TOKEI_TOBIRA_H

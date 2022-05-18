/*
 * File: z_obj_tokei_tobira.c
 * Overlay: ovl_Obj_Tokei_Tobira
 * Description: Clock Tower - Swinging Doors
 */

#include "z_obj_tokei_tobira.h"
#include "objects/object_tokei_tobira/object_tokei_tobira.h"
#define FLAGS 0x00000000

#define THIS ((ObjTokeiTobira*)thisx)

void ObjTokeiTobira_Init(Actor* thisx, GlobalContext* globalCtx);
void ObjTokeiTobira_Destroy(Actor* thisx, GlobalContext* globalCtx);
void ObjTokeiTobira_Update(Actor* thisx, GlobalContext* globalCtx);
void ObjTokeiTobira_Draw(Actor* thisx, GlobalContext* globalCtx);
void func_80ABD3B0(ObjTokeiTobira* thisx, GlobalContext* globalCtx);


const ActorInit Obj_Tokei_Tobira_InitVars = {
    ACTOR_OBJ_TOKEI_TOBIRA,
    ACTORCAT_BG,
    FLAGS,
    OBJECT_TOKEI_TOBIRA,
    sizeof(ObjTokeiTobira),
    (ActorFunc)ObjTokeiTobira_Init,
    (ActorFunc)ObjTokeiTobira_Destroy,
    (ActorFunc)ObjTokeiTobira_Update,
    (ActorFunc)ObjTokeiTobira_Draw,
};

static InitChainEntry D_80ABD750[] = {
    ICHAIN_F32(uncullZoneForward, 4000, ICHAIN_CONTINUE),
    ICHAIN_F32(uncullZoneScale, 300, ICHAIN_CONTINUE),
    ICHAIN_F32(uncullZoneDownward, 300, ICHAIN_CONTINUE),
    ICHAIN_VEC3F_DIV1000(scale, 100, ICHAIN_STOP),
};

extern CollisionHeader *D_80ABD770[];
extern s16 D_80ABD76C;
extern Vec3f D_80ABD760;
extern Gfx *D_80ABD780[];

void ObjTokeiTobira_Init(Actor* thisx, GlobalContext* globalCtx) {
    ObjTokeiTobira* this = THIS;
    s16* sp44;
    s32 params;
    Vec3f sp48;

    params = this->dyna.actor.params & 1;

    Actor_ProcessInitChain(&this->dyna.actor, D_80ABD750);
    DynaPolyActor_Init(&this->dyna, 3);
    DynaPolyActor_LoadMesh(globalCtx, &this->dyna, D_80ABD770[params]);
    if (params == 0) {
        Actor_SpawnAsChild(&globalCtx->actorCtx, &this->dyna.actor, globalCtx, ACTOR_OBJ_TOKEI_TOBIRA, this->dyna.actor.world.pos.x,
                           this->dyna.actor.world.pos.y, this->dyna.actor.world.pos.z, this->dyna.actor.shape.rot.x, this->dyna.actor.shape.rot.y,
                           this->dyna.actor.shape.rot.z,1);
    }
    sp44 = (s32)((params * 1) + &D_80ABD76C);
    Matrix_RotateY(this->dyna.actor.shape.rot.y + *sp44, 0);
    Matrix_MultiplyVector3fByState(&D_80ABD760, &sp48);
    this->dyna.actor.world.pos.x += sp48.x;
    this->dyna.actor.world.pos.y += sp48.y;
    this->dyna.actor.world.pos.z += sp48.z;
    if (sp44 == &D_80ABD76C && (gSaveContext.save.weekEventReg[59] & 4) == 0 && globalCtx->sceneNum == SCENE_CLOCKTOWER && gSaveContext.sceneSetupIndex == 0 && this->dyna.actor.cutscene >= 0) {
        this->actionFunc = func_80ABD3B0;
        this->dyna.actor.flags |= 0x10;
    }
}

void ObjTokeiTobira_Destroy(Actor* thisx, GlobalContext* globalCtx) {
    ObjTokeiTobira* this = (ObjTokeiTobira* ) thisx;
    DynaPoly_DeleteBgActor(globalCtx, &globalCtx->colCtx.dyna, this->dyna.bgId);
}

void func_80ABD3B0(ObjTokeiTobira* this, GlobalContext* globalCtx) {
    s16 cutscene;

    cutscene = this->dyna.actor.cutscene;

    if (ActorCutscene_GetCanPlayNext(cutscene) != 0) {
        ActorCutscene_StartAndSetUnkLinkFields(this->dyna.actor.cutscene, &this->dyna.actor);
        gSaveContext.save.weekEventReg[0x3B] |= 4;
        this->actionFunc = 0;
        this->dyna.actor.flags &= -0x11;
        return;
    }
    ActorCutscene_SetIntentToPlay(this->dyna.actor.cutscene);
}

#pragma GLOBAL_ASM("asm/non_matchings/overlays/ovl_Obj_Tokei_Tobira/ObjTokeiTobira_Update.s")

void ObjTokeiTobira_Draw(Actor* thisx, GlobalContext* globalCtx) {
    ObjTokeiTobira* this = (ObjTokeiTobira* ) thisx;
    Gfx_DrawDListOpa(globalCtx, D_80ABD780[PARAMS(thisx)]);
}

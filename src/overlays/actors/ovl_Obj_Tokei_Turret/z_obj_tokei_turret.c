/*
 * File: z_obj_tokei_turret.c
 * Overlay: ovl_Obj_Tokei_Turret
 * Description: South Clock Town - Flags & Carnival Platform
 */

#include "z_obj_tokei_turret.h"
#include "objects/object_tokei_turret/object_tokei_turret.h"

#define FLAGS 0x00000000

#define THIS ((ObjTokeiTurret*)thisx)

void ObjTokeiTurret_Init(Actor* thisx, GlobalContext* globalCtx);
void ObjTokeiTurret_Destroy(Actor* thisx, GlobalContext* globalCtx);
void ObjTokeiTurret_Update(Actor* thisx, GlobalContext* globalCtx);
void ObjTokeiTurret_Draw(Actor* thisx, GlobalContext* globalCtx);

const ActorInit Obj_Tokei_Turret_InitVars = {
    ACTOR_OBJ_TOKEI_TURRET,
    ACTORCAT_BG,
    FLAGS,
    OBJECT_TOKEI_TURRET,
    sizeof(ObjTokeiTurret),
    (ActorFunc)ObjTokeiTurret_Init,
    (ActorFunc)ObjTokeiTurret_Destroy,
    (ActorFunc)ObjTokeiTurret_Update,
    (ActorFunc)ObjTokeiTurret_Draw,
};

static InitChainEntry D_80B91EC0[] = {
    ICHAIN_F32(uncullZoneForward, 1200, ICHAIN_CONTINUE),
    ICHAIN_VEC3F_DIV1000(scale, 100, ICHAIN_STOP),
};

extern UNK_TYPE D_de00;

void ObjTokeiTurret_Init(Actor *thisx, GlobalContext *globalCtx)
{
    ObjTokeiTurret *this = THIS;
    ObjTokeiTurret *temp_a3;
    s32 temp_v0;

    temp_a3 = this;
    temp_v0 = temp_a3->dyna.actor.params & 3;

    this = temp_a3;

    Actor_ProcessInitChain(&this->dyna.actor, D_80B91EC0);
    DynaPolyActor_Init((DynaPolyActor *) this, 0);

    if ((temp_v0 == 0) || (temp_v0 == 1))
    {
        this->dyna.actor.uncullZoneScale = 240.0f;
        this->dyna.actor.uncullZoneDownward = 240.0f;

        if (temp_v0 == 0)
        {
            DynaPolyActor_LoadMesh(globalCtx, &this->dyna, &object_tokei_turret_Colheader_0026A0);
            return;
        }
        DynaPolyActor_LoadMesh(globalCtx, &this->dyna, &object_tokei_turret_Colheader_002D80);
        return;
    }
    this->dyna.actor.uncullZoneScale = 1300.0f;
    this->dyna.actor.uncullZoneDownward = 1300.0f;
}

void ObjTokeiTurret_Destroy(Actor *thisx, GlobalContext *globalCtx)
{
    ObjTokeiTurret *this = THIS;
    DynaPoly_DeleteBgActor(globalCtx, &globalCtx->colCtx.dyna, this->dyna.bgId);
}

void ObjTokeiTurret_Update(Actor *thisx, GlobalContext *globalCtx) {
    ObjTokeiTurret *this = THIS;
}

void ObjTokeiTurret_Draw(Actor *thisx, GlobalContext *globalCtx)
{
    ObjTokeiTurret *this = THIS;
    Gfx *temp_v1;
    Gfx *temp_v1_2;
    Gfx *temp_v1_3;
    GraphicsContext * gfxCtx;
    s32 temp_v0;
    s32 temptemp;

    temp_v0 = this->dyna.actor.params & 3;

    if (temp_v0 == 1)
    {
        gfxCtx = globalCtx->state.gfxCtx;
        temp_v1 = gfxCtx->polyOpa.p;
        temptemp = sSetupDL;
        temp_v1->words.w0 = 0xDE000000;
        temp_v1->words.w1 = (sSetupDL + 0x4B0);

        temp_v1_2 = temp_v1 + 8;
        temp_v1_2->words.w0 = 0xDA380003;

        temp_v1_3 = temp_v1_2 + 8;

        temp_v1_2->words.w1 = Matrix_NewMtx(globalCtx->state.gfxCtx);

        temp_v1_3->words.w0 = 0xDE000000;
        temp_v1_3->words.w1 = (u32) &object_tokei_turret_DL_002A88;

        gfxCtx->polyOpa.p = temp_v1_3 + 8;
        return;
    }
    if (temp_v0 == 0)
    {
        Gfx_DrawDListOpa(globalCtx, object_tokei_turret_DL_002508);
        return;
    }

    Gfx_DrawDListOpa(globalCtx, object_tokei_turret_DL_003038);
}



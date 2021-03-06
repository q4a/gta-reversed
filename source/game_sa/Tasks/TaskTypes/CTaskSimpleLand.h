#pragma once
#include "CTaskSimple.h"

class CTaskSimpleLand : public CTaskSimple
{
    CAnimBlendAssociation* m_pAnim;
    eAnimID m_nAnimId;
    union {
        struct
        {
            unsigned char bIsFinished : 1;
            unsigned char bNoAnimation : 1;
            unsigned char bPedNotUpdated : 1;
        };
        unsigned char m_nFlags;
    };
    unsigned char _pad_11[3];

private:
    CTaskSimpleLand* Constructor(eAnimID nAnimId);
public:
    CTaskSimpleLand(eAnimID nAnimId);
    ~CTaskSimpleLand() override;

    static void InjectHooks();

    eTaskType GetId() override { return TASK_SIMPLE_LAND; }
    CTask* Clone() override { return new CTaskSimpleLand(m_nAnimId); }
    bool ProcessPed(CPed* ped) override;
    bool MakeAbortable(CPed* ped, eAbortPriority priority, CEvent* _event) override;

    bool ProcessPed_Reversed(CPed* ped);
    bool MakeAbortable_Reversed(CPed* ped, eAbortPriority priority, CEvent* _event);

    bool LeftFootLanded();
    bool RightFootLanded();

    static void FinishAnimCB(CAnimBlendAssociation* pAnim, void* data);

};

VALIDATE_SIZE(CTaskSimpleLand, 0x14);

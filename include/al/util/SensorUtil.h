#pragma once

#include "al/sensor/HitSensor.h"
#include "al/sensor/HitSensorKeeper.h"
#include "al/sensor/SensorHitGroup.h"

#include "al/LiveActor/LiveActor.h" // for SensorMsg

#include <sead/math/seadVector.h>

struct SaveObjInfo;
struct HackEndParam;
struct IUsePlayerCollision;
struct IUsePlayerHack;

struct DigPoint;
struct TouchTargetInfo;
struct WhipTargetInfo;
struct CapTargetInfo;
struct GotogotonMark;
struct FishingFish;

typedef unsigned int uint;

namespace al
{

    struct ComboCounter;
    struct EventFlowExecutor;
    struct ParabolicPath;

    sead::Vector3f &getSensorPos(al::HitSensor const *);
    float getSensorRadius(al::HitSensor const*);
    sead::Vector3f* getActorTrans(al::HitSensor const*);

    void setSensorRadius(al::LiveActor *, const char *, float);

    void invalidateHitSensor(al::LiveActor *, const char *);
    void validateHitSensor(al::LiveActor *, const char *);

    bool tryReceiveMsgPushAndAddVelocity(al::LiveActor*, al::SensorMsg const*, al::HitSensor const*,
                                         al::HitSensor const*, float);

    bool isSensorTypeYoshiEnableSendPush(al::HitSensor const*);
    bool isSensorTypeYoshiMsgReceivable(al::HitSensor const*);
    bool isSensorValid(al::HitSensor const*);
    bool isSensorName(al::HitSensor const*, char const*);
    bool isSensorHostName(al::HitSensor const*, char const*);
    bool isSensorHost(al::HitSensor const*, al::LiveActor const*);
    bool isSensorValid(al::LiveActor const*, char const*);
    bool isSensorBindableAll(al::HitSensor const*);
    bool isSensorEnemy(al::HitSensor const*);
    bool isSensorEnemyAttack(al::HitSensor const*);
    bool isSensorEnemyBody(al::HitSensor const*);
    bool isSensorEye(al::HitSensor const*);
    bool isSensorMapObj(al::HitSensor const*);
    bool isSensorNpc(al::HitSensor const*);
    bool isSensorPlayerAll(al::HitSensor const*);
    bool isSensorRide(al::HitSensor const*);
    bool isSensorPlayerAttack(al::HitSensor const*);
    bool isSensorPlayer(al::HitSensor const*);
    bool isSensorPlayerFoot(al::HitSensor const*);
    bool isSensorPlayerDecoration(al::HitSensor const*);
    bool isSensorPlayerEye(al::HitSensor const*);
    bool isSensorPlayerOrPlayerWeapon(al::HitSensor const*);
    bool isSensorCollision(al::HitSensor const*);
    bool isSensorPlayerFireBall(al::HitSensor const*);
    bool isSensorHoldObj(al::HitSensor const*);
    bool isSensorLookAt(al::HitSensor const*);
    bool isSensorBindableGoal(al::HitSensor const*);
    bool isSensorBindableAllPlayer(al::HitSensor const*);
    bool isSensorBindableBubbleOutScreen(al::HitSensor const*);
    bool isSensorBindableKoura(al::HitSensor const*);
    bool isSensorBindableRouteDokan(al::HitSensor const*);
    bool isSensorBindableBubblePadInput(al::HitSensor const*);
    bool isSensorBindable(al::HitSensor const*);
    bool isSensorSimple(al::HitSensor const*);
    bool isSensorHitAnyPlane(al::HitSensor const*,al::HitSensor const*, sead::Vector3<float> const&);
    bool isSensorHitRingShape(al::HitSensor const*, al::HitSensor const*, float);

    bool isMsgRequestPlayerStainWet(al::SensorMsg const *, int *);
    bool isMsgPushAll(al::SensorMsg const *);
    bool isMsgPush(al::SensorMsg const *);
    bool isMsgPushStrong(al::SensorMsg const *);
    bool isMsgPushVeryStrong(al::SensorMsg const *);
    bool isMsgHoldReleaseAll(al::SensorMsg const *);
    bool isMsgHoldCancel(al::SensorMsg const *);
    bool isMsgPlayerRelease(al::SensorMsg const *);
    bool isMsgPlayerReleaseBySwing(al::SensorMsg const *);
    bool isMsgPlayerReleaseDead(al::SensorMsg const *);
    bool isMsgPlayerReleaseDamage(al::SensorMsg const *);
    bool isMsgPlayerReleaseDemo(al::SensorMsg const *);
    bool isMsgItemGetDirectAll(al::SensorMsg const *);
    bool isMsgPlayerItemGet(al::SensorMsg const *);
    bool isMsgRideAllPlayerItemGet(al::SensorMsg const *);
    bool isMsgPlayerTailAttack(al::SensorMsg const *);
    bool isMsgItemGetByObjAll(al::SensorMsg const *);
    bool isMsgBallItemGet(al::SensorMsg const *);
    bool isMsgKickKouraItemGet(al::SensorMsg const *);
    bool isMsgKillerItemGet(al::SensorMsg const *);
    bool isMsgItemGetAll(al::SensorMsg const *);
    bool isMsgFloorTouch(al::SensorMsg const *);
    bool isMsgPlayerFloorTouch(al::SensorMsg const *);
    bool isMsgEnemyFloorTouch(al::SensorMsg const *);
    bool isMsgUpperPunch(al::SensorMsg const *);
    bool isMsgPlayerUpperPunch(al::SensorMsg const *);
    bool isMsgEnemyUpperPunch(al::SensorMsg const *);
    bool isMsgPlayerTrample(al::SensorMsg const *);
    bool isMsgPlayerTrampleReflect(al::SensorMsg const *);
    bool isMsgPlayerHipDropAll(al::SensorMsg const *);
    bool isMsgPlayerStatueDrop(al::SensorMsg const *);
    bool isMsgPlayerObjHipDropAll(al::SensorMsg const *);
    bool isMsgPlayerObjStatueDrop(al::SensorMsg const *);
    bool isMsgPlayerObjHipDropReflectAll(al::SensorMsg const *);
    bool isMsgPlayerObjStatueDropReflect(al::SensorMsg const *);
    bool isMsgPlayerObjHipDropHighJump(al::SensorMsg const *);
    bool isMsgPlayerHipDropKnockDown(al::SensorMsg const *);
    bool isMsgPlayerObjStatueDropReflectNoCondition(al::SensorMsg const *);
    bool isMsgPlayerStatueTouch(al::SensorMsg const *);
    bool isMsgPlayerObjUpperPunch(al::SensorMsg const *);
    bool isMsgPlayerRollingAttack(al::SensorMsg const *);
    bool isMsgPlayerRollingReflect(al::SensorMsg const *);
    bool isMsgPlayerObjRollingAttack(al::SensorMsg const *);
    bool isMsgPlayerObjRollingAttackFailure(al::SensorMsg const *);
    bool isMsgPlayerInvincibleAttack(al::SensorMsg const *);
    bool isMsgPlayerFireBallAttack(al::SensorMsg const *);
    bool isMsgPlayerRouteDokanFireBallAttack(al::SensorMsg const *);
    bool isMsgPlayerKick(al::SensorMsg const *);
    bool isMsgPlayerCatch(al::SensorMsg const *);
    bool isMsgPlayerSlidingAttack(al::SensorMsg const *);
    bool isMsgPlayerBoomerangAttack(al::SensorMsg const *);
    bool isMsgPlayerBoomerangAttackCollide(al::SensorMsg const *);
    bool isMsgPlayerBoomerangReflect(al::SensorMsg const *);
    bool isMsgPlayerBoomerangBreak(al::SensorMsg const *);
    bool isMsgPlayerBodyAttack(al::SensorMsg const *);
    bool isMsgPlayerBodyLanding(al::SensorMsg const *);
    bool isMsgPlayerBodyAttackReflect(al::SensorMsg const *);
    bool isMsgPlayerClimbAttack(al::SensorMsg const *);
    bool isMsgPlayerSpinAttack(al::SensorMsg const *);
    bool isMsgPlayerGiantAttack(al::SensorMsg const *);
    bool isMsgPlayerCooperationHipDrop(al::SensorMsg const *);
    bool isMsgPlayerClimbSlidingAttack(al::SensorMsg const *);
    bool isMsgPlayerClimbRollingAttack(al::SensorMsg const *);
    bool isMsgPlayerGiantHipDrop(al::SensorMsg const *);
    bool isMsgPlayerDisregard(al::SensorMsg const *);
    bool isMsgPlayerDash(al::SensorMsg const *);
    bool isMsgPlayerDamageTouch(al::SensorMsg const *);
    bool isMsgPlayerFloorTouchBind(al::SensorMsg const *);
    bool isMsgPlayerTouch(al::SensorMsg const *);
    bool isMsgPlayerInvincibleTouch(al::SensorMsg const *);
    bool isMsgPlayerGiantTouch(al::SensorMsg const *);
    bool isMsgPlayerObjTouch(al::SensorMsg const *);
    bool isMsgPlayerPutOnEquipment(al::SensorMsg const *);
    bool isMsgPlayerReleaseEquipment(al::SensorMsg const *);
    bool isMsgPlayerReleaseEquipmentGoal(al::SensorMsg const *);
    bool isMsgPlayerCarryFront(al::SensorMsg const *);
    bool isMsgPlayerCarryFrontWallKeep(al::SensorMsg const *);
    bool isMsgPlayerCarryUp(al::SensorMsg const *);
    bool isMsgPlayerCarryKeepDemo(al::SensorMsg const *);
    bool isMsgPlayerCarryWarp(al::SensorMsg const *);
    bool isMsgPlayerLeave(al::SensorMsg const *);
    bool isMsgPlayerToss(al::SensorMsg const *);
    bool isMsgEnemyAttack(al::SensorMsg const *);
    bool isMsgEnemyAttackFire(al::SensorMsg const *);
    bool isMsgEnemyAttackKnockDown(al::SensorMsg const *);
    bool isMsgEnemyAttackBoomerang(al::SensorMsg const *);
    bool isMsgEnemyAttackNeedle(al::SensorMsg const *);
    bool isMsgEnemyItemGet(al::SensorMsg const *);
    bool isMsgEnemyRouteDokanAttack(al::SensorMsg const *);
    bool isMsgEnemyRouteDokanFire(al::SensorMsg const *);
    bool isMsgExplosion(al::SensorMsg const *);
    bool isMsgExplosionCollide(al::SensorMsg const *);
    bool isMsgBindStart(al::SensorMsg const *);
    bool isMsgBindInit(al::SensorMsg const *);
    bool isMsgBindEnd(al::SensorMsg const *);
    bool isMsgBindCancel(al::SensorMsg const *);
    bool isMsgBindCancelByDemo(al::SensorMsg const *);
    bool isMsgBindDamage(al::SensorMsg const *);
    bool isMsgBindSteal(al::SensorMsg const *);
    bool isMsgBindGiant(al::SensorMsg const *);
    bool isMsgPressureDeath(al::SensorMsg const *);
    bool isMsgNpcTouch(al::SensorMsg const *);
    bool isMsgHit(al::SensorMsg const *);
    bool isMsgHitStrong(al::SensorMsg const *);
    bool isMsgHitVeryStrong(al::SensorMsg const *);
    bool isMsgKnockDown(al::SensorMsg const *);
    bool isMsgMapPush(al::SensorMsg const *);
    bool isMsgVanish(al::SensorMsg const *);
    bool isMsgChangeAlpha(al::SensorMsg const *);
    bool isMsgShowModel(al::SensorMsg const *);
    bool isMsgHideModel(al::SensorMsg const *);
    bool isMsgRestart(al::SensorMsg const *);
    bool isMsgEnemyTouch(al::SensorMsg const *);
    bool isMsgEnemyTrample(al::SensorMsg const *);
    bool isMsgMapObjTrample(al::SensorMsg const *);
    bool isMsgNeedleBallAttack(al::SensorMsg const *);
    bool isMsgPunpunFloorTouch(al::SensorMsg const *);
    bool isMsgInvalidateFootPrint(al::SensorMsg const *);
    bool isMsgKickKouraAttack(al::SensorMsg const *);
    bool isMsgKickKouraAttackCollide(al::SensorMsg const *);
    bool isMsgKickKouraReflect(al::SensorMsg const *);
    bool isMsgKickKouraCollideNoReflect(al::SensorMsg const *);
    bool isMsgKickKouraBreak(al::SensorMsg const *);
    bool isMsgKickKouraBlow(al::SensorMsg const *);
    bool isMsgKickStoneAttack(al::SensorMsg const *);
    bool isMsgKickStoneAttackCollide(al::SensorMsg const *);
    bool isMsgKickStoneAttackHold(al::SensorMsg const *);
    bool isMsgKickStoneAttackReflect(al::SensorMsg const *);
    bool isMsgKickStoneTrample(al::SensorMsg const *);
    bool isMsgKillerAttack(al::SensorMsg const *);
    bool isMsgLiftGeyser(al::SensorMsg const *);
    bool isMsgWarpStart(al::SensorMsg const *);
    bool isMsgWarpEnd(al::SensorMsg const *);
    bool isMsgHoleIn(al::SensorMsg const *);
    bool isMsgJumpInhibit(al::SensorMsg const *);
    bool isMsgGoalKill(al::SensorMsg const *);
    bool isMsgGoal(al::SensorMsg const *);
    bool isMsgBallAttack(al::SensorMsg const *);
    bool isMsgBallRouteDokanAttack(al::SensorMsg const *);
    bool isMsgBallAttackHold(al::SensorMsg const *);
    bool isMsgBallAttackDRCHold(al::SensorMsg const *);
    bool isMsgBallAttackCollide(al::SensorMsg const *);
    bool isMsgBallTrample(al::SensorMsg const *);
    bool isMsgBallTrampleCollide(al::SensorMsg const *);
    bool isMsgFireBallCollide(al::SensorMsg const *);
    bool isMsgFireBallFloorTouch(al::SensorMsg const *);
    bool isMsgDokanBazookaAttack(al::SensorMsg const *);
    bool isMsgSwitchOn(al::SensorMsg const *);
    bool isMsgSwitchOnInit(al::SensorMsg const *);
    bool isMsgSwitchOffInit(al::SensorMsg const *);
    bool isMsgSwitchKillOn(al::SensorMsg const *);
    bool isMsgSwitchKillOnInit(al::SensorMsg const *);
    bool isMsgSwitchKillOffInit(al::SensorMsg const *);
    bool isMsgAskSafetyPoint(al::SensorMsg const *);
    bool isMsgTouchAssist(al::SensorMsg const *);
    bool isMsgTouchAssistNoPat(al::SensorMsg const *);
    bool isMsgTouchAssistTrig(al::SensorMsg const *);
    bool isMsgTouchAssistTrigOff(al::SensorMsg const *);
    bool isMsgTouchAssistTrigNoPat(al::SensorMsg const *);
    bool isMsgTouchAssistBurn(al::SensorMsg const *);
    bool isMsgTouchAssistAll(al::SensorMsg const *);
    bool isMsgTouchCarryItem(al::SensorMsg const *);
    bool isMsgTouchReleaseItem(al::SensorMsg const *);
    bool isMsgTouchStroke(al::SensorMsg const *);
    bool isMsgIsNerveSupportFreeze(al::SensorMsg const *);
    bool isMsgOnSyncSupportFreeze(al::SensorMsg const *);
    bool isMsgOffSyncSupportFreeze(al::SensorMsg const *);
    bool isMsgScreenPointInvalidCollisionParts(al::SensorMsg const *);
    bool isMsgBlockUpperPunch(al::SensorMsg const *);
    bool isMsgBlockLowerPunch(al::SensorMsg const *);
    bool isMsgBlockItemGet(al::SensorMsg const *);
    bool isMsgPlayerKouraAttack(al::SensorMsg const *);
    bool isMsgLightFlash(al::SensorMsg const *);
    bool isMsgForceAbyss(al::SensorMsg const *);
    bool isMsgSwordAttackHigh(al::SensorMsg const *);
    bool isMsgSwordAttackHighLeft(al::SensorMsg const *);
    bool isMsgSwordAttackHighRight(al::SensorMsg const *);
    bool isMsgSwordAttackLow(al::SensorMsg const *);
    bool isMsgSwordAttackLowLeft(al::SensorMsg const *);
    bool isMsgSwordAttackLowRight(al::SensorMsg const *);
    bool isMsgSwordBeamAttack(al::SensorMsg const *);
    bool isMsgSwordBeamReflectAttack(al::SensorMsg const *);
    bool isMsgSwordAttackJumpUnder(al::SensorMsg const *);
    bool isMsgShieldGuard(al::SensorMsg const *);
    bool isMsgAskMultiPlayerEnemy(al::SensorMsg const *);
    bool isMsgItemGettable(al::SensorMsg const *);
    bool isMsgKikkiThrow(al::SensorMsg const *);
    bool isMsgIsKikkiThrowTarget(al::SensorMsg const *);
    bool isMsgPlayerCloudGet(al::SensorMsg const *);
    bool isMsgAutoJump(al::SensorMsg const *);
    bool isMsgPlayerTouchShadow(al::SensorMsg const *);
    bool isMsgPlayerPullOutShadow(al::SensorMsg const *);
    bool isMsgPlayerAttackShadow(al::SensorMsg const *);
    bool isMsgPlayerAttackShadowStrong(al::SensorMsg const *);
    bool isMsgPlayerAttackChangePos(al::SensorMsg const *);
    bool isMsgAtmosOnlineLight(al::SensorMsg const *);
    bool isMsgLightBurn(al::SensorMsg const *);
    bool isMsgMoonLightBurn(al::SensorMsg const *);
    bool isMsgString(al::SensorMsg const *);
    bool isMsgStringV4fPtr(al::SensorMsg const *);
    bool isMsgStringV4fSensorPtr(al::SensorMsg const *);
    bool isMsgStringVoidPtr(al::SensorMsg const *);
    bool isMsgPlayerTrampleForCrossoverSensor(al::SensorMsg const *, al::HitSensor const *, al::HitSensor const *);
    bool isMsgPlayerTrampleReflectForCrossoverSensor(al::SensorMsg const *, al::HitSensor const *, al::HitSensor const *);
    bool isMsgPlayerUpperPunchForCrossoverSensor(al::SensorMsg const *, al::HitSensor const *, al::HitSensor const *, float);
    bool isMsgKickStoneTrampleForCrossoverSensor(al::SensorMsg const *, al::HitSensor const *, al::HitSensor const *);

    bool sendMsgPlayerAttackTrample(al::HitSensor *, al::HitSensor *, al::ComboCounter *);
    bool sendMsgPlayerTrampleReflect(al::HitSensor *, al::HitSensor *, al::ComboCounter *);
    bool sendMsgPlayerReflectOrTrample(al::HitSensor *, al::HitSensor *, al::ComboCounter *);
    bool sendMsgPlayerHipDrop(al::HitSensor *, al::HitSensor *, al::ComboCounter *);
    bool sendMsgPlayerObjHipDrop(al::HitSensor *, al::HitSensor *, al::ComboCounter *);
    bool sendMsgPlayerObjHipDropReflect(al::HitSensor *, al::HitSensor *, al::ComboCounter *);
    bool sendMsgPlayerObjHipDropHighJump(al::HitSensor *, al::HitSensor *, al::ComboCounter *);
    bool sendMsgPlayerHipDropKnockDown(al::HitSensor *, al::HitSensor *);
    bool sendMsgPlayerStatueDrop(al::HitSensor *, al::HitSensor *, al::ComboCounter *);
    bool sendMsgPlayerObjStatueDrop(al::HitSensor *, al::HitSensor *, al::ComboCounter *);
    bool sendMsgPlayerObjStatueDropReflect(al::HitSensor *, al::HitSensor *, al::ComboCounter *);
    bool sendMsgPlayerObjStatueDropReflectNoCondition(al::HitSensor *, al::HitSensor *);
    bool sendMsgPlayerStatueTouch(al::HitSensor *, al::HitSensor *);
    bool sendMsgPlayerUpperPunch(al::HitSensor *, al::HitSensor *);
    bool sendMsgPlayerObjUpperPunch(al::HitSensor *, al::HitSensor *);
    bool sendMsgPlayerRollingAttack(al::HitSensor *, al::HitSensor *);
    bool sendMsgPlayerRollingReflect(al::HitSensor *, al::HitSensor *);
    bool sendMsgPlayerObjRollingAttack(al::HitSensor *, al::HitSensor *);
    bool sendMsgPlayerObjRollingAttackFailure(al::HitSensor *, al::HitSensor *);
    bool sendMsgPlayerInvincibleAttack(al::HitSensor *, al::HitSensor *, al::ComboCounter *);
    bool sendMsgPlayerFireBallAttack(al::HitSensor *, al::HitSensor *);
    bool sendMsgPlayerRouteDokanFireBallAttack(al::HitSensor *, al::HitSensor *);
    bool sendMsgPlayerTailAttack(al::HitSensor *, al::HitSensor *, al::ComboCounter *);
    bool sendMsgPlayerTouch(al::HitSensor *, al::HitSensor *);
    bool sendMsgPlayerKick(al::HitSensor *, al::HitSensor *);
    bool sendMsgPlayerCatch(al::HitSensor *, al::HitSensor *);
    bool sendMsgPlayerSlidingAttack(al::HitSensor *, al::HitSensor *, al::ComboCounter *);
    bool sendMsgPlayerBoomerangAttack(al::HitSensor *, al::HitSensor *, al::ComboCounter *);
    bool sendMsgPlayerBoomerangAttackCollide(al::HitSensor *, al::HitSensor *);
    bool sendMsgPlayerBoomerangReflect(al::HitSensor *, al::HitSensor *);
    bool sendMsgPlayerBoomerangBreak(al::HitSensor *, al::HitSensor *);
    bool sendMsgPlayerBodyAttack(al::HitSensor *, al::HitSensor *, al::ComboCounter *);
    bool sendMsgPlayerBodyLanding(al::HitSensor *, al::HitSensor *, al::ComboCounter *);
    bool sendMsgPlayerBodyAttackReflect(al::HitSensor *, al::HitSensor *, al::ComboCounter *);
    bool sendMsgPlayerClimbAttack(al::HitSensor *, al::HitSensor *, al::ComboCounter *);
    bool sendMsgPlayerSpinAttack(al::HitSensor *, al::HitSensor *, al::ComboCounter *);
    bool sendMsgPlayerGiantAttack(al::HitSensor *, al::HitSensor *, al::ComboCounter *);
    bool sendMsgPlayerCooperationHipDrop(al::HitSensor *, al::HitSensor *, al::ComboCounter *);
    bool sendMsgPlayerClimbSlidingAttack(al::HitSensor *, al::HitSensor *, al::ComboCounter *);
    bool sendMsgPlayerClimbRollingAttack(al::HitSensor *, al::HitSensor *, al::ComboCounter *);
    bool sendMsgPlayerGiantHipDrop(al::HitSensor *, al::HitSensor *, al::ComboCounter *);
    bool sendMsgPlayerDisregard(al::HitSensor *, al::HitSensor *);
    bool sendMsgPlayerItemGet(al::HitSensor *, al::HitSensor *);
    bool sendMsgPlayerPutOnEquipment(al::HitSensor *, al::HitSensor *);
    bool sendMsgPlayerReleaseEquipment(al::HitSensor *, al::HitSensor *);
    bool sendMsgPlayerReleaseEquipmentGoal(al::HitSensor *, al::HitSensor *, uint);
    bool sendMsgPlayerFloorTouch(al::HitSensor *, al::HitSensor *);
    bool sendMsgPlayerDamageTouch(al::HitSensor *, al::HitSensor *);
    bool sendMsgPlayerCarryFront(al::HitSensor *, al::HitSensor *);
    bool sendMsgPlayerCarryFrontWallKeep(al::HitSensor *, al::HitSensor *);
    bool sendMsgPlayerCarryUp(al::HitSensor *, al::HitSensor *);
    bool sendMsgPlayerCarryKeepDemo(al::HitSensor *, al::HitSensor *);
    bool sendMsgPlayerCarryWarp(al::HitSensor *, al::HitSensor *);
    bool sendMsgPlayerLeave(al::HitSensor *, al::HitSensor *);
    bool sendMsgPlayerRelease(al::HitSensor *, al::HitSensor *);
    bool sendMsgPlayerReleaseBySwing(al::HitSensor *, al::HitSensor *);
    bool sendMsgPlayerReleaseDamage(al::HitSensor *, al::HitSensor *);
    bool sendMsgPlayerReleaseDead(al::HitSensor *, al::HitSensor *);
    bool sendMsgPlayerReleaseDemo(al::HitSensor *, al::HitSensor *);
    bool sendMsgPlayerToss(al::HitSensor *, al::HitSensor *);
    bool sendMsgPlayerInvincibleTouch(al::HitSensor *, al::HitSensor *, al::ComboCounter *);
    bool sendMsgEnemyAttack(al::HitSensor *, al::HitSensor *);
    bool sendMsgEnemyAttackBoomerang(al::HitSensor *, al::HitSensor *);
    bool sendMsgEnemyAttackFire(al::HitSensor *, al::HitSensor *, char const *);
    bool sendMsgEnemyAttackNeedle(al::HitSensor *, al::HitSensor *);
    bool sendMsgEnemyFloorTouch(al::HitSensor *, al::HitSensor *);
    bool sendMsgEnemyItemGet(al::HitSensor *, al::HitSensor *);
    bool sendMsgEnemyRouteDokanAttack(al::HitSensor *, al::HitSensor *);
    bool sendMsgEnemyRouteDokanFire(al::HitSensor *, al::HitSensor *);
    bool sendMsgEnemyTouch(al::HitSensor *, al::HitSensor *);
    bool sendMsgEnemyUpperPunch(al::HitSensor *, al::HitSensor *);
    bool sendMsgEnemyTrample(al::HitSensor *, al::HitSensor *);
    bool sendMsgMapObjTrample(al::HitSensor *, al::HitSensor *);
    bool sendMsgPressureDeath(al::HitSensor *, al::HitSensor *);
    bool sendMsgNpcTouch(al::HitSensor *, al::HitSensor *);
    bool sendMsgExplosion(al::HitSensor *, al::HitSensor *, al::ComboCounter *);
    bool sendMsgExplosionCollide(al::HitSensor *, al::HitSensor *, al::ComboCounter *);
    bool sendMsgPush(al::HitSensor *, al::HitSensor *);
    bool sendMsgPushStrong(al::HitSensor *, al::HitSensor *);
    bool sendMsgPushVeryStrong(al::HitSensor *, al::HitSensor *);
    bool sendMsgHit(al::HitSensor *, al::HitSensor *);
    bool sendMsgHitStrong(al::HitSensor *, al::HitSensor *);
    bool sendMsgHitVeryStrong(al::HitSensor *, al::HitSensor *);
    bool sendMsgKnockDown(al::HitSensor *, al::HitSensor *);
    bool sendMsgMapPush(al::HitSensor *, al::HitSensor *);
    bool sendMsgVanish(al::HitSensor *, al::HitSensor *);
    bool sendMsgChangeAlpha(al::LiveActor *, float);
    bool sendMsgShowModel(al::HitSensor *, al::HitSensor *);
    bool sendMsgHideModel(al::HitSensor *, al::HitSensor *);
    bool sendMsgRestart(al::HitSensor *, al::HitSensor *);
    bool sendMsgNeedleBallAttack(al::HitSensor *, al::HitSensor *);
    bool sendMsgPunpunFloorTouch(al::HitSensor *, al::HitSensor *);
    bool sendMsgInvalidateFootPrint(al::HitSensor *, al::HitSensor *);
    bool sendMsgKickKouraAttack(al::HitSensor *, al::HitSensor *, al::ComboCounter *);
    bool sendMsgKickKouraAttackCollide(al::HitSensor *, al::HitSensor *, al::ComboCounter *);
    bool sendMsgKickKouraGetItem(al::HitSensor *, al::HitSensor *);
    bool sendMsgKickKouraReflect(al::HitSensor *, al::HitSensor *);
    bool sendMsgKickKouraCollideNoReflect(al::HitSensor *, al::HitSensor *);
    bool sendMsgKickKouraBreak(al::HitSensor *, al::HitSensor *);
    bool sendMsgKickKouraBlow(al::HitSensor *, al::HitSensor *);
    bool sendMsgKickStoneAttack(al::HitSensor *, al::HitSensor *);
    bool sendMsgKickStoneAttackCollide(al::HitSensor *, al::HitSensor *);
    bool sendMsgKickStoneAttackHold(al::HitSensor *, al::HitSensor *);
    bool sendMsgKickStoneAttackReflect(al::HitSensor *, al::HitSensor *);
    bool sendMsgKickStoneTrample(al::HitSensor *, al::HitSensor *);
    bool sendMsgKillerAttack(al::HitSensor *, al::HitSensor *);
    bool sendMsgLiftGeyser(al::HitSensor *, al::HitSensor *);
    bool sendMsgWarpStart(al::HitSensor *, al::HitSensor *);
    bool sendMsgWarpEnd(al::HitSensor *, al::HitSensor *);
    bool sendMsgHoldCancel(al::HitSensor *, al::HitSensor *);
    bool sendMsgHoleIn(al::HitSensor *, al::HitSensor *);
    bool sendMsgJumpInhibit(al::HitSensor *, al::HitSensor *);
    bool sendMsgGoalKill(al::HitSensor *, al::HitSensor *);
    bool sendMsgGoal(al::HitSensor *, al::HitSensor *);
    bool sendMsgBindStart(al::HitSensor *, al::HitSensor *);
    bool sendMsgBindInit(al::HitSensor *, al::HitSensor *, uint);
    bool sendMsgBindEnd(al::HitSensor *, al::HitSensor *);
    bool sendMsgBindCancel(al::HitSensor *, al::HitSensor *);
    bool sendMsgBindCancelByDemo(al::HitSensor *, al::HitSensor *);
    bool sendMsgBindDamage(al::HitSensor *, al::HitSensor *);
    bool sendMsgBindSteal(al::HitSensor *, al::HitSensor *);
    bool sendMsgBindGiant(al::HitSensor *, al::HitSensor *);
    bool sendMsgBallAttack(al::HitSensor *, al::HitSensor *, al::ComboCounter *);
    bool sendMsgBallRouteDokanAttack(al::HitSensor *, al::HitSensor *, al::ComboCounter *);
    bool sendMsgBallAttackHold(al::HitSensor *, al::HitSensor *);
    bool sendMsgBallAttackDRCHold(al::HitSensor *, al::HitSensor *);
    bool sendMsgBallAttackCollide(al::HitSensor *, al::HitSensor *);
    bool sendMsgBallTrample(al::HitSensor *, al::HitSensor *, al::ComboCounter *);
    bool sendMsgBallTrampleCollide(al::HitSensor *, al::HitSensor *);
    bool sendMsgBallItemGet(al::HitSensor *, al::HitSensor *);
    bool sendMsgFireBalCollide(al::HitSensor *, al::HitSensor *);
    bool sendMsgFireBallFloorTouch(al::HitSensor *, al::HitSensor *);
    bool sendMsgDokanBazookaAttack(al::HitSensor *, al::HitSensor *);
    bool sendMsgRideAllPlayerItemGet(al::HitSensor *, al::HitSensor *);
    bool sendMsgHideModel(al::LiveActor *);
    bool sendMsgShowModel(al::LiveActor *);
    bool sendMsgRestart(al::LiveActor *);
    bool sendMsgCollisionImpulse(al::HitSensor *, al::HitSensor *, sead::Vector3f *, sead::Vector3f const &, float, sead::Vector3f const &, float);
    bool sendMsgSwitchOn(al::LiveActor *);
    bool sendMsgSwitchOnInit(al::LiveActor *);
    bool sendMsgSwitchOffInit(al::LiveActor *);
    bool sendMsgSwitchKillOn(al::LiveActor *);
    bool sendMsgSwitchKillOnInit(al::LiveActor *);
    bool sendMsgSwitchKillOffInit(al::LiveActor *);
    bool sendMsgPlayerFloorTouchToColliderGround(al::LiveActor *, al::HitSensor *);
    bool sendMsgPlayerUpperPunchToColliderCeiling(al::LiveActor *, al::HitSensor *);
    bool sendMsgEnemyFloorTouchToColliderGround(al::LiveActor *, al::HitSensor *);
    bool sendMsgEnemyUpperPunchToColliderCeiling(al::LiveActor *, al::HitSensor *);
    bool sendMsgAskSafetyPoint(al::HitSensor *, al::HitSensor *, sead::Vector3f **);
    bool sendMsgAskSafetyPointToColliderGround(al::LiveActor *, al::HitSensor *, sead::Vector3f **);
    bool sendMsgTouchAssist(al::HitSensor *, al::HitSensor *);
    bool sendMsgTouchAssistTrig(al::HitSensor *, al::HitSensor *);
    bool sendMsgTouchStroke(al::HitSensor *, al::HitSensor *);
    bool sendMsgScreenPointInvalidCollisionParts(al::HitSensor *, al::HitSensor *);
    bool sendMsgBlockUpperPunch(al::HitSensor *, al::HitSensor *, al::ComboCounter *);
    bool sendMsgBlockLowerPunch(al::HitSensor *, al::HitSensor *, al::ComboCounter *);
    bool sendMsgBlockItemGet(al::HitSensor *, al::HitSensor *);
    bool sendMsgKillerItemGet(al::HitSensor *, al::HitSensor *);
    bool sendMsgPlayerKouraAttack(al::HitSensor *, al::HitSensor *, al::ComboCounter *);
    bool sendMsgLightFlash(al::HitSensor *, al::HitSensor *);
    bool sendMsgForceAbyss(al::HitSensor *, al::HitSensor *);
    bool sendMsgIsNerveSupportFreeze(al::HitSensor *, al::HitSensor *);
    bool sendMsgOnSyncSupportFreeze(al::HitSensor *, al::HitSensor *);
    bool sendMsgOffSyncSupportFreeze(al::HitSensor *, al::HitSensor *);
    bool sendMsgSwordAttackHighLeft(al::HitSensor *, al::HitSensor *);
    bool sendMsgSwordAttackLowLeft(al::HitSensor *, al::HitSensor *);
    bool sendMsgSwordAttackHighRight(al::HitSensor *, al::HitSensor *);
    bool sendMsgSwordAttackLowRight(al::HitSensor *, al::HitSensor *);
    bool sendMsgSwordAttackJumpUnder(al::HitSensor *, al::HitSensor *);
    bool sendMsgSwordBeamAttack(al::HitSensor *, al::HitSensor *);
    bool sendMsgSwordBeamReflectAttack(al::HitSensor *, al::HitSensor *);
    bool sendMsgShieldGuard(al::HitSensor *, al::HitSensor *);
    bool sendMsgEnemyAttackKnockDown(al::HitSensor *, al::HitSensor *);
    bool sendMsgAskMultiPlayerEnemy(al::HitSensor *, al::HitSensor *);
    bool sendMsgItemGettable(al::HitSensor *, al::HitSensor *);
    bool sendMsgKikkiThrow(al::HitSensor *, al::HitSensor *);
    bool sendMsgIsKikkiThrowTarget(al::HitSensor *, al::HitSensor *);
    bool sendMsgPlayerCloudGet(al::HitSensor *, al::HitSensor *);
    bool sendMsgAutoJump(al::HitSensor *, al::HitSensor *);
    bool sendMsgPlayerTouchShadow(al::HitSensor *, al::HitSensor *);
    bool sendMsgPlayerPullOutShadow(al::HitSensor *, al::HitSensor *);
    bool sendMsgPlayerAttackShadow(al::HitSensor *, al::HitSensor *);
    bool sendMsgPlayerAttackShadowStrong(al::HitSensor *, al::HitSensor *);
    bool sendMsgPlayerAttackChangePos(al::HitSensor *, al::HitSensor *, sead::Vector3f *);
    bool sendMsgAtmosOnlineLight(al::HitSensor *, al::HitSensor *);
    bool sendMsgLightBurn(al::HitSensor *, al::HitSensor *);
    bool sendMsgMoonLightBurn(al::HitSensor *, al::HitSensor *);
    bool sendMsgString(al::HitSensor *, al::HitSensor *, char const *);
    bool sendMsgStringV4fPtr(al::HitSensor *, al::HitSensor *, char const *, sead::Vector4f *);
    bool sendMsgStringV4fSensorPtr(al::HitSensor *, al::HitSensor *, char const *, sead::Vector4f *);
    bool sendMsgStringVoidPtr(al::HitSensor *, al::HitSensor *, char const *, void *);
    bool sendMsgEnemyAttackForCrossoverSensor(al::HitSensor *, al::HitSensor *);
    bool sendMsgEnemyAttackForCrossoverCylinderSensor(al::HitSensor *, al::HitSensor *, sead::Vector3f const &, sead::Vector3f const &, float);
    bool sendMsgPushAndKillVelocityToTarget(al::LiveActor *, al::HitSensor *, al::HitSensor *);
    bool sendMsgPushAndKillVelocityToTargetH(al::LiveActor *, al::HitSensor *, al::HitSensor *);
    bool sendMsgCollidePush(al::HitSensor *, al::HitSensor *, sead::Vector3f const &);
    bool sendMsgScreenPointTarget(al::SensorMsg const &, al::ScreenPointer *, al::ScreenPointTarget *);

} // namespace al

// Fill out your copyright notice in the Description page of Project Settings.


#include "StreamLevelTrigger.h"
#include "Kismet/GameplayStatics.h"
#include "Engine/LevelStreaming.h"

AStreamLevelTrigger::AStreamLevelTrigger(const FObjectInitializer& ObjectInitializer)
    : Super(ObjectInitializer)
{
    // 트리거의 Overlap 이벤트와 함수를 바인딩합니다.
    OnActorBeginOverlap.AddDynamic(this, &AStreamLevelTrigger::OnOverlapBegin);

    bIsLoading = false;
    LevelToUnload = NAME_None;
    LevelToLoad = NAME_None;
}

void AStreamLevelTrigger::BeginPlay()
{
    Super::BeginPlay();
}

void AStreamLevelTrigger::OnOverlapBegin(AActor* OverlappedActor, AActor* OtherActor)
{
    APawn* PlayerPawn = Cast<APawn>(OtherActor);

    // 플레이어가 조종 중이고, 현재 이 트리거가 로딩 중이 아닐 때만 실행
    if (PlayerPawn && PlayerPawn->IsLocallyControlled() && !bIsLoading)
    {
        // [★중요] RemoveDynamic을 절대 쓰지 않습니다. 대신 락(Lock)을 겁니다.
        bIsLoading = true;

        FLatentActionInfo UnloadInfo;
        UnloadInfo.CallbackTarget = this;
        UnloadInfo.UUID = 1;
        UnloadInfo.Linkage = 1;

        FLatentActionInfo LoadInfo;
        LoadInfo.CallbackTarget = this;
        LoadInfo.UUID = 2;
        LoadInfo.Linkage = 2;
        LoadInfo.ExecutionFunction = FName("OnLevelLoadComplete");

        UE_LOG(LogTemp, Warning, TEXT("트리거 작동 완료 -> 언로드: %s | 로드: %s"), *LevelToUnload.ToString(), *LevelToLoad.ToString());

        // 언로드 및 로드 수행
        if (!LevelToUnload.IsNone())
        {
            UGameplayStatics::UnloadStreamLevel(GetWorld(), LevelToUnload, UnloadInfo, false);
        }

        if (!LevelToLoad.IsNone())
        {
            UGameplayStatics::LoadStreamLevel(GetWorld(), LevelToLoad, true, false, LoadInfo);
        }

        // [팁] 플레이어가 트리거 밖으로 완전히 나갔을 때 쿨타임을 풀어주거나, 
        // 지금은 테스트용이니 몇 초 뒤에 다시 트리거를 쓸 수 있게 풀어줍니다.
        FTimerHandle TimerHandle;
        GetWorldTimerManager().SetTimer(TimerHandle, FTimerDelegate::CreateLambda([this]() {
            bIsLoading = false; // 다시 밟을 수 있게 잠금 해제
            }), 2.0f, false);
    }
}
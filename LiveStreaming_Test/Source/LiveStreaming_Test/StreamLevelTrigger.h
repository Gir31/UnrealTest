// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/TriggerBox.h"
#include "StreamLevelTrigger.generated.h"

/**
 * 
 */
UCLASS()
class LIVESTREAMING_TEST_API AStreamLevelTrigger : public ATriggerBox
{
	GENERATED_BODY()
public:
    AStreamLevelTrigger(const FObjectInitializer& ObjectInitializer);

protected:
    virtual void BeginPlay() override;

    // 트리거에 플레이어가 들어왔을 때 호출될 함수
    UFUNCTION()
    void OnOverlapBegin(class AActor* OverlappedActor, class AActor* OtherActor);

    // 로딩 및 언로드할 레벨 이름 (에디터에서 수정 가능하도록 세팅)
    UPROPERTY(EditAnywhere, Category = "Level Streaming")
    FName LevelToUnload;

    UPROPERTY(EditAnywhere, Category = "Level Streaming")
    FName LevelToLoad;

    bool bIsLoading;
};

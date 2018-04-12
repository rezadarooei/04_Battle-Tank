// Fill out your copyright notice in the Description page of Project Settings.

#include "TankPlayerController.h"
#include "Engine/World.h"
#include "Runtime/Engine/Classes/Engine/World.h"
#include "GameFramework/PlayerController.h"



void ATankPlayerController::BeginPlay()
{
	Super::BeginPlay();

	UE_LOG(LogTemp, Warning, TEXT("We are in begin play"))
		auto ControlledTank = GetControlledTannk();
	if (!ControlledTank) {
		UE_LOG(LogTemp, Warning, TEXT("Pawn is not there"))
	}
	else {

		UE_LOG(LogTemp, Warning, TEXT("Pawn is %s"), *ControlledTank->GetName())
	}
	

}
// Called every frame
void ATankPlayerController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	AimTowardCrosshair();
}

//Get tank control(بدست آوردن کنترل تانک خروجی در غالب تانک و یافتن پاون که قبلا ساخت شده )
ATank* ATankPlayerController::GetControlledTannk() const {

	return Cast<ATank>(GetPawn());

}
//crosshair for the hit location (هدف گذاری برای شلیک با تانک)
void ATankPlayerController::AimTowardCrosshair() {
	if (!GetControlledTannk()) {return;	}
	FVector HitLocation;
	if (GetSightRayHitLocation(HitLocation)) {
		GetControlledTannk()->AimAt(HitLocation);
	}
	
	//Get world Location of lineTrace through crosshair
	//if hits landscape
		//tell controlledTank to aim this point
}

//get place that tank can hit(یافتن مکان های که بشود شلیک کرد )
bool ATankPlayerController::GetSightRayHitLocation(FVector& HitLocation) const
{
	//find crosshair Position(یافتن مکان نقطه هدف سفید)
	int32 ViewPortSizeX, ViewPortSizeY;
	GetViewportSize(ViewPortSizeX, ViewPortSizeY);//یافتن ابعاد تصویر که بازی اجرا می شود
	auto ScreenLocation=FVector2D(CrosssHairXLocation*ViewPortSizeX,CrosssHairYLocation*ViewPortSizeY);//get the white dot according to size of platform(یافتن هدف با توجه به ابعاد تصویر)

	//"De-project" Screen position of the Crosshair to a world direction(تبدیل نقطه یافته شده به جهان)
	FVector LookDirection;
	//(if get direction send line-trace)
	if (GetLookDirection(ScreenLocation, LookDirection))
	{
		//Line-Trace Long that  LookDirection,and see what we hit(up to max range)
		GetlookvectorhitLocation(LookDirection, HitLocation);
	}

	
	return true;
}
//( ورودی ابعاد تصویر و جهت را میگیرد خروجی تبیدل شده مقداری بازگشتی بولین)
bool ATankPlayerController::GetLookDirection(FVector2D ScreenLocation,FVector& LookDirection) const {

	FVector CameraWorldLocation;//to be discarded not important
	return DeprojectScreenPositionToWorld(ScreenLocation.X
		, ScreenLocation.Y,
		CameraWorldLocation,
		LookDirection);
	}
// یافتن برداری که برای ضربه می باشد و استفاده در لاین تریس یعنی موج می فرستد در فاصله ی نزدیک کاری باید کند
bool ATankPlayerController::GetlookvectorhitLocation(FVector LookDirection,FVector& HitLocation ) const {
	FHitResult HitResult;
	auto StartLocation = PlayerCameraManager->GetCameraLocation();
	auto EndLocation = StartLocation+(LineTraceRange*LookDirection);

	if (GetWorld()->LineTraceSingleByChannel
	(
		HitResult,
		StartLocation,
		EndLocation,
		ECollisionChannel::ECC_Visibility
			))
	{
		HitLocation = HitResult.Location;
		return true;
	}
	return false;//Line Trace didnt successes
}
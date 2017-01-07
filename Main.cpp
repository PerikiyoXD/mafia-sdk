#include <Windows.h>
#include <iostream>

#include "MafiaSDK/MafiaSDK.h"


void debugFunction();

BOOL WINAPI DllMain(
	HINSTANCE hinstDLL,  // handle to DLL module
	DWORD fdwReason,     // reason for calling function
	LPVOID lpReserved)  // reserved
{
	// Perform actions based on the reason for calling.
	switch (fdwReason)
	{
	case DLL_PROCESS_ATTACH:
		// Initialize once for each new process.
		// Return FALSE to fail DLL load.
		debugFunction();
		break;

	case DLL_THREAD_ATTACH:
		// Do thread-specific initialization.
		break;

	case DLL_THREAD_DETACH:
		// Do thread-specific cleanup.
		break;

	case DLL_PROCESS_DETACH:
		// Perform any necessary cleanup.
		break;
	}
	return TRUE;  // Successful DLL_PROCESS_ATTACH.
}

void debugFunction()
{
	//Console for debug
	AllocConsole();

	//Reopen sheeties
	freopen("CONIN$", "r", stdin);
	freopen("CONOUT$", "w", stdout);
	freopen("CONOUT$", "w", stderr);


	MafiaSDK::C_Mission* myPopiciMission = MafiaSDK::GetMission();

	myPopiciMission->GetGame()->ScoreOn(true);
	myPopiciMission->GetGame()->ScoreSet(500);

	auto myCam = myPopiciMission->GetGame()->GetCamera();

	Vector3D pos = { 0.0f, 0.0f, 0.0f };
	Vector3D rot = { 0.0f, 0.0f, 0.0f };

	myCam->LezeDoToyoty(true);
	//printf("Game: %X - Our Game: %X\n", game, (DWORD)mafiaInterface->mGame->GetInterface()->mCamera);
	//printf("Is score on: %d\n Score value: %d\n", mafiaInterface->mGame->GetInterface()->mIsScoreEnabled, mafiaInterface->mGame->GetInterface()->mIsScoreEnabled);
}
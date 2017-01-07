#ifndef _CGAME_H_
#define _CGAME_H_

namespace MafiaSDK
{
	struct C_Game_Interface
	{
		PADDING(C_Game_Interface, _pad0, 0x4C);
		C_Camera mCamera;
		PADDING(C_Game_Interface, _pad1, 0x94);
		C_Player* mLocalPlayer;
	};
	
	namespace C_Game_Enum
	{
		enum FunctionAddresses
		{
			NewExplosion = 0x005AAE10,
			ScoreSet = 0x005B9FE0,
			ScoreSetOn = 0x005B9FA0,
			SetTrafficVisible = 0x5A8470,
			PlayAllSounds = 0x5B85F0,
			PauseAllSounds = 0x5B8430,
			CreateStream = 0x5B6110,
			DestroyStream = 0x5B62C0,
			StreamGetFreeId = 0x5B5E90,
			GetStreamById = 0x5B64C0,
			ScoreEnabled = 0x5B9FA0, 
			SetScore = 0x5B9FE0,
			AddTemporaryActor = 0x5A77C0,
			RemoveTemporaryActor = 0x5A79A0
		};
	};

	namespace C_Game_Hooks
	{
		namespace FunctionsPointers
		{
			std::function<void()> gameTick;
			std::function<void()> gameInit;
		};

		namespace Functions
		{
			inline void GameTick()
			{
				if(FunctionsPointers::gameTick != nullptr)
					FunctionsPointers::gameTick();
			}

			inline void GameInit()
			{
				if (FunctionsPointers::gameInit != nullptr)
					FunctionsPointers::gameInit();
			}
		};

		namespace NakedFunctions
		{
			__declspec(naked) void Tick()
			{
				__asm
				{
					pushad
						call Functions::GameTick
					popad

					retn 4
				}
			}

			__declspec(naked) void Init()
			{
				__asm
				{
					pushad
						call Functions::GameInit
					popad

					retn
				}
			}

		};

		inline void HookOnGameStart(std::function<void()> funcitonPointer)
		{
			FunctionsPointers::gameTick = funcitonPointer;

			InstallJmpHook(0x005BE93A, (unsigned long)&NakedFunctions::Tick);
		}

		inline void HookOnGameInit(std::function<void()> functionPointer) 
		{
			FunctionsPointers::gameInit = functionPointer;

			InstallJmpHook(0x005A395B, (unsigned long)&NakedFunctions::Init);
		}
	};

	class C_Game
	{
	public:
		C_Game_Interface* GetInterface()
		{
			return reinterpret_cast<C_Game_Interface*>(this);
		}

		C_Camera* GetCamera()
		{
			return &this->GetInterface()->mCamera;
		}

		C_Player* GetLocalPlayer()
		{
			return this->GetInterface()->mLocalPlayer;
		}
		
		void SetTrafficVisible(BOOL toggle)
		{
			unsigned long funcAddress = C_Game_Enum::FunctionAddresses::SetTrafficVisible;

			__asm
			{
				push toggle
				call funcAddress
			}
		}

		void PlayAllSound(void)
		{	
			unsigned long funcAddress = C_Game_Enum::FunctionAddresses::PlayAllSounds;
			
			__asm
			{
				push 1
				mov ecx, this
				call funcAddress
			}
			
		}

		void PauseAllSound(void)
		{	
			unsigned long funcAddress = C_Game_Enum::FunctionAddresses::PauseAllSounds;
		
			__asm
			{
				mov ecx, this
				call funcAddress
			}
		}


		int CreateStream(const char * streamName)
		{
			
			unsigned long funcAddress = C_Game_Enum::FunctionAddresses::CreateStream;
			unsigned long funcAddressGetId = C_Game_Enum::FunctionAddresses::StreamGetFreeId;
			
			int returnId = -1;

			__asm
			{
				//Get Free Id for stream
				push 0
				mov ecx, this
				call funcAddressGetId
				mov returnId, eax

				//Create stream
				push eax
				push streamName
				mov ecx, this
				call funcAddress
			}

			return returnId;
		}

		unsigned long GetStreamById(int streamId)
		{
			
			unsigned long funcAddress = C_Game_Enum::FunctionAddresses::GetStreamById;
			unsigned long returnAddress = NULL;
			
			__asm
			{
				push streamId
				mov ecx, this
				call funcAddress
				mov returnAddress, eax
			}

			return returnAddress;
		}

		void SetStreamVolume(int streamId, float volume)
		{
			unsigned long streamAddress = GetStreamById(streamId);

			__asm
			{
				push volume
				push esi
				mov ecx, dword ptr ds : [esi]
				call dword ptr ds : [ecx + 0x38]
			}
		}

		void PlayStream(int streamId)
		{
			unsigned long streamAddress = GetStreamById(streamId);

			__asm
			{
				mov esi, streamAddress
				mov eax, dword ptr ds : [esi]
				push esi
				call dword ptr ds : [eax + 14h]
			}

			//Set volume of stream to same value as in options
			float currentMainVolume = *reinterpret_cast<float*>(0x6D4B10);
			SetStreamVolume(streamId, currentMainVolume);
		}

		void PauseStream(int streamId)
		{
			unsigned long streamAddress = GetStreamById(streamId);

			__asm
			{
				mov esi, streamAddress
				mov eax, dword ptr ds : [esi]
				push esi
				call dword ptr ds : [eax + 0x1C]
			}
		}

		void DestroyStream(int streamId)
		{
			
			unsigned long funcAddress = C_Game_Enum::FunctionAddresses::DestroyStream;
			unsigned long streamAddress = GetStreamById(streamId);
			
			__asm
			{
				push streamAddress
				mov ecx, this
				call funcAddress
			}
		}

		void NewExplosion(C_Actor* actor, Vector3D & pos, float radius, float force, BOOL b1, BOOL b2, BOOL b3, int int1)
		{
			unsigned long funcAddr = C_Game_Enum::FunctionAddresses::NewExplosion;

			__asm
			{
				push int1
				push b3
				push b2
				push b1
				push force
				push radius
				push pos
				push actor
				mov ecx, this
				call funcAddr
			}
		}


		void ScoreSet(int score)
		{
			unsigned long funcAddr = C_Game_Enum::FunctionAddresses::ScoreSet;

			__asm
			{
				push score
				mov ecx, this
				call funcAddr
			}
		}

		void ScoreOn(BOOL on)
		{
			unsigned long funcAddr = C_Game_Enum::FunctionAddresses::ScoreSetOn;

			__asm
			{
				push on
				mov ecx, this
				call funcAddr
			}
		}
	};
};

#endif
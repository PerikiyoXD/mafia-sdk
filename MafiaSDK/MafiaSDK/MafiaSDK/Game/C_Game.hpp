#ifndef _CGAME_H_
#define _CGAME_H_

namespace MafiaSDK
{
	struct C_Game_Interface
	{
		PADDING(C_Game_Interface, _pad0, 0x4C);
		C_Camera mCamera;
	};
	
	namespace C_Game_Enum
	{
		enum FunctionAddresses
		{
			NewExplosion = 0x005AAE10,
			ScoreSet = 0x005B9FE0,
			ScoreSetOn = 0x005B9FA0
		};
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
		
		void NewExplosion(unsigned long actor, Vector3D & pos, float radius, float force, BOOL b1, BOOL b2, BOOL b3, int int1)
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
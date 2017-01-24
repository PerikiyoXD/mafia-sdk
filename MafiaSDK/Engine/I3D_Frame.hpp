/*
	Copyright 2017 Dávid Svitana

	Licensed under the Apache License, Version 2.0 (the "License");
	you may not use this file except in compliance with the License.
	You may obtain a copy of the License at

	http://www.apache.org/licenses/LICENSE-2.0

	Unless required by applicable law or agreed to in writing, software
	distributed under the License is distributed on an "AS IS" BASIS,
	WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
	See the License for the specific language governing permissions and
	limitations under the License.
*/

#ifndef _I3D_Frame_H_
#define _I3D_Frame_H_

namespace MafiaSDK
{
	struct I3D_Frame_Interface
	{

	};

	namespace I3D_Frame_Enum
	{
		enum FunctionsAddresses
		{
			CacheBlock = 0x647ED8,
			CacheBlock_OpenModel = 0x647DD0,
			CacheBlock_CreateModel = 0x4087E0,
			SetScale = 0x0047A750,
			SetPos = 0x00460980
		};
	};

	class I3D_Frame
	{
	public:
		I3D_Frame_Interface* GetInterface()
		{
			return reinterpret_cast<I3D_Frame_Interface*>(this);
		}

		I3D_Frame()
		{
			unsigned long cacheBlock = I3D_Frame_Enum::FunctionsAddresses::CacheBlock;

			__asm
			{
				mov     eax, cacheBlock
				mov     eax, [eax]
				push    9
				push    eax
				mov     ecx, [eax]
				call    dword ptr[ecx + 50h]
				mov		this, eax
			}
		}

		void LoadModel(const char* modelName)
		{
			unsigned long cacheBlockOpenModel = I3D_Frame_Enum::FunctionsAddresses::CacheBlock_OpenModel;
			unsigned long cacheBlockCreateModel = I3D_Frame_Enum::FunctionsAddresses::CacheBlock_CreateModel;

			__asm
			{
				mov esi, this
				push 0
				push 0
				push 0
				push 0
				push modelName
				push esi
				mov ecx, cacheBlockOpenModel
				call cacheBlockCreateModel

				// Our model was created?
				test eax, eax
				jnz CCache

				// CCache spawn
				push esi
				mov ecx, dword ptr[esi]
				call dword ptr[ecx + 28h]

				mov ecx, dword ptr[esi]
				push esi
				call dword ptr[ecx + 18h]

				sub esp, 4
				CCache:
			}
		}

		void SetFramePos(Vector3D vPostion)
		{
			unsigned long funcAddr = I3D_Frame_Enum::FunctionsAddresses::SetPos;
		

			DWORD dwFunc2 = 0x0047AD10;
			DWORD dwFunc3 = 0x0047A6C0;
			DWORD dwFunc5 = 0x005D92D0;
			DWORD dwFunc6 = 0x0047ADF0;

			//Set position
			__asm
			{
				//SetFrame Pos
				lea eax, vPostion
				push eax
				mov ecx, this
				call funcAddr

				//Update frame
				mov eax, this
				push eax
				mov ecx, dword ptr ds : [eax]
				call dword ptr [ ecx + 0x18 ]

				//Get some offset
				mov ecx, this
				call dwFunc2

				//Check of exists
				cmp dword ptr ds : [eax], 0
				je jump

				//Get offset 1 
				mov ecx, this
				call dwFunc2

				//Get offset 2
				mov ecx, [eax]
				call dwFunc3

				cmp dword ptr ds : [eax], 5
				jnz end

				jump :
				mov ecx, dword ptr ds : [C_MISSION_CLASS]
					mov edx, this
					push edx
					call dwFunc5

					mov ecx, eax
					call dwFunc6
					end :
			}
		}

		void SetFrameRot( Vector4D vRotation )
		{

		}

		void SetFrameScale(Vector3D & vScale)
		{
			unsigned long addressFunc = I3D_Frame_Enum::FunctionsAddresses::SetScale;

			__asm
			{
				push vScale
				mov ecx, this
				call addressFunc
			}

			Update();
		}
	private:
		void Update()
		{

			__asm
			{
				mov eax, this
				push eax
				mov ecx, dword ptr ds : [eax]
				call dword ptr[ecx + 0x18]
			}
		}
	};
};

#endif
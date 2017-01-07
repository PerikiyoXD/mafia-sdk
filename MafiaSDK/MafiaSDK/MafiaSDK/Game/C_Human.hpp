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

#ifndef _CHUMAN_H_
#define _CHUMAN_H_

namespace MafiaSDK
{
	struct C_Human_Interface
	{
		C_Entity_Interface	entity;
		PADDING(C_Human_Interface, _pad0, 0x4);
		byte animStateLocal;
		byte isInAnimWithCarLocal;
		PADDING(C_Human_Interface, _pad1, 0x2);
		byte animState;
		byte isInAnimWithCar;
		PADDING(C_Human_Interface, _pad2, 0x22);
		C_Car* playersCar;
		C_Car* carLeavingOrEntering;
		PADDING(C_Human_Interface, _pad3, 0x144);
		bool isDucking;
		bool isAiming;
		PADDING(C_Human_Interface, _pad4, 0x16);
		bool isReloading;
		PADDING(C_Human_Interface, _pad5, 0x11B);
		I3D_Frame *	neckFrame;
		PADDING(C_Human_Interface, _pad6, 0x164);
		G_Inventory inventory;
		PADDING(C_Human_Interface, _pad7, 0xF4);
		float inCarRotation;
		PADDING(C_Human_Interface, _pad8, 0x4C);
		float health;
	};

	namespace C_Human_Enum
	{
		enum FunctionsAddresses
		{
			Hit = 0x5762A0,
			Intern_UseCar = 0x57E020,
			Intern_FromCar = 0x57E500,
			RepairWeaponPosition = 0x57E980,
			ChangeWeaponModel = 0x57EC20,
			Do_ChangeWeapon = 0x57F550,
			Do_WeaponDrop = 0x585D90,
			Use_Actor = 0x582180,
			Do_Shoot = 0x583590,
			Do_ThrowGranade	= 0x583F40,
			Do_Reload = 0x585B40,
			Do_Holster = 0x585C60,
			Do_Jump	= 0x586190,
			Do_PlayAnim	= 0x585E80,
			Do_ThrowCocotFromCar = 0x587D70,
			EineMeineKleineAutoInLuft = 0x58A5A0,
			NewScream = 0x58B470,
			Intern_ChangeModel = 0x587190,
			Do_StopAnim = 0x57D2E0,
			Do_Breath = 0x57D310,
			Do_Aimed = 0x57F830,
			Do_Crouched = 0x57F8A0,
			G_Inventory_Insert = 0x6092B0,
			G_Inventory_Remove	= 0x6095E0
		};
	};

	class C_Human
	{
	public:
		C_Human_Interface* GetInterface()
		{
			return reinterpret_cast<C_Human_Interface*>(this);
		}


		void Intern_UseCar(C_Car* car, int iSeatID)
		{
			unsigned long funcAddress = C_Human_Enum::FunctionsAddresses::Intern_UseCar;
			

			__asm
			{
				push iSeatID
				push car
				mov ecx, this
				call funcAddress
			}
		}

		void Intern_FromCar(void)
		{
			unsigned long funcAddress = C_Human_Enum::FunctionsAddresses::Intern_FromCar;
			unsigned long dwCarFrame = *(unsigned long*)((unsigned long)this->GetInterface()->playersCar + 0x68);
			

			__asm
			{
				push dwCarFrame
				mov ecx, this
				call funcAddress
			}
		}

		void RepairWeaponPosition(void)
		{
			unsigned long funcAddress = C_Human_Enum::FunctionsAddresses::RepairWeaponPosition;
			

			__asm
			{
				mov ecx, this
				call funcAddress
			}
		}

		void ChangeWeaponModel(void)
		{
			unsigned long funcAddress = C_Human_Enum::FunctionsAddresses::ChangeWeaponModel;
			

			__asm
			{
				mov ecx, this
				call funcAddress
			}
		}

		void Do_ChangeWeapon(int iWeaponId, bool bIdk)
		{
			unsigned long funcAddress = C_Human_Enum::FunctionsAddresses::Do_ChangeWeapon;
			

			__asm
			{
				push bIdk
				push iWeaponId
				mov ecx, this
				call funcAddress
			}
		}

		void Do_PlayAnim(char* szAnimName)
		{
			unsigned long funcAddress = C_Human_Enum::FunctionsAddresses::Do_PlayAnim;
			

			__asm
			{
				push 0
				push 0
				push szAnimName
				mov ecx, this
				call funcAddress
			}
		}

		void Do_StopAnim(void)
		{
			unsigned long funcAddress = C_Human_Enum::FunctionsAddresses::Do_PlayAnim;
			

			__asm
			{
				mov ecx, this
				call funcAddress
			}
		}

		void Use_Actor(unsigned long dwActor, int iUnk1, int iUnk2, int iUnk3)
		{
			unsigned long funcAddress = C_Human_Enum::FunctionsAddresses::Use_Actor;
			

			__asm
			{
				push iUnk3
				push iUnk2
				push iUnk1
				push dwActor
				mov ecx, this
				call funcAddress
			}
		}

		void Do_Shoot(bool bFromCar, Vector3D vPos)
		{
			unsigned long funcAddress = C_Human_Enum::FunctionsAddresses::Do_Shoot;
			

			__asm
			{
				lea eax, vPos
				push eax
				push bFromCar
				mov ecx, this
				call funcAddress
			}
		}

		void Do_ThrowGranade(Vector3D vPos)
		{
			unsigned long funcAddress = C_Human_Enum::FunctionsAddresses::Do_ThrowGranade;
			

			__asm
			{
				lea eax, vPos
				push eax
				mov ecx, this
				call funcAddress
			}
		}

		void Do_Reload(void)
		{
			unsigned long funcAddress = C_Human_Enum::FunctionsAddresses::Do_Reload;
			

			__asm
			{
				mov ecx, this
				call funcAddress
			}
		}

		void Do_Holster(void)
		{
			unsigned long funcAddress = C_Human_Enum::FunctionsAddresses::Do_Holster;
			

			__asm
			{
				mov ecx, this
				call funcAddress
			}
		}

		void Do_WeaponDrop(void)
		{
			unsigned long funcAddress = C_Human_Enum::FunctionsAddresses::Do_WeaponDrop;
			

			__asm
			{
				mov ecx, this
				call funcAddress
			}
		}

		void Do_ThrowCocotFromCar(C_Car * car, int iSeatId)
		{
			unsigned long funcAddress = C_Human_Enum::FunctionsAddresses::Do_ThrowCocotFromCar;
			

			__asm
			{
				push iSeatId
				push car
				mov ecx, this
				call funcAddress
			}
		}

		void EineMeineKleineAutoInLuft(C_Car * car)
		{
			unsigned long funcAddress = C_Human_Enum::FunctionsAddresses::EineMeineKleineAutoInLuft;
			

			__asm
			{
				push car
				mov ecx, this
				call funcAddress
			}
		}

		void NewScream(unsigned int iScream)
		{
			unsigned long funcAddress = C_Human_Enum::FunctionsAddresses::NewScream;
			

			__asm
			{
				push iScream
				mov ecx, this
				call funcAddress
			}
		}

		void Intern_ChangeModel(char* szModelName)
		{
			unsigned long funcAddress = C_Human_Enum::FunctionsAddresses::Intern_ChangeModel;
			

			__asm
			{
				push 0
				push szModelName
				mov ecx, this
				call funcAddress
			}
		}

		void G_Inventory_Insert(S_GameItem newItem, bool bUnk)
		{
			unsigned long funcAddress = C_Human_Enum::FunctionsAddresses::G_Inventory_Insert;
			G_Inventory* inventory = &this->GetInterface()->inventory;

			__asm
			{
				push bUnk
				lea eax, newItem
				push eax
				mov ecx, inventory
				call funcAddress
			}
		}

		S_GameItem* G_Inventory_AddWeapon(int iWeaponId, int iAmmoLoaded, int iAmmoHidden)
		{
			S_GameItem newItem = { iWeaponId, iAmmoLoaded, iAmmoHidden, NULL };

			this->G_Inventory_Insert(newItem, false);

			this->ChangeWeaponModel();

			return &newItem;
		}

		void G_Inventory_RemoveWeapon(short int iWeaponId)
		{
			G_Inventory* inventory = &this->GetInterface()->inventory;
			unsigned long funcAddress = C_Human_Enum::FunctionsAddresses::G_Inventory_Remove;

			__asm
			{
				sub esp, 500h
				mov ax, iWeaponId
				lea ecx, dword ptr ss : [esp + 0x1EC]
				push 0
				push ecx
				mov ecx, inventory
				mov word ptr ss : [esp + 0x1F4], ax
				call funcAddress
				add esp, 500h
			}

			this->ChangeWeaponModel();
		}
	};
};

#endif
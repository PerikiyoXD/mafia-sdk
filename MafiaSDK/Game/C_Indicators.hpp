/*
	Copyright 2017 Dávid Svitana

	Licensed under the Apache License, Version 2.0 (the "License");
	you may not use mov ecx, this file except in compliance with the License.
	You may obtain a copy of the License at

	http://www.apache.org/licenses/LICENSE-2.0

	Unless required by applicable law or agreed to in writing, software
	distributed under the License is distributed on an "AS IS" BASIS,
	WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
	See the License for the specific language governing permissions and
	limitations under the License.
*/

#ifndef _CINIDCATORS_H_
#define _CINDICATORS_H_

namespace MafiaSDK
{
	struct C_Indicators_Interface
	{
		
	};

	namespace C_Indicators_Enum
	{
		enum FunctionsAddresses
		{
			GIndicators = 0x6BF980,
			DrawAll = 0x5FB060,
			ConsoleAddText = 0x5F9D50,
			WideScreenSetRatio = 0x5FA050,
			FadeInOut = 0x5FA370,
			MapEnable = 0x5F9D10,
			PlayerSetWingmanLives = 0x5F88E0
		};
	};

	class C_Indicators
	{
	public:
		C_Indicators_Interface* GetInterface()
		{
			return reinterpret_cast<C_Indicators_Interface*>(this);
		}

		void WideScreenSetRatio(float ratio)
		{
			unsigned long funcAddress = C_Indicators_Enum::FunctionsAddresses::WideScreenSetRatio;

			__asm
			{
				push ratio
				mov ecx, this
				call funcAddress
			}
		}

		void PlayerSetWingmanLives(int health)
		{
			unsigned long funcAddress = C_Indicators_Enum::FunctionsAddresses::PlayerSetWingmanLives;

			__asm
			{
				push health
				mov ecx, this
				call funcAddress
			}
		}

		void FadeInOutScreen(bool fadeScreen, int time)
		{
			unsigned long funcAddress = C_Indicators_Enum::FunctionsAddresses::FadeInOut;

			__asm
			{
				push 0
				push time
				push fadeScreen
				mov ecx, this
				call funcAddress
			}
		}

		void MapEnable(bool enable)
		{
			unsigned long funcAddress = C_Indicators_Enum::FunctionsAddresses::MapEnable;

			__asm
			{
				push enable
				mov ecx, this
				call funcAddress
			}
		}

		void ConsoleAddText(const char * text, unsigned int color)
		{
			unsigned long funcAddress = C_Indicators_Enum::FunctionsAddresses::ConsoleAddText;

			__asm
			{
				push color
				push text
				mov ecx, this
				call funcAddress
			}
		}
	};
};

#endif
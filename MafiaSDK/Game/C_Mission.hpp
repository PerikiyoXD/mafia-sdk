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

namespace MafiaSDK
{
	namespace C_Mission_Enum
	{
		enum FunctionAddresses
		{
			CLASS_CMISSION = C_MISSION_CLASS
		};
	}

	struct C_Mission_Interface
	{
		PADDING(C_Mission_Interface, _pad0, 0x24);
		C_Game * mGame;
	};
	
	class C_Mission
	{
	public:
		C_Mission_Interface* GetMissionInterface()
		{
			return reinterpret_cast<C_Mission_Interface*>(this);
		}

		C_Game* GetGame()
		{
			return GetMissionInterface()->mGame;
		}
	};

	C_Mission* GetMission()
	{
		return *reinterpret_cast<C_Mission**>(C_Mission_Enum::FunctionAddresses::CLASS_CMISSION);
	}
}

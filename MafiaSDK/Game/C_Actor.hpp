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


#ifndef _CACTOR_H_
#define _CACTOR_H_

namespace MafiaSDK
{
	struct C_Actor_Interface
	{

	};

	enum C_Actor_FunctionsAddresses
	{

	};

	class C_Actor
	{
	public:
		C_Actor_Interface* GetInterface()
		{
			return reinterpret_cast<C_Actor_Interface*>(this);
		}
	};
};

#endif
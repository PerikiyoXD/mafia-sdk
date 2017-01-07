#ifndef _CPLAYER_H_
#define _CPLAYER_H_

namespace MafiaSDK
{
	struct C_Player_Interface
	{
	};

	namespace C_Player_Enum
	{
		enum FunctionAddresses
		{
			
		};
	};

	class C_Player
	{
	public:
		C_Player_Interface* GetInterface()
		{
			return reinterpret_cast<C_Player_Interface*>(this);
		}
	};
};

#endif
#ifndef _SHAREDUTILS_DEFINES_H_
#define _SHAREDUTILS_DEFINES_H_

// Macros
#define SAFE_RELEASE(p)               { if(p) { (p)->Release(); (p)=NULL; } }
#define SAFE_DELETE(p)                { if(p) { delete (p); (p)=NULL; } }
#define PADDING(prefix, name, size)	  BYTE prefix##_##name##[size]

#ifdef WIN32
#define PATH_SEPERATOR "\\"
#else
#define PATH_SEPERATOR "/"
#endif

// Constants
#define C_MISSION_CLASS 0x063788C


struct Vector3D 
{
	float x;
	float y;
	float z;
};

class S_GameItem
{
public:
	int		weaponId;
	int		ammoLoaded;
	int		ammoHidden;
	int		_unk;
};

class G_Inventory
{
public:
	S_GameItem items[8];
};


#endif
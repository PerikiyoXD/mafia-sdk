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

static void InstallJmpHook(DWORD address, DWORD function)
{
	DWORD lpflOldProtect;
	VirtualProtect((void*)address, 5, PAGE_EXECUTE_READWRITE, &lpflOldProtect);
	*(BYTE*)(address) = 0xE9;
	*(DWORD*)(address + 1) = (unsigned long)function - (address + 5);
	VirtualProtect((void*)address, 5, lpflOldProtect, &lpflOldProtect);
}



//TODO(Davo): Normal implementation needed
struct Vector3D 
{
	float x;
	float y;
	float z;
};

struct Vector4D
{
	float x;
	float y;
	float z;
	float w;
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
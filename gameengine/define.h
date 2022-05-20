#pragma once


#define SINGLE(type) public:\
						static type* GetInst()\
						 {\
						  static type mgr;\
						  return &mgr;\
						  }\
					private:\
						type();\
					   ~type();

#define fDT CtimerMgr::GetInst()->GetFDT()
#define DT CtimerMgr::GetInst()->GetDT()


enum class GROUP_TYPE
{
	DEFAULT,

	PALYER,
	MISSILE,
	MONSTER,

	END =32,
};


enum class SCENE_TYPE
{
	TOOL,
	START,
	STAGE_01,
	STAGE_02,
	END = 32,
};

enum class BRUSH_TYPE
{
	HOLLOW,
	END,
};

enum class PEN_TYPE
{
	RED,
	GREEN,
	BLUE,
	END
};
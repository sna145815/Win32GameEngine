#include "pch.h"
#include "CMissile.h"
#include"CtimerMgr.h"



CMissile::CMissile()
	:m_fDir(1)
{

}

CMissile::~CMissile()
{

}

void CMissile::update()
{
	Vec2 vPos = GetPos();

	vPos.y += 200.f * fDT * (float)m_fDir;

	SetPos(vPos);
}

#include "pch.h"
#include "CMonster.h"
#include"CtimerMgr.h"


CMonster::CMonster()
	:m_vCenterPos(Vec2(0.f,0.f))
	,m_fSpeed(100.f)
	,m_fMaxDistance(50.f)	
	,m_iDir(1)
{

}

CMonster::~CMonster()
{

}

void CMonster::update()
{
	Vec2 vCurpos = GetPos();

	//���� �������� �ð��� m_fSpeed ��ŭ �̵�
	vCurpos.x += fDT * m_fSpeed * m_iDir;

	//��ȸ �Ÿ� ���ط��� �Ѿ���� Ȯ��
	float fDist = abs(m_vCenterPos.x - vCurpos.x)-m_fMaxDistance;

	if (0.f < fDist)
	{
		//���� ����
		m_iDir *= -1;
		vCurpos.x += fDist * m_iDir;
	}

	SetPos(vCurpos);
}

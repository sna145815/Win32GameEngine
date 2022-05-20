#include "pch.h"
#include "CPlayer.h"
#include"CKeyMgr.h"
#include"CtimerMgr.h"
#include"CSceneMgr.h"
#include"CMissile.h"
#include"CTexture.h"
#include"CPathMgr.h"
#include"CResMgr.h"
#include "CCollider.h"
CPlayer::CPlayer()
	:m_pTex(nullptr)
{
	//Texture 로딩하기
	m_pTex=CResMgr::GetInst()->LoadTexture(L"PlyerTex", L"texture\\Player.bmp");
	CreateCollider();

	GetCollider()->SetScale(Vec2(100.f, 100.f));

}

CPlayer::~CPlayer()
{

	
}

void CPlayer::update()
{
	Vec2 vPos = GetPos();

	if (CKeyMgr::GetInst()->GetKeyState(KEY::W) == KEY_STATE::HOLD)
	{
		vPos.y -= 200.f * fDT;
	}
	if (CKeyMgr::GetInst()->GetKeyState(KEY::S) == KEY_STATE::HOLD)
	{
		vPos.y += 200.f * fDT;
	}
	if (CKeyMgr::GetInst()->GetKeyState(KEY::A) == KEY_STATE::HOLD)
	{
		vPos.x -= 200.f * fDT;
	}
	if (CKeyMgr::GetInst()->GetKeyState(KEY::D) == KEY_STATE::HOLD)
	{
		vPos.x += 200.f * fDT;
	}
	if (CKeyMgr::GetInst()->GetKeyState(KEY::SPACE) == KEY_STATE::TAP)
	{
		CreateMissile();
	}

	SetPos(vPos);
}

void CPlayer::render(HDC _dc)
{
	int iWidth=(int)m_pTex->Width();
	int iHeight=(int)m_pTex->Height();

	Vec2 vPos = GetPos();
	;
	;
	BitBlt(_dc, 
		int(vPos.x - (float)(iWidth / 2))
	, int(vPos.y - (float)(iHeight / 2))
	,iWidth,iHeight
	,m_pTex->GetDc()
	,0,0,SRCCOPY);

	//TransparentBlt(_dc
	//	, int(vPos.x - (float)(iWidth / 2))
	//	, int(vPos.y - (float)(iHeight / 2))
	//	, iWidth, iHeight
	//	, m_pTex->GetDc()
	//	, 0, 0, iWidth, iHeight
	//	, RGB(255, 0, 255));

	component_render(_dc);
}

void CPlayer::CreateMissile()
{
	Vec2 vMissilePos = GetPos();
	vMissilePos.y -= GetScale().y / 2.f;

	//Missile Object
	CMissile* pMissile = new CMissile;
	pMissile->SetPos(vMissilePos);
	pMissile->SetScale(Vec2(25.f, 25.f));
	pMissile->SetDir(true);

	CScene* pCurScene=CSceneMgr::GetInst()->GetCurScene();
	pCurScene->AddObject(pMissile,GROUP_TYPE::DEFAULT);

}



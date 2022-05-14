#include "pch.h"
#include "CPlayer.h"
#include"CKeyMgr.h"
#include"CtimerMgr.h"
#include"CSceneMgr.h"
#include"CMissile.h"
#include"CTexture.h"
#include"CPathMgr.h"

CPlayer::CPlayer()
	:m_pTex(nullptr)
{
	//Texture 로딩하기
	m_pTex = new CTexture;
	wstring strFilepath = CPathMgr::GetInst()->GetContentPath();
	strFilepath += L"texture\\Player.bmp";
	m_pTex->Load(strFilepath);


}

CPlayer::~CPlayer()
{
	if (nullptr != m_pTex)
	{
		delete m_pTex;
	}
	
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



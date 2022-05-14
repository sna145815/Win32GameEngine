#pragma once
class CtimerMgr
{

	SINGLE(CtimerMgr);
private:
	LARGE_INTEGER  m_llCurCount;
	LARGE_INTEGER  m_llPrevCount;
	LARGE_INTEGER  m_llFrequency;

	double		  m_dDT; //������ ���� �ð���
	double	      m_dAcc; //1�� üũ�� ���� �����ð�
	UINT		  m_iCallCount;// �Լ� ȣ�� ȸ�� üũ
	UINT		  m_iFPS;    //�ʴ� ȣ�� Ƚ��

public:
	void init();
	void update();
	void render();
public:
	double GetDT() { return m_dDT; }
	float GetFDT(){ return (float)m_dDT; }
};


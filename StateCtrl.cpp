#include "Include.h"
#include "Extern.h"


CStateCtrl::CStateCtrl()
{
	Init();
}

CStateCtrl::~CStateCtrl()
{
	Init();
}

bool CStateCtrl::StateAdd(int nIndex, CState* pState)
{
	if (m_pStates[nIndex] == NULL)
	{
		m_pStates[nIndex] = pState;
		return true;
	}
	else
		return false;
}

bool CStateCtrl::StateRelease(int nIndex)
{
	if (m_pStates[nIndex] != NULL)
	{
		m_pStates[nIndex] = NULL;
		return true;
	}
	else
		return false;
}

bool CStateCtrl::StateChange(int nIndex)
{
	CState* pState = m_pStates[nIndex];

	if (m_pCurState != NULL)
		m_pCurState->Exit();

	if (pState != NULL)
	{
		m_pPrevState = m_pCurState;
		m_pCurState = pState;
		m_pCurState->Start();
		return true;
	}
	else
		return false;
}

void CStateCtrl::Update()
{
	if (m_pCurState != NULL)
		m_pCurState->Update();	
}

void CStateCtrl::Draw()
{
	if (m_pCurState != NULL)
		m_pCurState->Draw();
}

void CStateCtrl::Init()
{
	for (int i = 0; i < E_SCENE_MAX; i++)
		m_pStates[i] = NULL;
}


#include "stdafx.h"
#include "MainGame.h"

#include "Engine_Include.h"

CMainGame::CMainGame()
{
}

CMainGame::~CMainGame()
{
	free();
}

HRESULT CMainGame::initalize()
{
	return NOERROR;
}

HRESULT CMainGame::update()
{
	return NOERROR;
}

HRESULT CMainGame::render()
{
	return NOERROR;
}

CMainGame* CMainGame::Create()
{
	CMainGame* pInstance = new CMainGame;

	if (FAILED(pInstance->initalize()))
	{
		MSG_BOX(L"CMainGame Create Failed");
		engine::SafeRelease(pInstance);
	}

	return pInstance;
}

void CMainGame::free()
{

}
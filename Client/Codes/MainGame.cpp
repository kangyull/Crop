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
	return S_OK;
}

HRESULT CMainGame::update()
{
	return S_OK;
}

HRESULT CMainGame::render()
{
	return S_OK;
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
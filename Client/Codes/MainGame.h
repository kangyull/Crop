#pragma once

#include "Base.h"

class CMainGame : public CBase
{
private:
	explicit CMainGame();
	virtual ~CMainGame();

public:
	HRESULT initalize();
	HRESULT update();
	HRESULT render();

public:
	static CMainGame*	Create();
	virtual void		free();
};
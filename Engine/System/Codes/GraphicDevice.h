#pragma once

#include "Base.h"

BEGIN(engine)

class ENGINE_DLL CGraphicDevice final : public CBase
{
	DECLARE_SINGLETON(CGraphicDevice)

public:
	enum WINMODE
	{
		WINMODE_FULL,
		WINMODE_WIN,
		WINMODE_END
	};

private:
	explicit CGraphicDevice();
	virtual ~CGraphicDevice() = default;

public:
	LPDIRECT3DDEVICE9	getGraphicDevice() const;

public:
	HRESULT	initailize(HWND hWnd, WINMODE eMode, const unsigned int iSizeX, const unsigned int iSizeY, LPDIRECT3DDEVICE9* ppGraphicDevice);

public:
	virtual void	free()	override;

private:
	LPDIRECT3D9			m_pSDK;
	LPDIRECT3DDEVICE9	m_pGraphicDevice;
};

END
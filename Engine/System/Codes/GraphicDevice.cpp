#include "Engine_Include.h"
#include "GraphicDevice.h"

USING(engine)
IMPLEMENT_SINGLETON(CGraphicDevice)

CGraphicDevice::CGraphicDevice()
	: m_pSDK(nullptr), m_pGraphicDevice(nullptr)
{
}

LPDIRECT3DDEVICE9 CGraphicDevice::getGraphicDevice() const
{
	return m_pGraphicDevice;
}

HRESULT CGraphicDevice::initailize(HWND hWnd, WINMODE eMode, const unsigned int iSizeX, const unsigned int iSizeY, LPDIRECT3DDEVICE9* ppGraphicDevice)
{
	m_pSDK = Direct3DCreate9(D3D_SDK_VERSION);
	if (nullptr == m_pSDK)
	{
		return E_FAIL;
	}

	D3DCAPS9 tDeviceCaps;
	ZeroMemory(&tDeviceCaps, sizeof(D3DCAPS9));

	if (FAILED(m_pSDK->GetDeviceCaps(D3DADAPTER_DEFAULT, D3DDEVTYPE_HAL, &tDeviceCaps)))
	{
		return E_FAIL;
	}

	unsigned long dwlong = 0;

	if (tDeviceCaps.DevCaps & D3DDEVCAPS_HWTRANSFORMANDLIGHT)
	{
		dwlong |= D3DCREATE_HARDWARE_VERTEXPROCESSING;
	}
	else
	{
		dwlong |= D3DCREATE_SOFTWARE_VERTEXPROCESSING;
	}

	dwlong |= D3DCREATE_MULTITHREADED;

	D3DPRESENT_PARAMETERS tPresentParameter;
	ZeroMemory(&tPresentParameter, sizeof(D3DPRESENT_PARAMETERS));

	tPresentParameter.BackBufferWidth = iSizeX;
	tPresentParameter.BackBufferHeight = iSizeY;
	tPresentParameter.BackBufferFormat = D3DFMT_A8R8G8B8;
	tPresentParameter.BackBufferCount = 1;

	tPresentParameter.MultiSampleType = D3DMULTISAMPLE_NONE;
	tPresentParameter.MultiSampleQuality = 0;

	tPresentParameter.SwapEffect = D3DSWAPEFFECT_DISCARD;
	tPresentParameter.hDeviceWindow = hWnd;

	tPresentParameter.Windowed = eMode;
	tPresentParameter.EnableAutoDepthStencil = TRUE;
	tPresentParameter.AutoDepthStencilFormat = D3DFMT_D24S8;

	tPresentParameter.FullScreen_RefreshRateInHz = D3DPRESENT_RATE_DEFAULT;
	tPresentParameter.PresentationInterval = D3DPRESENT_INTERVAL_IMMEDIATE;

	if (FAILED(m_pSDK->CreateDevice(D3DADAPTER_DEFAULT, D3DDEVTYPE_HAL, hWnd, dwlong, &tPresentParameter, &m_pGraphicDevice)))
	{
		return E_FAIL;
	}

	if (ppGraphicDevice)
	{
		*ppGraphicDevice = m_pGraphicDevice;

		m_pGraphicDevice->AddRef();
	}

	return NOERROR;
}

void CGraphicDevice::free()
{
	unsigned long dwRefCnt = 0;

	if (dwRefCnt = engine::SafeRelease(m_pGraphicDevice))
	{
		MSG_BOX(L"m_pGraphicDevice Release Failed");
	}

	if (dwRefCnt = engine::SafeRelease(m_pSDK))
	{
		MSG_BOX(L"m_pSDK Release Failed");
	}
}
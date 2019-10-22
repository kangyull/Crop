#include "Engine_Include.h"
#include "Component.h"

USING(engine)

CComponent::CComponent(LPDIRECT3DDEVICE9 pGraphicDevice)
	: m_pGraphicDevice(pGraphicDevice)
	, m_bIsClone(false)
{
	m_pGraphicDevice->AddRef();
}

CComponent::CComponent(const CComponent& rhs)
	: m_pGraphicDevice(rhs.m_pGraphicDevice)
	, m_bIsClone(true)
{
	m_pGraphicDevice->AddRef();
}

void CComponent::free()
{
	engine::SafeRelease(m_pGraphicDevice);
}
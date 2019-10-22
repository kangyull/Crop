#pragma once

#include "Base.h"

BEGIN(engine)

class ENGINE_DLL CComponent abstract : public CBase
{
protected:
	explicit CComponent(LPDIRECT3DDEVICE9 pGraphicDevice);
	explicit CComponent(const CComponent& rhs);
	virtual ~CComponent() = default;

public:
	virtual	HRESULT		initialize() = 0;
	virtual HRESULT		update() { return NOERROR; }
	virtual	CComponent*	cloneComponent(void* pArg) = 0;

protected:
	virtual void		free()	override;

protected:
	LPDIRECT3DDEVICE9	m_pGraphicDevice;

	bool	m_bIsClone;
};

END
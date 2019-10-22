#pragma once

#include "Component.h"

BEGIN(engine)

class ENGINE_DLL CBuffer : public CComponent
{
protected:
	explicit CBuffer(LPDIRECT3DDEVICE9 pGraphicDevcie);
	explicit CBuffer(const CBuffer& rhs);
	virtual ~CBuffer();

public:
	virtual HRESULT		initialize()				override;
	virtual CComponent*	cloneComponent(void* pArg)	override;

protected:
	virtual void		free()						override;
};

END
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
	virtual CComponent*	Clone_Component(void* pArg)	override;

protected:
	virtual void		free()						override;
};

END
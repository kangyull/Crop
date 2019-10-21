#pragma once

#include "Base.h"

BEGIN(engine)

class ENGINE_DLL CComponent abstract : public CBase
{
protected:
	explicit CComponent(LPDIRECT3DDEVICE9 pGraphicDevice);
	explicit CComponent(const CComponent& rhs);
	virtual ~CComponent();

public:
	virtual	CComponent*	Clone_Component(void* pArg) = 0;
	virtual void		free()	override;
};

END
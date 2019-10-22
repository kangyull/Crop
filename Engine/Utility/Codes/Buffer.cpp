#include "Engine_Include.h"
#include "Buffer.h"

USING(engine)

CBuffer::CBuffer(LPDIRECT3DDEVICE9 pGraphicDevcie)
	: CComponent(pGraphicDevcie)
{
}

CBuffer::CBuffer(const CBuffer& rhs)
	: CComponent(rhs)
{
}

CBuffer::~CBuffer()
{
}

HRESULT CBuffer::initialize()
{
	return NOERROR;
}

CComponent* CBuffer::cloneComponent(void* pArg)
{
	return nullptr;
}

void CBuffer::free()
{
}
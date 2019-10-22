#pragma once

class _declspec(dllexport) CBase
{
protected:
	explicit CBase() = default;
	virtual ~CBase() = default;

public:
	inline virtual unsigned long AddRef()
	{
		return ++m_dwRefCnt;
	}

	inline unsigned long Release()
	{
		if (0 == m_dwRefCnt)
		{
			free();

			delete this;

			return 0;
		}

		return m_dwRefCnt--;
	}

protected:
	virtual void free() = 0;

private:
	unsigned long m_dwRefCnt = 0;
};
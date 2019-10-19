#pragma once

class CBase
{
private:
	inline explicit CBase()
		: m_dwRefCnt(0)	{}

	virtual ~CBase() = default;

public:
	inline unsigned long addRef()
	{
		return ++m_dwRefCnt;
	}

	inline unsigned long release()
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
	unsigned long m_dwRefCnt;
};
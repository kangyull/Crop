#pragma once

#define BEGIN(name)	namespace name {
#define END			}
#define USING(name)	using namespace name;

#define MSG_BOX(msg)	MessageBox(nullptr, msg, L"error", MB_OK | MB_ICONERROR)

#ifdef ENGINE_EXPORTS
#define ENGINE_DLL _declspec(dllexport)
#else
#define ENGINE_DLL _declspec(dllimport)
#endif

#define DECLARE_SINGLETON(classname)					\
private:												\
	classname(const classname&) = delete;				\
	classname& operator = (const classname&) = delete;	\
public:													\
	static classname* getInstance();					\
	static unsigned long destroyInstance();				\
private:												\
	static classname* m_pInstance;

#define IMPLEMENT_SINGLETON(classname)				\
	classname* classname::m_pInstance = nullptr;	\
	classname* classname::getInstance() {			\
		if (nullptr == m_pInstance) {				\
			m_pInstance = new classname;			\
		}											\
		return m_pInstance;							\
	}												\
	unsigned long classname::destroyInstance() {	\
		unsigned long dwRefCnt = 0;					\
		if (m_pInstance) {							\
			dwRefCnt = m_pInstance->Release();		\
			if (0 == dwRefCnt) {					\
				m_pInstance = nullptr;				\
			}										\
		}											\
		return dwRefCnt;							\
	}
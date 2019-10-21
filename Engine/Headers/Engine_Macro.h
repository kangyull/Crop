#pragma once

#define BEGIN(name)	namespace name {
#define END			}
#define USING(name)	using namespace name;

#ifdef ENGINE_EXPORTS
#define ENGINE_DLL _declspec(dllexport)
#else
#define ENGINE_DLL _declspec(dllimport)
#endif
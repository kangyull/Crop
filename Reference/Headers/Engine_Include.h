#pragma once

#include <d3d9.h>
#include <d3dx9.h>

#include <vector>
#include <list>
#include <map>
#include <string>
#include <algorithm>
#include <functional>

#pragma warning(disable : 4251)

#ifndef DBG_NEW 
#define DBG_NEW new ( _NORMAL_BLOCK , __FILE__ , __LINE__ ) 
#define new DBG_NEW 
#endif  // _DEBUG

#include "Engine_Macro.h"
#include "Engine_Function.h"
#pragma once

template <typename T>
unsigned long SafeRelease(T& instance)
{
	unsigned long dwRef = 0;

	if (instance)
	{
		dwRef = instance->release();

		if (0 == dwRef)
		{
			instance = nullptr;
		}
	}

	return dwRef;
}

template <typename T>
void SafeDelete(T& instance)
{
	if (instance)
	{
		delete instance;
		instance = nullptr;
	}
}

template <typename T>
void SafeDeleteArray(T& instance)
{
	if (instance)
	{
		delete[] instance;
		instance = nullptr;
	}
}
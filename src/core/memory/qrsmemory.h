/***************************************************************************
QRsmemory.h - provide storage with memory pool
------------------
begin                : November 2013
copyright            : (C) 2013 by kassol
email                : kassol dot zx at gmail dot com
***************************************************************************
*                                                                         *
*   This program is free software; you can redistribute it and/or modify  *
*   it under the terms of the GNU General Public License as published by  *
*   the Free Software Foundation; either version 2 of the License, or     *
*   (at your option) any later version.                                   *
*                                                                         *
***************************************************************************/
#include <list>

#ifdef WIN32
	#ifdef QRSMEMORY_EXPORTS
		#define QRSMEMORY_API __declspec(dllexport)
	#else
		#define QRSMEMORY_API __declspec(dllimport)
	#endif
#endif


#ifdef linux
	#ifdef QRSMEMORY_EXPORTS
		#define QRSMEMORY_API
	#else
		#define QRSMEMORY_API
	#endif
#endif





class QRSMEMORY_API QRsMemory
{
private:
	QRsMemory();
	~QRsMemory();

public:
	static void Initialize();
	static void* Malloc(unsigned int nSize);
	static void Free(void** p);
	static void Reset();
private:
	class MemoryNode
	{
	public:
		MemoryNode(void* p, bool bused, unsigned int s)
		{
			pBuf = p; 
			bIsUsed = bused; 
			size = s;
		}
		void* pBuf;
		bool bIsUsed;
		unsigned int size;
	};

private:
	static std::list<MemoryNode> m_listMemoryPool;
};

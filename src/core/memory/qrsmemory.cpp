/***************************************************************************
    QRsmemory.cpp - provide storage with memory pool
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
#include <stdlib.h>

#define QRSMEMORY_EXPORTS

#include "qrsmemory.h"
 
std::list<QRsMemory::MemoryNode> QRsMemory::m_listMemoryPool;
 
 void QRsMemory::Initialize()
 {
	m_listMemoryPool.clear();
 }
 
 void* QRsMemory::Malloc(unsigned int nSize)
 {
	std::list<MemoryNode>::iterator temIte = m_listMemoryPool.begin();
	while(temIte != m_listMemoryPool.end())
	{
		if(temIte->bIsUsed == false && temIte->size*0.5 < nSize)
		{
			temIte->bIsUsed = true;
			return temIte->pBuf;
		}
		++temIte;
	}
	void* p = malloc(nSize);
	MemoryNode mn(p, true, nSize);
	m_listMemoryPool.push_front(mn);
	return p;
 }
 
 void QRsMemory::Free(void* p)
 {
	std::list<MemoryNode>::iterator temIte = m_listMemoryPool.begin();
	while(temIte != m_listMemoryPool.end())
	{
		if(temIte->pBuf == p)
		{
			temIte->bIsUsed = false;
			break;
		}
		++temIte;
	}
 }
 
 void QRsMemory::Reset()
 {
	std::list<MemoryNode>::iterator temIte = m_listMemoryPool.begin();
	while(temIte != m_listMemoryPool.end())
	{
		free(temIte->pBuf);
		++temIte;
	}
	m_listMemoryPool.clear();
 }
 

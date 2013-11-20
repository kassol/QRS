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
 
 #include "qrsmemory.h"
 
 static std::list<QRsMemory::MemoryNode> QRsMemory::m_listMemoryPool;
 
 void QRsMemory::Initialize()
 {
	m_listMemoryPool.clear();
 }
 
 void* QRsMemory::Malloc(long long nSize)
 {
	std::list<MemoryNode>::iterator temIte = m_listMemoryPool.begin();
	while(temIte != m_listMemoryPool.end())
	{
		if(temIte->bIsUsed == false && temIte->size*0.5 < nSize)
		{
			
		}
		++temIte;
	}
	void* p = malloc(nSize);
 }
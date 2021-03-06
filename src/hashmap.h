/*
 * Fermat
 *
 * Copyright (c) 2016-2019, NVIDIA CORPORATION. All rights reserved.
 * 
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *    * Redistributions of source code must retain the above copyright
 *      notice, this list of conditions and the following disclaimer.
 *    * Redistributions in binary form must reproduce the above copyright
 *      notice, this list of conditions and the following disclaimer in the
 *      documentation and/or other materials provided with the distribution.
 *    * Neither the name of the NVIDIA CORPORATION nor the
 *      names of its contributors may be used to endorse or promote products
 *      derived from this software without specific prior written permission.
 * 
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL NVIDIA CORPORATION BE LIABLE FOR ANY
 * DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
 * ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */
#pragma once

#include "buffers.h"

struct DeviceHashTable
{
	void resize(const uint32 N)
	{
		m_keys.alloc(N);
		m_slots.alloc(N);
		m_unique.alloc(N);
		m_size.alloc(1);
	}

	uint64 needed_bytes(const uint32 N) const
	{
		return (sizeof(uint64) * 2 + sizeof(uint32)) * N + sizeof(uint32);
	}

	void clear()
	{
		// initialize the cache size
		m_size.set(0, 0);

		// initialize the cache keys
		cudaMemset(m_keys.ptr(),  0xFFu, m_keys.sizeInBytes());
		cudaMemset(m_slots.ptr(), 0xFFu, m_slots.sizeInBytes());
	}

	uint32 size() const
	{
		return m_size[0];
	}

	DomainBuffer<CUDA_BUFFER, uint64>	m_keys;
	DomainBuffer<CUDA_BUFFER, uint64>	m_unique;
	DomainBuffer<CUDA_BUFFER, uint32>	m_slots;
	DomainBuffer<CUDA_BUFFER, uint32>	m_size;
};

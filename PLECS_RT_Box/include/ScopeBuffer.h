//
//  CircularWriteBuffer.h
//  PLECS HIL
//
//  Created by Oliver Schwartz on 17/03/16.
//  Copyright (c) 2016 Plexim GmbH. All rights reserved.
//

#ifndef _CIRCULARWRITEBUFFER_H_
#define _CIRCULARWRITEBUFFER_H_

#include <string.h>
#include "hw_wrapper.h"

#ifdef __cplusplus
extern "C"
{
#endif

struct ScopeBuffer
{
   float* mBuffer;
   int mMaxScopeBufferSize;
   int mScopeBufferSize;
   int mNumValidElements;
   int mWriteIdx;
   int mIsFull;
};

static inline void initScopeBuffer(struct ScopeBuffer* this, void* aBuffer, int aMaxSize)
{
   this->mBuffer = (float*)aBuffer;
   this->mMaxScopeBufferSize = aMaxSize;
   this->mNumValidElements = 0;
   this->mWriteIdx = 0;
   this->mIsFull = 0;
}

static inline void resetScopeBuffer(struct ScopeBuffer* this)
{
   this->mNumValidElements = 0;
   this->mWriteIdx = 0;
}

static inline void resizeScopeBuffer(struct ScopeBuffer* this, int aSize)
{
   if (aSize > this->mMaxScopeBufferSize)
      aSize = this->mMaxScopeBufferSize;
   this->mScopeBufferSize = aSize;
   resetScopeBuffer(this);
}

static inline void addToScopeBuffer(struct ScopeBuffer* this, float aValue)
{
   int idx = this->mWriteIdx;
   *(this->mBuffer + idx) = aValue;
   if (idx + 1 == this->mScopeBufferSize)
      this->mWriteIdx = 0;
   else
      this->mWriteIdx = idx + 1;
   if (this->mNumValidElements < this->mScopeBufferSize) this->mNumValidElements++;
}

static inline int getScopeBufferNumValidElements(const struct ScopeBuffer* this) { return this->mNumValidElements; }

static inline int getScopeBufferSize(const struct ScopeBuffer* this) { return this->mScopeBufferSize; }

static inline int getScopeBufferOffset(const struct ScopeBuffer* this) { return this->mWriteIdx * sizeof(float); }

static inline int isScopeBufferFull(const struct ScopeBuffer* this) { return this->mIsFull; }

static inline void setScopeBufferFull(struct ScopeBuffer* this, int aValue) { this->mIsFull = aValue; }

static inline void setScopeBufferNumValidElements(struct ScopeBuffer* this, int aNumElements)
{
   if (aNumElements <= this->mScopeBufferSize)
      this->mNumValidElements = aNumElements;
}

#ifdef __cplusplus
}
#endif

#endif

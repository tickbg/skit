/*
 * SystemLib.cpp
 *
 * Copyright (C) 2013  Emil Penchev, Bulgaria
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>
 *
 *  Created on: Aug 15, 2013
 *      Author: emo
 */

#include <cstdio>
#include "system/SystemLib.h"

extern "C" {
#include <dlfcn.h>
}

SystemLib::SystemLib() : mLibHandler(NULL)
{}

void SystemLib::LoadFile(const char* filePath)
{
    if (filePath)
    {
        mLibHandler = dlopen(filePath, RTLD_LAZY);
        if (NULL == mLibHandler)
        {
            ErrorCode err(errno);
            throw SystemException(err);
        }
    }
}


SystemLib::~SystemLib()
{
    if (NULL != mLibHandler)
    {
        dlclose(mLibHandler);
    }
}

void* SystemLib::GetSymbol(const char* inSymbolName, ErrorCode& outErr)
{
    char* errorStr = NULL;

    if (inSymbolName)
    {
        if (mLibHandler)
        {
            void* dlSymbol = dlsym(mLibHandler, inSymbolName);
            if ((errorStr = dlerror()) != NULL)
            {
                /* custom error */
                outErr.SetValue(-1);
                outErr.SetMessage(errorStr);
                return NULL;
            }
            return dlSymbol;
        }
        outErr.SetValue(EFAULT);
    }
    outErr.SetValue(EINVAL);

    return NULL;
}
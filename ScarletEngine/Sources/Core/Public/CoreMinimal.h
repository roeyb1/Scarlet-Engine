#pragma once

/** This is where we put core utility types which would be used both internally and externally */

#include "CorePCH.h"
#include "CoreDefines.h"
#include "CoreUtils.h"
#include "CoreSTL.h"
#include "Logger.h"
#include "Memory/Memory.h"

namespace ScarletEngine
{
    inline const glm::vec3 WorldRight = glm::vec3(1.f, 0.f, 0.f);
    inline const glm::vec3 WorldUp = glm::vec3(0.f, 1.f, 0.f);
    inline const glm::vec3 WorldForward = glm::vec3(0.f, 0.f, 1.f);
}
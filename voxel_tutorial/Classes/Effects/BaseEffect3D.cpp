//
//  BaseEffect3D.cpp
//  Geometry-Wars
//
//  Created by wang haibo on 15/9/13.
//
//

#include "BaseEffect3D.h"
USING_NS_CC;

BaseEffect3D::BaseEffect3D()
: m_pGLprogramstate(nullptr),m_bDirty(false),m_bSpriteSelfDraw(false)
{
}

BaseEffect3D::~BaseEffect3D()
{
    CC_SAFE_RELEASE_NULL(m_pGLprogramstate);
}
bool BaseEffect3D::initGLProgramState(const std::string& vertFilename, const std::string& fragFilename)
{
    CCASSERT(!m_strProgramName.empty(), "Program name must not empty!");

    auto glprogram = cocos2d::GLProgramCache::getInstance()->getGLProgram(m_strProgramName);
    if(!glprogram)
    {
        auto vertexFullPath = FileUtils::getInstance()->fullPathForFilename(vertFilename);
        auto fragmentFullPath = FileUtils::getInstance()->fullPathForFilename(fragFilename);
        auto vertSource = FileUtils::getInstance()->getStringFromFile(vertexFullPath);
        auto fragSource = FileUtils::getInstance()->getStringFromFile(fragmentFullPath);
        
        glprogram = cocos2d::GLProgram::createWithByteArrays(vertSource.c_str(), fragSource.c_str());
        cocos2d::GLProgramCache::getInstance()->addGLProgram(glprogram, m_strProgramName);
    }
    
    m_pGLprogramstate = GLProgramState::getOrCreateWithGLProgram(glprogram);
    m_pGLprogramstate->retain();
    
    return m_pGLprogramstate != nullptr;
}
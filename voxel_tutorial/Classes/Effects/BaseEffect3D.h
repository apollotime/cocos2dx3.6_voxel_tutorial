//
//  BaseEffect3D.h
//  Voxel_Tutorial
//
//  Created by wang haibo on 15/9/13.
//
//

#ifndef __Voxel_Tutorial__BaseEffect3D__
#define __Voxel_Tutorial__BaseEffect3D__

#include "cocos2d.h"
class EffectSprite3D;
class BaseEffect3D : public cocos2d::Ref
{
public:
    cocos2d::GLProgramState* getGLProgramState() const { return m_pGLprogramstate; }
    bool isUseSpriteSelfDraw() const { return m_bSpriteSelfDraw; }
protected:
    bool initGLProgramState(const std::string& vertFilename, const std::string& fragFilename);
    BaseEffect3D();
    virtual ~BaseEffect3D();
public:
    virtual void drawWithSprite3D(EffectSprite3D* sprite, const cocos2d::Mat4 &transform) = 0;
protected:
    cocos2d::GLProgramState*    m_pGLprogramstate;
    bool                        m_bDirty;
    bool                        m_bSpriteSelfDraw;
    std::string                 m_strProgramName;
};

#endif /* defined(__Voxel_Tutorial__BaseEffect3D__) */

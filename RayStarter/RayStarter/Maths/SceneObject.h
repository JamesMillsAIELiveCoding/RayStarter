#pragma once

#include <functional>
#include <list>

#include "Mat3.h"

using std::function;
using std::list;

class SceneObject
{
public:
    SceneObject();
    virtual ~SceneObject();

    void Start();
    void Update(float _dt);
    void Draw();
    void OnDestroy();

    void AddChild(SceneObject* _child);
    void RemoveChild(SceneObject* _child);
    void SetParent(SceneObject* _newParent);
    
    Mat3 GlobalTransform();
    Vec2 Position();
    Vec2 Scale();
    float Rotation();

    SceneObject* parent;
    list<SceneObject*> children;
    
    bool isAlive;
    Mat3 transform;

protected:
    virtual void OnStart() {}
    virtual void OnUpdate(float _dt) {}
    virtual void OnDraw() {}
    virtual void OnCleanup() {}

private:
    list<function<void()>> m_updateChildrenFunctions;
    
};

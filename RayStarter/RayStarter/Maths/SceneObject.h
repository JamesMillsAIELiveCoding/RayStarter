#pragma once

#include <GameObjects/IGameObject.h>

#include <functional>
#include <list>

#include "Mat3.h"

using std::function;
using std::list;

class SceneObject : public IGameObject
{
public:
    SceneObject();
    ~SceneObject() override;

    void Start() final;
    void Update(float _dt) final;
    void Draw() final;
    void OnDestroy() final;

    void AddChild(SceneObject* _child);
    void RemoveChild(SceneObject* _child);
    void SetParent(SceneObject* _newParent);
    
    Mat3 GlobalTransform();

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

#include "SceneObject.h"

SceneObject::SceneObject() : parent(nullptr), isAlive(true)
{
}

SceneObject::~SceneObject() = default;

void SceneObject::Start()
{
    OnStart();
}

void SceneObject::Update(float _dt)
{
    OnUpdate(_dt);

    position = transform.GetTranslation();

    if(!isAlive)
        SetParent(nullptr);

    for(auto& func : m_updateChildrenFunctions)
        func();

    m_updateChildrenFunctions.clear();

    for(const auto& child : children)
        child->Update(_dt);
}

void SceneObject::Draw()
{
    OnDraw();
    
    for(const auto& child : children)
        child->Draw();
}

void SceneObject::OnDestroy()
{
    OnCleanup();
}

void SceneObject::AddChild(SceneObject* _child)
{
    m_updateChildrenFunctions.emplace_back([&]
    {
        if(_child->parent != nullptr)
            _child->parent->RemoveChild(_child);

        _child->parent = this;
        children.emplace_back(_child);
    });
}

void SceneObject::RemoveChild(SceneObject* _child)
{
    m_updateChildrenFunctions.emplace_back([&]
    {
        if(_child->parent == this)
        {
            _child->parent = nullptr;
            children.remove(_child);
        }
    });
}

void SceneObject::SetParent(SceneObject* _newParent)
{
    if(_newParent == nullptr)
    {
        if(parent != nullptr)
            parent->RemoveChild(this);
    }
    else
    {
        _newParent->AddChild(this);
    }
}

Mat3 SceneObject::GlobalTransform()
{
    if(parent == nullptr)
        return transform;

    return transform * parent->transform;
}
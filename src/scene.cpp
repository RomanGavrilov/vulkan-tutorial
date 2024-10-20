#include "scene.hpp"

Object::Object(const std::vector<Vertex> &&vertices)
    : mVerticies(std::move(vertices))
{
}

const std::vector<Vertex> &Object::GetVertices() const
{
    return mVerticies;
}

std::unique_ptr<Object> ObjectFactory::CreateObject(const std::vector<Vertex> &&vertices)
{
    return std::make_unique<Object>(std::move(vertices));
}

Scene::Scene()
{
    mObject = ObjectFactory::CreateObject(std::move(VERTICES));
}

const Object &Scene::GetObject() const
{
    return *mObject;
}

std::unique_ptr<Scene> SceneFactory::CreateScene()
{
    return std::make_unique<Scene>();
}

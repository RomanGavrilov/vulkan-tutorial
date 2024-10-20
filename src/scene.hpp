#pragma once
#include <vector>
#include <memory>
#include <glm/glm.hpp>
#include <vector>
#include <vulkan/vulkan.hpp>

struct Vertex
{
    glm::vec2 pos;
    glm::vec3 color;

    static const VkVertexInputBindingDescription GetBindingDescription()
    {
        VkVertexInputBindingDescription bindingDescription = {};
        bindingDescription.binding = 0;
        bindingDescription.stride = sizeof(Vertex);
        bindingDescription.inputRate = VK_VERTEX_INPUT_RATE_VERTEX;

        return bindingDescription;
    }

    static const std::array<VkVertexInputAttributeDescription, 2> GetAttributeDescriptions()
    {
        std::array<VkVertexInputAttributeDescription, 2> attributeDescriptions = {};

        attributeDescriptions[0].binding = 0;
        attributeDescriptions[0].location = 0;
        attributeDescriptions[0].format = VK_FORMAT_R32G32_SFLOAT;
        attributeDescriptions[0].offset = offsetof(Vertex, pos);

        attributeDescriptions[1].binding = 0;
        attributeDescriptions[1].location = 1;
        attributeDescriptions[1].format = VK_FORMAT_R32G32B32_SFLOAT;
        attributeDescriptions[1].offset = offsetof(Vertex, color);

        return attributeDescriptions;
    }
};

const std::vector<Vertex> VERTICES = {
    {{-0.5f, -0.5f}, {1.0f, 0.0f, 0.0f}},
    {{0.5f, -0.5f}, {0.0f, 1.0f, 0.0f}},
    {{0.5f, 0.5f}, {0.0f, 0.0f, 1.0f}},
    {{-0.5f, 0.5f}, {1.0f, 1.0f, 1.0f}}};

const std::vector<uint16_t> INDICIES = {
    0, 1, 2, 2, 3, 0};

class Object
{ 
    Object &operator=(const Object &) = delete;
    

public:
    const std::vector<Vertex> &GetVertices() const;
    Object(const std::vector<Vertex> &&vertices);

private:
    std::vector<Vertex> mVerticies;
};

class Scene
{
public:
    Scene();
    const Object& Scene::GetObject() const;

private:
    std::unique_ptr<Object> mObject;
};

class SceneFactory
{
public:
    static std::unique_ptr<Scene> CreateScene();
};

class ObjectFactory
{
public:
    static std::unique_ptr<Object> CreateObject(const std::vector<Vertex> &&vertices);
};

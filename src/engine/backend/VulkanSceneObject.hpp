#pragma once

#include "VulkanModel.hpp"

#include <glm/ext/matrix_float2x2.hpp>
#include <memory>

namespace Vulkan {

struct RigidBody2dComponent {
  glm::vec2 velocity;
  float mass{1.0f};
};

struct Transform2dComponent {
    glm::vec2 translation{};
    glm::vec2 scale{1.f, 1.f};
    float rotation;

    glm::mat2 mat2() {
        const float s = glm::sin(rotation);
        const float c = glm::cos(rotation);
        glm::mat2 rotMatrix{{c, s}, {-s, c}};

        glm::mat2 scaleMat{{scale.x, .0f}, {.0f, scale.y}};
        return rotMatrix * scaleMat;
    }
};

class SceneObject {
public:
    using id_t = unsigned int;

    static SceneObject createSceneObject() {
        static id_t currentId = 0;
        return SceneObject{currentId++};
    }

    SceneObject(const SceneObject &) = delete;
    SceneObject &operator=(const SceneObject &) = delete;
    SceneObject(SceneObject &&) = default;
    SceneObject &operator=(SceneObject &&) = default;

    id_t getId() const { return id; }

    std::shared_ptr<Model> model{};
    glm::vec3 color{};
    Transform2dComponent transform2d{};
    RigidBody2dComponent rigidBody2d{};

private:
    SceneObject(id_t objId): id{objId} {};

    id_t id;
};

}

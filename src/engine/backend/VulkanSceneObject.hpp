#pragma once

#include "VulkanModel.hpp"

#include <glm/ext/matrix_transform.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/ext/matrix_float2x2.hpp>
#include <memory>

namespace Vulkan {

struct TransformComponent {
    glm::vec3 translation{};
    float scale = 1.f;
    glm::vec3 rotation{};

    glm::mat4 mat4();
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
    TransformComponent transform{};

private:
    SceneObject(id_t objId): id{objId} {};

    id_t id;
};

}

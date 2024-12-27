#include <glm/mat4x4.hpp>

struct TransformationUBO {
    alignas(16) glm::mat4 model;
    alignas(16) glm::mat4 view;
    alignas(16) glm::mat4 proj;
};

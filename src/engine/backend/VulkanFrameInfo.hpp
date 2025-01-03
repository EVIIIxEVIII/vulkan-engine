#pragma once

#include "VulkanCamera.hpp"
#include "VulkanSceneObject.hpp"

#include <vulkan/vulkan.h>

namespace Vulkan {

struct FrameInfo {
    int framIndex;
    float frameTime;
    VkCommandBuffer commandBuffer;
    Camera &camera;
    VkDescriptorSet globalDescriptorSet;
    SceneObject::Map &sceneObjects;
};

}

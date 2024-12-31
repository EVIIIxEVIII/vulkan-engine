#pragma once

#include <vector>
#include <memory>
#include <vulkan/vulkan_core.h>

#include "VulkanPipeline.hpp"
#include "VulkanDevice.hpp"
#include "VulkanSceneObject.hpp"
#include "VulkanCamera.hpp"

namespace Vulkan {

class SimpleRenderSystem {

public:
    SimpleRenderSystem(Device& device, VkRenderPass renderPass);
    ~SimpleRenderSystem();

    SimpleRenderSystem(const SimpleRenderSystem&) = delete;
    SimpleRenderSystem operator=(const SimpleRenderSystem&) = delete;

    void renderSceneObjects(
        VkCommandBuffer commandBuffer,
        std::vector<SceneObject> &sceneObjects,
        const Camera& camera
    );

private:
    void createPipelineLayout();
    void createPipeline(VkRenderPass renderPass);

    Device& device;

    std::unique_ptr<Pipeline> pipeline;
    VkPipelineLayout pipelineLayout;
};

}


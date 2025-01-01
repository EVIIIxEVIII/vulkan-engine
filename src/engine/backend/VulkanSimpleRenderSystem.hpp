#pragma once

#include <vector>
#include <memory>
#include <vulkan/vulkan_core.h>

#include "VulkanPipeline.hpp"
#include "VulkanDevice.hpp"
#include "VulkanSceneObject.hpp"
#include "VulkanCamera.hpp"
#include "VulkanFrameInfo.hpp"

namespace Vulkan {

class SimpleRenderSystem {

public:
    SimpleRenderSystem(Device& device, VkRenderPass renderPass, VkDescriptorSetLayout globalSetLayout);
    ~SimpleRenderSystem();

    SimpleRenderSystem(const SimpleRenderSystem&) = delete;
    SimpleRenderSystem operator=(const SimpleRenderSystem&) = delete;

    void renderSceneObjects(FrameInfo &frameInfo);

private:
    void createPipelineLayout(VkDescriptorSetLayout globalSetLayout);
    void createPipeline(VkRenderPass renderPass);

    Device& device;

    std::unique_ptr<Pipeline> pipeline;
    VkPipelineLayout pipelineLayout;
};

}


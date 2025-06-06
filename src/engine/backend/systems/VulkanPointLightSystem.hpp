#pragma once

#include <memory>
#include <vulkan/vulkan_core.h>

#include "../VulkanPipeline.hpp"
#include "../VulkanDevice.hpp"
#include "../VulkanFrameInfo.hpp"

namespace Vulkan {

class PointLightSystem {

public:
    PointLightSystem(Device& device, VkRenderPass renderPass, VkDescriptorSetLayout globalSetLayout);
    ~PointLightSystem();

    PointLightSystem(const PointLightSystem&) = delete;
    PointLightSystem operator=(const PointLightSystem&) = delete;

    void update(FrameInfo &frameInfo, GlobalUbo &ubo);
    void render(FrameInfo &frameInfo);

private:
    void createPipelineLayout(VkDescriptorSetLayout globalSetLayout);
    void createPipeline(VkRenderPass renderPass);

    Device& device;

    std::unique_ptr<Pipeline> pipeline;
    VkPipelineLayout pipelineLayout;
};

}


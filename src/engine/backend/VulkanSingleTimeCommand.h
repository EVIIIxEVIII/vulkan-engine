#pragma once

#include <vulkan/vulkan.h>
#include <vector>
#include <vulkan/vulkan_core.h>

class VulkanContext;
class VulkanSwapChain;

class VulkanSingleTimeCommand {
public:
    void init(VulkanContext& context, uint32_t MAX_FRAMES_IN_FLIGHT);
    void cleanup(VulkanContext& context);

    VkCommandBuffer beginSingleTimeCommands(VulkanContext& context);
    void            endSingleTimeCommands(VulkanContext& context, VkCommandBuffer commandBuffer);

    VkCommandPool                 getCommandPool()    { return m_commandPool; }
    const std::vector<VkCommandBuffer>& getCommandBuffers() const { return m_commandBuffers; }

private:
    VkCommandPool m_commandPool = VK_NULL_HANDLE;
    std::vector<VkCommandBuffer> m_commandBuffers;

    void createCommandPool(VulkanContext& context);
    void createCommandBuffers(VulkanContext& context, uint32_t MAX_FRAMES_IN_FLIGHT);
};

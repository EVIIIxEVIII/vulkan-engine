#pragma once

#include <vulkan/vulkan.h>
#include <vector>
#include <vulkan/vulkan_core.h>

namespace Vulkan {

class Context;
class SwapChain;

class SingleTimeCommand {

public:
    void init(Context& context, uint32_t MAX_FRAMES_IN_FLIGHT);
    void cleanup(Context& context);

    VkCommandBuffer beginSingleTimeCommands(Context& context);
    void            endSingleTimeCommands(Context& context, VkCommandBuffer commandBuffer);

    VkCommandPool                       getCommandPool()    { return m_commandPool; }
    const std::vector<VkCommandBuffer>& getCommandBuffers() const { return m_commandBuffers; }

private:
    VkCommandPool m_commandPool = VK_NULL_HANDLE;
    std::vector<VkCommandBuffer> m_commandBuffers;

    void createCommandPool(Context& context);
    void createCommandBuffers(Context& context, uint32_t MAX_FRAMES_IN_FLIGHT);
};

}

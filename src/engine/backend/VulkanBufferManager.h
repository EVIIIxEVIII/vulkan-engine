#pragma once

#include <cstdint>
#include <vulkan/vulkan_core.h>

class VulkanContext;
class VulkanSingleTimeCommand;

class VulkanBufferManager {
public:
    VulkanBufferManager(
        VulkanContext& context,
        VulkanSingleTimeCommand& singleTimeCommand
    ):
        m_context(context),
        m_singleTimeCommand(singleTimeCommand)
    {}

    void createBuffer(
        VkDeviceSize size,
        VkBufferUsageFlags usage,
        VkMemoryPropertyFlags properties,
        VkBuffer& buffer,
        VkDeviceMemory& bufferMemory
    );

    uint32_t findMemoryType(uint32_t typeFilter, VkMemoryPropertyFlags properties);
    void copyBuffer(VkBuffer srcBuffer, VkBuffer dstBuffer, VkDeviceSize size);
private:
    VulkanContext& m_context;
    VulkanSingleTimeCommand& m_singleTimeCommand;
};

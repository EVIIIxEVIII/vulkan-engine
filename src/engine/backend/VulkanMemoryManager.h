#pragma once

#include <cstdint>
#include <vulkan/vulkan_core.h>
class VulkanContext;

class VulkanMemoryManager {
public:
   VulkanMemoryManager();
   ~VulkanMemoryManager();

    void createBuffer(
        VulkanContext& context, VkDeviceSize size,
        VkBufferUsageFlags usage,
        VkMemoryPropertyFlags properties,
        VkBuffer& buffer,
        VkDeviceMemory& bufferMemory
    );

    uint32_t findMemoryType(VulkanContext& context, uint32_t typeFilter, VkMemoryPropertyFlags properties);
};

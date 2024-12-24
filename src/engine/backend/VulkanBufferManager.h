#pragma once

#include <cstdint>
#include <vulkan/vulkan_core.h>

namespace Vulkan {

class SingleTimeCommand;
class Context;

class BufferManager {
public:
    BufferManager(
        Vulkan::Context& context,
        Vulkan::SingleTimeCommand& singleTimeCommand
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
    Vulkan::Context& m_context;
    Vulkan::SingleTimeCommand& m_singleTimeCommand;
};


}

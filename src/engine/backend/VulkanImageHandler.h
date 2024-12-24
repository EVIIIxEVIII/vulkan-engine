#pragma once

#include <vulkan/vulkan.h>
#include <vulkan/vulkan_core.h>

namespace Vulkan {

class Context;
class BufferManager;
class SingleTimeCommand;

struct ImageProperties {
    uint32_t width;
    uint32_t height;
    uint32_t mipLevels;
    VkSampleCountFlagBits numSamples;
    VkFormat format;
    VkImageTiling tiling;
    VkImageUsageFlags usage;
    VkMemoryPropertyFlags memoryProperties;
};

class ImageHandler {
public:
    ImageHandler(Context& context, SingleTimeCommand& singleTimeCommand, BufferManager& bufferManager):
        m_context(context),
        m_singleTimeCommand(singleTimeCommand),
        m_bufferManager(bufferManager)
    {};

    void createImage(ImageProperties properties, VkImage& image, VkDeviceMemory& imageMemory);
    VkImageView createImageView(VkImage image, VkFormat format, VkImageAspectFlags aspectFlags, uint32_t mipLevels);
    void transitionImageLayout(VkImage image, VkFormat format, VkImageLayout oldLayout, VkImageLayout newLayout, uint32_t mipLevels);
    bool hasStencilComponent(VkFormat format);
    void copyBufferToImage(VkBuffer buffer, VkImage image, uint32_t width, uint32_t height);

private:
    Context& m_context;
    SingleTimeCommand& m_singleTimeCommand;
    BufferManager& m_bufferManager;
};

}

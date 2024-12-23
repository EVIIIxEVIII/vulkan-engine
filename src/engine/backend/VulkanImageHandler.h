#pragma once

#include <vulkan/vulkan.h>
#include <vulkan/vulkan_core.h>

class VulkanContext;
class VulkanBufferManager;
class VulkanSingleTimeCommand;

struct ImageProperties {
    uint32_t width;
    uint32_t height;
    uint32_t mipLevels;
    VkSampleCountFlagBits numSamples;
    VkFormat format;
    VkImageTiling tiling;
    VkImageUsageFlags usage;
    VkMemoryPropertyFlags properties;
};

class VulkanImageHandler {
public:
    VulkanImageHandler(VulkanContext& context, VulkanSingleTimeCommand& singleTimeCommand, VulkanBufferManager& bufferManager):
        m_context(context),
        m_singleTimeCommand(singleTimeCommand),
        m_bufferManager(bufferManager)
    {};

    void createImage(ImageProperties properties, VkImage& image, VkDeviceMemory& imageMemory);
    VkImageView createImageView(VkImage image, VkFormat format, VkImageAspectFlags aspectFlags, uint32_t mipLevels);
    void transitionImageLayout(VkImage image, VkFormat format, VkImageLayout oldLayout, VkImageLayout newLayout, uint32_t mipLevels);
    bool hasStencilComponent(VkFormat format);

private:
    VulkanContext& m_context;
    VulkanSingleTimeCommand& m_singleTimeCommand;
    VulkanBufferManager& m_bufferManager;
};

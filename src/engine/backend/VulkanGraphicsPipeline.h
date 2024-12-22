#pragma once

#include <vulkan/vulkan.h>
#include <vector>
#include <string>
#include "VulkanDescriptors.h"
#include "VulkanSwapChain.h"
#include <glm/mat4x4.hpp>
#include <vulkan/vulkan_core.h>

class VulkanContext;
class Window;

class VulkanGraphicsPipeline {

public:
    VulkanGraphicsPipeline();
    ~VulkanGraphicsPipeline();

    void init(VulkanContext& context,  Window& window, VulkanSwapChain& swapChain, VulkanDescriptors& descriptors);
    void cleanup(VulkanContext& context);

    VkFormat findDepthFormat(VulkanContext& context);

    VkRenderPass            getRenderPass()             { return m_renderPass; }
    VkPipeline              getGraphicsPipeline()       { return m_graphicsPipeline; }
    VkPipelineLayout        getGraphicsPipelineLayout() { return m_pipelineLayout; }

private:
    void createRenderPass(VulkanContext& context, VulkanSwapChain& swapChain);
    void createGraphicsPipeline(VulkanContext& context, VulkanSwapChain& swapChain, VulkanDescriptors& descriptors);

    VkShaderModule createShaderModule(VulkanContext& context, const std::vector<char>& code);
    VkFormat findSupportedFormat(VulkanContext& context, const std::vector<VkFormat>& candidates, VkImageTiling tiling, VkFormatFeatureFlags features);
    static std::vector<char> readFile(const std::string& filename);

private:
    VkRenderPass                    m_renderPass = VK_NULL_HANDLE;
    VkPipelineLayout                m_pipelineLayout = VK_NULL_HANDLE;
    VkPipeline                      m_graphicsPipeline = VK_NULL_HANDLE;
};

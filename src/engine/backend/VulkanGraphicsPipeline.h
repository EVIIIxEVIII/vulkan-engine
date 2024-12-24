#pragma once

#include <vulkan/vulkan.h>
#include <vector>
#include <string>
#include <glm/mat4x4.hpp>
#include <vulkan/vulkan_core.h>

namespace Vulkan {

class Context;
class Window;
class Descriptors;
class SwapChain;

class GraphicsPipeline {

public:
    GraphicsPipeline();
    ~GraphicsPipeline();

    void init(Context& context,  Window& window, SwapChain& swapChain, Descriptors& descriptors);
    void cleanup(Context& context);

    VkFormat findDepthFormat(Context& context);

    VkRenderPass            getRenderPass()             { return m_renderPass; }
    VkPipeline              getGraphicsPipeline()       { return m_graphicsPipeline; }
    VkPipelineLayout        getGraphicsPipelineLayout() { return m_pipelineLayout; }

private:
    void createRenderPass(Context& context, SwapChain& swapChain);
    void createGraphicsPipeline(Context& context, SwapChain& swapChain, Descriptors& descriptors);

    VkShaderModule createShaderModule(Context& context, const std::vector<char>& code);
    VkFormat findSupportedFormat(Context& context, const std::vector<VkFormat>& candidates, VkImageTiling tiling, VkFormatFeatureFlags features);
    static std::vector<char> readFile(const std::string& filename);

private:
    VkRenderPass                    m_renderPass = VK_NULL_HANDLE;
    VkPipelineLayout                m_pipelineLayout = VK_NULL_HANDLE;
    VkPipeline                      m_graphicsPipeline = VK_NULL_HANDLE;
};

}

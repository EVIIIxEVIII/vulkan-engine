#pragma once

#include "VulkanDevice.hpp"

#include <string>
#include <vector>
#include <vulkan/vulkan_core.h>

namespace Vulkan {

struct PipelineConfigInfo {
    VkViewport viewport;
    VkRect2D scissor;
    VkPipelineInputAssemblyStateCreateInfo inputAssemblyInfo;
    VkPipelineRasterizationStateCreateInfo rasterizationInfo;
    VkPipelineMultisampleStateCreateInfo multisampleInfo;
    VkPipelineColorBlendAttachmentState colorBlendAttachment;
    VkPipelineColorBlendStateCreateInfo colorBlendInfo;
    VkPipelineDepthStencilStateCreateInfo depthStencilInfo;
    VkPipelineLayout pipelineLayout = nullptr;
    VkRenderPass renderPass = nullptr;
    uint32_t subpass = 0;
};

class Pipeline {

public:
    Pipeline(
        Device &device,
        const std::string& vertFilepath,
        const std::string& fragFilepath,
        const PipelineConfigInfo& configInfo
    );

    ~Pipeline();
    Pipeline(const Pipeline&) = delete;
    void operator=(const Pipeline&) = delete;

    void bind(VkCommandBuffer commandBuffer);
    static PipelineConfigInfo defaultPipelineConfigInfo(uint32_t width, uint32_t height);

private:
    static std::vector<char> readFile(const std::string& filename);
    void createPipeline(
        const std::string& vertFilepath,
        const std::string& fragFilepath,
        const PipelineConfigInfo& configInfo
    );

    void createShaderModule(const std::vector<char>& code, VkShaderModule *shaderModule);

    Device& device;
    VkPipeline pipeline;
    VkShaderModule vertShaderModule;
    VkShaderModule fragShaderModule;
};

}

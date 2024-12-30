#include "VulkanSimpleRenderSystem.hpp"

#include "VulkanPipeline.hpp"
#include "VulkanSceneObject.hpp"

#include <memory>
#include <array>
#include <stdexcept>
#include <vulkan/vulkan_core.h>
#include <glm/gtc/constants.hpp>

namespace Vulkan {

struct SimplePushConstantData {
    alignas(16) glm::mat4 transform{1.f};
    alignas(16) glm::vec3 color;
};

SimpleRenderSystem::SimpleRenderSystem(Device& device, VkRenderPass renderPass):
    device(device)
{
    createPipelineLayout();
    createPipeline(renderPass);
}

SimpleRenderSystem::~SimpleRenderSystem() {
    vkDestroyPipelineLayout(device.device(), pipelineLayout, nullptr);
}

void SimpleRenderSystem::createPipelineLayout() {
    VkPushConstantRange pushConstantRange{};
    pushConstantRange.stageFlags = VK_SHADER_STAGE_VERTEX_BIT | VK_SHADER_STAGE_FRAGMENT_BIT;
    pushConstantRange.offset = 0;
    pushConstantRange.size = sizeof(SimplePushConstantData);

    VkPipelineLayoutCreateInfo pipelineLayoutCreateInfo{};
    pipelineLayoutCreateInfo.sType = VK_STRUCTURE_TYPE_PIPELINE_LAYOUT_CREATE_INFO;
    pipelineLayoutCreateInfo.setLayoutCount = 0;
    pipelineLayoutCreateInfo.pSetLayouts = nullptr;
    pipelineLayoutCreateInfo.pushConstantRangeCount = 1;
    pipelineLayoutCreateInfo.pPushConstantRanges = &pushConstantRange;
    if (vkCreatePipelineLayout(device.device(), &pipelineLayoutCreateInfo, nullptr, &pipelineLayout) != VK_SUCCESS) {
        throw std::runtime_error("failed to create a pipeline layout");
    }
}

void SimpleRenderSystem::createPipeline(VkRenderPass renderPass) {
    assert(pipelineLayout != nullptr && "Cannot create pipeline before pipeline layout");

    PipelineConfigInfo pipelineConfig{};
    Pipeline::defaultPipelineConfigInfo(pipelineConfig);
    pipelineConfig.renderPass = renderPass;
    pipelineConfig.pipelineLayout = pipelineLayout;
    pipeline = std::make_unique<Pipeline>(
        device,
        "src/shaders/vert.spv",
        "src/shaders/frag.spv",
        pipelineConfig
    );
}

void SimpleRenderSystem::renderSceneObjects(VkCommandBuffer commandBuffer, std::vector<SceneObject> &sceneObjects) {
    pipeline->bind(commandBuffer);

    for (auto& obj: sceneObjects) {
        obj.transform.rotation.y = glm::mod(obj.transform.rotation.y + 0.01f, glm::two_pi<float>());
        obj.transform.rotation.x = glm::mod(obj.transform.rotation.x + 0.005f, glm::two_pi<float>());

        SimplePushConstantData push{};
        push.color = obj.color;
        push.transform = obj.transform.mat4();

        vkCmdPushConstants(
            commandBuffer,
            pipelineLayout,
            VK_SHADER_STAGE_VERTEX_BIT | VK_SHADER_STAGE_FRAGMENT_BIT,
            0,
            sizeof(SimplePushConstantData),
            &push
        );

        obj.model->bind(commandBuffer);
        obj.model->draw(commandBuffer);
    }
}


}

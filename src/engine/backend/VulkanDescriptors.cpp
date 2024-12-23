#include "VulkanDescriptors.h"
#include "VulkanContext.h"
#include "VulkanSingleTimeCommand.h"

#include <stdexcept>
#include <array>
#include <vulkan/vulkan_core.h>

Vulkan::Descriptors::Descriptors() {}
Vulkan::Descriptors::~Descriptors() {}

void Vulkan::Descriptors::init(Context& context, uint32_t MAX_FRAMES_IN_FLIGHT) {
    createDescriptorSetLayout(context);
    createDescriptorPool(context, MAX_FRAMES_IN_FLIGHT);
    // createDescriptorSets(context, singleTimeCommand, MAX_FRAMES_IN_FLIGHT);
}

void Vulkan::Descriptors::cleanup(Context& context) {
    vkDestroyDescriptorSetLayout(context.getDevice(), m_descriptorSetLayout, nullptr);
    vkDestroyDescriptorPool(context.getDevice(), m_descriptorPool, nullptr);
}

void Vulkan::Descriptors::createDescriptorSetLayout(Context& context) {
    VkDescriptorSetLayoutBinding uboLayoutBinding{};
    uboLayoutBinding.binding = 0;
    uboLayoutBinding.descriptorType = VK_DESCRIPTOR_TYPE_UNIFORM_BUFFER;
    uboLayoutBinding.descriptorCount = 1;
    uboLayoutBinding.stageFlags = VK_SHADER_STAGE_VERTEX_BIT;
    uboLayoutBinding.pImmutableSamplers = nullptr;

    VkDescriptorSetLayoutBinding samplerLayoutBinding{};
    samplerLayoutBinding.binding = 1;
    samplerLayoutBinding.descriptorCount = 1;
    samplerLayoutBinding.descriptorType = VK_DESCRIPTOR_TYPE_COMBINED_IMAGE_SAMPLER;
    samplerLayoutBinding.pImmutableSamplers = nullptr;
    samplerLayoutBinding.stageFlags = VK_SHADER_STAGE_FRAGMENT_BIT;

    std::array<VkDescriptorSetLayoutBinding, 2> bindings = {uboLayoutBinding, samplerLayoutBinding};

    VkDescriptorSetLayoutCreateInfo layoutInfo{};
    layoutInfo.sType = VK_STRUCTURE_TYPE_DESCRIPTOR_SET_LAYOUT_CREATE_INFO;
    layoutInfo.bindingCount = static_cast<uint32_t>(bindings.size());
    layoutInfo.pBindings = bindings.data();

    if (vkCreateDescriptorSetLayout(context.getDevice(), &layoutInfo, nullptr, &m_descriptorSetLayout) != VK_SUCCESS) {
        throw std::runtime_error("failed to crate descriptor set layout!");
    }
}

void Vulkan::Descriptors::createDescriptorPool(Context& context, uint32_t MAX_FRAMES_IN_FLIGHT) {
    std::array<VkDescriptorPoolSize, 2> poolSizes{};
    poolSizes[0].type = VK_DESCRIPTOR_TYPE_UNIFORM_BUFFER;
    poolSizes[0].descriptorCount = static_cast<uint32_t>(MAX_FRAMES_IN_FLIGHT);

    poolSizes[1].type = VK_DESCRIPTOR_TYPE_COMBINED_IMAGE_SAMPLER;
    poolSizes[1].descriptorCount = static_cast<uint32_t>(MAX_FRAMES_IN_FLIGHT);

    VkDescriptorPoolCreateInfo poolInfo{};
    poolInfo.sType = VK_STRUCTURE_TYPE_DESCRIPTOR_POOL_CREATE_INFO;
    poolInfo.poolSizeCount = static_cast<uint32_t>(poolSizes.size());
    poolInfo.pPoolSizes = poolSizes.data(); // this is not validated, so be cautios about it
    poolInfo.maxSets = static_cast<uint32_t>(MAX_FRAMES_IN_FLIGHT);

    if (vkCreateDescriptorPool(context.getDevice(), &poolInfo, nullptr, &m_descriptorPool) != VK_SUCCESS) {
        throw std::runtime_error("failed to create a descriptor pool!");
    }
}

//void VulkanDescriptors::createDescriptorSets(VulkanContext& context, VulkanSingleTimeCommand& singleTimeCommand, uint32_t MAX_FRAMES_IN_FLIGHT) {
//    std::vector<VkDescriptorSetLayout> layouts(MAX_FRAMES_IN_FLIGHT, m_descriptorSetLayout);
//    VkDescriptorSetAllocateInfo allocInfo{};
//    allocInfo.sType = VK_STRUCTURE_TYPE_DESCRIPTOR_SET_ALLOCATE_INFO;
//    allocInfo.descriptorPool = m_descriptorPool;
//    allocInfo.descriptorSetCount = static_cast<uint32_t>(MAX_FRAMES_IN_FLIGHT);
//    allocInfo.pSetLayouts = layouts.data();
//
//    m_descriptorSets.resize(MAX_FRAMES_IN_FLIGHT);
//    if (vkAllocateDescriptorSets(context.getDevice(), &allocInfo, m_descriptorSets.data()) != VK_SUCCESS) {
//        throw std::runtime_error("failed to allocated descriptor sets!");
//    }
//
//    for (size_t i = 0; i < MAX_FRAMES_IN_FLIGHT; i++) {
//        VkDescriptorBufferInfo bufferInfo{};
//        bufferInfo.buffer = uniformBuffers[i];
//        bufferInfo.offset = 0;
//        bufferInfo.range = sizeof(UniformBufferObject);
//
//        VkDescriptorImageInfo imageInfo{};
//        imageInfo.imageLayout = VK_IMAGE_LAYOUT_SHADER_READ_ONLY_OPTIMAL;
//        imageInfo.imageView = textureImageView;
//        imageInfo.sampler = textureSampler;
//
//        std::array<VkWriteDescriptorSet, 2> descriptorWrites{};
//        descriptorWrites[0].sType = VK_STRUCTURE_TYPE_WRITE_DESCRIPTOR_SET;
//        descriptorWrites[0].dstSet = m_descriptorSets[i];
//        descriptorWrites[0].dstBinding = 0;
//        descriptorWrites[0].dstArrayElement = 0;
//        descriptorWrites[0].descriptorType = VK_DESCRIPTOR_TYPE_UNIFORM_BUFFER;
//        descriptorWrites[0].descriptorCount = 1;
//        descriptorWrites[0].pBufferInfo = &bufferInfo;
//
//        descriptorWrites[1].sType = VK_STRUCTURE_TYPE_WRITE_DESCRIPTOR_SET;
//        descriptorWrites[1].dstSet = m_descriptorSets[i];
//        descriptorWrites[1].dstBinding = 1;
//        descriptorWrites[1].dstArrayElement = 0;
//        descriptorWrites[1].descriptorType = VK_DESCRIPTOR_TYPE_COMBINED_IMAGE_SAMPLER;
//        descriptorWrites[1].descriptorCount = 1;
//        descriptorWrites[1].pImageInfo = &imageInfo;
//
//        vkUpdateDescriptorSets(context.getDevice(), static_cast<uint32_t>(descriptorWrites.size()), descriptorWrites.data(), 0, nullptr);
//    }
//}

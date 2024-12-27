#include <cstring>
#include <vulkan/vulkan_core.h>
#include <memory>

#include "VulkanUBO.h"
#include "UBOStructs.h"

#include "../VulkanBufferManager.h"
#include "../VulkanContext.h"

using namespace Vulkan;

template class Vulkan::UBO<TransformationUBO>;

template <typename T>
UBO<T>::UBO(Context& context, BufferManager& bufferManager, T& uniformBufferStruct, uint32_t MAX_FRAMES_IN_FLIGHT)
    : m_context(context),
      m_bufferManager(bufferManager),
      m_uniformBufferStruct(uniformBufferStruct)
{
    createUBO(MAX_FRAMES_IN_FLIGHT);
}

template <typename T>
void UBO<T>::createUBO(uint32_t MAX_FRAMES_IN_FLIGHT) {
    VkDeviceSize bufferSize = sizeof(m_uniformBufferStruct);

    m_uniformBuffers.resize(MAX_FRAMES_IN_FLIGHT);
    m_uniformBuffersMemory.resize(MAX_FRAMES_IN_FLIGHT);
    m_uniformBuffersMapped.resize(MAX_FRAMES_IN_FLIGHT);

    for (size_t i = 0; i < MAX_FRAMES_IN_FLIGHT; i++) {
        m_bufferManager.createBuffer(
            bufferSize,
            VK_BUFFER_USAGE_UNIFORM_BUFFER_BIT,
            VK_MEMORY_PROPERTY_HOST_VISIBLE_BIT | VK_MEMORY_PROPERTY_HOST_COHERENT_BIT,
            m_uniformBuffers[i],
            m_uniformBuffersMemory[i]
        );

        vkMapMemory(
            m_context.getDevice(),
            m_uniformBuffersMemory[i],
            0,
            bufferSize,
            0,
            &m_uniformBuffersMapped[i]
        );
    }
}

template <typename T>
void UBO<T>::updateUBO(uint32_t currentFrame, const T& ubo) {
    memcpy(m_uniformBuffersMapped[currentFrame], &ubo, sizeof(ubo));
}

template <typename T>
VkWriteDescriptorSet UBO<T>::createDescriptorWrite(VkDescriptorSet& descriptorSet, uint32_t frameInFlight) {
    VkDescriptorBufferInfo* bufferInfo = new VkDescriptorBufferInfo{};
    bufferInfo->buffer = m_uniformBuffers[frameInFlight];
    bufferInfo->offset = 0;
    bufferInfo->range = sizeof(T);

    VkWriteDescriptorSet descriptorWrite{};
    descriptorWrite.sType = VK_STRUCTURE_TYPE_WRITE_DESCRIPTOR_SET;
    descriptorWrite.dstSet = descriptorSet;
    descriptorWrite.dstBinding = 0;
    descriptorWrite.dstArrayElement = 0;
    descriptorWrite.descriptorType = VK_DESCRIPTOR_TYPE_UNIFORM_BUFFER;
    descriptorWrite.descriptorCount = 1;
    descriptorWrite.pBufferInfo = bufferInfo;

    return descriptorWrite;
}

template <typename T>
VkDescriptorSetLayoutBinding createDescriptorSetLayoutConfig() {
    VkDescriptorSetLayoutBinding uboLayoutBinding{};
    uboLayoutBinding.binding = 0;
    uboLayoutBinding.descriptorType = VK_DESCRIPTOR_TYPE_UNIFORM_BUFFER;
    uboLayoutBinding.descriptorCount = 1;
    uboLayoutBinding.stageFlags = VK_SHADER_STAGE_VERTEX_BIT;
    uboLayoutBinding.pImmutableSamplers = nullptr;

    return uboLayoutBinding;
}

template <typename T>
VkDescriptorPoolSize createDescriptorPoolConfig(uint32_t MAX_FRAMES_IN_FLIGHT) {
    VkDescriptorPoolSize poolSize{};
    poolSize.type = VK_DESCRIPTOR_TYPE_UNIFORM_BUFFER;
    poolSize.descriptorCount = static_cast<uint32_t>(MAX_FRAMES_IN_FLIGHT);
    return poolSize;
}

template <typename T>
void UBO<T>::cleanup(uint32_t MAX_FRAMES_IN_FLIGHT) {
    for (size_t i = 0; i < MAX_FRAMES_IN_FLIGHT; i++) {
        vkDestroyBuffer(m_context.getDevice(), m_uniformBuffers[i], nullptr);
        vkFreeMemory(m_context.getDevice(), m_uniformBuffersMemory[i], nullptr);
    }
}



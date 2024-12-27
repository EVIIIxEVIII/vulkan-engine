#pragma once

#include <cstdint>
#include <vector>
#include <vulkan/vulkan.h>
#include <glm/mat4x4.hpp>
#include <vulkan/vulkan_core.h>
#include "../VulkanBufferManager.h"
#include "../VulkanContext.h"

namespace Vulkan {

class Context;
class BufferManager;

template <typename T>
class UBO {

public:
    UBO(Context& context, BufferManager& bufferManager, T& uniformBufferStruct, uint32_t MAX_FRAMES_IN_FLIGHT);
    void* getUBOMapped(uint32_t currentFrame) { return m_uniformBuffersMapped[currentFrame]; };
    void updateUBO(uint32_t currentFrame, const T& ubo);

    VkWriteDescriptorSet createDescriptorWrite(VkDescriptorSet& descriptorSet, uint32_t frameInFlight);
    VkDescriptorSetLayoutBinding createDescriptorSetLayoutConfig();
    VkDescriptorPoolSize createDescriptorPoolConfig();

    void cleanup(uint32_t MAX_FRAMES_IN_FLIGHT);

    VkBuffer getBuffer(uint32_t frame) { return m_uniformBuffers[frame]; };

private:
    std::vector<VkBuffer> m_uniformBuffers;
    std::vector<VkDeviceMemory>  m_uniformBuffersMemory;
    std::vector<void*> m_uniformBuffersMapped;

    VkDescriptorBufferInfo m_descriptor;
    VkWriteDescriptorSet m_writeDescriptor;

    BufferManager& m_bufferManager;
    Context& m_context;

    T& m_uniformBufferStruct;

    void createUBO(uint32_t MAX_FRAMES_IN_FLIGHT);
};

}

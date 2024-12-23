#pragma once

#include "VulkanBufferManager.h"
#include <vector>
#include <vulkan/vulkan.h>
#include <vulkan/vulkan_core.h>
#include <glm/mat4x4.hpp>

class VulkanContext;
class VulkanSingleTimeCommand;

struct UniformBufferObject {
    alignas(16) glm::mat4 model;
    alignas(16) glm::mat4 view;
    alignas(16) glm::mat4 proj;
};

class VulkanDescriptors {
public:
    VulkanDescriptors();
    ~VulkanDescriptors();

    void init(VulkanContext& context, uint32_t MAX_FRAMES_IN_FLIGHT);
    void cleanup(VulkanContext& context);

public:
    const VkDescriptorSetLayout&    getDescriptorSetLayout() const { return m_descriptorSetLayout; }
    VkDescriptorPool                getDescriptorPool()      const { return m_descriptorPool; }
    std::vector<VkDescriptorSet>    getDescriptorSets()      const { return m_descriptorSets; }

private:
    void createDescriptorSetLayout(VulkanContext& context);
    void createDescriptorPool(VulkanContext& context, uint32_t MAX_FRAMES_IN_FLIGHT);
    void createDescriptorSets(VulkanContext& context, VulkanSingleTimeCommand& singleTimeCommand, uint32_t MAX_FRAMES_IN_FLIGHT);

private:
    VkDescriptorSetLayout m_descriptorSetLayout;
    VkDescriptorPool m_descriptorPool;
    std::vector<VkDescriptorSet> m_descriptorSets;
    std::vector<UniformBufferObject> m_uniformBuffers;
    std::vector<VkDeviceMemory>  m_uniformBuffersMemory;
    std::vector<void*> m_uniformBuffersMapped;
};

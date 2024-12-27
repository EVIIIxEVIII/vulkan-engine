#pragma once

#include "VulkanBufferManager.h"
#include <vector>
#include <vulkan/vulkan.h>
#include <vulkan/vulkan_core.h>
#include <glm/mat4x4.hpp>

namespace  Vulkan {

class Context;
class SingleTimeCommand;


class Descriptors {
public:
    Descriptors();
    ~Descriptors();

    void init(Context& context, uint32_t MAX_FRAMES_IN_FLIGHT);
    void cleanup(Context& context);

public:
    const VkDescriptorSetLayout&    getDescriptorSetLayout() const { return m_descriptorSetLayout; }
    VkDescriptorPool                getDescriptorPool()      const { return m_descriptorPool; }
    std::vector<VkDescriptorSet>    getDescriptorSets()      const { return m_descriptorSets; }

private:
    void createDescriptorSetLayout(Context& context);
    void createDescriptorPool(Context& context, uint32_t MAX_FRAMES_IN_FLIGHT);
    void createDescriptorSets(Context& context, SingleTimeCommand& singleTimeCommand, uint32_t MAX_FRAMES_IN_FLIGHT);

private:
    VkDescriptorSetLayout m_descriptorSetLayout;
    VkDescriptorPool m_descriptorPool;
    std::vector<VkDescriptorSet> m_descriptorSets;
};

}

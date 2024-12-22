#pragma once

#include <GLFW/glfw3.h>
#include <vulkan/vulkan.h>
#include <vector>
#include <string>
#include <optional>
#include <vulkan/vulkan_core.h>

class Window;

struct SwapChainSupportDetails {
    VkSurfaceCapabilitiesKHR capabilities;
    std::vector<VkSurfaceFormatKHR> formats;
    std::vector<VkPresentModeKHR> presentModes;
};

struct QueueFamilyIndices {
    std::optional<uint32_t> graphicsFamily;
    std::optional<uint32_t> presentFamily;

    bool isComplete() {
        return graphicsFamily.has_value() && presentFamily.has_value();
    }
};

class VulkanContext {
public:
    VulkanContext();
    ~VulkanContext();

    void init(Window& window);
    void cleanup();

    VkInstance            getInstance()         const { return m_instance; }
    VkPhysicalDevice      getPhysicalDevice()   const { return m_physicalDevice; }
    VkDevice              getDevice()           const { return m_device; }
    VkQueue               getGraphicsQueue()    const { return m_graphicsQueue; }
    VkQueue               getPresentQueue()     const { return m_presentQueue; }
    VkSampleCountFlagBits getMsaaSamples()      const { return m_msaaSamples; }
    VkSurfaceKHR          getSurface()          const { return m_surface; }
    QueueFamilyIndices    getQueueFamilyIndices() const { return m_queueFamilyIndices; }
    bool                  isValidationEnabled() const { return m_enableValidationLayers; }

    SwapChainSupportDetails querySwapChainSupport(VkPhysicalDevice device);

private:
    void createInstance();
    void setupDebugMessenger();
    void createSurface(Window& window);
    void pickPhysicalDevice();
    QueueFamilyIndices findQueueFamilies(VkPhysicalDevice device);
    void createLogicalDevice();

    bool isDeviceSuitable(VkPhysicalDevice device);
    bool checkDeviceExtensionSupport(VkPhysicalDevice device);

    VkSampleCountFlagBits getMaxUsableSampleCount();

    bool checkValidationLayerSupport();
    std::vector<const char*> getRequiredExtensions();
    void populateDebugMessengerCreateInfo(VkDebugUtilsMessengerCreateInfoEXT& createInfo);

private:
    VkInstance                  m_instance = VK_NULL_HANDLE;
    VkDebugUtilsMessengerEXT    m_debugMessenger = VK_NULL_HANDLE;
    VkSurfaceKHR                m_surface = VK_NULL_HANDLE;
    QueueFamilyIndices          m_queueFamilyIndices;

    VkPhysicalDevice            m_physicalDevice = VK_NULL_HANDLE;
    VkDevice                    m_device = VK_NULL_HANDLE;

    VkQueue                     m_graphicsQueue = VK_NULL_HANDLE;
    VkQueue                     m_presentQueue = VK_NULL_HANDLE;
    VkSampleCountFlagBits       m_msaaSamples = VK_SAMPLE_COUNT_1_BIT;

    bool m_enableValidationLayers = true;
};

#pragma once

#include <vulkan/vulkan.h>
#include <vector>
#include <vulkan/vulkan_core.h>

namespace Vulkan {

class Context;
class Window;

class SwapChain {
public:
    SwapChain();
    ~SwapChain();

    void init(Context& context, Window& window);
    void cleanup(Context& context);
    void recreate(Context& context, Window& window);

    VkFormat            getImageFormat() const { return m_swapChainFormat; }
    VkExtent2D          getExtent()      const { return m_swapChainExtent; }
    VkSwapchainKHR      getSwapChain()            const { return m_swapChain; }
    const std::vector<VkImageView>& getImageViews() const { return m_swapChainImageViews; }

private:
    void createSwapChain(Context& context, Window& window);
    void createImageViews(Context& context);
    VkImageView createImageView(Context& context, VkImage image, VkFormat format);

    VkSurfaceFormatKHR chooseSwapSurfaceFormat(const std::vector<VkSurfaceFormatKHR>& availableFormats);
    VkPresentModeKHR   chooseSwapPresentMode(const std::vector<VkPresentModeKHR>& availablePresentModes);
    VkExtent2D         chooseSwapExtent(const VkSurfaceCapabilitiesKHR& capabilities, Window& window);

private:
    VkSwapchainKHR           m_swapChain = VK_NULL_HANDLE;
    std::vector<VkImage>     m_swapChainImages;
    std::vector<VkImageView> m_swapChainImageViews;

    VkFormat                 m_swapChainFormat;
    VkExtent2D               m_swapChainExtent;
};

}

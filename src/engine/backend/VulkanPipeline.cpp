#include "VulkanPipeline.hpp"

#include <string>
#include <vector>
#include <fstream>
#include <iostream>

namespace Vulkan {

GraphicsPipeline::GraphicsPipeline(const std::string& vertFilepath, const std::string& fragFilepath) {
    createGraphicsPipeline(vertFilepath, fragFilepath);
}

std::vector<char> GraphicsPipeline::readFile(const std::string& filename) {
    std::ifstream file(filename, std::ios::ate | std::ios::binary);

    if (!file.is_open()) {
        std::cout << "Failed with file: "<< filename << "\n";
        throw std::runtime_error("failed to open file!");
    }

    size_t fileSize = (size_t) file.tellg();
    std::vector<char> buffer(fileSize);

    file.seekg(0);
    file.read(buffer.data(), fileSize);

    file.close();

    return buffer;
}

void GraphicsPipeline::createGraphicsPipeline(const std::string& vertFilepath, const std::string& fragFilepath) {
    auto vertCode = readFile(vertFilepath);
    auto fragCode = readFile(fragFilepath);

    std::cout << "Vertex shader size: " << vertCode.size() << "\n";
    std::cout << "Fragment shader size: " << fragCode.size() << "\n";
}

}

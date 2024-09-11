#pragma once
#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>
#include <vector>
#include <optional>

using namespace std;

struct QueueFamilyIndicesTmp
{
    optional<uint32_t> graphicsFamily;
    optional<uint32_t> presentFamily;

    bool isComplete()
    {
        return graphicsFamily.has_value() && presentFamily.has_value();
    }
};

struct SwapChainSupportDetailsTmp
{
    VkSurfaceCapabilitiesKHR capabilities;
    std::vector<VkSurfaceFormatKHR> formats;
    std::vector<VkPresentModeKHR> presentModes;
};

class App
{
public:
    void Run();

private:
    void InitWindow();
    void InitVulkan();
    void MainLoop();
    void Cleanup();

    void CreateInstance();
    void SetupDebugMessenger();
    void CreateSurface();
    void PickPhysicalDevice();
    void CreateLogicalDevice();
    void CreateSwapChain();
    void CreateImageViews();
    void CreateRenderPass();
    void CreateGraphicsPipeline();
    void CreateFramebuffers();
    void CreateCommandPool();
    void CreateCommandBuffers();
    void CreateSyncObjects();

    void RecordCommandBuffer(VkCommandBuffer commandBuffer, uint32_t imageIndex);
    void DrawFrame();

private:
    GLFWwindow *mWindow;

    VkInstance mInstance;
    VkDebugUtilsMessengerEXT mDebugMessenger;
    VkSurfaceKHR mSurface;

    VkPhysicalDevice mPhysicalDevice = VK_NULL_HANDLE;
    VkDevice mDevice;

    VkQueue mGraphicsQueue;
    VkQueue mPresentQueue;

    VkSwapchainKHR mSwapChain;
    vector<VkImage> mSwapChainImages;
    VkFormat mSwapChainImageFormat;
    VkExtent2D mSwapChainExtent;
    vector<VkImageView> mSwapChainImageViews;
    vector<VkFramebuffer> mSwapChainFramebuffers;

    VkRenderPass mRenderPass;
    VkPipelineLayout mPipelineLayout;
    VkPipeline mGraphicsPipeline;

    VkCommandPool mCommandPool;
    vector<VkCommandBuffer> mCommandBuffers;

    vector<VkSemaphore> mImageAvailableSemaphores;
    vector<VkSemaphore> mRenderFinishedSemaphores;
    vector<VkFence> mInFlightFences;

    int mCurrentFrame = 0;

private:
    // todo move to device class
    bool IsDeviceSuitable(VkPhysicalDevice device);
    QueueFamilyIndicesTmp FindQueueFamilies(VkPhysicalDevice device);
    bool CheckDeviceExtensionSupport(VkPhysicalDevice device);
    SwapChainSupportDetailsTmp QuerySwapChainSupport(VkPhysicalDevice device);
    VkExtent2D ChooseSwapExtent(const VkSurfaceCapabilitiesKHR &capabilities);
    VkShaderModule CreateShaderModule(const std::vector<char> &code);
};
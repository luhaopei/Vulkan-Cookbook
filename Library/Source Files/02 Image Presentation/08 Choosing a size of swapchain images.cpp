// Permission is hereby granted, free of charge, to any person obtaining a
// copy of this software and associated documentation files (the "Software"),
// to deal in the Software without restriction, including without limitation
// the rights to use, copy, modify, merge, publish, distribute, sublicense,
// and / or sell copies of the Software, and to permit persons to whom the
// Software is furnished to do so, subject to the following conditions:
//
// The below copyright notice and this permission notice shall be included
// in all copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.IN NO EVENT SHALL
// THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
// FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
// DEALINGS IN THE SOFTWARE.
//
// Vulkan Cookbook
// ISBN: 9781786468154
// � Packt Publishing Limited
//
// Author:   Pawel Lapinski
// LinkedIn: https://www.linkedin.com/in/pawel-lapinski-84522329
//
// Chapter: 02 Image Presentation
// Recipe:  08 Choosing a size of swapchain images

#include "02 Image Presentation/08 Choosing a size of swapchain images.h"

namespace VulkanCookbook {

  bool ChooseSizeOfSwapchainImages( VkSurfaceCapabilitiesKHR const & surface_capabilities,
                                    VkExtent2D                     & size_of_images ) {
    if( 0xFFFFFFFF == surface_capabilities.currentExtent.width ) {
      size_of_images = { 640, 480 };

      if( size_of_images.width < surface_capabilities.minImageExtent.width ) {
        size_of_images.width = surface_capabilities.minImageExtent.width;
      } else if( size_of_images.width > surface_capabilities.maxImageExtent.width ) {
        size_of_images.width = surface_capabilities.maxImageExtent.width;
      }

      if( size_of_images.height < surface_capabilities.minImageExtent.height ) {
        size_of_images.height = surface_capabilities.minImageExtent.height;
      } else if( size_of_images.height > surface_capabilities.maxImageExtent.height ) {
        size_of_images.height = surface_capabilities.maxImageExtent.height;
      }
    } else {
      size_of_images = surface_capabilities.currentExtent;
    }
    return true;
  }

} //namespace VulkanCookbook

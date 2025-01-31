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
// Chapter: 05 Descriptor Sets
// Recipe:  02 Creating a sampled image

#include "04 Resources and Memory/05 Creating an image.h"
#include "04 Resources and Memory/06 Allocating and binding memory object to an image.h"
#include "04 Resources and Memory/08 Creating an image view.h"
#include "05 Descriptor Sets/02 Creating a sampled image.h"

namespace VulkanCookbook {

  bool CreateSampledImage( VkPhysicalDevice    physical_device,
                           VkDevice            logical_device,
                           VkImageType         type,
                           VkFormat            format,
                           VkExtent3D          size,
                           uint32_t            num_mipmaps,
                           uint32_t            num_layers,
                           VkImageUsageFlags   usage,
                           bool                cubemap,
                           VkImageViewType     view_type,
                           VkImageAspectFlags  aspect,
                           bool                linear_filtering,
                           VkImage           & sampled_image,
                           VkDeviceMemory    & memory_object,
                           VkImageView       & sampled_image_view ) {
    VkFormatProperties format_properties;
    vkGetPhysicalDeviceFormatProperties( physical_device, format, &format_properties );
    if( !(format_properties.optimalTilingFeatures & VK_FORMAT_FEATURE_SAMPLED_IMAGE_BIT) ) {
      std::cout << "Provided format is not supported for a sampled image." << std::endl;
      return false;
    }
    if( linear_filtering &&
        !(format_properties.optimalTilingFeatures & VK_FORMAT_FEATURE_SAMPLED_IMAGE_FILTER_LINEAR_BIT) ) {
      std::cout << "Provided format is not supported for a linear image filtering." << std::endl;
      return false;
    }

    if( !CreateImage( logical_device, type, format, size, num_mipmaps, num_layers, VK_SAMPLE_COUNT_1_BIT, usage | VK_IMAGE_USAGE_SAMPLED_BIT, cubemap, sampled_image ) ) {
      return false;
    }

    if( !AllocateAndBindMemoryObjectToImage( physical_device, logical_device, sampled_image, VK_MEMORY_PROPERTY_DEVICE_LOCAL_BIT, memory_object ) ) {
      return false;
    }

    if( !CreateImageView( logical_device, sampled_image, view_type, format, aspect, sampled_image_view ) ) {
      return false;
    }
    return true;
  }

} //namespace VulkanCookbook

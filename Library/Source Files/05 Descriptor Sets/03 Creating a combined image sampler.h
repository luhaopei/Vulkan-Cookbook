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
// Recipe:  03 Creating a combined image sampler

#ifndef CREATING_A_COMBINED_IMAGE_SAMPLER
#define CREATING_A_COMBINED_IMAGE_SAMPLER

#include "Common.h"

namespace VulkanCookbook {

  bool CreateCombinedImageSampler( VkPhysicalDevice       physical_device,
                                   VkDevice               logical_device,
                                   VkImageType            type,
                                   VkFormat               format,
                                   VkExtent3D             size,
                                   uint32_t               num_mipmaps,
                                   uint32_t               num_layers,
                                   VkImageUsageFlags      usage,
                                   bool                   cubemap,
                                   VkImageViewType        view_type,
                                   VkImageAspectFlags     aspect,
                                   VkFilter               mag_filter,
                                   VkFilter               min_filter,
                                   VkSamplerMipmapMode    mipmap_mode,
                                   VkSamplerAddressMode   u_address_mode,
                                   VkSamplerAddressMode   v_address_mode,
                                   VkSamplerAddressMode   w_address_mode,
                                   float                  lod_bias,
                                   bool                   anisotropy_enable,
                                   float                  max_anisotropy,
                                   bool                   compare_enable,
                                   VkCompareOp            compare_operator,
                                   float                  min_lod,
                                   float                  max_lod,
                                   VkBorderColor          border_color,
                                   bool                   unnormalized_coords,
                                   VkSampler            & sampler,
                                   VkImage              & sampled_image,
                                   VkDeviceMemory       & memory_object,
                                   VkImageView          & sampled_image_view );

} //namespace VulkanCookbook

#endif // CREATING_A_COMBINED_IMAGE_SAMPLER
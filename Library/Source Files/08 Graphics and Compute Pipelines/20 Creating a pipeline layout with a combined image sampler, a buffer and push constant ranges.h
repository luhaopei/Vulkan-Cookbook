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
// Chapter: 08 Graphics and Compute Pipelines
// Recipe:  20 Creating a pipeline layout with a combined image sampler, a buffer and push constant ranges

#ifndef CREATING_A_PIPELINE_LAYOUT_WITH_A_COMBINED_IMAGE_SAMPLER_A_BUFFER_AND_PUSH_CONSTANT_RANGES
#define CREATING_A_PIPELINE_LAYOUT_WITH_A_COMBINED_IMAGE_SAMPLER_A_BUFFER_AND_PUSH_CONSTANT_RANGES

#include "Common.h"

namespace VulkanCookbook {

  bool CreatePipelineLayoutWithCombinedImageSamplerBufferAndPushConstantRanges( VkDevice                                 logical_device,
                                                                                std::vector<VkPushConstantRange> const & push_constant_ranges,
                                                                                VkDescriptorSetLayout                  & descriptor_set_layout,
                                                                                VkPipelineLayout                       & pipeline_layout );

} //namespace VulkanCookbook

#endif // CREATING_A_PIPELINE_LAYOUT_WITH_A_COMBINED_IMAGE_SAMPLER_A_BUFFER_AND_PUSH_CONSTANT_RANGES
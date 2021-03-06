#include "tp_obj/Globals.h"

#include "tp_utils/DebugUtils.h"

namespace tp_obj
{

//##################################################################################################
TextureOptions splitTextureOptions(const std::string& in)
{
  TextureOptions textureOptions;

  std::vector<std::string> parts;
  tpSplit(parts, in, ' ', tp_utils::SplitBehavior::KeepEmptyParts);

  for(size_t i=0; i<parts.size(); i+=2)
  {
    std::string key = parts.at(i);
    if(tpStartsWith(key, "-"))
    {
      std::string value;
      if(size_t ii = i+1; ii<parts.size())
        value = parts.at(ii);
      textureOptions.options.emplace_back(key, value);
      tpWarning() << "Extra options: " << key << " " << value;
    }
    else
    {
      for(; i<parts.size(); i++)
      {
        if(!textureOptions.file.empty())
          textureOptions.file += ' ';
        textureOptions.file += parts.at(i);
      }
    }
  }

  return textureOptions;
}

}

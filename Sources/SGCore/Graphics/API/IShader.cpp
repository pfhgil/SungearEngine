//
// Created by stuka on 13.05.2023.
//

#include "IShader.h"

void Core::Graphics::API::IShader::addShaderDefines(const std::vector<ShaderDefine>& shaderDefines)
{
    for(auto& shaderDefine : shaderDefines)
    {
        if(std::find(m_defines.begin(), m_defines.end(), shaderDefine) != m_defines.end()) return;

        m_defines.push_back(shaderDefine);
    }

    if(m_assetModifiedChecking) onAssetModified();
}

void Core::Graphics::API::IShader::removeShaderDefine(const Core::Graphics::API::ShaderDefine& shaderDefine)
{
    m_defines.remove(shaderDefine);

    if(m_assetModifiedChecking) onAssetModified();
}

void Core::Graphics::API::IShader::removeShaderDefine(const std::string& shaderDefineName)
{
    m_defines.remove(ShaderDefine(shaderDefineName, ""));

    if(m_assetModifiedChecking) onAssetModified();
}

void Core::Graphics::API::IShader::onAssetModified()
{
    compile(m_fileAsset.lock());
}

void Core::Graphics::API::IShader::onAssetPathChanged()
{
    compile(m_fileAsset.lock());
}

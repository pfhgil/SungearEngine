#pragma once

#ifndef SUNGEARENGINE_IMATERIAL_H
#define SUNGEARENGINE_IMATERIAL_H

#include <map>
#include <string>

#include "SGCore/Graphics/API/ITexture2D.h"
#include "SGCore/Graphics/API/IShader.h"
#include "SGCore/Memory/AssetManager.h"
#include "SGCore/Memory/Assets/IAsset.h"

namespace Core::Memory::Assets
{
    class IMaterial : public std::enable_shared_from_this<IMaterial>, public IAsset
    {
    protected:
        // EXAMPLE:
        // first: material texture type
        // second : std::pair<std::uint8_t, std::map<std::string, std::pair<std::uint8_t, std::shared_ptr<Texture2DAsset>>>>
        //      first: maximum textures of this type
        //      second: offset of first texture block for this texture type
        //      third: std::map<std::string, std::pair<std::uint8_t, std::shared_ptr<Texture2DAsset>>>
        //          first: std::string - path to texture
        //          second: std::tuple<std::uint8_t, std::shared_ptr<Texture2DAsset>> - Texture2DAsset
        //              first: std::uint8_t - texture unit to bind for this texture (watch down - second)
        //              second: std::shared_ptr<Texture2DAsset> - texture 2d asset
        std::map<SGMaterialTextureType, std::tuple<std::uint8_t, std::uint8_t, std::map<std::string, std::pair<std::uint8_t, std::shared_ptr<Texture2DAsset>>>>> m_textures;

        std::shared_ptr<Graphics::API::IShader> m_shader;

    public:
        std::string m_name;

        //virtual IMaterial() noexcept;

        #pragma region Materials

        //void createAsPBR() noexcept;

        #pragma endregion

        std::shared_ptr<IMaterial> bind();

        // TODO: impl
        std::shared_ptr<IAsset> load(const std::string& path) override = 0;

        /**
        * Adds texture2D. Method is copying texture.
        * @param type - Material type of texture
        * @param texture2DAsset - Texture asset
        * @return this
        */
        virtual std::shared_ptr<IMaterial> addTexture2D(const SGMaterialTextureType& type,
                                                const std::shared_ptr<Memory::Assets::Texture2DAsset>& texture2DAsset) = 0;

        /**
        * Adds texture2D. Method is copying texture. This method is looking for texture asset by path.
        * @param type - Material type of texture
        * @param texture2DAsset - Texture asset
        * @return this
        */
        virtual std::shared_ptr<IMaterial> findAndAddTexture2D(const SGMaterialTextureType& type, const std::string& path) = 0;

        /**
         * Sets texture2D by name. Method is copying texture.
         * @param type - Material type of texture
         * @param path - The path to the texture to be replaced
         * @param texture2DAsset - Texture asset
         *
         * @return this
         */
        virtual std::shared_ptr<IMaterial> setTexture2D(const SGMaterialTextureType& type, const std::string_view& path,
                                                const std::shared_ptr<Memory::Assets::Texture2DAsset>& texture2DAsset) = 0;
        /**
         * Sets texture2D by name. Method is copying texture. This method is looking for texture asset by path.
         * @param type - Material type of texture
         * @param path - Path to texture asset
         * @return
         */
        virtual std::shared_ptr<IMaterial> findAndSetTexture2D(const SGMaterialTextureType& type, const std::string& path) = 0;

        //std::shared_ptr<Texture2DAsset> getTexture2D(const std::string& name) noexcept;
    };
}

#endif //SUNGEARENGINE_IMATERIAL_H
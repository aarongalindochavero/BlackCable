#pragma once
#define STB_IMAGE_IMPLEMENTATION
#include <GL\glew.h>
#include <string>

namespace BCE
{
	namespace Graphics
	{

		class Texture
		{
		public:
			Texture();
			Texture(std::string fileLoc);
			void LoadTexture();
			void UseTexture(unsigned int i = 0);
			void ClearTexture();
			~Texture();
		private:
			GLuint textureID;
			int width, height, bitDepth;
			std::string fileLocation;
		};

	}
}